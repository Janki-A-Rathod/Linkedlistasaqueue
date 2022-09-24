/*!
 ********************************************************************************
 * @file : LinkedlistAsaQueue.c
 * Project : LinkedlistAsaQueue
 * @copyright : eInfochips © 2021
 * @author : JankiRathod
 * @brief :Trying to use Linkedlist As a Queue with more complexity.
 *******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>
#include"LinkedlistAsaQueue.h"
/*Global Variables*/
extern struct Node *Queue[25];/*This array is extern because we need to free up the memory allocated via malloc in Queue.*/
int Commandtype; 
unsigned int Timer[25];/*This array is use to store the value of Timer (Some Seconds) given by user.*/ 
int Timer_Index = 0;/*Time_Index is use to Use the timer array.*/
extern int Node_Count;
FILE  *FilePointer; 

int main()
{  
    int Choice;
    int Exit_Flag = 0;/*In order to stop the repetation of fork*/
    int DeletedElement;/*Local variable which is used to access the function DeleteNode*/
    int DisplayElement = 1;
    int Total_Node = 0;
    int Store_NodeValue;
    int Memory_Free;
    printf("\n:: Queue Implementation using Linked List ::\n");
    while(!Exit_Flag)
    {
        if(!Exit_Flag)
        {
        printf("\n****** MENU ******\n");
        printf("1. Add_Node_In_The_Queue\n2. Delete_First_Node_From_The_Queue\n3. Display_All_The_AddedNode\n4. Thread_Process\n5. Exit_From_The_Code\n");
        printf("\nEnter your choice: ");
        scanf("%d",&Choice);
        switch(Choice)
        {
        case 1:
        while(1)
        {    
            printf("\nEnter the value for timer in milliseconds:");
            scanf("%d",&Timer[Timer_Index]);
            printf("\nEnter the value of Command Type:\n");
            scanf("%d",&Commandtype);
            if(Timer[Timer_Index]<25000)
            {            
                Total_Node++;/*Total_Node is used to display the data added into the node*/
                Timer_Index++;
                break;
            }
            else
            {
                printf("The entered value should be less than 25000\n");
            }
            
        }
            if(Add_Timer_And_CommandType_Value(Timer[Timer_Index-1],Commandtype))
            {
                printf("\nInsertion is Success!!!\n");
            }
        break;
        case 2:
            DeletedElement = Delete_First_NodeData_From_LLAQ();
            if(DeletedElement == 1)
            {
                 printf("Queue is empty\n");
            }
            
            else
            {
                 Total_Node--;
                 printf("\nDeleted element: %d\n", DeletedElement);
            }
        break;
        case 3:
            if(DisplayElement == 0)
            {
                 printf("Queue is empty\n");
            }
            else
            {
                 for(Store_NodeValue = 0; Store_NodeValue<Total_Node; Store_NodeValue++)
                 {
                      Display_All_Added_Nodes_In_LLAQ(Store_NodeValue);
                 }
                 printf("NULL\n");
            }
        break;
        case 4:
            if (fork() == 0) 
            {
                pthread_t ThreadID1,ThreadID2,ThreadID3; 
                /*Opening a file for one time in "w" mode in order to clean the file everytime */
                FilePointer = fopen("./LLAQ.txt","w");
                fclose(FilePointer);
                /*Opening a file in append mode to get the data of all the Thread Functions*/
    	        FilePointer = fopen("./LLAQ.txt","a");
    	        if(FilePointer == NULL)
    	        {
    	             printf("Error in the creation of file\n");
    	             break;
    	        }
    	        printf("\nThread Execution Started\n"); 
    	        int Thread1_Creation_Error;
    	        int Thread2_Creation_Error;
    	        int Thread3_Creation_Error;
                if((Thread1_Creation_Error=(pthread_create(&ThreadID1, NULL, Thread1,NULL))) != 0)
                {
                    perror("Thread 1 creation error\n");
                }
                if((Thread2_Creation_Error=(pthread_create(&ThreadID2, NULL, Thread2,NULL))) != 0)
                {
                    perror("Thread 2 creation error\n");
                }
                if((Thread3_Creation_Error=(pthread_create(&ThreadID3, NULL, Thread3,NULL))) != 0)
                {
                    perror("Thread 3 creation error\n");
                }
                pthread_join(ThreadID1,NULL);
                pthread_join(ThreadID2,NULL);
                pthread_join(ThreadID3,NULL); 
                fclose(FilePointer);  
            }
            wait(NULL);
            printf("\nThread Execution Completed\n"); 
            break;
        case 5 :
            printf("\nExited from the program:\n"); 
            Exit_Flag=1;
        default:
            printf("\nWrong selection!!! Please try again!!!\n");
            break;
            } 
        } 
    }
    for(Memory_Free =0; Memory_Free < Node_Count; Memory_Free++)
    {
        free(Queue[Store_NodeValue]);
    }
    return 0;
}
     
            
          




