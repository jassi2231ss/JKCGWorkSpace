
#include "dams.h"

DD* signupDoctor(DD *dd, int *_did)
{
	DD *newNode =NULL;
	DD *head = NULL;
	head = dd;

	newNode = (DD *)malloc(sizeof(DD));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		head = newNode;
		dd = newNode;
	}
	else
	{
		while(dd->next != NULL)
			dd = dd->next;
		        
		dd->next = newNode;
	       	dd = dd->next;
	}
	printf("\n\tEnter the doctor ID: ");
	scanf("%d",&newNode->_did);
	printf("\n\tEnter Name: ");
	getchar();
	scanf("%[^\n]s",newNode->_name);
        printf("\n\tEnter Phone Number: ");
	getchar();
	scanf("%d",&newNode->_phonenum);
	printf("\n\tEnter the designation: ");
	getchar();
	scanf("%[^\n]s"newNode->_designation);
	*_did = newNode->_did;
	
	return head;
    

}


int signInDoctor(DD *head)
{
	DD _dd;
	int flag = 0;

	printf("\n\tEnter doctor id: ");
        scanf("%d", _dd._did);
	
	while(head != NULL)
	{
		if((head->_did == _dd._did))
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

DD* loadDD()
{
	FILE *fp = NULL;
	DD *newNode = NULL;
	DD *head = NULL;
	DD *dd;
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
				newNode = (DD *)malloc(sizeof(DD));
				newNode->next = NULL;
				head = newNode;
				dd = newNode;
				tokenizeDD(newNode, tmpBuff);

			}
			else /* rest of the records */
			{
				newNode = (DD *)malloc(sizeof(DD));
				newNode->next = NULL;
				dd->next = newNode;
				tokenizeDD(newNode, tmpBuff);
				dd = dd->next;
			}


		}

	}

	fclose(fp);
	return head;

}

int tokenizeDD(DD *dd, char *tmpBuff)
{
	char *tokens;
	tokens = strtok(tmpBuff, ",");
	dd->_did = atoi(tokens);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,dd->_name);

	tokens = strtok(NULL, ",");
	dd->_phonenum = atoi(tokens);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,dd->_designation);
	
	
	tokens = strtok(NULL, ",");
	
    return 0;
}

int writeDD(DD *dd)
{
	FILE *fp = NULL;

	fp = fopen("./data/DD.dat","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	fseek(fp, 0L, SEEK_END);
	if(dd == NULL)
		printf("\n\t NULL Write pd");
	while(dd != NULL)
	{
		fprintf(fp,"%d, %s, %d, %s, \n",dd->_did,dd->_name,dd->_phonenum,dd->_designation);
		dd = dd->next;
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

void dispDD(DD *dd)
{
	while(dd != NULL)
	{
		printf("\n\tID: ");
		printf("%d",dd->_did);
		printf("\tName: ");
		printf("%s",dd->_name);
                printf("\n\tphone number: ");
		printf("%d",dd->_phonenum);
		printf("\tDesignation:" );
		printf("%s\n",dd->_designation);
		dd = dd->next;
	}
}

int updateDocDetails(DD *head)
{
	
	DD _dd;
	int flag = 0;
	printf("\n Enter your id to update:");
	getchar();
	scanf("%d",&_dd._did);
	while(head != NULL)
	{
		if(head->_did == _dd._did)
		{
			//flag = 1;
			printf("\n Enter name to update:");
			getchar();
			scanf("%[^\n]s",_dd._name);
			//head->_name == _dd._name;
			strcpy(head->_name,_dd._name);
			//free(head);
			writeDD(head);
			//dispDD(head);
			break;
		}
		head = head->next;
	}
	//writeDD(head);

	if(flag == 1)
		return 1;
	return 0;
}
