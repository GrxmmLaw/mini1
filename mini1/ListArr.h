#ifndef LISTARR_H
#define LISTARR_H

class ListArr{
	private:
		struct Node{
			int* arr;//arreglo interno del nodo
			int b;//tamaño del arreglo del nodo
			int num_elements;//cantidad elementos en el nodo
			Node* next;//puntero al siguiente nodo

			Node(int b){
				this->b = b;
				num_elements = 0;
				arr = new int[b];
				next = nullptr;
			}

			~Node(){
				delete [] arr;
			}
		};
		struct NodeSummary{
		    int total_capacity;//capacidad total del hijo izquierdo y derecho del NodeSummary
		    int total_size;//capacidad utilizada por el hijo izquierdo y derecho del NodeSummary
		    NodeSummary* left_child; //puntero a hijo izquierdo
		    NodeSummary* right_child; //puntero a hijo derecho
			Node* left; //puntero izquiero a nodo tipo Node
			Node* right; //puntero derecho a nodo tipo Node
			
		   NodeSummary(int total_capacity, int total_size){
		    	this->total_capacity = total_capacity;
		    	this->total_size = total_size;
		    	this->left_child = nullptr;
		    	this->right_child = nullptr;
				this->left = nullptr;
				this->right = nullptr;
		    }

		    ~NodeSummary(){
		    	delete left_child;
		    	delete right_child;
				delete left;
				delete right;
				total_capacity = 0;
				total_size = 0;
		    }
		};
		int b; //variable que guarda la capacidad de un Node
		int num_nodes; //variable que guarda la cantidad de NodeSummary
		Node* head; //nodo que apunta al primer Nodo de la lista ligada que contiene ListArr
		NodeSummary* summary_head; //nodo que apunta a la raíz del árbol resumen de ListArr
	public:
		ListArr(int b);
		~ListArr();
		int size();
		void insert_left(int v);
		void insert_right(int v);
		void insert(int v, int i);
		void print();
		bool find(int v);
		void update_summary();
};

#endif