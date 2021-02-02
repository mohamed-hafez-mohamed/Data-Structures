/****************************************************************************
* Title                 :   QUEUE   
* Filename              :   QUEUE_interface.h
* Author                :   Mohamed Hafez
* Origin Date           :   10/01/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None
*
*****************************************************************************/
/****************************************************************************
* Doxygen C Template 
*
*****************************************************************************/
/*************** INTERFACE CHANGE LIST **************************************
*
*    Date    Version   Author          Description 
*  10/01/21   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  QUEUE_interface.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef QUEUE_INTERFACE_H_
#define QUEUE_INTERFACE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/
	
/******************************************************************************
* Typedefs
*******************************************************************************/
typedef u32  NodeEntry_t;
typedef void (*CallBackFunc)(NodeEntry_t Copy_Entry);

typedef struct queuenode
{
   NodeEntry_t        NodeEntry;
   struct queuenode * NextNode;
}QueueNode_t;

typedef struct Queue
{
   QueueNode_t * QueueFront;
   QueueNode_t * QueueRear;
   u32           QueueSize;
}Queue_t;
/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

void QUEUE_voidInitializeQUEUE(Queue_t   * Copy_ptrToQueue);
u8   QUEUE_u8AppendElement(NodeEntry_t  * Copy_ptrToElement,Queue_t * Copy_ptrToQueue);
void Queue_voidServeElement(NodeEntry_t * Copy_ptrToElement,Queue_t * Copy_ptrToQueue);
u8   QUEUE_u8IsQueueEmpty(Queue_t * Copy_ptrToQueue);
u8   QUEUE_u8IsQueueFull(Queue_t  * Copy_ptrToQueue);
u8   QUEUE_u8ReturnQueueSize(Queue_t * Copy_ptrToQueue);
void QUEUE_voidClearQueue(Queue_t * Copy_ptrToQueue);
void QUEUE_voidTraverseQueue(Queue_t * Copy_ptrToQueue, CallBackFunc CallBackFunction);

#endif /*File_H_*/

/*** End of File **************************************************************/
