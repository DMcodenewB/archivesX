#include "tep_lab_2.h"
#include <string>
#include <iostream>

using namespace std;

CTable::CTable()
{
	s_name = DEFAULT_NAME;
	tableLength = DEFAULT_LENGTH;
	tablica = new int[tableLength];
	cout << "bezp: " + s_name << endl;
}

CTable::CTable(string sName, int iTableLength) {
	s_name = sName;
	tableLength = iTableLength;
	tablica = new int[tableLength];
	cout << "parametr: " + sName << endl;
}

CTable::CTable(CTable & pcOther)
{
	s_name = pcOther.s_name + "_copy";
	tablica = new int[pcOther.tableLength];
	for (int i = 0; i < tableLength; i++) {
		tablica[i] = pcOther.tablica[i];
	}
	fill_n(tablica, tableLength, DEFAULT_VALUE);
	cout << "kopiuj: " + s_name << endl;

}

CTable::~CTable() {
	delete[] tablica;
	(*tablica) = NULL;
	cout << "Usuwam:" + s_name << endl;
}

void CTable::vSetName(string sName)
{
	this->s_name = sName;
}

bool CTable::setTableLength(int iTableLen)
{
	if (iTableLen <= 0) cout << "niewlasciwa dlugosc tablicy!" << endl;
	int newLength = iTableLen;
	int* newTab = new int[newLength];
	fill_n(newTab, newLength, DEFAULT_VALUE);
	for (int n = 0; n < newLength; n++) {
		newTab[n] = tablica[n];
	}
	newTab = tablica;
	delete tablica;
	

	if (iTableLen == newLength) {
		cout << "zmiana rozmiaru tablicy " + sGetName() + " zakonczona sukcesem" << endl;
		return true;
	}
	cout << "zmiana rozmiaru tablicy " + sGetName() + " zakonczona niepowodzeniem" << endl;
	return false;
}

CTable * CTable::pcClone()
{
	CTable* newTab = new CTable(this->s_name, this->tableLength);
	
	for (int ii = 0; ii < tableLength; ii++) {
		newTab->tablica[ii] = this->tablica[ii];
	}

	return newTab;
} 
//móg³bym to zrobiæ z u¿yciem konstruktora kopiuj¹cego, lecz nie by³by to 
//idealny klon obiektu CTable, ze wzglêdu na strukturê tego konstruktora

string CTable::sGetName()
{
	return this->s_name;
}

//void CTable::v_print_Tab()
//{
//	cout << "Tab " + s_name + ":\t";
//
//	for (int ii = 0; ii < tableLength; ii++) {
//		cout << tablica[tableLength] + " ";
//	}
//}


void v_mod_tab(CTable *pcTab, int iNewSize) {
	pcTab->setTableLength(iNewSize);
}
void v_mod_tab(CTable cTab, int iNewSize) {
	cTab.setTableLength(iNewSize);
}
