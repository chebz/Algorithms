#pragma once
#include <string>
#include <vector>
#include <map>

#include <vector>

namespace Anagrams
{
    /*
     * Dictionary provides a wrapper around word data that is organized to easily find anagrams
     */
    class Dictionary
    {
    public:
        // Create a source dictionary from text file
        bool ConstructDictionary(const std::string& dictionaryFileName);

        // Get a list of anagrams excluding the word itself
        const std::vector<std::string>& GetAnagrams(const std::string& word) const;

    private:
        // map of alphabetically sorted keys matching all words in dictionary
        std::map<std::string, std::vector<std::string>> m_wordMap;

        // Add new word to a dictionary
        void AddWord(const std::string& word);
    };
}
