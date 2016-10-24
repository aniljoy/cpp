#include <iostream>
#include <vector>
#include <interfacesorting.h>
#include <interfacelist.h>

using namespace std;


/**
 * @class DoublyNode
 * @author vamo;
 * @date 31/08/2016
 * @file doublylinkedlist.h
 * @brief Represents a DoublyNode
 */
template <class T>
class DoublyNode
{
public:
        T data;
        DoublyNode<T> *prev;
        DoublyNode<T> *next;
        DoublyNode(T a);
};

template <class T>
DoublyNode<T>::DoublyNode(T a)
{
    this->data=a;
}


/**
 * @class DoublyLinkedList
 * @author vanil
 * @date 31/08/2016
 * @file doublylinkedlist.h
 * @brief Represents a DoublyLinkedList and it uses the interface InterfaceList.
 */
template <class T>
class DoublyLinkedList : public InterfaceList<T>, public InterfaceSort
{
        DoublyNode<T> *start;
        DoublyNode<T> *list;
public:
        DoublyLinkedList();
        virtual ~DoublyLinkedList();
        virtual int sort();
        virtual void add(const T);
        virtual void remove(const T);
        virtual void listall();
};


/**
 * @brief Constructor
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
    :start(NULL),
    list(NULL)
{

}


/**
 * @brief Destructor
 */
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    int i;
    DoublyNode<T> *temp = NULL;
    DoublyNode<T> *node = start;
    
    for(i = 0; node != NULL ; node=temp, i++)
    {
        temp = node->next;
        cout << typeid(this).name() << ": Delete" << node << endl;
        delete node;
    }     
    
    start = NULL;
}

template <class T>
int DoublyLinkedList<T>::sort()
{
}


template <class T>
void DoublyLinkedList<T>::add(const T a)
{
    if(start == NULL)
    {
        start       = new DoublyNode<T>(a);
        start->data = a;
        start->next = NULL;
        start->prev = NULL;
        list        = start;
    }
    else
    {
        list->next  = new DoublyNode<T>(a);
        list->next->data = a;
        list->next->next = NULL;
        list->next->prev = list;
        list = list->next;
    }
            
}
    
template <class T>
void DoublyLinkedList<T>::remove(const T)
{
    
}

template <class T>
void DoublyLinkedList<T>::listall()
{
    int i = 0;
    
    for(DoublyNode<T> *node = start; node!=NULL; node=node->next)
    {
        cout << "node=" <<  node << "data=" << node->data << "prev=" << node->prev << "next=" << node->prev << endl;
    }
}


