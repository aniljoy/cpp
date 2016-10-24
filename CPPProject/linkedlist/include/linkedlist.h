#include <iostream>
#include <vector>
#include <interfacelist.h>
#include <typeinfo> 

using namespace std;

template <class T>
class Node
{
    public:
        T data;
        Node<T> *next;

        Node(T a)
        {
            data = a;
        }
};

template <class T>
class LinkedList : public InterfaceList<T>
{
    int m_n;
    Node<T> *start;
    Node<T> *list;

    public:
        LinkedList();
        LinkedList(const LinkedList& list);
        virtual ~LinkedList();
        virtual void add(T);
        virtual void remove(T);
        virtual void listall();
};

template <class T>
LinkedList<T>::LinkedList()
:   start(NULL),
    list(NULL)
{
}


template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *temp = NULL;

    cout << "<<<<<<<<<< ~LinkedList() >>>>>>>>>>>>" << endl;

    for(Node<T> *ptr = start; ptr != NULL ; ptr = temp )
    {
        temp = ptr->next;

        cout <<  typeid(this).name() << ": Delete=" <<  ptr << endl;
        delete(ptr);
    }
    
    start = NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& list)
{
    cout << "LinkedList Copy Constructor" << endl;
}

template <class T>
void LinkedList<T>::add(T a)
{
    cout << "Add.." << a << endl;

    if(start==NULL)
    {
        start = new Node<int>(a);
        start->next = NULL;
        list = start;
    }
    else
    {
        list->next = new Node<int>(a);
        list->next->next = NULL;
        list = list->next;
    }
}

template <class T>
void LinkedList<T>::remove(T a)
{
    cout << "Remove.." << endl;
}


template <class T>
void LinkedList<T>::listall()
{
    cout << "<<<<<<<<< listall >>>>>>>>>>>" << endl;

    int i = 1;

    for(Node<T> *ptr = start; ptr != NULL; ptr = ptr->next, i++)
    {
        cout << i << ". Node " << ptr << "  data=" << ptr->data << " next=" << ptr->next << endl;
    }

    cout << "<<<<<<<<< end listall >>>>>>>>>>>" << endl;
}

