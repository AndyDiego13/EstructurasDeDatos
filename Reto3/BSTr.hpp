/*
    "BTS.hpp"
    
    Created by:
    Serrano Diego Andrea - A01028728
    Garcia Puebla Diego Fernando - A01028597 

    Fecha: 05/11/2021
*/

#ifndef BSTr_hpp
#define BSTr_hpp

#include "NodeBST.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

class BSTr
{
    private:
        NodeBST *root;
        int size = 0;
    public:
        virtual ~BSTr(){};
        BSTr();

        int getSize();
        bool insertNode(std::string name, int num);
        void printInOrder();
        void printInOrder(int n);
        void printLast();
        void kthLarge(NodeBST *root, int n);
        void kthLargeRec(NodeBST *root, int n, int &visitNode);
        void printKth(int n);
        void keepKth(int n, std::map<std::string, int> &mapp);
        void keepKthLarge(NodeBST *root, int n, std::map<std::string, int> &mapp);
        void keepKthLargeRec(NodeBST *root, int n, int &visitNode, std::map<std::string , int> &mapp);
        
};

BSTr::BSTr()
{
    root = nullptr;
    size++;
}

int BSTr::getSize()
{
    return size;
}

bool BSTr::insertNode(std::string name, int num)
{
    NodeBST *post = root;
    NodeBST *pre = nullptr;

    while (post != nullptr)
    {
        if (post ->getValName() == name)
        {
            return false;
        }
        pre = post;
        post = post->getValNum() > num ? post->getLeft() : post->getRight();
    }
    
    NodeBST *newNode = new NodeBST(name, num);

    if (pre == nullptr)
    {
        root = newNode;
    }
    else
    {
        if (pre ->getValNum() < num)
        {
            pre ->setRight(newNode);
        }
        else
        {
            pre ->setLeft(newNode);
        }  
    }
    size++;
    return true;
}

void BSTr::printInOrder()
{
    root->showInOrder();
}

void BSTr::printInOrder(int n)
{
    root->showInOrder(n);
}

void BSTr::printLast()
{
    NodeBST *post = root;

    while (post->getRight() != nullptr)
    {
        post = post->getRight();
    }

    std::cout << post->getValName() << ":\t" << post->getValNum() << std::endl; 
}

void BSTr::kthLargeRec(NodeBST *root, int n, int &visitNode)
{
    if (root == NULL || visitNode >= n)
    {
        return;
    }
    kthLargeRec(root->getRight(), n, visitNode);
    visitNode++;

    if (visitNode == n)
    {
        std::cout << root->getValName() << ":\t" << root->getValNum() << std::endl;
        return;
    }
    
    kthLargeRec(root->getLeft(), n, visitNode);

}

void BSTr::kthLarge(NodeBST *root, int n)
{
    int visitNode = 0;
    kthLargeRec(root, n, visitNode);
}

void BSTr::printKth(int n)
{
    for (int i = 0; i <= n; i++)
    {
        kthLarge(root, i);
    }
}

void BSTr::keepKthLargeRec(NodeBST *root, int n, int &visitNode, std::map<std::string , int> &mapp)
{
    if (root == NULL || visitNode >= n)
    {
        return;
    }
    keepKthLargeRec(root->getRight(), n, visitNode, mapp);
    visitNode++;

    if (visitNode == n)
    {
        mapp[root->getValName()] += root->getValNum();
        return;
    }

    keepKthLargeRec(root->getLeft(), n, visitNode, mapp); 
}

void BSTr::keepKthLarge(NodeBST *root, int n, std::map<std::string, int> &mapp)
{
    int visitNode = 0;
    keepKthLargeRec(root, n, visitNode, mapp);
}

void BSTr::keepKth(int n, std::map<std::string, int> &mapp)
{
    for (int i = 0; i < n; i++)
    {
        keepKthLarge(root, i, mapp);
    }   
}

#endif // !BSTr_hpp