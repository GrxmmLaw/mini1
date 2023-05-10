#ifndef VectorADT_H                       
#define VectorADT_H

class VectorADT{
public:
    virtual int at(int) = 0;
    virtual int size() = 0;
    virtual void insertAt(int,int) = 0;
    virtual void insert(int) = 0;
    virtual bool empty() = 0;
};

#endif