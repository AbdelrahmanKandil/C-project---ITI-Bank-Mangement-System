/*======================================================================================
===========================   - Bank.h			 ===========================
===========================   - Created:01/09/2022			 ===========================
===========================   - Author: Abdelrahman_Kandil   ===========================
===========================   - Version : _1_				 ===========================
===========================   - Note :
									  *-
									  *-
 ======================================================================================*/ 
/***
 *      ____              _       _____           _                   _____       _             __               
 *     |  _ \            | |     / ____|         | |                 |_   _|     | |           / _|              
 *     | |_) | __ _ _ __ | | __ | (___  _   _ ___| |_ ___ _ __ ___     | |  _ __ | |_ ___ _ __| |_ __ _  ___ ___ 
 *     |  _ < / _` | '_ \| |/ /  \___ \| | | / __| __/ _ \ '_ ` _ \    | | | '_ \| __/ _ \ '__|  _/ _` |/ __/ _ \
 *     | |_) | (_| | | | |   <   ____) | |_| \__ \ ||  __/ | | | | |  _| |_| | | | ||  __/ |  | || (_| | (_|  __/
 *     |____/ \__,_|_| |_|_|\_\ |_____/ \__, |___/\__\___|_| |_| |_| |_____|_| |_|\__\___|_|  |_| \__,_|\___\___|
 *                                       __/ |                                                                   
 *                                      |___/                                                                    
 */
/*=====================================================================================
		* What i sell To Customer
		*  The Architecture Give The API
						- The Name Of Function 
						- What is The Input 
						- What Is The Output
						- Macro 
						 
======================================================================================*/ 

/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/



#ifndef _BANK_H_

#define _BANK_H_
/*===========  Include HEADER FILE USED IN PROJECT ===========*/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
#include<windows.h>
#include"STD_TYPES.h"
#include<time.h>

/*===========  Macros  ===========*/

#define 	_ADMIN_CHOICE_  		1	
#define 	_CLEINT_CHOICE_ 		2	
#define 		_EXIT_				3	
	
#define 	_MAX_INPUT_TRYS_		5	

#define    _CREATE_NEW_ACC			1
#define    _OPEN_EXISTING_ACC		2


#define 	Active 					1
#define 	Restricted 				2
#define 	Closed 					3
#define Start_ID 1000
#define End_ID 9999

#define Start_Password 100000
#define End_Password 999999

/*=================================*/

/*===========  Structs  ===========*/

typedef struct {
	char username[50];
	char password[10];
}Admin_t;

typedef struct
{
	u8 Full_Name[100];
	u8 Full_Address[100];
	u8 Age;
	u8 National_ID[14];
	u8 Guardian_National_ID[14];
	s32 Balance;
	u8  Account_Status ;
 	u32 Bank_Account_ID;
	u16 Password;

}New_Account_t;

/*=================================*/


/*===========  Enums  ===========*/

typedef enum{
	RETURN_NOK,
	RETURN_OK,
}EStatus_t;

/*=================================*/





/*===========  Functions Prototypes  ===========*/

void printMessageCenter(const u8* message)  ;
void headMessage(const u8* message)         ;
void BankWellcome(void)                     ;
int  compare(u8 a[],u8 b[])                  ;
int  USER_PASS_CHECK(char a[],char b[])  	;
void Admin_Panel(void);
EStatus_t Create_New_Account(void);
void Make_Transaction(void);
u16 Check_Exisiting_Account(void);
void Deposit_In_Account(void);
void GetCash(void);
void Change_Account_Status(void);
void Change_Account_Password_client(void);
void Client_Panel(void);
void intro();
int main (void);

/*=================================*/













#endif /*End of _BANK_H_*/
/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/

