/*!
 ********************************************************************************
 * @file : FunctionsOfLLAQ.c
 * Project : LinkedlistAsaQueue
 * @copyright : eInfochips © 2021
 * @author : Janki Rathod
 * @brief :Trying to use Linkedlist As a Queue with more complexity.
 *******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include"LinkedlistAsaQueue.h"

static int Traverse_Queue=0;//to travese the timer array
int Node_Count=0;
int Commandtype=0;
extern FILE  *FilePointer;

// Node for the storage of Timer and Command type data which should be enter by user.

struct Node
{
    unsigned int Timer;
    int CommandType;
    struct Node *Next;
    
};
struct Node *Front;
struct Node *Rear;
struct Node *Temporary;
struct Node *Queue[25];
int Queue_Index=0;

/*!
 ********************************************************************************
 * @fn :Add_Timer_And_CommandType_Value
 * @brief :This is the function which is used to add the node data into a linkedlist as a queue.
 * @AddNode: [Tim,cmd]
 * @AddNode: [Queue,Node_Count]
 * @return :1
 *******************************************************************************/
int Add_Timer_And_CommandType_Value(int Tim,int cmd)
{   
    struct Node *NewNode;
    NewNode = (struct Node*)malloc(sizeof(struct Node));
    if(NewNode == NULL)
    {
        printf("Error! memory not allocated.");
        exit(EXIT_FAILURE);
    }
    Queue[Queue_Index] = NewNode;
    Queue_Index++;
    Node_Count++;
    NewNode->Timer = Tim;  
    NewNode->CommandType = cmd;      
    NewNode->Next = NULL;
    if(Front == NULL)
    {
        Front = Rear = NewNode;
    }
    else
    {
        Rear->Next = NewNode;
	Rear = NewNode;
    }   
}

/*!
 ********************************************************************************
 * @fn :Delete_First_NodeData_From_LLAQ
 * @brief :This is the function which is used to Delete the first node data from the linkedlistas a queue.
 * @AddNode: [Temp]
 * @AddNode: [DeletedElement]
 * @return :1
 *******************************************************************************/
int  Delete_First_NodeData_From_LLAQ()
{
    int DeletedElement = 0;
    if(Front == NULL)
    {
        return 1;
    }
    else
    {
        struct Node *Temp = Front;
	Front = Front->Next;
	DeletedElement = Temp->Timer;
	free(Temp);
	Temp = NULL;
    }
}

/*!
 ********************************************************************************
 * @fn :Display_All_Added_Nodes_In_LLAQ
 * @brief :This is the function which is used to Display the Node data of a linkedlist.
 * @AddNode: [Timer,CommandType]
 * @AddNode: [Temporary]
 * @return :0,1
 *******************************************************************************/
int Display_All_Added_Nodes_In_LLAQ(int Node_Index)
{
    if(Node_Index== 0)
    {
        Temporary = Front;
    }
    if(Front == NULL)
    {
        return 0;
    }
    else
    {
    if(Temporary != NULL)
    {
         printf("%d,%d--->",Temporary->Timer,Queue[Node_Index]->CommandType);
         Temporary = Temporary->Next;
    }
    }
    return 1;
}
/*!
 ********************************************************************************
 * @fn :Thread1
 * @brief :This is the function which is used to run the Thread1.
 * @AddNode: [Node_Count,ind1]
 * @AddNode: [-]
 * @return :NULL
 *******************************************************************************/
 
 void* Thread1()
 {
 while(1)
 {
     if(Node_Count != 0)
     {
         int ind1 = 0;
         Node_Count--;
         if(Traverse_Queue!= 0)
         {
             Traverse_Queue= Traverse_Queue + 1;
             ind1 = Traverse_Queue;
         }
         else
         {
             ind1=0;
         }
         if(Queue[ind1]->CommandType == 0)
         {
            while(Queue[ind1]->Timer != 0)
            {
                fprintf(FilePointer,"Thread no.1and timer value is = %d\r\n",Queue[ind1]->Timer--);
                sleep(1);
                fflush(stdout);
            }
            fprintf(FilePointer,"\n Element 1 is completed.\n");
         }
        else
        {
            if(Queue[ind1]->CommandType == 1)
            {
                 fprintf(FilePointer,"\n Element 1 is on hold for %d milliseconds.\n",Queue[ind1]->Timer);
                 sleep(Queue[ind1]->Timer);
                 fprintf(FilePointer,"Element 1 is free\n");
            }
        }
    }
    else
    {
        break;
    }
} 
}

/*!
 ********************************************************************************
 * @fn :Thread2
 * @brief :This is the function which is used to run the Thread2.
 * @AddNode: [Node_Count,ind2]
 * @AddNode: [-]
 * @return :NULL
 *******************************************************************************/
void* Thread2()
{
while(1)
{
    if(Node_Count != 0) 
    {
        int ind2 = 0;
        Node_Count--;
        Traverse_Queue = Traverse_Queue+1;
        ind2 = Traverse_Queue;
        if(Queue[ind2]->CommandType == 0)
        {
             while(Queue[ind2]->Timer != 0)
             {
                  fprintf(FilePointer,"Thread no.2and timer value is = %d\r\n",Queue[ind2]->Timer--);
                  sleep(1);
                  fflush(stdout);
             }
             fprintf(FilePointer,"\n Element 2 is completed.\n");
        }  
        else
        {
            if(Queue[ind2]->CommandType == 1)
            {
                fprintf(FilePointer,"\n Element 2 is on hold for %d milliseconds.\n",Queue[ind2]->Timer);
                sleep(Queue[ind2]->Timer);
                fprintf(FilePointer,"Element 2 is free");
            }     
        }
    }
    else
    {
        break;
    }
} 
}

/*!
 ********************************************************************************
 * @fn :Thread3
 * @brief :This is the function which is used to run the Thread3.
 * @AddNode: [Node_Count,ind3]
 * @AddNode: [-]
 * @return :NULL
 *******************************************************************************/

void* Thread3()
{
while(1)
{
    if(Node_Count != 0)
    { 
        int ind3 = 0;
        Node_Count--;
        Traverse_Queue= Traverse_Queue+1;
        ind3 = Traverse_Queue;
        if(Queue[ind3]->CommandType == 0)
        {
            while(Queue[ind3]->Timer != 0)
            {
                fprintf(FilePointer,"Thread no.3 and timer value is = %d\r\n",Queue[ind3]->Timer--);
                sleep(1);
                fflush(stdout);
            }
            fprintf(FilePointer,"\n Element 3 is completed.\n");
        }
        else
        {
            if(Queue[ind3]->CommandType == 1)
            {
                fprintf(FilePointer,"\n Element 3 is on hold for %d milliseconds.\n",Queue[ind3]->Timer);
                sleep(Queue[ind3]->Timer);
                fprintf(FilePointer,"Element 3 is free\n");
            }   
        }   
    }    
    else
    {
        break;
    }
} 
}



