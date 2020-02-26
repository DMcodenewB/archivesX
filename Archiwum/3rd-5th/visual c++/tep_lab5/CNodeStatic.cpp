#include "CNodeStatic.h"
#include <iostream>
#include <string>


CNodeStatic::CNodeStatic()
{
	i_val = 0; 
	pc_parent_node = NULL;
}

CNodeStatic::~CNodeStatic()
{
	for (size_t ii = 0; ii < v_children.size(); ii++) {
		delete &v_children[ii];
	}
}

void CNodeStatic::vSetValue(int iNewVal)
{
	i_val = iNewVal;
}

int CNodeStatic::igetValue()
{
	return i_val;
}

int CNodeStatic::iGetChildrenNumber()
{
	return v_children.size();
}

void CNodeStatic::vAddNewChild()
{
	CNodeStatic* child = new CNodeStatic();
	child->pc_parent_node = this;
	this->v_children.push_back(*child);

}
 
CNodeStatic * CNodeStatic::pcGetChild(int iChildOffset)
{
	try {
		return &(this->v_children[iChildOffset]);
	}
	catch(exception e){
		cout << "Brak takiego elementu, zwracam null pointer" << endl;
	}
	return nullptr;
}

void CNodeStatic::vAddChild(CNodeStatic cNewChild)
{
	v_children.push_back(cNewChild);
	(&cNewChild)->pc_parent_node = this;
}

void CNodeStatic::vPrint()
{
	cout << " " << i_val;
}

void CNodeStatic::vPrintAllBelow()
{
	this->vPrint();
	for (size_t ii = 0; ii < this->v_children.size(); ii++) {
		this->v_children[ii].vPrintAllBelow();
	}
}

void CNodeStatic::vPrintUp()
{
	this->vPrint();
	if (this->pc_parent_node != NULL) {
		pc_parent_node->vPrintUp();
	}
}

CNodeStatic * CNodeStatic::pcGetParentNode()
{
		return this->pc_parent_node;
}

vector<CNodeStatic>* CNodeStatic::pcGetChildren()
{
	return &v_children;
}

//bool operator==(const CNodeStatic n1, const CNodeStatic n2)
//{
//	return (n1.i_val == n2.i_val) && (n1.pc_parent_node == n2.pc_parent_node) && (n1.v_children == n2.v_children);
//}
