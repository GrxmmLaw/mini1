#include "ListArr.h"
#include <iostream>
#include <chrono>
using namespace std;


void execution_time_find(int n, int b, int rep){
	double total_time = 0;
	srand(time(nullptr));
	int v = 200;
	ListArr list_arr(b);
	for(int j = 0; j < n/2; j++){//rellenar la mitad por izquierda
		int random = rand()%100;
		list_arr.insert_left(random);
	}
	for(int j = n/2; j < n-1; j++){//rellenar la mitad por la derecha dejando un espacio para el elemento v
		int random = rand()%100;
		list_arr.insert_right(random);
	}
	list_arr.insert_right(v);//se inserta al final el valor a encontrar
	for(int i = 0; i < rep; i++){
		auto start_time = chrono::high_resolution_clock::now();
		list_arr.find(v);
		auto end_time = chrono::high_resolution_clock::now();
		auto single_execution_time = chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count();
		total_time += single_execution_time;
	} 
	double avg_time = total_time/rep;
	cout << "find(v) b = " << b << ": " << avg_time << endl;
}

void execution_time_insert_left(int n, int b, int rep){
	double total_time = 0;
	srand(time(nullptr));
	int aux = 0;
	for(int i = 0; i < rep; i++){
		ListArr list_arr(b);
		auto start_time = chrono::high_resolution_clock::now();
		for(int j = 0; j < n; j++){
			int random = rand()%100;
			list_arr.insert_left(random);
		}
		auto end_time = chrono::high_resolution_clock::now();
		auto single_execution_time = chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count();
		total_time += single_execution_time;
		aux++;
		if(aux == rep){
			list_arr.update_summary();
		}
	} 
	double avg_time = total_time/rep;
	cout << "insert_left(v) b = " << b << ": " << avg_time << endl;
}

void execution_time_insert_right(int n, int b, int rep){
	double total_time = 0;
	srand(time(nullptr));
	int aux = 0;
	for(int i = 0; i < rep; i++){
		ListArr list_arr(b);
		auto start_time = chrono::high_resolution_clock::now();
		for(int j = 0; j < n; j++){
			int random = rand()%100;
			list_arr.insert_right(random);
		}
		auto end_time = chrono::high_resolution_clock::now();
		auto single_execution_time = chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count();
		total_time += single_execution_time;
		aux++;
		if(aux == rep){
			list_arr.update_summary();
		}	
	}
	double avg_time = total_time/rep;
	cout << "insert_right(v) b = " << b << ": " << avg_time << endl;
}


