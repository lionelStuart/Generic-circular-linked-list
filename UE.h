#ifndef UE_H
#define UE_H
#include"global.h"
#include "list.h"

#define UE_IMEI_BASE	(1000)
#define UE_IMSI_BASE	(10000)
#define UE_STATUS_BASE	(0)
#define UE_STATUS_MAX	(10)

typedef struct ue_s UE;
typedef struct data_t DATA;

struct data_t
{
	int ue_imei;
	int ue_imsi;
	int status;
};

struct ue_s
{
	NODE node;
	DATA ue_info;
};

int random_status();
int printUeInfo(NODE* currentNode, void*);
int setUeInfo(NODE* currentNode, void* data);
int EqualImsi(NODE* currentNode, void* imsi);
int EqualImei(NODE* currentNode, void * imei);
#endif


