#ifndef VectorArray_H                       
#define VectorArray_H

#include "VectorADT.h"
using namespace std;

class VectorArray: public VectorADT{
private:
    int length;
    int *vector;
    int rank;
public:
    VectorArray(int);
    ~VectorArray();
    int at(int);
    int size();
    void insertAt(int, int);
    void insert(int);
    bool empty();
    bool find(int);
};

#endif