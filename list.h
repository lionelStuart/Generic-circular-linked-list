#ifndef LIST_H
#define LIST_H


#define FAILURE (-1)
#define SUCCESS (0)

typedef struct __node__ NODE;
typedef unsigned int UINT;
typedef int INT;

typedef INT(*PTRFUNC)(NODE* node);
typedef INT(*PTRFUNC_P)(NODE* node,void* param);

struct __node__
{

	NODE *next;

	NODE *prev;

};

NODE* InitList(UINT elemSize);
NODE* InsertAfter(NODE* prevNode, NODE* newNode);
NODE* GetNode(NODE* listHead, PTRFUNC_P func, void* param);
NODE* ReleaseList(NODE** pListHead);
INT   GetListElemCount(NODE* listHead);
INT   TraverseList(NODE* listHead,PTRFUNC_P func, void* param);
INT   RemoveNode(NODE* listHead, NODE* currentNode);


NODE* CreateNode(NODE** pnode, UINT elemSize);
NODE* ModifyNode(NODE* currentNode, PTRFUNC_P func, void* param);
#endif //!LIST_H

