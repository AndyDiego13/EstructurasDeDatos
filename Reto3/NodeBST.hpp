/* 

    "NodeBST.hpp"
*/

#ifndef NodeBST_hpp
#define NodeBST_hpp

#include <iostream>
#include <string>
#include <vector>
#include <queue>

class NodeBST
{
    public:
        std::pair<std::string, int> value;
        NodeBST *left;
        NodeBST *right;
        int deep;

        /* Destructores */
        virtual ~NodeBST();

        /* Constructores */
        NodeBST() {};

        NodeBST(std::string name, int num);
        NodeBST(std::pair<std::string, int> val);
        NodeBST(std::string name, int num, NodeBST *_left, NodeBST *_right);
        NodeBST(std::pair<std::string, int> val, NodeBST *_left, NodeBST *_right);

        std::pair<std::string, int> getVal();
        std::string getValName();
        int getValNum();

        NodeBST *getLeft()
        {
            return left;
        }

        NodeBST *getRight()
        {
            return right;
        }

        void setVal(std::pair<std::string, int> val);
        void setValName(std::string name);
        void setValNum(int num);

        void setLeft(NodeBST *node);
        void setRight(NodeBST *node);

        void showInOrder();
        void showInOrder(int n);
        void showInOrderRec(int n, int i);
};

NodeBST::NodeBST(std::string name, int num)
{
    value.first = name;
    value.second = num;
    left = nullptr;
    right = nullptr;
}

NodeBST::NodeBST(std::pair<std::string, int> val)
{
    value = val;
    left = nullptr;
    right = nullptr;
}

NodeBST::NodeBST(std::string name, int num, NodeBST *_left, NodeBST *_right)
{
    value.first = name;
    value.second = num;
    left = _left;
    right = _right;
}

NodeBST::NodeBST(std::pair<std::string, int> val, NodeBST *_left, NodeBST *_right)
{
    value = val;
    left = _left;
    right = _right;
}

std::pair<std::string, int> NodeBST::getVal()
{
    return value;
}

std::string NodeBST::getValName()
{
    return value.first;
}

int NodeBST::getValNum()
{
    return value.second;
}

void NodeBST::setVal(std::pair<std::string, int> val)
{
    value = val;
}

void NodeBST::setValName(std::string name)
{
    value.first = name;
}

void NodeBST::setValNum(int num)
{
    value.second = num;
}

void NodeBST::setLeft(NodeBST *node)
{
    left = node;
}

void NodeBST::setRight(NodeBST *node)
{
    right = node;
}

void NodeBST::showInOrder()
{
    if (right != nullptr)
    {
        right ->showInOrder();
    }

    std::cout << value.first << ":\t"<< value.second << std::endl;

    if (left != nullptr)
    {
        left ->showInOrder();
    }   
}

void NodeBST::showInOrder(int n)
{
    
}


#endif // !NodeBST_hpp
