/****************************************************************************
* Title                 :   STACK
* Filename              :   STACK_interface.h
* Author                :   Mohamed Hafez
* Origin Date           :   30/01/2021
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
*  30/01/21   1.0.0   Mohamed Hafez   Interface Created.
*
*****************************************************************************/
/** @file  STACK_interface.h
 *  @brief This module TODO: WHAT DO I DO?
 *
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef STACK_INTERFACE_H_
#define STACK_INTERFACE_H_

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
typedef u8 NodeEntry_t;
typedef void (*CallBackFunc)(NodeEntry_t Copy_Entry));

typedef struct stacknode
{
   NodeEntry_t        NodeEntry;
   struct stacknode * NextNode;
}StackNode_t;

typedef struct Stack
{
   StackNode_t * StackTop;
   int           StackSize;
}Stack_t;
/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function PrototyCopy_ptrToNodeEntrys
*******************************************************************************/

void STACK_voidInitializeStack(Stack_t *Copy_ptrToStack);
u8   STACK_u8PushEntryElement(NodeEntry_t *Copy_ptrToNodeEntry,Stack_t *Copy_ptrToStack);
void STACK_u8PopEntryElement(NodeEntry_t *Copy_ptrToNodeEntry,Stack_t *Copy_ptrToStack);
u8   STACK_u8IsStackEmpty(Stack_t *Copy_ptrToStack);
u8   STACK_u8IsStackFull(Stack_t *Copy_ptrToStack);
void STACK_voidClearStack(Stack_t *Copy_ptrToStack);
void STACK_voidStackTop(NodeEntry_t *Copy_ptrToNodeEntry,Stack_t *Copy_ptrToStack);
u8   STACK_u8ReturnStackSize(Stack_t *Copy_ptrToStack);
void STACK_voidTraverseStack(Stack_t *Copy_ptrToStack, CallBackFunc CallBackFunction);

#endif /*File_H_*/

/*** End of File **************************************************************/
