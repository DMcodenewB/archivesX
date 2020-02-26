#include <iostream>
#include "tep_lab_2.h"

using namespace std;

int main() {

	CTable* table1 = new CTable();
	CTable* table2 = new CTable("Tablica2", 10);
	table1->setTableLength(10);
	table1->vSetName("tablica1");
	cout << table1->sGetName();


	CTable c_tab;
	CTable *pc_new_tab;
	CTable *pc_new_tab2;
	pc_new_tab = c_tab.pcClone();
	pc_new_tab2 = c_tab.pcClone();

	
	cout << "mod1 (*pc) " << endl;
	cout << "before " << pc_new_tab << endl;
	pc_new_tab->v_mod_tab(pc_new_tab, 7);
	cout << "after " << pc_new_tab << endl;
	
	cout << "\nmod2 (c)" << endl;
	cout << "before " << pc_new_tab2 << endl;
	pc_new_tab2->v_mod_tab((*pc_new_tab2), 7);
	cout << "after " << pc_new_tab2 << endl;




	cin.get();
}