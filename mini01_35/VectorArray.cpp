#include "VectorArray.h"
#include <iostream>

VectorArray::VectorArray(int data){
    this->vector = new int[data];
    this->length = data;
    this->rank = 0;
}

VectorArray::~VectorArray(){
    delete(vector);
    vector = nullptr;
    this->length = 0;
    this->rank = 0;
}

int VectorArray::at(int data){
    try{
        if(data < 0 || data >= rank)                    
        throw "Indice fuera de posicion!";             
        return vector[data];                            
    }catch(const char* message){                       
        std::cerr << message << std::endl;              
        exit(EXIT_FAILURE);                             
    }
}

int VectorArray::size(){
    return rank;
}

void VectorArray::insertAt(int val,  int pos){
    try{
        rank++;                                         
        if(pos < 0 || pos >= rank)                      
        throw "Indice fuera de posicion!";              
        if(rank == length){                             
            length = 2*rank;                            
            int* aux = new int[length];                
            for (int i = 0; i < rank; i++){             
                aux[i] = vector[i];                     
            }
            int* oldV = vector;                         
            vector = aux;                              
            delete(oldV);                              
        }
        int k = 0;                                     
        for (int i = pos; i < rank; i++){               
            vector[rank-1-k] = vector[rank-2-k];        
            k++;                                        
        }
        vector[pos] = val;                              
        
    }catch(const char* message){                        
        std::cerr << message << std::endl;              
        exit(EXIT_FAILURE);                             
    }
}

void VectorArray::insert(int data){
    if(rank == length){
        length = 2*rank;
        int* aux = new int[length];
        aux[0] = data;
        for (int i = 0; i < rank; i++){
            aux[i+1] = vector[i];
        }
        rank++;
        int* oldV = vector;
        vector = aux;
        delete(oldV);
    }else{
        rank++;
        for (int i = 0; i < rank; i++){
            vector[rank-1-i] = vector[rank-2-i];
        }
        vector[0] = data;
    }
}

bool VectorArray::find(int v){
    for (int i = 0; i < rank; i++){
        if(vector[i] == v){
            return true;
        }
    }
    return false;    
}

bool VectorArray::empty(){
    if(rank == 0) return true;
    return false;
}