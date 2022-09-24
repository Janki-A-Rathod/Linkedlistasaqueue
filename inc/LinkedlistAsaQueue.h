/*!
 ********************************************************************************
 * @file : LinkedlistAsaQueue.h
 * Project : LinkedlistAsaQueue
 * @copyright : eInfochips © 2021
 * @author : JankiRathod
 * @brief :Trying to use Linkedlist As a Queue with more complexity.
 *******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int Add_Timer_And_CommandType_Value(int,int); /*Function for Adding an Elements in to LinkedlistAsaQueue*/
int Delete_First_NodeData_From_LLAQ(); /*Function to Delete the First element from the LinkedlistAsaQueue*/
int Display_All_Added_Nodes_In_LLAQ(int);/*Function to Display all the elements that are added into LinkedlistAsaQueue*/
void* Thread1();/*Function for running Thread1*/
void* Thread2();/*Function for running Thread2*/
void* Thread3();/*Function for running Thread3*/



