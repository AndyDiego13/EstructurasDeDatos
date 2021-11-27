/*
    "appGrafos.cpp"
    
    Created by:
    Serrano Diego Andrea - A01028728
    Garcia Puebla Diego Fernando - A01028597 

    Fecha: 26/11/2021
*/

#include <iostream>
#include "NodeLL.hpp"
#include "LinkedList.hpp"

class NodeP
{
    public:
    int info;
    NodeP *next;

};

void moveNode(NodeP** destRef, NodeP** sourceRef)
{
        
    NodeP* newNode = *sourceRef;
    assert(newNode != NULL);
 
        
    *sourceRef = newNode->next;
 
        
    newNode->next = *destRef;
 
        
    *destRef = newNode;
}

NodeP *sortedMerge(NodeP *a, NodeP *b)
{
    NodeP dummy;
    NodeP *tail = &dummy;

    dummy.next = NULL;

    while (1)
    {
        if(a == NULL)
        {
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->info <= b->info)
        {
            moveNode(&(tail->next), &a);
        }
        else
        {
            moveNode(&(tail->next), &b);
        }
            
        tail = tail->next;
    }
    return (dummy.next);
}

void insert(NodeP **headRef, int newInfo)
{
    NodeP *newNode = new NodeP();
    newNode->info = newInfo;
    newNode->next = (*headRef);
    (*headRef) =  newNode;
}

void printLista(NodeP *node)
{
    while (node != NULL)
    {
        std::cout << node->info << " " <<std::endl;
        node = node->next;
    } 
}

void getDifference(NodeP c, NodeP d)
{
    for ( Node *it = c.head; it != NULL; it->next)
    {
        for ( Node *it2 = d.head; it2 != NULL; it2->next)
        {
            if (it2->info != it->info && c.find(it2) != 1 && d.find(it) != 1)
            {
                it->info;
                it2->info;
            }
            else
            {
                continue;
            }
        }
    }
}

void display()
{
    Node *iterator = head;
    while (iterator != NULL)
    {
        std::cout << iterator->info << " ->" << std::endl;
        iterator = iterator->next;
    }
    std::cout << "end" << std::endl;
}

int main(int argc, char const *argv[])
{
    Node<int> node;
    
    std::cout << "=========== 4. INTERSECTION  ==============" << std::endl;
    
    Node<int> *a = NULL;
    Node<int> *b = NULL;
    Node<int> *intersect = NULL;
    

    node.push(&a, 6);
    node.push(&a, 5);
    node.push(&a, 4);
    node.push(&a, 3);
    node.push(&a, 2);
    node.push(&a, 1);

    node.push(&b, 8);
    node.push(&b, 6);
    node.push(&b, 4);
    node.push(&b, 2);

    intersect = node.sortedIntersect(a,b);

    node.printList(intersect);
    
    std::cout << "=========== 3. UNION  ==============" << std::endl;

    NodeP *res = NULL;
    NodeP *c = NULL;
    NodeP *d = NULL;

    insert(&c, 15);
    insert(&c, 10);
    insert(&c, 5);

    insert(&d, 20);
    insert(&d, 3);
    insert(&d, 2);

    res = sortedMerge(c, d);
    printLista(res);

    std::cout << "=========== 5. EXCEPT  ==============" << std::endl;

    dif = getDifference(c,d);
    display(dif);



    return 0;
}
