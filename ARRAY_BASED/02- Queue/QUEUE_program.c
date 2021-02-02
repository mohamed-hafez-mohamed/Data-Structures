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

void QUEUE_voidInitializeQUEUE(Queue_t * Copy_ptrToQueue)
{
   Copy_ptrToQueue->QueueFront = 0;
   Copy_ptrToQueue->QueueRear  = -1;
   Copy_ptrToQueue->QueueSize  = 0;
}

u8 QUEUE_u8AppendElement(QueueEntry_t  * Copy_ptrToElement,Queue_t * Copy_ptrToQueue)
{
   Copy_ptrToQueue->QueueRear = (Copy_ptrToQueue-> QueueRear + 1) % (QUEUE_MAX_OF_ENTRIES);
   Copy_ptrToQueue->QueueEntry[Copy_ptrToQueue->QueueRear] = *Copy_ptrToElement;
   Copy_ptrToQueue->QueueSize++;
}

void Queue_voidServeElement(QueueEntry_t  * Copy_ptrToElement,Queue_t * Copy_ptrToQueue)
{
   *Copy_ptrToElement = Copy_ptrToQueue->QueueEntry[Copy_ptrToQueue -> QueueFront];
   Copy_ptrToQueue -> QueueFront = (Copy_ptrToQueue->QueueFront + 1) % (QUEUE_MAX_OF_ENTRIES);
   Copy_ptrToQueue -> QueueSize--;
}

u8  QUEUE_u8IsQueueEmpty(Queue_t * Copy_ptrToQueue)
{
   return !Copy_ptrToQueue->QueueSize;
}

u8  QUEUE_u8IsQueueFull(Queue_t * Copy_ptrToQueue)
{
   return (Copy_ptrToQueue->QueueSize == QUEUE_MAX_OF_ENTRIES);
}

u8  QUEUE_u8ReturnQueueSize(Queue_t * Copy_ptrToQueue)
{
   return Copy_ptrToQueue->QueueSize;
}

void QUEUE_voidClearQueue(Queue_t * Copy_ptrToQueue)
{
   Copy_ptrToQueue->QueueFront = 0;
   Copy_ptrToQueue->QueueRear  = -1;
   Copy_ptrToQueue->QueueSize  = 0;
}

void QUEUE_voidTraverseQueue(Queue_t * Copy_ptrToQueue, CallBackFunc CallBackFunction)
{
   u8 Local_u8Position ,Local_u8Size = 0;
   for(Local_u8Position = Copy_ptrToQueue -> QueueFront;Local_u8Size = Copy_ptrToQueue->QueueSize;Local_u8Size++)
   {
      CallBackFunction(Copy_ptrToQueue->QueueEntry[Local_u8Position]);
      Local_u8Position = (Local_u8Position + 1) % (QUEUE_MAX_OF_ENTRIES);
   }
}

/*************** END OF FUNCTIONS ***************************************************************************/
