#pragma once
#include <string>
using namespace std;

const int DEFAULT_LENGTH = 5;
const string DEFAULT_NAME = "Tab";
const int DEFAULT_VALUE = 0;

class CTable {
public:
	CTable();
	CTable(string s_name, int iTableLength);
	CTable(CTable &pcOther);
	~CTable();
	void vSetName(string sName);
	bool setTableLength(int iTableLen);
	//void v_print_Tab();
	CTable* pcClone();
	string sGetName();

	void v_mod_tab(CTable *pcTab, int iNewSize);
	void v_mod_tab(CTable cTab, int iNewSize);

private:
	string s_name;
	int* tablica;
	int tableLength;

}

;