
#include "dams.h"
PD* signupPatient(PD *pd, int *_pid)
{
	PD *newNode =NULL;
	PD *head = NULL;
	head = pd;

	newNode = (PD *)malloc(sizeof(PD));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		head = newNode;
		dd = newNode;
	}
	else
	{
		while(pd->next != NULL)
			pd = pd->next;

		pd->next = newNode;
		pd = pd->next;
	}
	printf("\n\tEnter the patient ID: ");
	scanf("%d",&newNode->_pid);
	printf("\n\tEnter Name: ");
	getchar();
	scanf("%[^\n]s",newNode->_name);
        printf("\n\tEnter Phone Number: ");
	getchar();
	scanf("%d",&newNode->_phonenum);
	printf("\n\tEnter the illness: ");
	getchar();
	scanf("%[^\n]s",newNode->_illness);
	*_pid = newNode->_pid;
	
	return head;
    

}


int signInPatient(PD *head)
{
	PD _pd;
	int flag = 0;

	printf("\n\tEnter patient id: ");
        scanf("%d", _pd._pid);
	
	while(head != NULL)
	{
		if((head->_pid == _pd._pid))
		{
			flag = 1;
			break;
		}
		head = head->next;
	}

	if(flag == 1)
		return 1;
	return 0;
}

PD* loadPD()
{
	FILE *fp = NULL;
	PD *newNode = NULL;
	PD *head = NULL;
	PD *dd;
	int _fSize = 0;
	char tmpBuff[256] = {'\0', };

	fp = fopen("./data/DD.dat","r");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return NULL;
	}

	fseek(fp, 0L, SEEK_SET);
	fseek(fp, 0L, SEEK_END);
	_fSize = ftell(fp);
	if(_fSize == 0) /* No records */
	{
		head = NULL;
	}
	else
	{
		fseek(fp, 0L, SEEK_SET);
		memset(tmpBuff,'\0', 256);
		// head = newNode;
		while(fgets(tmpBuff, 256, fp))
		{

			if(head == NULL) /* first record */
			{
				newNode = (PD *)malloc(sizeof(PD));
				newNode->next = NULL;
				head = newNode;
				pd = newNode;
				tokenizePD(newNode, tmpBuff);

			}
			else /* rest of the records */
			{
				newNode = (PD *)malloc(sizeof(PD));
				newNode->next = NULL;
				pd->next = newNode;
				tokenizePD(newNode, tmpBuff);
				pd = pd->next;
			}


		}

	}

	fclose(fp);
	return head;

}

int tokenizePD(PD *pd, char *tmpBuff)
{
	char *tokens;
	tokens = strtok(tmpBuff, ",");
	pd->_pid = atoi(tokens);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,pd->_name);

	tokens = strtok(NULL, ",");
	pd->_phonenum = atoi(tokens);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,pd->_illness);
	
	
	tokens = strtok(NULL, ",");
	
    return 0;
}

int writePD(PD *pd)
{
	FILE *fp = NULL;

	fp = fopen("./data/DD.dat","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	fseek(fp, 0L, SEEK_END);
	if(pd == NULL)
		printf("\n\t NULL Write pd");
	while(pd != NULL)
	{
		fprintf(fp,"%d, %s, %d, %s, \n",pd->_pid,pd->_name,pd->_phonenum,pd->_illness);
		pd = pd->next;
	}

	fclose(fp);
    return 0;
}

void removeLeading(char *str, char *str1)
{
    int idx = 0, j, k = 0;

    // Iterate String until last
    // leading space character
    while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
    {
        idx++;
    }

    // Run a for loop from index until the original
    // string ends and copy the content of str to str1
    for (j = idx; str[j] != '\0'; j++)
    {
        str1[k] = str[j];
        k++;
    }

    // Insert a string terminating character
    // at the end of new string
    str1[k] = '\0';

}

void removeTrailing(char *str)
{
	if((str[strlen(str)-1] == ' ' || str[strlen(str)-1] == '\t' || str[strlen(str)-1] == '\n'))
    {
    	str[strlen(str)-1] = '\0';
    }

}

void dispPD(PD *pd)
{
	while(pd != NULL)
	{
		printf("\n\tID: ");
		printf("%d",pd->_pid);
		printf("\tName: ");
		printf("%s",pd->_name);
                printf("\n\tphone number: ");
		printf("%d",pd->_phonenum);
		printf("\tIllness: " );
		printf("%s\n",pd->_illness);
		pd = pd->next;
	}
}



int updatePatDetails(PD *head)
{

        PD _pd;
        int flag = 0;
        printf("\n Enter your id to update:");
        getchar();
        scanf("%d",&_pd._pid);
        while(head != NULL)
        {
                if(head->_pid == _pd._pid)
                {
                        //flag = 1;
                        printf("\n Enter name to update:");
                        getchar();
                        scanf("%[^\n]s",_pd._name);
                        //head->_name == _pd._name;
                        strcpy(head->_name,_pd._name);
                        //free(head);
                        writePD(head);
                        //dispPD(head);
                        break;
                }
                head = head->next;
        }
        //writePD(head);

        if(flag == 1)
                return 1;
        return 0;
}
