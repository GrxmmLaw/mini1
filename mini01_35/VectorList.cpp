#include "VectorList.h"
#include <iostream>

VectorList::VectorList(){
    this->Vector = nullptr;
    this->rank = 0;
}

VectorList::~VectorList(){
    Node* current = Vector;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    this->Vector = nullptr;
    this->rank = 0;
}

void VectorList::insertAt(int val, int pos){
    rank++;                                                  
    try{
        if(pos < 0 || pos >= rank)                            
        throw "Elemento fuera de posicion!";                 
        if(pos == 0){                                         
            this->insert(val);                                
            rank--;                                           
        }else{
            Node* aux = Vector;                               
            Node* newNode = new Node(val);                    
            int count = 0;                                    
            while(count != pos-1){                            
                aux = aux->next;                              
                count++;                                      
            }
            newNode->next = aux->next;                        
            aux->next = newNode;                              
        }      
    }catch(const char* message){                              
        std::cerr << message << std::endl;                   
        exit(EXIT_FAILURE);                                   
    }
}

int VectorList::size(){
    return rank;
}

int VectorList::at(int data){
    try{
        if(data < 0 || data >= rank)                
        throw "Elemento fuera de posicion!";        
        Node* aux = Vector;                         
        int count = 0;                              
        while(count != data){                       
            aux = aux->next;                        
            count++;                               
        }                                           
        return aux->data;                          
    }catch(const char* message){                   
        std::cerr << message << std::endl;          
        exit(EXIT_FAILURE);                        
    }
}

void VectorList::insert(int data){
    Node* current = Vector;
    Vector = new Node(data);
    Vector->next = current;
    rank++;
}

bool VectorList::empty(){
    if(rank == 0) return true;
    return false;
}

bool VectorList::find(int v){
    Node* current = Vector;
    while(current!= nullptr){
        if(current->data == v){
            return true;
        }
        current = current->next;
    }
    return false;
}