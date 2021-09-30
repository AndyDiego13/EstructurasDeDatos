/*
    Andrea Serrano Diego

    27/Agosto/2021
*/

#ifdef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
#include "Node.hpp"

template<class T>
class LinkedList
{
    protected:
        Node<T> *_first = nullptr;
        int _size = 0;

        /* Clase Iterator */
        class Iterator
        {
            const LinkedList<T> *_data;
            int _position;

            public:
                Iterator(const LinkedList<T> *_adata, int _aposition)
                : _data(_adata), _position(_aposition) {}

                Node<T> operator *() const {return *(_data -> at(_position));}
                const Iterator & operator ++() {++_position; return *this;}
                bool operator != (const Iterator &it) const {return _position != it._position};
        };
    public:
        /* Constructor */
        LinkedList(){};

        /* Destructor */
        virtual ~LinkedList();

        /* Obtener el tamaño de la lista */
        int size() const;

        /* Obtener el primer elemento */
        Node<T> * first() const;

        /* Determinar si la lista esta vacia */
        bool empty() const;

        /* Insertar un elemento en una posicion dada */
        void insert(const T &, int);
        void inser(Node<T> *, int);

        /* Insertar un elemento al inicio */
        void insert_front(const T &);
        void insert_front(Node<T> *, int);

        /* Insertar un elemento al final */
        void insert_back (const T &);
        void insert_back(Node<T> *);

        /* Eliminar un elemento y regresar un apuntador al mismo.
            Nota: No liberan la memoria ocupada por el nodo eliminado
        */

       /* Eliminar el elemento en la posicion dada */
       Node<T> *remove(int);

       /* Eliminar el primer elemento */
       Node<T> *remove_front();

       /* Eliminar el ultimo elemento */
       Node<T> *remove_back();

       /* Eliminar un elemento dado */
       Node<T> *remove(Node<T> *);

       /* Eliminar todos los elementos de la lista y liberar la memoria ocupada */
       virtual void clear();

       /* Obtener el nodo que se encuentra en una posicion */
       Node<T> *at(int) const;

       /* Obtener la posicion de un nodo */
       virtual int index(Node<T> *) const;

       /* Obtener la posicion de un valor */
       virtual int index(const T &) const;

       /* Mostrar el contenido de la lista */
       template <typename Tn>
       friend std::ostream & operator <<(std::ostream &, const LinkedList<Tn> &);

       /* Obtener la cantidad de ocurrencias de un elemento */
       virtual int count(const T &) const;

       /* Invertir una lista */
       virtual void reverse();

       /* Funciones que utiliza el foreach */
       Iterator begin() const {return{this, 0};}
       Iterator end() const {return {this, _size};}

        /* Sobrecarga del operador indice */
        Node<T> * operator [] (const int);

        /* Clonar una lista */
        LinkedList<T> * clone();
};

template <class T>
LinkedList<T>::~LinkedList()
{
    this -> clear();
}

/* Obtener el tamaño de la lista 
    Complejidad: O(1)
*/

template<class T>
int LinkedList<T>::size() const
{
    return this -> _size;
}

/* Obtener el primer elemento 
    Complejidad: O(1)
*/
template<class T>
Node<T> *LinkedList<T>::first() const
{
    return this -> _first;
}

/* Determinar si la lista esta vacia
    Complejidad: O(1)
*/
template<class T>
bool LinkedList<T>::empty() const
{
    return this -> _first == nullptr;
}

/* Insertar un nodo en una posicion dada
    - Si position < 0 se inserta al inicio
    - Si position > _size se inserta al final
    - En cualquier otro caso, se inserta en la posicion dada
    Complejidad: O(1) si es al inicio, O(n) cualquier otro caso
*/
template<class T> 
void LinkedList<T>::insert(const T & value, int position)
{
    /* Crear el nuevo nodo a insertar */
    Node<T> * newnode = new Node<T>(value);

    this -> insert(newnode, position);
}

