#include <iostream>

#include "Dictionary.h"

int main(const int argc, const char* const argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: Anagram <dictionary_filename>\n";
		return -1;
	}

	const char* dictionaryFile = argv[1];

	Anagrams::Dictionary dictionary;
	if (!dictionary.ConstructDictionary(dictionaryFile))
	{
		return 0;
	}

	bool exiting = false;
	while (!exiting)
	{
		std::string word;
		std::cout << "Enter word (empty to exit):" << std::endl;
		std::getline(std::cin, word);

		if (!word.empty())
		{
			std::cout << "Anagrams found: { ";
			auto anagrams = dictionary.GetAnagrams(word);
			for (const auto& anagram : anagrams)
			{
				if (anagram != word)
				{
					std::cout << anagram.c_str() << " ";
				}
			}
			std::cout << "}" << std::endl;
		}
		else
		{
			exiting = true;
		}
	}

	return 0;
}

