#include <algorithm>
#include <fstream>
#include <iostream>

#include "Dictionary.h"

namespace Anagrams
{
    const std::vector<std::string>& Dictionary::GetAnagrams(const std::string& word) const
    {
        std::string sortedWord = word;
        // rearrange word alphabetically and find a matching key in m_wordMap
        std::sort(sortedWord.begin(), sortedWord.end());
        auto it = m_wordMap.find(sortedWord);
        if (it == m_wordMap.end())
        {
            static const std::vector<std::string> empty;
            return empty;
        }
        return it->second;
    }

    bool Dictionary::ConstructDictionary(const std::string& dictionaryFileName)
    {
        std::ifstream dictionaryFile(dictionaryFileName);
        if (!dictionaryFile)
        {
            std::cerr << "Failed to open dictionary file." << std::endl;
            return false;
        }

        std::string word;
        while (std::getline(dictionaryFile, word))
        {
            AddWord(word);
        }

        dictionaryFile.close();

        if (m_wordMap.empty())
        {
            std::cerr << "No words found in dictionary file." << std::endl;
            return false;
        }
        return true;
    }

    void Dictionary::AddWord(const std::string& word)
    {
        std::string sortedWord = word;
        // rearrange word alphabetically and use it as key
        std::sort(sortedWord.begin(), sortedWord.end());
        // add original word to the collection for this key
        m_wordMap[sortedWord].push_back(word);
    }
}
