#include <common.h>
void countstring(char *str)
{
	int count=0;
	char* token =strtok(str," ");
	while(token!=NULL)
	{
		count++;
		token=strtok(NULL," ");:wq
	