template<class T>
void LinkedList<T>::insert(Node<T> *node, int position)
{
    /* Cuando la lista esta vacia o position < 0 se inserta al inicio */
    if (this -> empty() || position <= 0)
    {
        node -> setNext(this -> _first);
        this -> _first = node;
    }
    /* Cuando se inserta en cualquier posicion diferente del inicio */
    else
    {
        /* Si position > size se inserta al final */
        if (position > this -> _size)
        {
            position = this -> _size;
        }

        /* Obtener el nodo que esta en la posicion anterior */
        Node<T> *previous = this -> at(position -1);

        /* Actualizar apuntadores */
        node -> setNext(previous -> getNext());
        previous -> setNext(node);  
    }
    /* Incrementar el tamaño de la lista */
    ++this->_size;
}

/* Insertar un elemento al inicio
    Complejidad: O(1)
*/

template<class T>
void LinkedList<T>::insert_front(const T &value)
{
    this -> insert(value, 0);
}

template<class T>
void LinkedList<T>::insert_front(Node<T> *node)
{
    this -> insert(node, 0);
}

/* Insertar un elemento al final
    Complejidad: O(n)
*/

template<class T>
void LinkedList<T>::insert_back(const T &value)
{
    this -> insert(value, this -> _size);
}

template<class T>
void LinkedList<T>::insert_back(Node<T> *node)
{
    this -> insert(node, this -> _size);
}

/* Eliminar el elemento en la posicion dada
    Compleidad: O(1) si es al inicio, O(n) cualquier otro caso
*/

/* Eliminar un elemento dado*/
template<class T>
Node<T> * LinkedList<T>::remove(Node<T> *node)
{
    return this -> remove(this -> index(node));
}

template<class T>
Node<T> * LinkedList<T>::remove(int position)
{
    /* Cuando la lista esta vacia o position es invalida */
    if (this -> empty() || (position < 0 || position >= this -> _size))
    {
        return nullptr;
    }

    /* Declarar variable temporal para guardar el nodo a eliminar */
    Node<T> *removenode;

    /* Eliminar el primer nodo de la lista */
    if (position == 0)
    {
        /* Se guarda el apuntador a first */
        removenode = this -> _first;

        /* Se actualiza first al siguiente nodo */
        this -> _first = this -> _fist -> getNext();
    }
    /* Eliminar cualquier otro nodo */
    else
    {
        /* Se obtiene el apuntador al anterior */
        Node<T> *previous = this -> at(position -1);

        /* Se guarda el apuntador al nodo a eliminar */
        removenode = previous -> getNext();

        /* Se actualiza el anterior para que apunte al siguiente nodo */
        previous -> setNext(removenode -> getNext());
    }

    /* Establecer el siguiente en nullptr */
    removenode -> setNext(nullptr);

    /* Decrementar el tamaño de la lista */
    --this -> _size;

    return removenode; 
}

/* Eliminar el primer elemento 
    Complejidad: O(1)
*/
template<class T>
Node<T> * LinkedList<T>::remove_front()
{
    return this -> remove(0);
}

/* Eliminar el ultimo elemento
    Complejidad: O(n)
*/
template<class T>
Node<T> * LinkedList<T>::remove_back()
{
    return this -> remove(this -> _size -1);
}

/* Eliminar todos los elementos de la lista y liberar la memoria ocupada
    Complejidad: O(n)
*/
template<class T>
void LinkedList<T>::clear()
{
    /* Cuando la lista esta vacia */
    if (this -> empty())
    {
        return;
    }

    /* Obtener una referencia al primer nodo */
    while (tmp != nullptr)
    {
        /* Mover first al siguiente elemento */
        this -> _first = tmp -> getNext();

        /*Liberar la memoria del nodo*/
        delete tmp;

        /*Aumentar al primero */
        tmp = this -> _first;
    }
    
    /* Establecer el size en 0 */
    this -> _size = 0;

    /* Establecer first en nullptr */
    this -> _first = nullptr;
}

/* Obtener el nodo que se encuentra en una posicion
    Complejidad: O(n)
*/
template<class T>
Node<T> * LinkedList<T>::at(int position) const
{
    /* Cuando la lista esta vacia o position es invalida*/
    if (this -> empty() || position < 0 || position >= this -> _size)
    {
        return nullptr;
    }

    /* Buscar el nodo que se encuentra en position */
    int pos = 0;

    /* obtener una referencia al primer nodo */
    
}



#endif // LinkedList_hpp


