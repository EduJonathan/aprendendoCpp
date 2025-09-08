#include <iostream>
#include <algorithm>
#include "class_prototipo.hpp"

bool Prototipo::isUniverse(std::array<int, 26> &s1, std::array<int, 26> &s2)
{
    for (int i = 0; i < 26; ++i)
    {
        if (s1[i] < s2[i])
            return false;
    }
    return true;
}

std::vector<std::string> Prototipo::wordSubsets(const std::vector<std::string> &words1,
                                                const std::vector<std::string> &words2)
{
    std::array<int, 26> maxFrequency{0};

    for (const auto &word : words2)
    {
        std::array<int, 26> freq{0};

        for (char ch : word)
            freq[ch - 'a']++;

        for (int i = 0; i < 26; ++i)
            maxFrequency[i] = std::max(maxFrequency[i], freq[i]);
    }

    // Depuração: mostra maxFrequency
    std::cout << "maxFrequency: ";
    for (int i = 0; i < 26; ++i)
        std::cout << maxFrequency[i] << ' ';
    std::cout << "\n\n";

    std::vector<std::string> result;

    for (const auto &word : words1)
    {
        std::array<int, 26> freq{0};

        for (char ch : word)
            freq[ch - 'a']++;

        // Depuração: mostra frequência da palavra
        std::cout << "frequency for \"" << word << "\": ";
        for (int i = 0; i < 26; ++i)
            std::cout << freq[i] << ' ';
        std::cout << '\n';

        if (isUniverse(freq, maxFrequency))
        {
            std::cout << word << " é um subconjunto.\n\n";
            result.push_back(word);
        }
        else
        {
            std::cout << word << " não é subconjunto.\n\n";
        }
    }

    std::cout << "Foram encontradas " << result.size() << " palavras.\n";
    return result;
}
