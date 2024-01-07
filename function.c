/*
NAME           :NIYASKHAN M
DATE           :/ /2023
DESCDRIPTION   :
INPUT          :
OUTPUT         :
*/


#include"main.h"


int read_and_validation(Slist **head,int agrc,char **agrv)
{
    for(int i = 1;i<agrc;i++)
    {
        if((strstr(agrv[i],".") == NULL))
	{
	    printf("\x1b[31m""error : %s  is Not txt file\n""\x1b[36m""Hence we are not adding this into the list\n""\x1b[0m",agrv[i]);
	}
	else if((strstr(agrv[i],".") == NULL) && strcmp(strstr(agrv[i],"."), ".txt") != 0) //check file is txt or not
	{
	    printf("\x1b[31m""error : %s  is Not txt file\n""\x1b[36m""Hence we are not adding this into the list\n""\x1b[0m",agrv[i]);
	
	}
	else
	{
	    FILE *fp;
	    fp = fopen(agrv[i],"r");

	    if(fp == NULL)    //check file persent or not
	    {
		printf("\x1b[31m""error : %s is file is not present\n""\x1b[36m""Hence we are not adding this into the list\n""\x1b[0m",agrv[i]);
	    }
	    else
	    {
		fseek(fp,0,SEEK_END);
		int pos = ftell(fp);
		if(pos == 0 )            //check file empty or not
		{
		    printf("\x1b[31m""%s is empty file\n""\x1b[36m""Hence we are not adding this into the list""\x1b[0m",agrv[i]);
		}
		else
		{
		    insert_last(head,agrv[i]);   //call the insert last function
		}
	    }
	   // printf("sucess");
	}
    }
}


int insert_last (Slist **head, char *data)  //function definition for insert last
{
    Slist *newNode = malloc(sizeof(Slist));
    if (newNode == NULL)                         //node is not created,print error msg
    {
        printf("Memory allocation error\n");
        return 1;
    }
    strcpy(newNode->data, data);
    newNode->link = NULL;
    if (*head == NULL)                            //check head is null or not
    {
        *head = newNode;
        printf("Inserted %s at the last\n", data);
    }
    else
    {
        Slist *temp = *head;
        while (temp->link != NULL)
        {
            if(strcmp(temp->data,data)==0)        //check duplicated file or not
            {
                printf("\x1b[31m""Duplicate data found: %s\n""\x1b[36m""FAILURE:This file is already added in linked list,so no need to add more than once\n",data);
                free(newNode);
                return 1;
           }
            temp = temp->link;
        }
        if(strcmp(temp->data,data)==0)
        {
            printf("\x1b[31m""Duplicate data found: %s\n""\x1b[36m""FAILURE:This file is already added in linked list,so no need to add more than once\n",data);
            free(newNode);
            return 1;
        }
        temp->link = newNode;
        printf("Inserted %s at the last\n", data);
    }

}


   





