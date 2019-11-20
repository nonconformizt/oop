#ifndef TEXT_COMPARATOR
#define TEXT_COMPARATOR
#include <iostream>
#include <fstream>
#include <map>
#include <list>

namespace oop
{


class TextComparator {  
    
    private:
        std::map <std::string, int> text1, text2;
    public: 
        TextComparator(std::string text1name, std::string text2name);

        std::list<std::string> findSingleWords();
        std::list<std::string> getDictionary();


};




TextComparator::TextComparator(std::string text1name, std::string text2name)
{
    std::ifstream input;
    std::string word;

    input.open(text1name);
    if (!input.is_open())
        throw "Cannot open file!";

    while (input >> word)
    {
        if (text1.count(word) == 0)
            text1[word] = 1;
        else 
            text1[word]++;
    }
    
    input.close();
    input.open(text2name);
    if (!input.is_open())
        throw "Cannot open file!";

    while (input >> word)
    {
        if (text2.count(word) == 0)
            text2[word] = 1;
        else 
            text2[word]++;
    }
}


std::list<std::string> TextComparator::findSingleWords()
{
    std::list <std::string> res;

    for (const auto & w : text1)
    {
        if (w.second == 1)
            if (text2.count(w.first) == 1)
                res.push_back(w.first);
    }

    std::cout << "\n\nSingle words found: \n===================\n";
    for (const auto & word : res)
        std::cout << word << std::endl;

    return res;
}


std::list<std::string> TextComparator::getDictionary()
{
    std::list <std::string> res;
    std::map <std::string, int> dictMap;

    dictMap.insert(text1.begin(), text1.end());
    dictMap.insert(text2.begin(), text2.end());

    for (const auto & w : dictMap)
        res.push_back(w.first);


    std::cout << "\n\nDictionary: \n===========\n";
    for (const auto & w : res)
        std::cout << w << std::endl;


    return res;
}








} // namespace oop

#endif // TEXT_COMPARATOR