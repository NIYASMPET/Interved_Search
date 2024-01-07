#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct sub_node                     //sub node struct
{
    int word_c;
    char file_name[30];
    struct sub_node *link;
}sn;

typedef struct main_node                     //main node struct
{
    int file_c;	
    char word[30];
    sn *sub_nodelink;
    struct main_node *max_nodelink;
}mn;


typedef struct node_list                   //node list struct
{
    char data[25];
    struct node_list *link;
}Slist;

typedef struct hashing_t                 //hashtable struct
{
    int key;
   mn *link;
}hashing;



int read_and_validation(Slist **head,int agrc,char *agrv[]); //function declaraction for read and validation
int insert_last (Slist **head,char *data);                   //function declaraction for insert last
int create_database(Slist *head,hashing *hashtable);          //function declaraction for create function
int display_database(hashing *hashtable);                     //function declaraction for display function
int search_database(Slist *head,hashing *hashtable);          //function declaraction for search function
int save_database(hashing *hashtable);                        //function declaration for save function
int update_database(hashing *hashtable);                      //function declaration for update function
