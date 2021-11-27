/*
    "appGrafos.cpp"
    
    Created by:
    Serrano Diego Andrea - A01028728
    Garcia Puebla Diego Fernando - A01028597 

    Fecha: 26/11/2021
*/

#ifndef Node_hpp
#define Node_hpp

#include <iostream>

template <class T>
class Node {
private:
    T info;
    Node<T> * next = nullptr;
    Node<T> *head = nullptr;
    
public:
    /* Constructores */
    Node() { };
    Node(const T & _info) : info(_info) {}
    Node(const Node<T> & );
    
    /* Destructor */
    virtual ~Node();
    
    /* Getter y Setter */
    T getInfo() const { return info; }
    void setInfo(T & value) { info = value; }
    
    Node<T> * getNext() const { return next; }
    void setNext(Node<T> * value) { next = value; }
    
    /* Sobrecarga operador == */
    bool operator ==(Node<T> &);

    void push(Node **headRef, int newInfo)
    {
        Node *newNode = (Node*)malloc(sizeof(Node));

        newNode->info = newInfo;
        newNode->next = (*headRef);
        (*headRef) = newNode;
    }

    Node *sortedIntersect(Node *a, Node *b)
    {
        Node dummy;
        Node *tail = &dummy;
        dummy.next = NULL;

        while (a != NULL && b != NULL)
        {
            if (a->info == b->info)
            {
                push((&tail->next), a->info);
                tail = tail->next;
                a = a->next;
                b = b->next;
            }
            else if (a->info < b->info)
            {
                a = a->next;
            }
            else
            {
                b = b->next;
            }   
        }
        return (dummy.next);
    }


    void print(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            std::cout << temp->info << " " << std::endl;
            temp = temp->next;
        }
    }

    

   

    void printList(Node *node)
    {
        while (node != NULL)
        {
            std::cout << node->info << " " <<std::endl;
            node = node->next;
        }
    }
    
    /* Sobrecarga operador << */
    template <typename Tn>
    friend std::ostream & operator << (std::ostream & os, const Node<Tn> & node);
};

template <class T>
Node<T>::Node(const Node<T> & other)
{
    info = other.info;
    next = other.next;
}

template <class T>
Node<T>::~Node()
{
    info.~T();
    next = nullptr;
}

template <class T>
bool Node<T>::operator ==(Node<T> & other)
{
    return (info == other.info) && (next == other.next);
}

template <class T>
std::ostream & operator << (std::ostream & os, const Node<T> & node)
{
    os << node.info;
    
    return os;
}

#endif /* Node_hpp */