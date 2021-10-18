/* 
    "BinaryTree.hpp"
    
    Created by:
    Serrano Diego Andrea - A01028728
    Garcia Puebla Diego Fernando - A01028597 

    Fecha: 18/10/2021
*/

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <iostream>
#include "TreeNode.hpp"

template <class T>
class BinaryTree {
protected:
    TreeNode<T> * root = nullptr;
    
    void clear(TreeNode<T> * );
    
public:
    BinaryTree() {}
    virtual ~BinaryTree();
    
    /* Insertar un nodo en el árbol */
    bool insert(T &, TreeNode<T> *);
    bool insert(TreeNode<T> *, TreeNode<T> *);
    
    bool empty() const;
    
    /* Eliminar un nodo del árbol */
    virtual TreeNode<T> * remove(T &);
    
    /* Eliminar todos los nodos del árbol */
    void clear();
    
    
    /* Recorridos de un árbol */
    void preOrden() const;
    void preOrden(TreeNode<T> *) const;

    void inOrden() const;
    void inOrden(TreeNode<T> *) const;
    
    void postOrden() const;
    void postOrden(TreeNode<T> *) const;
    
    int topN() const;
    int topN(TreeNode<T> *, int, int) const;

    void inorderNivel(TreeNode<T> *, int, int);
    void inorderNivel(int);

    void height();
    int height2(TreeNode<T> *);

    bool printAncestor(TreeNode<T> *, int);

    int whatLevelAmI(TreeNode<T> *, int, int);
    int getLevel(TreeNode<T> *, int);
    
};

template <class T>
BinaryTree<T>::~BinaryTree()
{
    this->clear();
}

template <class T>
bool BinaryTree<T>::empty() const
{
    return this->root == nullptr;
}

/* Insertar un nodo en el árbol */
template <class T>
bool BinaryTree<T>::insert(T & value, TreeNode<T> * parent)
{
    return this->insert( new TreeNode<T>(value), parent );
}

template <class T>
bool BinaryTree<T>::insert(TreeNode<T> * node, TreeNode<T> * parent)
{
    /* Declarar variable para saber si se insertó el nodo */
    bool inserted = false;
    
    /* Verificar si el árbol está vacío */
    if (this->root == nullptr) {
        /* Establecer el nodo como raíz */
        this->root = node;
    }
    else if (parent == nullptr)
    {
        /* Insertar un nuevo nodo raiz */
        node->setLeft(root);
        root = node;
    }
    else {
        if (parent->getLeft() == nullptr) {
            parent->setLeft(node);
            inserted = true;
        }
        else if (parent->getRight() == nullptr) {
            parent->setRight(node);
            inserted = true;
            }
        else {
            inserted = insert(node, parent->getLeft() );
            if (!inserted) {
                insert(node, parent->getRight() );
            }
        }
    }
    
    return inserted;
}

/* Eliminar un nodo del árbol */
template <class T>
TreeNode<T> * BinaryTree<T>::remove(T &)
{
    return nullptr;
}

/* Eliminar todos los nodos del árbol */
template <class T>
void BinaryTree<T>::clear()
{
    this->clear(this->root);
    this->root = nullptr;
}

template <class T>
void BinaryTree<T>::clear(TreeNode<T> * node)
{
    if (node != nullptr) {
        clear( node->getLeft() );
        clear( node->getRight() );
        delete node;
    }
}

/* Recorridos de un árbol */
template <class T>
void BinaryTree<T>::preOrden() const
{
    this->preOrden( this->root );
}

template <class T>
void BinaryTree<T>::preOrden(TreeNode<T> * node) const
{
    if (node != nullptr) {
        /* Procesar el nodo */
        std::cout << *node << " ";
        
        /* Desplazarse a la izquierda */
        preOrden( node->getLeft() );
        
        /* Desplazarse a la derecha */
        preOrden( node->getRight() );
    }
}

template <class T>
void BinaryTree<T>::inOrden() const
{
    this->inOrden( this->root );
}

