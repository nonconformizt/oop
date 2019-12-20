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

    Flight() {
        fill();
    }

    void print() {
        std::cout << "Flight number: " << number << "; time: " << time << "; week days: " << days << std::endl;
    }

    void fill() {
        std::cout << "Insert flight number: ";
        std::cin >> number;

        std::cout << "Insert time: ";
        std::cin >> time;

        std::cout << "Insert flight days: ";
        std::cin >> days;
    }

};



/***************************************************************************/



template <typename T>
class TreeNode {

public:
    TreeNode<T> * left = nullptr;
    TreeNode<T> * right = nullptr;

    TreeNode(T data) { this->data = data; }
    int getNumValue();
    T getRealValue() { return data; };
    void setRealValue(T data) { this->data = data; };
    void insert(T value);
    void print();

private: 
    T data;

};


template <>
int TreeNode <std::queue<Flight *>> ::getNumValue()
{
    return data.size();
}

template <typename T>
int TreeNode<T>::getNumValue()
{
    return data;
}


template <>
void TreeNode< std::queue<Flight *> >::insert( std::queue<Flight *> queue)
{
    if (queue.size() < data.size())
        if (left == nullptr)
            left = new TreeNode <std::queue<Flight *>> (queue);
        else 
            left->insert(queue);
    else 
        if (right == nullptr)
            right = new TreeNode <std::queue<Flight *>> (queue);
        else 
            right->insert(queue);
}


template <typename T>
void TreeNode<T>::insert(T value)
{
    if (value < data) 
    {
        if (left == nullptr)
            left = new TreeNode<T>(value);
        else 
            left->insert(value);
    }
    else 
    {
        if (right == nullptr)
            right = new TreeNode<T>(value);
        else 
            right->insert(value);
    }
}


template <>
void TreeNode< std::queue<Flight *> >::print()
{
    std::cout << "=== Node: \n";
    while(!data.empty())
    {
        data.front()->print();
        data.pop();
    }
    std::cout << "=== End of node: \n\n";
}


template <typename T>
void TreeNode<T>::print()
{
    std::cout << data << "\n";
}



/***************************************************************************/



template <typename T>
class Tree {

private: 
    TreeNode<T> * root;
    void traverse(TreeNode<T> * node);
    TreeNode<T> * deleteNode(TreeNode<T> * node, int key);
    TreeNode<T> * minValueNode(TreeNode<T> * node);
    int sum(TreeNode<T> * node);

public: 
    Tree() {};
    ~Tree() {};
    void insert(T data);
    void print();
    void deleteNode(int key);
    TreeNode<T> * min();
    int sum();

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
        node->print();
        traverse(node->right);
    }

}


template <typename T>
void Tree<T>::deleteNode(int key)
{
    root = deleteNode(root, key);
}


template <typename T>
TreeNode<T> * Tree<T>::deleteNode(TreeNode<T> * node, int data)
{ 
    if (node == nullptr) return node; 

    if (data < node->getNumValue()) 
        node->left = deleteNode(node->left, data); 

    else if (data > node->getNumValue()) 
        node->right = deleteNode(node->right, data); 

    else
    { 
        if (node->left == nullptr) 
        { 
            TreeNode<T> * temp = node->right; 
            delete node;
            return temp; 
        } 
        else if (node->right == nullptr) 
        {
            TreeNode<T> * temp = node->left; 
            delete node;
            return temp; 
        } 
  
        TreeNode<T> * temp = minValueNode(node->right); 
  
        node->setRealValue(temp->getRealValue()); 
  
        node->right = deleteNode(node->right, temp->getNumValue()); 
    } 
    return node;
} 


template <typename T>
TreeNode<T> * Tree<T>::minValueNode(TreeNode<T> * node) 
{ 
    TreeNode<T> * current = node; 
  
    while (current && current->left != nullptr) 
        current = current->left; 
  
    return current; 
} 


template<typename T>
TreeNode<T> * Tree<T>::min()
{
    auto temp = root;
    while (temp->left)
        temp = temp->left;

    return temp;
}


template<typename T>
int Tree<T>::sum()
{
    return sum(root);
}


template<typename T>
int Tree<T>::sum(TreeNode<T> * node)
{
    if (node == nullptr) 
        return 0;

    return sum(node->left) + node->getNumValue() + sum(node->right);
}




} // namespace oop

#endif // AIRCRAFT_CPP