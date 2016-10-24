#include <iostream.h>
using namespace std;

class BinarySearchTree
{
    public:
        BinarySearchTree();
        virtual void insert() = 0;
        virtual void delete() = 0;
        virtual void remove() = 0;
        virtual void traverse() = 0;
        virtual ~BinarySearchTree();
};