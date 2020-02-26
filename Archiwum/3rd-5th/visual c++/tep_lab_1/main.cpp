#include "tep_lab1.h"
#include <iostream>
using namespace std;

int main() {
	//zadanie 1
	v_alloc_table_add_5(5);

	int** piTable;

	//zadanie 2
	b_alloc_table_2_dim(&piTable, 5, 3);

	//zadanie 3
	b_dealloc_table_2_dim(&piTable, 5, 3);
	cout << "zadanie" << piTable << endl;


	cout << "\n\nmodyfikacje programu:\n" << endl;



	int* piTableNew;
	int size = 5;
	piTableNew = new int[size];

	//sprawdzenie dzialania funkcji 1
	cout << "funkcja 1\n";
	show(piTableNew, size);

	//sprawdzenie dzialania funkcji 2
	cout << "funkcja 2\n";
	show(alloc1(5), 5);

	//sprawdzenie dzialania funkcji 3
	cout << "funkcja 3\n";
	alloc2(&piTableNew, 5);
	show(piTableNew, 5);

	//sprawdzenie dzialania funkcji 4
	cout << "funkcja 4\n";
	dealloc(&piTableNew);

	cout << "mod tab" << piTableNew << endl;

	cout << "\n\nnacisnij enter aby zakonczyc";
	cin.get();
	return 0;
}