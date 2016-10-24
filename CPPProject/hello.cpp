

#include <stdio.h>
#include <linkedlist.h>
#include <doublylinkedlist.h>

int main()
{
    InterfaceList<int> *ilist;
    LinkedList<int> linkedList;
    

    ilist = new LinkedList<int>();

    ilist->add(20);
    ilist->add(30);
    ilist->add(40);
    ilist->add(50);
    ilist->add(60);
    ilist->listall();

    delete ilist;
    
    
    DoublyLinkedList<int> doublyLinkedList;
    
    ilist = new DoublyLinkedList<int>();
    
    ilist->add(20);
    ilist->add(30);
    ilist->add(40);
    ilist->add(50);
    ilist->add(60);
    ilist->listall();
    
    delete ilist;

    return(0);
}
