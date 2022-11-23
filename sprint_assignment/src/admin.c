#include "dams.h"

int signInAdmin(AD *head)
{
        AD _ad;
        int flag = 0;

        printf("\n\tEnter admin id: ");
        scanf("%d", _ad._aid);

        while(head != NULL)
        {
                if((head->_aid == _ad._aid))
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


Appd* bookAppointment(Appd *appd, int *_pid)
{
	Appd *newNode =NULL;
	Appd *head = NULL;
	head = appd;
	int _status;

	newNode = (Appd *)malloc(sizeof(Appd));
	newNode->next = NULL;

	if(head == NULL)
	{
		head = newNode;
		appd = newNode;
	}
	else
	{
		while(appd->next != NULL)
			appd = appd->next;

		appd->next = newNode;
		appd = appd->next;
	}
	printf("\n\tEnter the capacity: ");
	scanf("%d",&newnode->capacity);
	
	printf("\n\tEnter the Patient id: ");
	scanf("%d",&newNode->_pid);
	
	printf("\n\tEnter the Doctor id: ");
	scanf("%d",&newNode->_did);
        
        printf("\n\tEnter the date: ");
        scanf
        printf("\n\tEnter the time: ");
	scanf


	printf("\n\tEnter 1/0 for booking appointment : ");
	//getchar();
	scanf("%d",&_status);
	if(_status == 1){
		printf("\n\tBooking appointment succesfull");
		cap(appd);
		
	}
	else{
		printf("\n Booking appointment cancelled");
	}
	*_pid = newNode->capacity;

	return head;

}


int cap(Appd *appd)
{
	printf("\n\tCapacity: ");
	printf("%d",appd->capacity);		
	exit(EXIT_SUCCESS);
        return 0;
}


Appd* loadappd()
{
	FILE *fp = NULL;
	Appd *newNode = NULL;
	Appd *head = NULL;
	Appd *appd;
	int _fSize = 0;
	char tmpBuff[BUFF] = {'\0', };

	fp = fopen("./data/Appd.dat","r+");
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
		memset(tmpBuff,'\0', BUFF);
		// head = newNode;
		while(fgets(tmpBuff, BUFF, fp)){

			if(head == NULL) /* first record */
			{
				newNode = (Appd *)malloc(sizeof(Appd));
				newNode->next = NULL;
				head = newNode;
				appd = newNode;
				tokenizeappd(newNode, tmpBuff);

			}
			else /* rest of the records */
			{
				newNode = (Appd *)malloc(sizeof(Appd));
				newNode->next = NULL;
				appd->next = newNode;
				tokenizeappd(newNode, tmpBuff);
				appd = appd->next;
			}


		}

	}

	fclose(fp);
	return head;

}



int writeappd(Appd *appd)
{
	FILE *fp = NULL;

	fp = fopen("./data/Appd.dat","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	fseek(fp, 0L, SEEK_END);
	if(appd == NULL)
		printf("\n\t NULL Write appd");
	while(appd != NULL){
		
		fprintf(fp,"%d| %d| %d| %s| %d\n",appd->capacity,appd->_pid,appd->_did,appd->_date,appd->_time);
		appd = appd->next;
	}

	fclose(fp);
    return 0;

}


int tokenizeappd(Appd *appd, char *tmpBuff)
{
	char *tokens;
	tokens = strtok(tmpBuff, ",");
	appd->capacity = atoi(tokens);

	tokens = strtok(NULL, ",");
	appd->_pid = atoi(tokens);

	tokens = strtok(NULL, ",");
	appd->_did = atoi(tokens);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,appd->date);
	
        tokens = strtok(NULL, ",");
	appd->_time =  atoi(tokens);
	tokens = strtok(NULL, ",");
	
    return 0;

}

void viewAppointment(Appd *appd)
{
       while(appd != NULL)
       {
                printf("\n\tCapacity: ");
                printf("%d",appd->capacity);
                printf("\tDoctor id: ");
                printf("%d",appd->_did);
                printf("\n\tPatient id: ");
                printf("%d",appd->_pid);
                printf("\tDate of appointment: ");
                printf("%s",appd->_date);
		printf("\tTime for the appointment: ");
                printf("%d",appd->_time);
                appd = appd->next;
      }

}
