/****************************************************************************
* Title                 :   LIST   
* Filename              :   LIST_interface.h
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
/** @file  LIST_interface.h
 *  @brief This module TODO: WHAT DO I DO?
 * 
 *  This is the header file for the definition TODO: MORE ABOUT ME!
 */
//TODO: UPDATE MACRO BELOW
#ifndef LIST_INTERFACE_H_
#define LIST_INTERFACE_H_

/******************************************************************************
* Includes
*******************************************************************************/
#include <string.h>
/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/
#ifdef KeyType String
   #define LIST_EQUAL(a, b)              (!strcmb((a),(b)))
   #define LIST_LESS_THAN(a, b)          (strcmb((a),(b)) < 0)
   #define  LIST_LES_OR_EQUAL(a, b)      (strcmb((a),(b)) <= 0)
   #define LIST_GREATER_THAN(a, b)       (strcmb((a),(b)) > 0)
   #define LIST_GREATER_OR_EQUAL(a, b)   (strcmb((a),(b)) >= 0)
#else  
   #define LIST_EQUAL(a, b)              ((a) == (b))
   #define LIST_LESS_THAN(a, b)          ((a) <  (b))
   #define LIST_LESS_OR_EQUAL(a, b)      ((a) <= (b))
   #define LIST_GREATER_THAN(a, b)       ((a) >  (b))`
   #define LIST_GREATER_OR_EQUAL(a, b)   ((a) >= (b))
#endif // KeyType

#define LIST_MAX_OF_ENTRIES              5
/******************************************************************************
* Macros
*******************************************************************************/
	
/******************************************************************************
* Typedefs
*******************************************************************************/
typedef int      KeyType_t;

typedef struct   ElementType
{
   KeyType_t key;
}ElementType_t;
typedef ElementType_t ListEntry_t;

typedef void (*CallBackFunc)(ListEntry_t Copy_Entry);

typedef struct List
{
   int         ListSize;
   ListEntry_t ListEntry[LIST_MAX_OF_ENTRIES];
}List_t;
/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void LIST_voidInitializeList(List_t * Copy_ptrToList);
u8   LIST_u8InsertElement(u8 Copy_u8ElementPosition, ListEntry_t  * Copy_ptrToElement, List_t * Copy_ptrToList);
void LIST_voidRetrieveElement(u8 Copy_u8ElementPosition, ListEntry_t * Copy_ptrToElement, List_t * Copy_ptrToList);
void LIST_u8ReplaceElement(u8 Copy_u8ElementPosition, ListEntry_t  * Copy_ptrToElement, List_t * Copy_ptrToList);
void LIST_u8DeleteElement(u8 Copy_u8ElementPosition, ListEntry_t  * Copy_ptrToElement, List_t * Copy_ptrToList);
u8   LIST_u8IsListEmpty(List_t * Copy_ptrToList);
u8   LIST_u8IsListFull(List_t  * Copy_ptrToList);
u8   LIST_u8ReturnListSize(List_t * Copy_ptrToList);
void LIST_voidClearList(List_t * Copy_ptrToList);
void LIST_voidTraverseList(List_t * Copy_ptrToList, CallBackFunc CallBackFunction);
void LIST_voidInsertOrder(ListEntry_t * Copy_ptrToElement,List_t * Copy_ptrToList);
u32  LIST_u32sequentialSearch(KeyType_t Copy_Target, List_t * Copy_ptrToList);
u32  LIST_u32BinarySearch(KeyType_t Copy_Target, List_t * Copy_ptrToList);

#endif /*File_H_*/

/*** End of File **************************************************************/
