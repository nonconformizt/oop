#include <iostream>
#include <map>
#include "./text.cpp"
using namespace std;



int main()
{
    oop::TextComparator txtcmp("file1", "file2");

    txtcmp.findSingleWords();
    txtcmp.getDictionary();
}