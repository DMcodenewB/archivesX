#include "CTreeStatic.h"
#include <algorithm>
CTreeStatic::CTreeStatic(){}

CTreeStatic::~CTreeStatic()
{
}

CNodeStatic * CTreeStatic::pcGetRoot()
{
	return &c_root;
}

void CTreeStatic::setRoot(CNodeStatic & root)
{
	c_root = root;
}

void CTreeStatic::vPrintTree()
{
	c_root.vPrintAllBelow();
}

//void CTreeStatic::vTransferSubTree(CNodeStatic * cTargetNode, CNodeStatic * cNewParent)
//{
//
//	
//		if (cTargetNode != NULL) {
//			CNodeStatic* cParent = cTargetNode->pcGetParentNode();
//			if (cParent != NULL) {
//				cout << "Przenoszony wêze³ ma parenta" << endl;
//				vector<CNodeStatic>* parentVect = cParent->pcGetChildren();
//				for (size_t ii = 0; ii < (*parentVect).size(); ii++) {
//					if ((*cTargetNode) == (*parentVect)[ii]) {
//						cout << "znaleziono odpowiedni wezel" << endl;
//						parentVect->erase(std::remove(parentVect->begin(), parentVect->end(), parentVect[ii]), parentVect->end());
//						cNewParent->vAddChild(*(cTargetNode)); //metoda vAddChild automatycznie nadpisze parenta dla cTargetNode
//						break;
//					}
//				}
//			}
//			else {
//				cout << "Parent przenoszonego poddrzewa nie istnieje" << endl;
//				cNewParent->vAddChild(*(cTargetNode)); //metoda vAddChild automatycznie przypisze parenta dla cTargetNode
//
//			}
//		}
//	
//}
