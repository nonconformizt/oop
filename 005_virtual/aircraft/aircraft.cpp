#ifndef AIRCRAFT_CPP
#define AIRCRAFT_CPP
#include <iostream>
#include <string>
#include <queue>

namespace oop
{


class Flight {

public:
    int number;
    int time;
    std::string days;

    Flight (int number, int time, std::string days) {
        this->number = number;
        this->time = time;
        this->days = days;
    }

    void print() {
        std::cout << "Flight number: " << number << "; time: " << time << "; week days: " << days << std::endl;
    }

};


template <typename T>
class TreeNode {

public:
    T data;
    TreeNode<T> * left = nullptr;
    TreeNode<T> * right = nullptr;

    TreeNode(T data) { this->data = data; }
    void insert(T value);
    void print();

};


// template <>
// void TreeNode< std::queue<Flight *> >::insert( std::queue<Flight *> queue)
// {
//     if (queue.size() < data.size())
//         if (left == nullptr)
//             left = new TreeNode<std::queue<Flight *>>(queue);
//         else 
//             left->insert(queue);
//     else 
//         if (right == nullptr)
//             right = new TreeNode<std::queue<Flight *>>(queue);
//         else 
//             right->insert(queue);
// }


template <typename T>
void TreeNode<T>::insert(T value)
{
    if (value < data) {
        if (left == nullptr) {
            auto node = new TreeNode<T>(value);
            node->left = nullptr;
            node->right = nullptr;
            left = node;
        }
        else 
            left->insert(value);
    }
    else {
        if (right == nullptr) {
            auto node = new TreeNode<T>(value);
            node->left = nullptr;
            node->right = nullptr;
            right = node;
        }
        else 
            right->insert(value);
    }
}


// template <>
// void TreeNode< std::queue<Flight *> >::print()
// {
//     std::cout << "=== Node: \n";
//     while(!data.empty())
//     {
//         data.front()->print();
//         data.pop();
//     }
//     std::cout << "=== End of node: \n\n";
// }


template <typename T>
void TreeNode<T>::print()
{
    std::cout << data << "\n";
}





template <typename T>
class Tree {

private: 
    TreeNode<T> * root;

public: 
    void insert(T data);
    void print();
    void traverse(TreeNode<T> * node);


};


template <typename T>
void Tree<T>::insert(T data)
{   
    if (root == nullptr)
        root = new TreeNode<T>(data);
    else
        root->insert(data);
}


template <typename T>
void Tree<T>::print()
{
    traverse(root);
}


template <typename T>
void Tree<T>::traverse(TreeNode<T> * node)
{
    if (node != nullptr)
    {
        traverse(node->left);
        // node->print();
        std::cout << node->data;
        traverse(node->right);
    }

}





} // namespace oop

#endif // AIRCRAFT_CPP