#pragma once
#include <iostream>

class Stack
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

        ~Stack()
        {
            while (head->next != NULL)
            {
                head = head->next;
                delete head->before;
            }

            size = 0;
            delete head;
        }

        Stack(Node *head = NULL, Node *tail = NULL)
        {
            this->head = head;
            this->tail = tail;
            size = 0;
        }

        size_t getSize();
        int popOut();
        bool isEmpty();

        void push(int);
        void clear();
};

size_t Stack::getSize()
{
    return size;
}

int Stack::popOut()
{
    int cont;

    if (size == 1)
    {
        size = 0;
        cont = tail->contenido;
        head = NULL;
        tail = NULL;
    }
    else if (size > 1)
    {
        cont = tail->contenido;
        tail = tail->before;
        delete tail->next;

        tail->next = NULL;
        size--;
    }

    return cont; 
}

bool Stack::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }

    return false; 
}

void Stack::push(int add)
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

void Stack::clear()
{
    if (head != NULL)
    {
        while (head->next != NULL)
        {
            head = head->next;
            delete head->before;
        }

        size = 0;
        head = NULL;
        tail = NULL;
    } 
}