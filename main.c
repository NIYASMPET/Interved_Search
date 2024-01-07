/*
NAME           :NIYASKHAN M
DATE           :/ /2023
DESCDRIPTION   :
INPUT          :
OUTPUT         :
 */


#include "main.h"                      //user header file

int main(int argc ,char *argv[])       //main function
{
    Slist *head = NULL;
    if(argc < 2)                       //check the arg count is greater than 2
    {
	printf("\x1b[31m""error""\x1b[0m");
	return 0;
    }
    else
    {
	read_and_validation(&head,argc,argv);         //function call for read and validation
	printf("\x1b[32m""---read_and_validation is success---\n""\x1b[0m");
    }

    hashing hashtable[27];         

    for(int i=0;i<27;i++)               //hashtable is update
    {
	hashtable[i] . key = i;
	hashtable[i] . link = NULL;
    }

    printf("\x1b[0m""1.create_database\n2.display_database\n3.search_database\n4.save_database\n5.update_database\n6.exit""\x1b[0m");
    int choice;
    int x=1,flag = 1;
    while(x)
    {
	printf("\x1b[32m""\nEnter the choice\n""\x1b[0m");
	scanf("%d",&choice);                                 //read the choice from user

	switch(choice)
	{
	    case 1:                                         //choice 1 is selected ,then executed
		{
		    if(flag == 1)                          //check flag value is 1,then executed and function call for cteate function
		    {
			if(create_database(head,hashtable) == 0)
			{
			    flag = 0;
			    printf("\x1b[32m""successfully create the database\n""\x1b[0m");
			}
			else
			{
			    printf("\x1b[31m""create the database is failure\n""\x1b[0m");
			}

		    }
		    else                                     //already user selected choice 5,then print error
		    {
			printf("INFO: create_database is not possible,Because already update the database\n");
		    }
		    break;
		}
	    case 2:                                         //user selected the chioce 2 ,then call the display function
		{
		    if(flag == 0)
		    {
			if(display_database(hashtable) == 0)  //function return 0,then success msg
			{
			    printf("\x1b[32m""\nsuccessfully display the database\n""\x1b[0m");
			}
			else
			{
			    printf("\x1b[31m""\ndisplay the database is failure\n""\x1b[0m");
			}
		    }
		    else
		    {
			printf("\x1b[31m""INFO: Display database is failed,Hence database is empty\n""\x1b[0m");
		    }
		    break;
		}
	    case 3:                                       //user selected the choice 3 ,then call the search functio
		{
		    if(flag == 0)
		    {
			if(search_database(head,hashtable) == 0)  //function return the 0 ,then print the success msg
			{
			    printf("\x1b[32m""\nsuccessfully search the database\n""\x1b[0m");
			}
		    }
		    else
		    {
			printf("\x1b[31m""INFO: search database is failed,Hence database is empty\n""\x1b[0m");
		    }
		    break;
		}
	    case 4:                                       //user selevted the choice 4, then cal the save function
		{
		    if(flag == 0)
		    {
			if(save_database(hashtable) == 0)     //function return the 0 ,then print success msg
			{
			    printf("\x1b[32m""\nsuccessfully save the database\n""\x1b[0m");
			}
			else
			{
			    printf("\x1b[31m""\nsave the database is failure\n""\x1b[0m");
			}
		    }
		    else
		    {
			printf("\x1b[31m""INFO: save database is failed,Hence database is empty\n""\x1b[0m");
		    }

		    break;
		}
	    case 5:
		{
		    if(flag == 1)                  //check flag is 1,then executed
		    {
			if(update_database(hashtable) == 0) //function call for update function and function return the 0,print the success msg
			{
			    flag = 0;
			    printf("\x1b[32m""\nsuccessfully update the database\n""\x1b[0m");
			}
			else
			{
			    printf("\x1b[31m""\nupdate the database is failure\n""\x1b[0m");
			}
		    }
		    else
		    {
			printf("INFO: update database is not possible,Because already create the database\n");
		    }
		    break;
		}
	    case 6:                               //user selected choice 6 ,then exit the loop
		{
		    x= 0;
		    break;
		}
	    default:
		{
		    printf("\x1b[31m""INFO:Your choice is wrong\nEnter the correct choice\n""\x1b[0m");
		}
	}
    }

}
