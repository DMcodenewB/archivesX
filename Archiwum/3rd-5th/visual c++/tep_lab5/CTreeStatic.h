#pragma once
#include "CNodeStatic.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CTreeStatic {

public:
	CTreeStatic();
	~CTreeStatic();
	
	CNodeStatic* pcGetRoot();
	void setRoot(CNodeStatic& root);
	void vPrintTree();
	
	//void vTransferSubTree(CNodeStatic* cTargetNode, CNodeStatic* cNewParent);

private:
	CNodeStatic c_root;

};