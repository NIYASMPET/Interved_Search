/*
NAME           :NIYASKHAN M
DATE           :/ /2023
DESCDRIPTION   :
INPUT          :
OUTPUT         :
 */

#include "main.h"                                         //user header file

int save_database(hashing *hashtable)                    //function definition for save function
{
    char filename[30];
    printf("Enter the file name\t");
    scanf("%s",filename);                                //read the filename form user
    if((strstr(filename,".") != NULL) && strcmp(strstr(filename,"."), ".txt") == 0) //check file is .txt or not
    {

	FILE *fptr = fopen(filename,"w");                                  //created file pointer and write

	for(int i=0;i<27;i++)                                              
	{ 
	    if(hashtable[i].link != NULL)                                  //check the hashtable link is not equal to NULL,then executed
	    {
		mn *temp=hashtable[i].link;                                //main node temp pointer and store the hashtable link
		while(temp)
		{
	    	fprintf(fptr, "#%d;", i);                                  //index value store the file pointer
		    fprintf(fptr, "%s;", temp->word);                      //store the word in file pointer
		    fprintf(fptr, "%d;", temp->file_c);                    //store the file count in file pointer
		    sn *current=temp->sub_nodelink;
		    while(current)
		    {
			fprintf(fptr, "%s;", current->file_name);           //store the file_name in file pointer
			fprintf(fptr, "%d;", current->word_c);              //store the word count in file pointer
			current=current->link;
		    }
		    temp=temp->max_nodelink;
		
		    fprintf(fptr,"#\n");
		}
		
	    }
	}
    }

    else
    {
	printf("Its not txt file");
	return 1;
    }
    return 0;
}

