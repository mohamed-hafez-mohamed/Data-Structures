/*******************************************************************************
* Title                 :   QUEUE
* Filename              :   QUEUE_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   10/01/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description
*  10/01/21   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file QUEUE_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO?
 */
/******************************************************************************
* Includes
*******************************************************************************/

#include <stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "QUEUE_interface.h"
#include "QUEUE_config.h"
#include "QUEUE_private.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module TyCopy_ptrToElementdefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function PrototyCopy_ptrToElements
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

void QUEUE_voidInitializeQUEUE(Queue_t   * Copy_ptrToQueue)
{
   Copy_ptrToQueue->QueueFront = NULL;
   Copy_ptrToQueue->QueueRear  = NULL;
   Copy_ptrToQueue->QueueSize  = 0;
}

u8 QUEUE_u8AppendElement(NodeEntry_t  * Copy_ptrToElement,Queue_t * Copy_ptrToQueue)
{
   QueueNode_t * Copy_ptrToNode = (QueueNode_t*)malloc(sizeof(QueueNode_t));
   if(!Copy_ptrToNode)
   {
      return 0;
   }
   else
   {
      Copy_ptrToNode->NodeEntry = *Copy_ptrToElement;
      Copy_ptrToNode->NextNode  = NULL;
      if(!Copy_ptrToQueue->QueueRear)
      {
         Copy_ptrToQueue->QueueFront = Copy_ptrToNode;
      }
      else
      {
         Copy_ptrToQueue->QueueRear->NextNode = Copy_ptrToNode;
      }
      Copy_ptrToQueue->QueueRear = Copy_ptrToNode;
      Copy_ptrToQueue->QueueSize++;
      return 1;
   }
}

void Queue_voidServeElement(NodeEntry_t * Copy_ptrToElement,Queue_t * Copy_ptrToQueue)
{
   QueueNode_t * Copy_ptrToNode = Copy_ptrToQueue->QueueFront;
   *Copy_ptrToElement = Copy_ptrToNode->NodeEntry;
   Copy_ptrToQueue->QueueFront = Copy_ptrToNode->NextNode;
   free(Copy_ptrToNode);
   if(!Copy_ptrToQueue->QueueFront)
   {
      Copy_ptrToQueue->QueueRear = NULL;
   }
   Copy_ptrToQueue->QueueSize--;
}

u8  QUEUE_u8IsQueueEmpty(Queue_t * Copy_ptrToQueue)
{
   return !Copy_ptrToQueue->QueueSize;
}

u8  QUEUE_u8IsQueueFull(Queue_t  * Copy_ptrToQueue)
{
   return 0;
}

u8  QUEUE_u8ReturnQueueSize(Queue_t * Copy_ptrToQueue)
{
   return Copy_ptrToQueue->QueueSize;
}

void QUEUE_voidClearQueue(Queue_t * Copy_ptrToQueue)
{
   while(Copy_ptrToQueue->QueueFront)
   {
      Copy_ptrToQueue->QueueRear = Copy_ptrToQueue->QueueFront->NextNode;
      free(Copy_ptrToQueue->QueueFront);
      Copy_ptrToQueue->QueueFront = Copy_ptrToQueue->QueueRear;
   }
   Copy_ptrToQueue->QueueSize = 0;
}

void QUEUE_voidTraverseQueue(Queue_t * Copy_ptrToQueue, CallBackFunc CallBackFunction)
{
   QueueNode_t * Copy_ptrToNode;
    for(Copy_ptrToNode = Copy_ptrToQueue->QueueFront;Copy_ptrToNode;Copy_ptrToNode = Copy_ptrToNode->NextNode)
    {
      CallBackFunction(Copy_ptrToNode->NodeEntry);
    }
}

/*************** END OF FUNCTIONS ***************************************************************************/
