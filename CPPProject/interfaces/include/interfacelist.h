#ifndef _INTERFACELIST_H_
#define _INTERFACELIST_H_

/**
 * @class InterfaceList
 * @author vanil
 * @date 31/08/2016
 * @file interfacelist.h
 * @brief List interface
 */
template <class T>
class InterfaceList
{
    public:
        virtual void add(const T)=0;
        virtual void remove(const T)=0;
        virtual void listall()=0;
        virtual ~InterfaceList(){};
};

#endif