#include "global.h"


void LOG(const char* log_message)
{
	printf(log_message);
	printf("\n");
}

void LOGN(const char* log_message, int extra_argc, char* extra_argv[])
{
	printf(log_message);
	printf("\n");
	if (extra_argc <=0)
		return;
	int ii = 0;
	for (ii = 0; ii != extra_argc; ii++) {
		printf("extra_argv %d :\t", ii + 1);
		printf(extra_argv[ii]);
		printf("\n");
	}
}