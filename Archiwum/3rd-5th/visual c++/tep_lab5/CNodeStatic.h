#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CNodeStatic {

public:
	CNodeStatic();
	~CNodeStatic();

	void vSetValue(int iNewVal);
	int igetValue();
	int iGetChildrenNumber();
	void vAddNewChild();
	CNodeStatic *pcGetChild(int iChildOffset);
	void vAddChild(CNodeStatic cNewChild);
	void vPrint();
	void vPrintAllBelow();
	void vPrintUp();
	CNodeStatic* pcGetParentNode();
	vector<CNodeStatic>* pcGetChildren();

	//friend bool operator==(const CNodeStatic n1, const CNodeStatic n2);

private:
	vector<CNodeStatic> v_children;
	CNodeStatic *pc_parent_node;
	int i_val;
};