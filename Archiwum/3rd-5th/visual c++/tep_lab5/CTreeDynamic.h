#pragma once
#include "CNodeDynamic.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CTreeDynamic {

public:
	CTreeDynamic();
	~CTreeDynamic();

	CNodeDynamic* pcGetRoot();
	void vSetRoot(CNodeDynamic *root);
	void vPrintTree();

	void vTransferSubTree(CNodeDynamic* cTargetNode, CNodeDynamic* cNewParent);

private:
	CNodeDynamic* c_root;
};