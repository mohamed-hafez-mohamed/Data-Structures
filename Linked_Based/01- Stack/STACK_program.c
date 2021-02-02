/*******************************************************************************
* Title                 :   STACK
* Filename              :   STACK_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   30/01/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author          Description
*  30/01/21   1.0.0   Mohamed Hafez   Initial Release.
*
*******************************************************************************/
/** @file STACK_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO?
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STACK_interface.h"
#include "STACK_config.h"
#include "STACK_private.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module TyCopy_ptrToNodeEntrydefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function PrototyCopy_ptrToNodeEntrys
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

void STACK_voidInitializeStack(Stack_t *Copy_ptrToStack)
{
   Copy_ptrToStack->StackTop  = NULL;
   Copy_ptrToStack->StackSize = 0;
}

u8 STACK_u8PushEntryElement(NodeEntry_t * Copy_ptrToNodeEntry,Stack_t * Copy_ptrToStack)
{
   StackNode_t * Local_ptrToNode = (StackNode_t *)malloc(sizeof(StackNode_t));
   if(!Local_ptrToNode)
   {
      return 0;
   }
   else
   {
      Local_ptrToNode->NodeEntry = *Copy_ptrToNodeEntry;
      Local_ptrToNode->NextNode  = Copy_ptrToStack->StackTop;
      Copy_ptrToStack->StackTop   = Local_ptrToNode;
      Copy_ptrToStack->StackSize++;
      return 1;
   }
}

void STACK_u8PopEntryElement(NodeEntry_t *Copy_ptrToNodeEntry,Stack_t *Copy_ptrToStack)
{
   StackNode_t * Local_ptrToNode = Copy_ptrToStack->StackTop;
   *Copy_ptrToNodeEntry         = Copy_ptrToStack->StackTop->NodeEntry;
   Copy_ptrToStack->StackTop     = Copy_ptrToStack->StackTop->NextNode;
   free(Local_ptrToNode);
   Copy_ptrToStack->StackSize--;
}

u8  STACK_u8IsStackEmpty(Stack_t * Copy_ptrToStack)
{
   return  !Copy_ptrToStack->StackTop;
}

u8  STACK_u8IsStackFull(Stack_t * Copy_ptrToStack)
{
   return 0;
}

void STACK_voidClearStack(Stack_t * Copy_ptrToStack)
{
   StackNode_t * Local_ptrToNode;
   Local_ptrToNode = Copy_ptrToStack->StackTop;
   while(Local_ptrToNode)
   {
      Copy_ptrToStack -> StackTop = Copy_ptrToStack->StackTop->NextNode;
      free(Local_ptrToNode);
      Local_ptrToNode  = Copy_ptrToStack->StackTop;
   }
}
void STACK_voidStackTop(NodeEntry_t * Copy_ptrToNodeEntry,Stack_t * Copy_ptrToStack)
{
   *Copy_ptrToNodeEntry = Copy_ptrToStack->StackTop->NodeEntry;
}

u8  STACK_u8ReturnStackSize(Stack_t *Copy_ptrToStack)
{
   return Copy_ptrToStack->StackSize;
}

void STACK_voidTraverseStack(Stack_t * Copy_ptrToStack, CallBackFunc CallBackFunction)
{
   for(StackNode_t * Local_ptrToNode = Copy_ptrToStack->StackTop;Local_ptrToNode = Local_ptrToNode->NextNode)
   {
      CallBackFunction(Local_ptrToNode->NodeEntry);
   }
}

/*************** END OF FUNCTIONS ***************************************************************************/
