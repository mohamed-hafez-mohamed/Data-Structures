/*******************************************************************************
* Title                 :   LIST 
* Filename              :   LIST_program.c
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
/** @file LIST_program.c
 *  @brief This is the source file for TODO: WHAT DO I DO? 
 */
/******************************************************************************
* Includes
*******************************************************************************/	

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LIST_interface.h"
#include "LIST_config.h"
#include "LIST_private.h"

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

void LIST_voidInitializeList(List_t * Copy_ptrToList)
{
   Copy_ptrToList->ListHead = NULL;
   Copy_ptrToList->ListSize = 0;
}

u8   LIST_u8InsertElement(u8 Copy_u8ElementPosition, NodeEntry_t  * Copy_ptrToElement, List_t * Copy_ptrToList)
{
   ListNode_t * Copy_ptrToNode;
   Copy_ptrToNode = (ListNode_t *)malloc(sizeof(ListNode_t));
   if(!Copy_ptrToNode)
   {
     return 0;
   }
   else
   {
      Copy_ptrToNode->NodeEntry = *Copy_ptrToElement;
      Copy_ptrToNode->NextNode  = NULL;
      if(Copy_u8ElementPosition == 0)
      {
         Copy_ptrToNode->NextNode        = Copy_ptrToList->ListHead;
         Copy_ptrToList->ListHead        = Copy_ptrToNode;
	      Copy_ptrToList->CurrentPosition = 0;
         Copy_ptrToList->CurrentNode     = Copy_ptrToList->ListHead;
      }
      else
      {
	      if(Copy_u8ElementPosition <= Copy_ptrToList -> CurrentPosition)
	      {
	      	Copy_ptrToList->CurrentPosition = 0;
	      	Copy_ptrToList->CurrentNode     = Copy_ptrToList->ListHead;
	      }
	      for(; Copy_ptrToList -> CurrentPosition != Copy_u8ElementPosition - 1; Copy_ptrToList -> CurrentPosition++)
         {
            Copy_ptrToList->CurrentNode = Copy_ptrToList->CurrentNode->NextNode;
         }
	      Copy_ptrToNode->NextNode = Copy_ptrToList->CurrentNode->NextNode;
	      Copy_ptrToList->CurrentNode->NextNode = Copy_ptrToNode;
      }
   }
   Copy_ptrToList -> ListSize++;
   return 1;
}

void LIST_voidRetrieveElement(u8 Copy_u8ElementPosition, NodeEntry_t * Copy_ptrToElement, List_t * Copy_ptrToList)
{
   if(Copy_u8ElementPosition == 0)
   {
	  *Copy_ptrToElement = Copy_ptrToList->ListHead->NodeEntry;
   }
   if(Copy_u8ElementPosition <= Copy_ptrToList->CurrentPosition)
 	{
		Copy_ptrToList->CurrentPosition = 0;
		Copy_ptrToList->CurrentNode     = Copy_ptrToList->ListHead;
	}
	for(; Copy_ptrToList -> CurrentPosition != Copy_u8ElementPosition - 1; Copy_ptrToList -> CurrentPosition++)
   {
      Copy_ptrToList->CurrentNode = Copy_ptrToList->CurrentNode->NextNode;
   }
   *Copy_ptrToElement = Copy_ptrToList->CurrentNode->NextNode->NodeEntry;
}

void LIST_voidReplaceElement(u8 Copy_u8ElementPosition, NodeEntry_t  * Copy_ptrToElement, List_t * Copy_ptrToList)
{
   if(Copy_u8ElementPosition == 0)
   {
	  *Copy_ptrToElement = Copy_ptrToList-> ListHead ->NodeEntry;
   }
    if(Copy_u8ElementPosition <= Copy_ptrToList->CurrentPosition)
 	{
		Copy_ptrToList->CurrentPosition = 0;
		Copy_ptrToList->CurrentNode     = Copy_ptrToList->ListHead;
	}
	for(; Copy_ptrToList->CurrentPosition != Copy_u8ElementPosition - 1; Copy_ptrToList->CurrentPosition++)
   {
      Copy_ptrToList->CurrentNode = Copy_ptrToList->CurrentNode->NextNode;
   }
   Copy_ptrToList->CurrentNode->NextNode->NodeEntry = *Copy_ptrToElement;
}

