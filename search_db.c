/*
NAME           :NIYASKHAN M
DATE           :/ /2023
DESCDRIPTION   :
INPUT          :
OUTPUT         :
 */


#include "main.h"                                      //user header file

int search_database(Slist *head ,hashing *hashtable)   //function definition for search functiom
{
    Slist *tempt = head;
    int index;
    char buffer[30];
    printf("\x1b[36m""Enter the word\n""\x1b[0m");
    scanf("%s",buffer);                                //read the word from user
    if(buffer[0] >= 65 && buffer[0] <= 90)             //find the index value
    {
	index = buffer[0] % 65;
    }
    else if(buffer[0] >= 97 && buffer[0] <= 122)
    {
	index = buffer[0] % 97;
    }
    else
    {
	index = 26;
    }

    mn *temp = hashtable[index].link;                  //created the main node temp pointer and store the hashtable link address
    if(hashtable[index].link == NULL)                  //hashtable is NULL ,then print the error msg
    {
	printf("\x1b[31m""Word is not available in the database\n""\x1b[0m");
    }
    else                                                 //hashtable is Not NULL,then executed
    {
	while(temp)
	{
	    if(strcmp(temp->word,buffer)==0)            //check the word is matched or not
	    {
		printf("\x1b[33m""word '%s' is present in %dfiles\n""\x1b[0m",buffer,temp->file_c);
		sn *cur_sub_node = temp->sub_nodelink;
		while (cur_sub_node != NULL)
		{
		    printf("\x1b[33m""In file:%s-%dtime\n""\x1b[0m", cur_sub_node->file_name, cur_sub_node->word_c);
		    cur_sub_node = cur_sub_node->link;
		}
		return 0;
	    }
	    temp = temp -> max_nodelink;
	}
	if(temp == NULL)                                //temp reach the NULL,then word is not found
	{
	    printf("\x1b[31m""word is not available in the database""\x1b[0m");
	    return 1;
	}
    }


}

