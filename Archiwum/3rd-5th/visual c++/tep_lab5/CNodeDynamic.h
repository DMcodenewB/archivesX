#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CNodeDynamic {

public:
	CNodeDynamic();
	~CNodeDynamic();

	void vSetValue(int iNewVal);
	int iGetValue();
	int iGetChildrenNumber();
	void vAddChild(CNodeDynamic* newChild);
	void vAddNewChild();
	CNodeDynamic *pcGetChild(int iChildOffset);
	CNodeDynamic *pcGetParentNode();
	vector<CNodeDynamic*>* pcGetChildren();
	void vSetParent(CNodeDynamic* newParent);

	void vPrint();
	void vPrintAllBelow();
	void vPrintUp();
	

private:
	vector<CNodeDynamic*> v_children;
	CNodeDynamic *pc_parent_node;
	int i_val;
};