void LIST_u8DeleteElement(u8 Copy_u8ElementPosition, NodeEntry_t  * Copy_ptrToElement, List_t * Copy_ptrToList)
{
   ListNode_t * Local_PtrToNode;
   if (Copy_u8ElementPosition == 0)
   {
	   *Copy_ptrToElement = Copy_ptrToList->ListHead->NodeEntry;
	   Copy_ptrToList->CurrentNode = Copy_ptrToList-> ListHead->NextNode;
	   free(Copy_ptrToList->ListHead);
	   Copy_ptrToList->ListHead = Copy_ptrToList -> CurrentNode;
	   Copy_ptrToList->CurrentPosition = 0;
   }
   else
   {
 	   if (Copy_u8ElementPosition <= Copy_ptrToList->CurrentPosition)
 	   {
	   	Copy_ptrToList->CurrentPosition = 0;
	   	Copy_ptrToList->CurrentNode = Copy_ptrToList->ListHead;
	   }
	   for(; Copy_ptrToList -> CurrentPosition != Copy_u8ElementPosition - 1; Copy_ptrToList->CurrentPosition++)
      {
         Copy_ptrToList->CurrentNode = Copy_ptrToList->CurrentNode-> NextNode;
      }
	   *Copy_ptrToElement = Copy_ptrToList->CurrentNode-> NextNode->NodeEntry;
	   Local_PtrToNode = Copy_ptrToList ->CurrentNode->NextNode->NextNode;
	   free(Copy_ptrToList -> CurrentNode->NextNode);
	   Copy_ptrToList->CurrentNode->NextNode = Local_PtrToNode;
   }
	Copy_ptrToList->ListSize--;
}

u8   LIST_u8IsListEmpty(List_t * Copy_ptrToList)
{
   return !Copy_ptrToList->ListSize;
}

u8   LIST_u8IsListFull(List_t  * Copy_ptrToList)
{
   return 0;
}

u8   LIST_u8ReturnListSize(List_t * Copy_ptrToList)
{
   return Copy_ptrToList->ListSize;
}

void LIST_voidClearList(List_t * Copy_ptrToList)
{
   ListNode_t * Local_PtrToNode;
   while(Copy_ptrToList->ListHead)
   {
      Local_PtrToNode = Copy_ptrToList->ListHead->NextNode;
      free(Copy_ptrToList->ListHead);
      Copy_ptrToList->ListHead = Local_PtrToNode;
   }
}

void LIST_voidTraverseList(List_t * Copy_ptrToList, CallBackFunc CallBackFunction)
{
   ListNode_t * Copy_ptrToNode;
   for(Copy_ptrToNode = Copy_ptrToList->ListHead;Copy_ptrToNode;Copy_ptrToNode = Copy_ptrToNode->NextNode)
   {
      CallBackFunction(Copy_ptrToNode->NodeEntry);
   }
}

u32  LIST_u32sequentialSearch(KeyType_t Copy_Target, List_t * Copy_ptrToList)
{
   u32 Local_u32CurrentPosition, Local_u32ListSize = LIST_u8ReturnListSize(Copy_ptrToList);
   NodeEntry_t Local_CurrentNodeEntry;
   for(Local_u32CurrentPosition = 0;Local_u32CurrentPosition < Local_u32ListSize ;Local_u32CurrentPosition++)
   {
      LIST_voidRetrieveElement(Local_u32CurrentPosition, &Local_CurrentNodeEntry, Copy_ptrToList);
      if(LIST_EQUAL(Copy_Target, Local_CurrentNodeEntry.key))
      {
         return Local_u32CurrentPosition;
      }
   }
   return -1;
}


/*************** END OF FUNCTIONS ***************************************************************************/
