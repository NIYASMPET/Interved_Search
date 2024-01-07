/*
NAME           :NIYASKHAN M
DATE           :/ /2023
DESCDRIPTION   :
INPUT          :
OUTPUT         :
 */


#include "main.h"                                                                   //user header file
void free_all_nodes(hashing *hash_table);
int update_database(hashing *hash_table)                                           //function definition for update function
{
    char filename[30];
    char buffer[100];
    printf("Enter the filename :");
    scanf("%s", filename);                                                          //read the filename from user
    if((strstr(filename,".") == NULL))
    {
	printf("hi");
	return 1;
    }
    if (strcmp(strstr(filename,"."), ".txt") != 0)                                 //check the file is txt file or not
    {
	return 1;
    
    }
    FILE *fp=fopen(filename, "r");                                                    //check file is present or not
    if(fp==NULL)
    {
	return 1;
    }
    fseek(fp, 0 , SEEK_END);
    int num = ftell(fp);
    if(num < 0)                                                                    //check file is empty or not
    {
	return 1;
    }
    rewind(fp);
    //printf("hoooooo");
    while((fscanf(fp, "%s", buffer)) != EOF)                                 //loop run upto end of file
    {
	int hash = 0, colon = 0;
	for(int j = 0;buffer[j];j++)
	{
	    if(buffer[j] == '#')                                          //count the no of # present in buffer
	    {
		hash++;
	    }
	    if(buffer[j] == ';')                                          //count the no of ; present in buffer
	    {
		colon++;
	    }
	}
	if(hash >= 2 && colon >= 5)                                      //check the condition ,its true then executed
	{
	    mn *main_temp=malloc(sizeof(mn));
	    if(buffer[0] == '#')                                          //check first character is # or not 
	    {
		char *token =strtok(&buffer[1], ";");
		int index=atoi(token);
		//printf("%d", value);
		token=strtok(NULL, ";");
		strcpy(main_temp->word,token);                            //store the word
		token=strtok(NULL, ";");
		int value=atoi(token);
		main_temp->file_c=value;                                  //store the filecount
									  //	printf("%d\n",main_temp->file_c);
		for(int i=0;i<value;i++)                                  //loop run upto file_count
		{
		    sn *sub_temp=malloc(sizeof(sn));                      //created the sub temp and allocated dynamic memory 
		    token = strtok(NULL, ";");
		    strcpy(sub_temp->file_name,token);                    //store the file name
		    token=strtok(NULL, ";");
		    int value1=atoi(token);
		    sub_temp->word_c=value1;                              //store the wordcount
		    sub_temp -> link =NULL;
		    if(main_temp->sub_nodelink== NULL)                    //main node sub link is null ,then store sub temp pointer address
		    {
			main_temp->sub_nodelink=sub_temp;
		    }
		    else                             //main node sub link is not null, created the one temp  pointer travelled null,then stored address
		    {
			sn *current=main_temp->sub_nodelink;
			while(current->link)
			{
			    current=current->link;
			}
			current->link=sub_temp;
		    }
		}
		if(hash_table[index].link == NULL)                           //hashtable link is NULL,then store the main temp pointer address
		{
		    hash_table[index].link = main_temp;
		    main_temp ->max_nodelink = NULL;
		}
		else               //hashtable is  not NULL,created the temp pointer ,that pointer reach null then stored the main temp pointer address 
		{
		    mn *prev=hash_table[index].link;
		    while(prev->max_nodelink)
		    {
			prev=prev->max_nodelink;
		    }
		    prev->max_nodelink=main_temp;      //travelled the pointer
		    main_temp ->max_nodelink = NULL;  //main temp main_node link is NULL
		}

	    }
	    else
	    {
		free_all_nodes(hash_table);
		printf("\x1b[31mERROR:Enter Proper backupfile\n\x1b[0m");
		return 1;
	    }
	}
	else
	{
	    free_all_nodes(hash_table);
	    printf("\x1b[31mERROR:Enter Proper backupfile\n\x1b[0m");
	    return 1;

	}


    }

    return 0;
}
void free_all_nodes(hashing *hash_table)
{
    for(int i=0;i<27;i++)
    {
	mn *current_main=hash_table[i].link;
	while(current_main!=NULL)
	{
	    mn *main_temp=current_main;
	    current_main=current_main->max_nodelink;
	    sn*current_sub=main_temp->sub_nodelink;
	    while(current_sub!=NULL)
	    {
		sn*temp_sub=current_sub;
		current_sub=current_sub ->link;
		free(temp_sub);
	    }
	    free(main_temp);
	}
	hash_table[i].link=NULL;
    }
}
