#ifndef TEP_LAB1
#define TEP_LAB1

void v_alloc_table_add_5(int iSize);
void v_delete_tab(int* tab);

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY);
bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY);

bool show(int* p, int size);
int* alloc1(int size);
bool alloc2(int** p, int size);
void dealloc(int** p);

#endif