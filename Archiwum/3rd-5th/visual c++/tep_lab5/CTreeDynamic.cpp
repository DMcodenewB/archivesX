#include "CTreeDynamic.h"
#include <algorithm>

CTreeDynamic::CTreeDynamic()
{
}

CTreeDynamic::~CTreeDynamic()
{
}

CNodeDynamic * CTreeDynamic::pcGetRoot()
{
	return c_root;
}

void CTreeDynamic::vSetRoot(CNodeDynamic * root)
{
	c_root = root;
}

void CTreeDynamic::vPrintTree()
{
	c_root->vPrintAllBelow();
}

void CTreeDynamic::vTransferSubTree(CNodeDynamic* cTargetNode, CNodeDynamic* cNewParent)
{
	if (cTargetNode != NULL) {
		CNodeDynamic* cParent = cTargetNode->pcGetParentNode();
		if (cParent != NULL) {
			cout << "Przenoszony wêze³ ma parenta" << endl;
			vector<CNodeDynamic*>* parentVect = cParent->pcGetChildren();
			for (size_t ii = 0; ii < (*parentVect).size(); ii++) {
				if (cTargetNode == (*parentVect)[ii]) {
					cout << "znaleziono odpowiedni wezel" << endl;
					(*parentVect).erase(std::remove((*parentVect).begin(), (*parentVect).end(), parentVect[ii]), (*parentVect).end());
					cNewParent->vAddChild(cTargetNode); //metoda vAddChild automatycznie nadpisze parenta dla cTargetNode
					break;
				}
			}
		}
		else {
			cout << "Parent przenoszonego poddrzewa nie istnieje" << endl;
			cNewParent->vAddChild(cTargetNode); //metoda vAddChild automatycznie przypisze parenta dla cTargetNode

		}
	}
}
