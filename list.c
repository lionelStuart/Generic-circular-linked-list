#include "global.h"
#include "list.h"

static INT DeleteNode(NODE* node);

NODE * InitList(UINT elemSize)
{
	NODE* listHead = NULL;
	CreateNode(&listHead, elemSize);
	listHead->next = listHead;
	listHead->prev = listHead;
	return listHead;
}

INT GetListElemCount(NODE* listHead)
{
	if (NULL == listHead)
	{
		return FAILURE;
	}
	int elemCount = 0;
	NODE* ptr = listHead->next;
	while (ptr != listHead)
	{
		elemCount++;
		ptr = ptr->next;
	}
	return elemCount;
}

INT TraverseList(NODE * listHead, PTRFUNC_P  func, void* param)
{
	if (NULL == listHead)
	{
		LOG("Traverse list failure");
		return FAILURE;
	}
	NODE* ptr = listHead->next;
	while (ptr != listHead)
	{
		func(ptr, param);
		ptr = ptr->next;
	}
	return SUCCESS;
}

NODE* GetNode(NODE * listHead, PTRFUNC_P func, void * param)
{
	if (NULL == listHead )
	{
		LOG("get node failure");
	}
	NODE* ptr = listHead->next;
	while (ptr != listHead)
	{
		INT retval = func(ptr, param);
		if (SUCCESS == retval)
		{
			return ptr;
		}
		ptr = ptr->next;
	}
	LOG("get node failure");
	return NULL;
}

NODE * ReleaseList(NODE ** pListHead)
{
	if (NULL == pListHead)
	{
		LOG("release list failure");
	}
	NODE* tailNode = (*pListHead)->prev;
	NODE* nextNode = tailNode;
	while (tailNode != *pListHead)
	{
		nextNode = tailNode->prev;
		DeleteNode(tailNode);
		tailNode = nextNode;
	}
	DeleteNode(*pListHead);
	return NULL;
}

INT RemoveNode(NODE * listHead, NODE * currentNode)
{
	if (NULL == listHead || NULL == currentNode)
	{
		LOG("remove node failure");
	}
	NODE* ptr = listHead->next;
	while (ptr != listHead)
	{
		if (ptr == currentNode) {
			NODE* prevNode = currentNode->prev;
			NODE* nextNode = currentNode->next;
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
			return DeleteNode(currentNode);
		}
		ptr = ptr->next;
	}
	return FAILURE;
}



NODE* InsertAfter(NODE* prevNode, NODE* newNode)
{
	if (NULL == prevNode || NULL == newNode || prevNode == newNode)
	{
		LOG("Insert After failure");
		return NULL;
	}
	NODE* nextNode = prevNode->next;

	prevNode->next = newNode;
	newNode->prev = prevNode;

	newNode->next = nextNode;
	nextNode->prev = newNode;

	return newNode;
}

NODE* CreateNode(NODE** node, UINT elemSize)
{
	if (NULL == node || NULL != *node)
	{
		LOG("CreateNode failure");
		return NULL;
	}
	if (0 == elemSize)
	{
		LOG("CreateNode failure");
		return NULL;
	}
	*node = (NODE*)malloc(elemSize);
	memset(*node, 0x0, elemSize);
	return *node;
}
NODE * ModifyNode(NODE * currentNode, PTRFUNC_P func, void* param)
{
	if (NULL == currentNode)
	{
		LOG("Modify Node failure");
		return NULL;
	}
	func(currentNode, param);
	return currentNode;
}


static INT DeleteNode(NODE* node)
{
	if (NULL == node)
	{
		LOG("Delete Node failure");
		return FAILURE;
	}
	free(node);
	return SUCCESS;
}

