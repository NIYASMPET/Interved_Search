/*
NAME           :NIYASKHAN M
DATE           :/ /2023
DESCDRIPTION   :
INPUT          :
OUTPUT         :
*/


#include "main.h"

int create_database(Slist *head,hashing *hashtable)                //function definition for create database
{
    Slist *tempt = head;                                           //create temp pointer
    int index;
    while(tempt)                                                   //loop run upto NULL 
    {

        FILE *fptr = fopen(tempt->data,"r");                        //open and read the file
        char buffer[20];

        while(fscanf(fptr,"%s",buffer) != EOF)                      //loop run upto end of file
        {
            if(buffer[0] >= 65 && buffer[0] <= 90)                  //check the first character is upper case ,then modulo by 65 and store in index
            {
                index = buffer[0] % 65;
            }
            else if(buffer[0] >= 97 && buffer[0] <= 122)           //check the first character is lower case ,then modulp by 97 and store in index
            {
                index = buffer[0] % 97;
            }
            else                                                   //otherwise special character and number ,then store index 
            {
                index = 26;
            }


                mn *temp = malloc(sizeof(mn));                     //create main node temp pointer
                sn *temp1 = malloc(sizeof(sn));                    //create sub node temp pointer

            if(hashtable[index].link == NULL)                       //hashtable link is NULL,then execute
            {

                temp->file_c = 1;
                strcpy(temp -> word ,buffer);
                temp->sub_nodelink = temp1;
                temp->max_nodelink = NULL;
                hashtable[index].link = temp;

                temp1->word_c = 1;
                strcpy(temp1->file_name,tempt->data);
                temp1->link = NULL;
            }
            else                                                    //hashtable link is not NULL
            {
                mn *mn_temp = hashtable[index].link;
                mn *mn_prev = mn_temp;
                while(mn_temp)
                {
                    if(strcmp(mn_temp -> word,buffer) == 0)
                    {
                        sn *sn_temp = mn_temp -> sub_nodelink;
                        sn *sn_prev = sn_temp;
                        while(sn_temp)
                        {
                            if(strcmp(sn_temp->file_name,tempt->data) == 0)
                            {
                                (sn_temp->word_c)++;
                                break;
                            }
                            sn_prev = sn_temp;
                            sn_temp = sn_temp ->link;                          //sub node temp pointer travelled
                        }
                        if(sn_temp == NULL)
                        {
                        temp1 -> word_c = 1;
                        strcpy(temp1->file_name,tempt->data);
                        sn_prev->link = temp1;
                        (mn_temp->file_c)++;

                        }
                        break;
                    }
                    mn_prev = mn_temp;

                    mn_temp = mn_temp ->max_nodelink;                     //main node temp pointed travelled
                }
                if(mn_temp == NULL)                                       //main node main_node link is NULL,then executed
                {
                temp->file_c = 1;
                strcpy(temp -> word ,buffer);
                temp->sub_nodelink = temp1;
                temp->max_nodelink = NULL;
                mn_prev->max_nodelink = temp;

                temp1->word_c = 1;
                strcpy(temp1->file_name,tempt->data);
                temp1->link = NULL;
                }
            }
        }
        tempt = tempt -> link;                                             //temp list pointer is travelled
    }
    return 0;
}
