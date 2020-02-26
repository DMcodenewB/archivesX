#include "tep_lab1.h"
#include <iostream>
using namespace std;

//zadanie 1
void v_alloc_table_add_5(int iSize)
{
	int* pi_tab;
	//sprawdzenie warunku dla iSize
	if (iSize < 0) {
		cout << "Table size can't be lower than zero!";
		return;
	}
	//zaalokowanie tablicy
	pi_tab = new int[iSize];

	//wypełnienie tablicy
	for (int ii = 0; ii < iSize; ii++) {
		pi_tab[ii] = ii + 5;
	}
	
	//wyświetlenie oraz wypełnienie tablicy 
	show(pi_tab, iSize);
	v_delete_tab(pi_tab);
}
//zadanie 2
bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
	if (iSizeX < 0 || iSizeY < 0) {
		cout << "Allocation failed: incorrect table size!";
		return false;
	}
	//zaalokowanie tablicy jednowymiarowej
	*piTable = new int*[iSizeX];
	
	for (int ii = 0; ii < iSizeX; ii++) {
		(*piTable)[ii] = new int[iSizeY];
	}
	cout << "2-dimensional table allocate success" << endl;
	return true;
}

//zadanie 3

bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
	if (iSizeX < 0 || iSizeY < 0) {
		cout << "Deallocation failed: incorrect table size!";
		return false;
	}

	for (int ii = 0; ii < iSizeX; ii++) {
		delete [] (*piTable)[ii];
	}

	delete[] (*piTable);
	(*piTable) = NULL;
	cout << "2-dimensional table deallocate success" << endl;
	return true;
}


void v_delete_tab(int* tab) {
	delete [] tab;
	tab = NULL;
}

/*zadania do modyfikacji:

1) funkcja wyświetlająca tablicę, przyjmuje wskaźnik na nią oraz rozmiar: bool show(int* p, int size)
2) funkcja alokująca tablicę o podanym rozmiarze oraz wypełniająca ją kolejnymi liczbami: int* alloc1(int size)
3) funkcja alokująca tablicę podanym rozmiarze oraz wypełniająca ją liczbami np. parzystymi: bool alloc2(int** p, int size)
4) funkcja dealokująca tablicę: void dealloc(int** p)

*/

//mod 1
bool show(int* p, int size) {
	if (size < 0) {
		cout << "rozmiar tablicy nie moze byc mniejszy od 0!";
		return false;
	}
	//zakładam rozmiar tablicy mniejszy od 100000
	if (size > 100000) {
		cout << "rozmiar tablicy nie moze byc wiekszy od 100000!";
		return false;
	}

	cout << "tablica: ";
		for (int ii = 0; ii < size; ii++) {
			cout << p[ii] << " ";
	}
		cout << "\n" << endl;
		return true;
}

//mod 2
int* alloc1(int size) {
	if (size < 0) {
		cout << "rozmiar tablicy nie moze byc mniejszy od 0!";
		return false;
	}
	//zakładam rozmiar tablicy mniejszy od 100000
	if (size > 100000) {
		cout << "rozmiar tablicy nie moze byc wiekszy od 100000!";
		return false;
	}

	int* pi_table;
	pi_table = new int[size];

	for (int ii = 0; ii < size; ii++) {
		pi_table[ii] = ii;
	}

	return pi_table;
}

//mod 3

bool alloc2(int** p, int size) {
	if (size < 0) {
		cout << "rozmiar tablicy nie moze byc mniejszy od 0!";
		return false;
	}
	//zakładam rozmiar tablicy mniejszy od 100000
	if (size > 100000) {
		cout << "rozmiar tablicy nie moze byc wiekszy od 100000!";
		return false;
	}

	for (int ii = 0; ii < size; ii++) {
		(*p)[ii] = 2*ii;
	}


	return true;
}

//mod 4

void dealloc(int** p) {
	delete[]  (*p);
	(*p) = NULL;

	if ((*p) == NULL) cout << "Dealokacja zakonczona powodzeniem" << endl;
}


