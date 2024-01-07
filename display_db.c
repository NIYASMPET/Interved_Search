/*
NAME           :NIYASKHAN M
DATE           :/ /2023
DESCDRIPTION   :
INPUT          :
OUTPUT         :
*/


#include"main.h"                                        //user header file

int display_database(hashing *hashtable)             //finction definition for display function
{
	    printf("\x1b[34m""\n-------------------------------------------------------------------------""\x1b[0m");
	    printf("\x1b[0m""\n-----------------------------------------------------------------------\n""\x1b[0m");
            printf("\x1b[35m""%-14s %-14s %-14s %-14s %-14s""\x1b[0m","Index","Word","File_count","File_name","Word_count""\x1b[0m");
	    printf("\x1b[0m""\n-------------------------------------------------------------------------""\x1b[0m");
	    printf("\x1b[34m""\n-------------------------------------------------------------------------""\x1b[0m");
    for (int i = 0; i < 27; i++)                                 //loop run upto i = 27
    {
        mn *cur_main_node = hashtable[i].link;                    //main node temp pointer is created and store hashtable address 

        while (cur_main_node != NULL)                             //loop run upto NULL
        {
            printf("\n%-14d %-14s %-14d ", i, cur_main_node->word, cur_main_node->file_c); //print the index word file_count

            sn *cur_sub_node = cur_main_node->sub_nodelink;        //sub node temp pointer iscreated and store the main node's sub nodelink address
            while (cur_sub_node != NULL)
            {
                printf("%-14s %-14d", cur_sub_node->file_name, cur_sub_node->word_c);  //printf the file_name,word_count
                cur_sub_node = cur_sub_node->link;
            }
            //printf("\n");
	    printf("\x1b[34m""\n-------------------------------------------------------------------------""\x1b[0m");

            cur_main_node = cur_main_node->max_nodelink;                //main node temp pointer is travelled
        }
    }
    return 0;
}
