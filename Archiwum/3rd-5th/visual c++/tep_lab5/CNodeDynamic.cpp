#include "CNodeDynamic.h"
#include <iostream>
#include <string>


CNodeDynamic::CNodeDynamic()
{
	i_val = 0;
	pc_parent_node = NULL;
}

CNodeDynamic::~CNodeDynamic()
{
	for (size_t ii = 0; ii < v_children.size(); ii++) {
		delete[] &v_children[ii];
	}
}

void CNodeDynamic::vSetValue(int iNewVal)
{
	i_val = iNewVal;
}

int CNodeDynamic::iGetValue()
{
	return i_val;
}

int CNodeDynamic::iGetChildrenNumber()
{
	return v_children.size();
}

void CNodeDynamic::vAddChild(CNodeDynamic * newChild)
{
	v_children.push_back(newChild);
	newChild->pc_parent_node = this;
}

void CNodeDynamic::vAddNewChild()
{
	CNodeDynamic* child = new CNodeDynamic();
	child->pc_parent_node = this;
	this->v_children.push_back(child);
}

CNodeDynamic * CNodeDynamic::pcGetChild(int iChildOffset)
{
	try {
		return (this->v_children[iChildOffset]);
	}
	catch (exception e) {
		cout << "Brak takiego elementu, zwracam null pointer" << endl;
	}
	return nullptr;
}

vector<CNodeDynamic*>* CNodeDynamic::pcGetChildren()
{
	return &v_children;
}

void CNodeDynamic::vSetParent(CNodeDynamic * newParent)
{
	pc_parent_node = newParent;
}

CNodeDynamic * CNodeDynamic::pcGetParentNode()
{
	return this->pc_parent_node;
}

void CNodeDynamic::vPrint()
{
	cout << " " << i_val;
}

void CNodeDynamic::vPrintAllBelow()
{
	this->vPrint();
	for (size_t ii = 0; ii < this->v_children.size(); ii++) {
		(*(this->v_children[ii])).vPrintAllBelow();
	}
}

void CNodeDynamic::vPrintUp()
{
	this->vPrint();
	if (this->pc_parent_node != NULL) {
		pc_parent_node->vPrintUp();
	}
}


