#include "CNodeStatic.h"
#include "CTreeStatic.h"
#include "CTreeDynamic.h"
#include "CNodeDynamic.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	//utworzenie poczatkowego wezla
	CTreeStatic* c_tree_s_1 = new CTreeStatic();
	CNodeStatic* c_node_s_1 = new CNodeStatic();
	c_node_s_1->vSetValue(1);
	//dodanie dzieci do wezla root
	c_node_s_1->vAddNewChild();
	c_node_s_1->vAddNewChild();

	cout << "Zadanie 1,2 i 3)\nIlosc dzieci wezla: ";
	cout << c_node_s_1->iGetChildrenNumber() << endl;
	
	c_node_s_1->pcGetChild(0)->vSetValue(11);
	c_node_s_1->pcGetChild(1)->vSetValue(12);
	
	//dodanie kolejnych dzieci i zmiana ich i_val
	c_node_s_1->pcGetChild(0)->vAddNewChild();
	c_node_s_1->pcGetChild(0)->vAddNewChild();
	c_node_s_1->pcGetChild(0)->pcGetChild(0)->vSetValue(111);
	c_node_s_1->pcGetChild(0)->pcGetChild(1)->vSetValue(112);
	
	c_node_s_1->pcGetChild(1)->vAddNewChild();
	c_node_s_1->pcGetChild(1)->pcGetChild(0)->vSetValue(121);

	cout << "Wartosci wezla " << c_node_s_1->igetValue() << " i wszystkich jego dzieci: ";
	c_node_s_1->vPrintAllBelow();
	cout << endl;

	cout << "Wartosci wezla " << c_node_s_1->pcGetChild(1)->pcGetChild(0)->igetValue() << " i jego rodzicow: ";
	c_node_s_1->pcGetChild(1)->pcGetChild(0)->vPrintUp();
	cout << endl;


	//zadanie 4

	c_tree_s_1->setRoot(*c_node_s_1);
	c_tree_s_1->vPrintTree();
	cout << endl;

	//zadanie 5

	CTreeDynamic* c_tree_d_1 = new CTreeDynamic();
	CNodeDynamic* c_node_d_1 = new CNodeDynamic();
	c_tree_d_1->vSetRoot(c_node_d_1);
	c_tree_d_1->pcGetRoot()->vSetValue(1);
	c_tree_d_1->pcGetRoot()->vAddNewChild();
	c_tree_d_1->pcGetRoot()->vAddNewChild();
	c_tree_d_1->pcGetRoot()->pcGetChild(0)->vSetValue(11);
	c_tree_d_1->pcGetRoot()->pcGetChild(1)->vSetValue(12);
	c_tree_d_1->vPrintTree();
	cout << endl << endl;

	//zadanie 6

	CTreeDynamic* c_tree_d_2 = new CTreeDynamic();
	CNodeDynamic* c_node_d_2 = new CNodeDynamic();

	c_tree_d_2->vSetRoot(c_node_d_2);
	c_tree_d_2->pcGetRoot()->vSetValue(2);
	c_tree_d_2->pcGetRoot()->vAddNewChild();
	c_tree_d_2->pcGetRoot()->vAddNewChild();
	c_tree_d_2->pcGetRoot()->pcGetChild(0)->vSetValue(21);
	c_tree_d_2->pcGetRoot()->pcGetChild(1)->vSetValue(22);

	c_tree_d_2->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_d_2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(212);

	//transfer poddrzewa c_tree_d_2 do jednego z wêz³ów c_tree_d_1
	c_tree_d_2->vTransferSubTree(c_node_d_2, c_tree_d_1->pcGetRoot()->pcGetChild(1));
	c_tree_d_1->vPrintTree();
	cin.get();
}