#include "global.h"
#include "list.h"
#include "ue.h"

int main(int argc, char** argv)
{
	LOG("main_starts\n");
	//!	1.Create list of ue
	int ueCount = 40;
	UINT elemSize = sizeof(UE);
	NODE* listHead = InitList(elemSize);
	if (NULL == listHead)
	{
		LOG("init list failure");
		return 0;
	}
	NODE* tailNode = listHead;
	NODE* newNode = NULL;
	for (int i = 0; i != ueCount; i++) {
		newNode = NULL;
		if (NULL==CreateNode(&newNode, elemSize))
		{
			LOG("createNode failure");
			return 0;
		}
		DATA tmp;
		tmp.ue_imei = UE_IMEI_BASE + i;
		tmp.ue_imsi = UE_IMSI_BASE + i;
		tmp.status = random_status();
		if (NULL == ModifyNode(newNode, setUeInfo, &tmp))
		{
			LOG("init node failure");
			return 0;
		}
		if (NULL == InsertAfter(tailNode, newNode))
		{
			LOG("insert node failure");
			return 0;
		}
		else {
			tailNode = newNode;
		}	
	}

	//!	2.print list of ue
	printf("list count\t%d\n", GetListElemCount(listHead));
	TraverseList(listHead, printUeInfo, NULL);

	//!	3.find and remove ue by imei
	int selectImei = UE_IMEI_BASE + 10;
	NODE* selectNode= GetNode(listHead,EqualImei, &selectImei);
	if (NULL == selectNode)
	{
		LOG("search node with imei failed");
	}
	else {
		LOG("delete select ue");
		printUeInfo(selectNode, NULL);
		RemoveNode(listHead, selectNode);
		printf("list count\t%d\n", GetListElemCount(listHead));
	}

	//!	3.find and remove ue by imsi
	int selectImsi = UE_IMSI_BASE + 20;
	selectNode = GetNode(listHead, EqualImsi, &selectImsi);
	if (NULL == selectNode)
	{
		LOG("search node with imsi failed");
	}
	else {
		LOG("delete select ue");
		printUeInfo(selectNode, NULL);
		RemoveNode(listHead, selectNode);		
		TraverseList(listHead, printUeInfo, NULL);
		printf("list count\t%d\n", GetListElemCount(listHead));
	}
	
	//!	4.free list
	ReleaseList(&listHead);
	LOG("main_ends\n");
	getchar();
	return 0;
}