int main(){
	/*Mediciones para insert_left(v)*/
	int n = 10000, rep = 20;
	cout << "Tiempos de ejecucion para insert_left(v) con n = " << n << ":"<< endl;
	execution_time_insert_left(n,1,rep);
	execution_time_insert_left(n,64,rep);
	execution_time_insert_left(n,512,rep);
	execution_time_insert_left(n,1024,rep);
	execution_time_insert_left(n,n,rep);

	n += 10000;
	cout << "Tiempos de ejecucion para insert_left(v) con n = " << n << ":"<< endl;
	execution_time_insert_left(n,1,rep);
	execution_time_insert_left(n,64,rep);
	execution_time_insert_left(n,512,rep);
	execution_time_insert_left(n,1024,rep);
	execution_time_insert_left(n,n,rep);

	n += 10000;
	cout << "Tiempos de ejecucion para insert_left(v) con n = " << n << ":"<< endl;
	execution_time_insert_left(n,1,rep);
	execution_time_insert_left(n,64,rep);
	execution_time_insert_left(n,512,rep);
	execution_time_insert_left(n,1024,rep);
	execution_time_insert_left(n,n,rep);

	n += 10000;
	cout << "Tiempos de ejecucion para insert_left(v) con n = " << n << ":"<< endl;
	execution_time_insert_left(n,1,rep);
	execution_time_insert_left(n,64,rep);
	execution_time_insert_left(n,512,rep);
	execution_time_insert_left(n,1024,rep);
	execution_time_insert_left(n,n,rep);

	n += 10000;
	cout << "Tiempos de ejecucion para insert_left(v) con n = " << n << ":"<< endl;
	execution_time_insert_left(n,1,rep);
	execution_time_insert_left(n,64,rep);
	execution_time_insert_left(n,512,rep);
	execution_time_insert_left(n,1024,rep);
	execution_time_insert_left(n,n,rep);

	//Mediciones para insert_left(v)
	n = 10000;
	cout << "Tiempos de ejecucion para insert_right(v) con n = " << n << ":"<< endl;
	execution_time_insert_right(n,1,rep);
	execution_time_insert_right(n,64,rep);
	execution_time_insert_right(n,512,rep);
	execution_time_insert_right(n,1024,rep);
	execution_time_insert_right(n,n,rep);

	n += 10000;
	cout << "Tiempos de ejecucion para insert_right(v) con n = " << n << ":"<< endl;
	execution_time_insert_right(n,1,rep);
	execution_time_insert_right(n,64,rep);
	execution_time_insert_right(n,512,rep);
	execution_time_insert_right(n,1024,rep);
	execution_time_insert_right(n,n,rep);
	
	n += 10000;
	cout << "Tiempos de ejecucion para insert_right(v) con n = " << n << ":"<< endl;
	execution_time_insert_right(n,1,rep);
	execution_time_insert_right(n,64,rep);
	execution_time_insert_right(n,512,rep);
	execution_time_insert_right(n,1024,rep);
	execution_time_insert_right(n,n,rep);

	n += 10000;
	cout << "Tiempos de ejecucion para insert_right(v) con n = " << n << ":"<< endl;
	execution_time_insert_right(n,1,rep);
	execution_time_insert_right(n,64,rep);
	execution_time_insert_right(n,512,rep);
	execution_time_insert_right(n,1024,rep);
	execution_time_insert_right(n,n,rep);

	n += 10000;
	cout << "Tiempos de ejecucion para insert_right(v) con n = " << n << ":"<< endl;
	execution_time_insert_right(n,1,rep);
	execution_time_insert_right(n,64,rep);
	execution_time_insert_right(n,512,rep);
	execution_time_insert_right(n,1024,rep);
	execution_time_insert_right(n,n,rep);

	/*Mediciones para find(v)*/
	n = 10000;
	cout << "Tiempos de ejecucion para find(v) con n = " << n << ":"<< endl;
	execution_time_find(n,1,rep);
	execution_time_find(n,64,rep);
	execution_time_find(n,512,rep);
	execution_time_find(n,1024,rep);
	execution_time_find(n,n,rep);

	n += 10000;
	cout << "Tiempos de ejecucion para find(v) con n = " << n << ":"<< endl;
	execution_time_find(n,1,rep);
	execution_time_find(n,64,rep);
	execution_time_find(n,512,rep);
	execution_time_find(n,1024,rep);
	execution_time_find(n,n,rep);

	n += 10000;
	cout << "Tiempos de ejecucion para find(v) con n = " << n << ":"<< endl;
	execution_time_find(n,1,rep);
	execution_time_find(n,64,rep);
	execution_time_find(n,512,rep);
	execution_time_find(n,1024,rep);
	execution_time_find(n,n,rep);

	n += 10000;
	cout << "Tiempos de ejecucion para find(v) con n = " << n << ":"<< endl;
	execution_time_find(n,1,rep);
	execution_time_find(n,64,rep);
	execution_time_find(n,512,rep);
	execution_time_find(n,1024,rep);
	execution_time_find(n,n,rep);

	n += 10000;
	cout << "Tiempos de ejecucion para find(v) con n = " << n << ":"<< endl;
	execution_time_find(n,1,rep);
	execution_time_find(n,64,rep);
	execution_time_find(n,512,rep);
	execution_time_find(n,1024,rep);
	execution_time_find(n,n,rep);


	return 0;
}