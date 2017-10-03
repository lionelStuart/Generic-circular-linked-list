#include "UE.h"
#include<stdlib.h>
int random_status()
{
	return rand()% UE_STATUS_MAX;
}

int printUeInfo(NODE* currentNode, void* _null)
{
	if (NULL == currentNode)
	{
		LOG("print UE info failure");
		return FAILURE;
	}
	UE * currUE = (UE*)(currentNode);
	DATA ue_info = currUE->ue_info;
	printf("ue_imei \t%d\n",ue_info.ue_imei);
	printf("ue_imsi \t%d\n", ue_info.ue_imsi);
	printf("ue_status \t%d\n", ue_info.status);
	return SUCCESS;
}
int setUeInfo(NODE* currentNode, void* elemEntity)
{
	if (NULL == currentNode)
	{
		LOG("set UE  Info failure");
		return FAILURE;
	}
	UE * currUE = (UE*)(currentNode);
	currUE->ue_info = *((DATA*)elemEntity);
	return SUCCESS;
}

int EqualImsi(NODE * currentNode, void * imsi)
{
	if (NULL == currentNode)
	{
		LOG("equal imsi failure");
		return FAILURE;
	}
	UE * currUE = (UE*)(currentNode);
	DATA ue_info = currUE->ue_info;
	if (ue_info.ue_imsi == *((int*)imsi))
	{
		return SUCCESS;
	}
	return FAILURE;
}

int EqualImei(NODE * currentNode, void * imei)
{
	if (NULL == currentNode)
	{
		LOG("equal imei failure");
		return FAILURE;
	}
	UE * currUE = (UE*)(currentNode);
	DATA ue_info = currUE->ue_info;
	if (ue_info.ue_imei == *((int*)imei))
	{
		return SUCCESS;
	}
	return FAILURE;
}
