#ifndef VectorList_H                       
#define VectorList_H

#include "VectorADT.h"
using namespace std;

class VectorList: public VectorADT{
private:
    struct Node {
        int data;
        Node* next;
        Node(int data, Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };
    Node* Vector;
    int rank;
public:
    VectorList();
    ~VectorList();
    int at(int);
    int size();
    void insertAt(int, int);
    void insert(int);
    bool empty();
    bool find(int);
};

#endif