#include "ListArr.h"
#include <iostream>
#include <vector>
using namespace std;

/**
 * Este método es el constructor para la clase ListArr. Inicializa sus propiedades.
 *  
 * @param b El parámetro 'b' es un entero que representa el máximo número de elementos que se
 * pueden almacenar en cada nodo tipo Node de ListArr.
 */
ListArr::ListArr(int b){
	this->b = b;
	this->num_nodes = 1;
	this->head = new Node(b);
	this->summary_head = new NodeSummary(2*b, 0);
	this->summary_head->left = this->head;
}

/**
 * Este método elimina todos los Node y NodeSummary almacenados en un ListArr.
 */
ListArr::~ListArr(){
	Node* current = head;
    while(current != nullptr){
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    summary_head = nullptr;

    NodeSummary* current_summary = summary_head;
    while (current_summary != nullptr) {
        NodeSummary* next_summary = current_summary->right_child;
        delete current_summary;
        current_summary = next_summary;
    }

	NodeSummary* current_summary2 = summary_head;
    while (current_summary2 != nullptr) {
        NodeSummary* next_summary2 = current_summary2->left_child;
        delete current_summary2;
        current_summary2 = next_summary2;
    }
}

/**
 * El método size retorna el número total de elementos almacenados en un ListArr.
 * 
 * @return El método 'size()' retorna el número total de elementos almacenados en un 'ListArr'.
 * Este valor se obtiene desde la variable 'total_size' del objeto 'summary_head'.
 */
int ListArr::size(){ //Cantidad de elementos almacenados en LisArr
	return summary_head->total_size;
}

/**
 * Este método inserta un valor al principio de ListArr, es decir, en el índice 0.
 * 
 * @param v 'v' es el valor entero que se desea insertar en ListArr. El método 'insert_left' inserta 
 * este elemento al principio del ListArr.
 */
void ListArr::insert_left(int v){
	this->insert(v, 0);
}

/**
 * Este método inserta un valor en al final del ListArr. Inserta el valor en el índice size()-1.
 * 
 * @param v 'v' es el valor entero que se desea insertar en ListArr. El método 'insert_right' inserta 
 * este elemento al principio del ListArr.
 */
void ListArr::insert_right(int v){
	insert(v, size());
}

/**
 * Este método inserta un valor en un índice específico del ListArr, con manejo de errores para índices
 * fuera de rango.
 * 
 * @param v Valor ha ser insertado en el ListArr.
 * @param i 'i' representa el índice dentro de ListArr en que se debe insertar el valor 'v'.
 */
void ListArr::insert(int v, int i){
    try{
        if(i < 0 || i > summary_head->total_size) throw "Indice fuera de rango!";
		//Recorrido de Nodos NodeSummary, hasta llegar a un nodo tipo Node
		NodeSummary* aux = summary_head;
		while(aux->left == nullptr){
			if(i <= aux->left_child->total_size){
				aux = aux->left_child;
			}else{
				i = i - aux->left_child->total_size;
				aux = aux->right_child;
			}                                                                                                     
		}
		//En que nodo realizar la inserción
		Node* current;
		if(i <=  aux->left->num_elements){
			current = aux->left;
		}else{
			i = i - aux->left->num_elements;
			current = aux->right;
		}
		//Si el nodo no está lleno, se inserta en la posición correspondiente
		if(current->num_elements < current->b){
			for (int j = 0; j < current->num_elements-i ; j++){
				current->arr[current->num_elements-j] = current->arr[current->num_elements-j-1];
			}
			current->arr[i] = v;
			current->num_elements++;
		}else{
			if(i == current->num_elements){
				Node* newNode = new Node(b);
				newNode->arr[0] = v;
				newNode->num_elements++;
				num_nodes++; 
				newNode->next = current->next;
				current->next = newNode;
			}else{
				Node* newNode = new Node(b);
				newNode->arr[0] = current->arr[b-1];
				newNode->num_elements++;
				num_nodes++; 
				for (int j = 0; j < current->num_elements-i ; j++){
					current->arr[current->num_elements-j] = current->arr[current->num_elements-j-1];
				}
				current->arr[i] = v;
				newNode->next = current->next;
				current->next = newNode;
			}
		}

	//update_summary();
		
	}catch(const char* message){
        std::cerr << message << std::endl;
        exit(EXIT_FAILURE);
    }
}


/**
 * Este método imprime todos los valores almacenados en el ListArr.
 */
void ListArr::print(){
	Node *current = head;
	cout << "[";
	while(current != nullptr){
		for(int i=0; i<current->num_elements; i++){
			cout << current->arr[i];
			if(i == current->num_elements-1 && current->next == nullptr){
				cout << "]"<< endl;
			}else{
				cout << " ";
			}
		}
		current = current->next;
	}
}

/**
 * Este método busca un valor en la estructura de datos ListArr y retorna true si es encontrado o falso
 * si no es encontrado.
 * 
 * @param v El valor que es buscado en ListArr.
 * 
 * @return un valor booleano indicando si el entero v está o no presente en ListArrtArr.
 * Si v está presente, la funcion retorna true, si no, retorna false.
 */
bool ListArr::find(int v){
	if(size() == 0){
		return false;
	}
	Node *current = head;
	while(current != nullptr){
		for(int i=0; i<current->b; i++){
			if(current->arr[i] == v){
				return true;
			}
		}
		current = current->next;
	}
	return false;
}

/**
 * Este método actualiza el resumen de ListArr creando una estructura tipo árbol con nodos NodeSummary.
 */
void ListArr::update_summary(){
	int k310;
	if(num_nodes%2 == 0){
		k310 = num_nodes/2;
	}else{
		k310 = num_nodes/2+1;
	}
	vector<NodeSummary*> base;
	for (int i = 0; i < k310; i++){
		NodeSummary* n = new NodeSummary(2*b,0);
		base.insert(base.begin()+i,n);
	}
	Node* first = head;
	for (int i = 0; i < k310; i++){
		base.at(i)->left = first;
		base.at(i)->right = first->next;
		if(base.at(i)->right == nullptr){
			base.at(i)->total_size = base.at(i)->left->num_elements;
		}else{
			base.at(i)->total_size = base.at(i)->left->num_elements + base.at(i)->right->num_elements;
		}
		if(first->next != nullptr){
			first = first->next->next;
		}
	}
	while(k310 != 1){
		if(k310%2 == 0){
			k310 = k310/2;
		}else{
			k310 = k310/2+1;
		}
		vector<NodeSummary*> next;
		for (int j = 0; j < k310; j++){
			NodeSummary* n = new NodeSummary(0,0);
			next.insert(next.begin(), n);
		}
		for (int i = 0; i < k310; i++){
			next.at(i)->left_child = base.at(2*i);
			if(2*i+1 >= base.size()){
				next.at(i)->total_size = next.at(i)->left_child->total_size;
				next.at(i)->total_capacity = next.at(i)->left_child->total_capacity*2;
			}else{
				next.at(i)->right_child = base.at(2*i+1);
				next.at(i)->total_size = next.at(i)->left_child->total_size + next.at(i)->right_child->total_size;
				next.at(i)->total_capacity = next.at(i)->left_child->total_capacity*2;
			}
		}
		
		base = next;
	}
	summary_head = base.at(0);
}

















