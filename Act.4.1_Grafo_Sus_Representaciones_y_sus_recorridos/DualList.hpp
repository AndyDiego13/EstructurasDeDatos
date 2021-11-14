#pragma once
#include <iostream>

class DualList
{
    private:

        class Node
        {
            public:

                Node *next;
                Node *before;
                int contenido;

                ~Node(){}

                Node(int contenido = 0, Node *before = NULL, Node *next = NULL)
                {
                    this->contenido = contenido;
                    this->before = before;
                    this->next = next;
                }
        };

        Node *head;
        Node *tail;
        size_t size;

    public:

        ~DualList()
        {
            while (head->next != NULL)
            {
                head = head->next;
                delete head->before;
            }
            size = 0;
            delete head;
        }

        DualList(Node *head = NULL, Node *tail = NULL)
        {
            this->head = head;
            this->tail = tail;
            size = 0;
        }

        size_t getSize();
        int at(size_t);
        bool isEmpty();

        void pushBackI(int);
        void pushFront(int);
        void pushBack(DualList);

        void popBack();
        void popFront();

        void remove(size_t);
        void insert(int, size_t);
        void set(size_t, int);
        void print();
        void clear();
};

size_t DualList::getSize()
{
    return size;
}

int DualList::at(size_t i)
{
    if (i >= size)
    {
        throw std::out_of_range("Index es mayor que el tamaño de la lista");
    }
    else if (i == size-1)
    {
        return tail->contenido;
    }
    else
    {
        Node *cur = head;

        while (i)
        {
            cur = cur->next;
            i--;
        }

        return cur->contenido;
    }
}

bool DualList::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }

    return false;   
}

void DualList::pushBackI(int add)
{
    if (size == 0)
    {
        head = new Node(add);
        tail = head;
    }
    else
    {
        Node *curr = new Node(add);
        curr->before = tail;
        tail->next = curr;
        tail = curr;
    }

    size++;  
}

void DualList::pushFront(int add)
{
    if (size == 0)
    {
        head = new Node(add);
        tail = head;
    }
    else
    {
        Node *curr = new Node(add);
        curr->next = head;
        head->before = curr;
        head = curr;
    }
    
    size++;
}

void DualList::pushBack(DualList addToEnd)
{
    Node *headAddToEnd = addToEnd.head;

    while (headAddToEnd != NULL)
    {
        this->pushBack(headAddToEnd->contenido);
        headAddToEnd = headAddToEnd->next;
    }
}