#include <iostream>
#include <queue>
#include "aircraft.cpp"
using namespace std;



int main () 
{
    oop::Tree<int> * tree = new oop::Tree<int>();

    tree->insert(111);
    tree->insert(2);
    tree->insert(4);
    tree->insert(11);
    tree->insert(5);
    tree->insert(7);

    tree->deleteNode(2);

    cout << tree->min()->getNumValue() << endl;

    return 0;
}
