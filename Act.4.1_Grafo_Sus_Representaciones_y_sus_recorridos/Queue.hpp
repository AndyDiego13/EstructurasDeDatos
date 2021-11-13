#pragma once
#include <iostream>

class Queue
{
    private:
        Node *head; // head list
        Node *tail; // tail list
        size_t size; // list size

        class Node
        {
            public:
                int contenido;
                Node *next;
                Node *before;

                ~Node(){}

                Node(int contenido = 0, Node *before = NULL, Node *next = NULL)
                {
                    this->contenido = contenido;
                    this->before = before;
                    this->next = next;

                }
       };

    public:
        ~Queue()
        {
            while (head->next != NULL)
            {
                head = head->next;
                delete head->before;
            }

            size = 0;
            detele head;
            
        }

        Queue(Node *head = NULL, Node *tail = NULL)
        {
            this->head = head;
            this->tail = tail;
            size = 0;
        }

        size_t getSize();
        int popOut(); // borrar el primer elemento
        bool isEmpty();

        void push(int); // agregar item al final
        void clear();

};

size_t Queue::getSize()
{
    return size;
}

int Queue::popOut()
{
    int cont;
    if (size == 1)
    {
        cont = head->contenido;
        size = 0;
        head = NULL;
        tail = NULL;
    }
    else if (size > 1)
    {
        cont = head->contenido;
        head = head->next;
        delete head->before;
        head->before = NULL;
        size--;
    }
    else
    {
        throw out_of_range("Segmentation fault");
    }

    return cont;
}

bool Queue::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    return false; 
}

void Queue::push(int add)
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

void Queue::clear()
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

