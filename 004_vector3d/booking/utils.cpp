#ifndef UTILS
#define UTILS
#include <iostream>
#include <vector>
#include <algorithm>

namespace oop
{


inline bool hyphen(char c){
    return c == '-';
}
 
inline bool nothyphen(char c){
    return c != '-';
}

//break a sentence into words
std::vector <std::string> split(const std::string & s)
{
    typedef std::string::const_iterator iter;
    std::vector<std::string> ret;
    iter i = s.begin();

    while(i != s.end())
    {
        i = find_if(i, s.end(), nothyphen); // find the beginning of a word
        iter j= find_if(i, s.end(), hyphen); // find the end of the same word
        if(i!=s.end()){
            ret.push_back(std::string(i, j)); //insert the word into vector
            i = j; // repeat 1,2,3 on the rest of the line.
        }
    }
    return ret;
}





} // namespace oop

#endif // UTILS