//Complejidad Computacional: Lineal - O(n)
template <class T>
void BinaryTree<T>::inOrden(TreeNode<T> * node) const
{
    if (node != nullptr) {
        /* Desplazarse a la izquierda */
        inOrden( node->getLeft() );
        
        /* Procesar el nodo */
        std::cout << *node << " ";
        
        /* Desplazarse a la derecha */
        inOrden( node->getRight() );
    }
}

//Complejidad Computacional: Lineal - O(n)
template <class T>
void BinaryTree<T>::postOrden() const
{
    this->postOrden( this->root );
}

//Complejidad Computacional: Lineal - O(n)
template <class T>
void BinaryTree<T>::postOrden(TreeNode<T> * node) const
{
    if (node != nullptr) {
        /* Desplazarse a la izquierda */
        postOrden( node->getLeft() );
        
        /* Desplazarse a la derecha */
        postOrden( node->getRight() );
        
        /* Procesar el nodo */
        std::cout << *node << " ";
    }
}


//Complejidad Computacional: Lineal - O(n)
template <class T>
int BinaryTree<T>::topN() const
{
    return this->topN( this->root, 4, 0 );
}

//Complejidad Computacional: Lineal - O(n)
template <class T>
int BinaryTree<T>::topN(TreeNode<T> * node, int n, int cont) const
{
    if (node != nullptr && cont < n) {
        
        /* Desplazarse a la izquierda */
        cont = topN( node->getLeft(), n, cont );
         
        if (cont < n ) {
            std::cout << *node << " (" << ++cont << ") ";
        }
        else return cont;
        
        /* Desplazarse a la derecha */
        cont = topN( node->getRight(), n, cont );
    }
    
    return cont;
}

//Complejidad Computacional: Lineal - O(n)
template <class T>
void BinaryTree<T>::inorderNivel(TreeNode<T> *temp, int nivel, int nivelBuscado)
{
    if (temp != nullptr)
    {
        inorderNivel(temp ->left, nivel +1, nivelBuscado);
        if (nivelBuscado == nivel)
        {
            std::cout << temp -> info << " "<< std::endl;
        }
        inorderNivel(temp -> right, nivel +1, nivelBuscado);
        
    }
    
}

template <class T>
void BinaryTree<T>::inorderNivel(int buscador)
{
    inorderNivel(root, 1, buscador);
    std::cout << std::endl;
}

//Metodo para obtener la altura de nuestro árbol
//Complejidad Computacional: Lineal - O(n)
template<class T>
int BinaryTree<T>::height2(TreeNode<T> *temp)
{
    if (temp == nullptr)
    {
        return 0;
    }
    else
    {
        int left = height2(temp->getLeft());
        int right = height2(temp->getRight());
        
        if (left > right)
        {
            temp->deep = left +1;
        }

        temp->deep = right +1;
        return temp->deep;
    }
}

template<class T>
void BinaryTree<T>::height()
{
    height(root);
}

//Complejidad Computacional: Lineal - O(n)
template<class T>
bool BinaryTree<T>::printAncestor(TreeNode<T> *temp, int ancestor)
{
    if (temp == nullptr)
    {
        return false;
    }
    if (temp->info == ancestor)
    {
        return true;
    }

    bool searchL = printAncestor(temp->left, ancestor);
    bool searchR = false;
    if (!searchL)
    {
        searchR = printAncestor(temp->right, ancestor);
    }

    if (searchL || searchR)
    {
        std::cout << temp->info << " " << std::endl;
    }

    return searchL || searchR;
}

//Complejidad Computacional: Lineal - O(n)
template<class T>
int BinaryTree<T>::whatLevelAmI(TreeNode<T> *temp, int data, int level)
{
    if (temp == nullptr)
    {
        return 0;
    }

    if (temp->info == data)
    {
        return level;
    }

    int downlevel = whatLevelAmI(temp->left, data, level +1);

    if (downlevel != 0)
    {
        return downlevel;
    }

    downlevel = whatLevelAmI(temp->right, data, level +1);
    
    return downlevel; 
}

template<class T>
int BinaryTree<T>::getLevel(TreeNode<T> *temp, int data)
{
    return whatLevelAmI(temp, data, 1);
}

#endif /* BinaryTree_hpp */
