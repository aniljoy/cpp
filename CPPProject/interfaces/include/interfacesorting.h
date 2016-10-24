#include <iostream>

class InterfaceSort
{
    public:
        InterfaceSort(){};
        virtual int sort()=0;
        virtual ~InterfaceSort(){}
};