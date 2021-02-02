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
   Copy_ptrToList->ListSize  = 0;
}

u8   LIST_u8InsertElement(u8 Copy_u8ElementPosition, ListEntry_t  * Copy_ptrToElement, List_t * Copy_ptrToList)
{
   u8 Local_u8Counter;
   for(Local_u8Counter = Copy_ptrToList -> ListSize - 1;Local_u8Counter >= Copy_u8ElementPosition;Local_u8Counter--)
   {
      Copy_ptrToList->ListEntry[Local_u8Counter + 1] = Copy_ptrToList->ListEntry[Local_u8Counter];
   }
   Copy_ptrToList->ListEntry[Copy_u8ElementPosition] = *Copy_ptrToElement;
   Copy_ptrToList->ListSize++;
}

void LIST_voidRetrieveElement(u8 Copy_u8ElementPosition, ListEntry_t * Copy_ptrToElement, List_t * Copy_ptrToList)
{
   *Copy_ptrToElement = Copy_ptrToList->ListEntry[Copy_u8ElementPosition];
}

void LIST_u8ReplaceElement(u8 Copy_u8ElementPosition, ListEntry_t  * Copy_ptrToElement, List_t * Copy_ptrToList)
{
   Copy_ptrToList->ListEntry[Copy_u8ElementPosition] = *Copy_ptrToElement;
}

void LIST_u8DeleteElement(u8 Copy_u8ElementPosition, ListEntry_t  * Copy_ptrToElement, List_t * Copy_ptrToList)
{
   u8 Local_u8Counter;
   *Copy_ptrToElement  = Copy_ptrToList->ListEntry[Copy_u8ElementPosition];
   for(Local_u8Counter = Copy_u8ElementPosition + 1;Local_u8Counter <= Copy_ptrToList->ListSize - 1;Local_u8Counter++)
   {
      Copy_ptrToList->ListEntry[Local_u8Counter - 1] = Copy_ptrToList->ListEntry[Local_u8Counter];
   }
   Copy_ptrToList->ListSize--;
}

u8   LIST_u8IsListEmpty(List_t * Copy_ptrToList)
{
   return !Copy_ptrToList->ListSize;
}

u8   LIST_u8IsListFull(List_t  * Copy_ptrToList)
{
   return !(Copy_ptrToList->ListSize == LIST_MAX_OF_ENTRIES);
}

u8   LIST_u8ReturnListSize(List_t * Copy_ptrToList)
{
   return Copy_ptrToList->ListSize;
}

void LIST_voidClearList(List_t * Copy_ptrToList)
{
   Copy_ptrToList->ListSize = 0;
}

void LIST_voidTraverseList(List_t * Copy_ptrToList, CallBackFunc CallBackFunction)
{
   u8 Local_u8ElementPosition;
   for(Local_u8ElementPosition = 0;Local_u8ElementPosition < Copy_ptrToList -> ListSize;Local_u8ElementPosition++)
   {
      CallBackFunction(Copy_ptrToList->ListEntry[Local_u8ElementPosition]);
   }
}

void LIST_voidInsertOrder(ListEntry_t * Copy_ptrToElement,List_t * Copy_ptrToList)
{
   int Local_u32Current, Local_u32ListSize = LIST_u8ReturnListSize(Copy_ptrToList);
   ListEntry_t Local_CurrentListEnyry;
   for(Local_u32Current = 0;Local_u32Current < Local_u32ListSize;Local_u32Current++)
   {
      LIST_voidRetrieveElement(Local_u32Current, &Local_CurrentListEnyry, Copy_ptrToList);
      if(LIST_LESS_OR_EQUAL(Copy_ptrToElement->key,Local_CurrentListEnyry.key))
      {
         break;
      }
   }
   LIST_u8InsertElement(Local_u32Current,Copy_ptrToElement,Copy_ptrToList);
}

u32  LIST_u32sequentialSearch(KeyType_t Copy_Target, List_t * Copy_ptrToList)
{
   int Local_u32Current, Local_u32ListSize = LIST_u8ReturnListSize(Copy_ptrToList);
   ListEntry_t Local_CurrentListEnyry;
   for(Local_u32Current = 0;Local_u32Current < Local_u32ListSize;Local_u32Current++)
   {
      LIST_voidRetrieveElement(Local_u32Current, &Local_CurrentListEnyry, Copy_ptrToList);
      if(LIST_EQUAL(Copy_Target, Local_CurrentListEnyry.key))
      {
         return Local_u32Current;
      }
   }
   return -1;
}

u32  LIST_u32BinarySearch(KeyType_t Copy_Target, List_t * Copy_ptrToList)
{
   int Local_u32Middle, Local_u32Bottom = 0, Local_u32Top = Copy_ptrToList->ListSize - 1;
   while(Local_u32Bottom <= Local_u32Top)
   {
      Local_u32Middle = (Local_u32Top + Local_u32Bottom) / 2;
      if(LIST_EQUAL(Copy_Target,Copy_ptrToList->ListEntry[Local_u32Middle].key))
      {
         return Local_u32Middle;
      }
      if(LIST_LESS_THAN(Copy_Target,Copy_ptrToList->ListEntry[Local_u32Middle].key))
      {
         Local_u32Top = Local_u32Middle - 1;
      }
      else
      {
         Local_u32Bottom = Local_u32Middle + 1;
      }
   }
   return -1;
}


/*************** END OF FUNCTIONS ***************************************************************************/
