/*
    "Queue.hpp"
    
    Created by:
    Serrano Diego Andrea - A01028728
    Garcia Puebla Diego Fernando - A01028597 

    Fecha: 14/11/2021
*/

#pragma once
#include <iostream>

class Queue
{
    private:

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
       Node *head; // head list
       Node *tail; // tail list
       size_t size; // list size

    public:
        ~Queue()
        {
            while (head->next != NULL)
            {
                head = head->next;
                delete head->before;
            }

            size = 0;
            delete head;
            
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

