 /*======================================================================================
===========================   - Bank.c			 ===========================
===========================   - Created:01/09/2022			 ===========================
===========================   - Author: Abdelrahman_Kandil   ===========================
===========================   - Version : _1_				 ===========================
===========================   - Note :
									  *-
									  *-
 ======================================================================================*/ 
/***
 *      ____          _   _ _  __  __  __          _   _  _____ ______ __  __ ______ _   _ _______    _______     _______ _______ ______ __  __  
 *     |  _ \   /\   | \ | | |/ / |  \/  |   /\   | \ | |/ ____|  ____|  \/  |  ____| \ | |__   __|  / ____\ \   / / ____|__   __|  ____|  \/  | 
 *     | |_) | /  \  |  \| | ' /  | \  / |  /  \  |  \| | |  __| |__  | \  / | |__  |  \| |  | |    | (___  \ \_/ / (___    | |  | |__  | \  / | 
 *     |  _ < / /\ \ | . ` |  <   | |\/| | / /\ \ | . ` | | |_ |  __| | |\/| |  __| | . ` |  | |     \___ \  \   / \___ \   | |  |  __| | |\/| | 
 *     | |_) / ____ \| |\  | . \  | |  | |/ ____ \| |\  | |__| | |____| |  | | |____| |\  |  | |     ____) |  | |  ____) |  | |  | |____| |  | | 
 *     |____/_____ \_\_| \_|_|\__ __|__|______  \______________|___________|_|______|_| \_|  |_|    |_____/   |_| |_____/   |_|  |______|_|  |_| 
 *           |  _ \   /\   | \ | | |/ / / ____| |  ____|_   _| |    |  ____|                                                                     
 *           | |_) | /  \  |  \| | ' / | |      | |__    | | | |    | |__                                                                        
 *           |  _ < / /\ \ | . ` |  <  | |      |  __|   | | | |    |  __|                                                                       
 *           | |_) / ____ \| |\  | . \ | |____  | |     _| |_| |____| |____                                                                      
 *           |____/_/    \_\_| \_|_|\_(_)_____| |_|    |_____|______|______|                                                                     
 *                                                                                                                                               
 *                                                                                                                                               
 */
/*===========  Include HEADER FILE USED IN PROJECT ===========*/

#include"Bank.h" 

extern New_Account_t Client[1000];
extern u16 Number_Of_Accounts;
extern u8 counter;
extern u16 Account_index;
extern u32 ID_Number;
extern u16 Client_Password;
extern u16 New_Password;


void printMessageCenter(const u8* message)
{
    int len =0;
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}
void headMessage(const u8* message)
{
    printf("\t\t\t#############################################################################");
    printf("\n\t\t\t############                                                     ############");
    printf("\n\t\t\t############     BANK Management System Project in C             ############");
    printf("\n\t\t\t############                                                     ############");
    printf("\n\t\t\t#############################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
void BankWellcome(void)
{	
	headMessage(" Auther Name : Abdelrahman kandil\n\t\t\t https://www.linkedin.com/in/abdulrahman-kandil/");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                  Bank                     =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....\n");
	getch();
	system("cls");
	printf("Choose one of the following options: \n");
	printf("\n\t\t1.Enter System as Admin        press [1]\n");
	printf("\n\t\t2.Enter System as Client       press [2]\n");
	printf("\n\t\t3.Exit  the Bank Program       press [3]\n");
	printf("----------------------------------------------------------\n");
	printf("---> You Choice is: ");

}

void intro()
{

	printf( "\n\n\n\t\t\t\tWelcome To BANK MANAGEMENT SYSTEM");
	//Note: All the data of the new account entered will be stored in the file
	printf( "\n\n\n\t\t\t\tPlease wait while loading\n\n");
	char a = 177, b = 219;
	printf( "\t\t\t\t");
	for (int i = 0; i <= 15; i++)
		printf( "%c",a);
	printf( "\r");
	printf( "\t\t\t\t");
	for (int i = 0; i <= 15; i++)
	{
		printf("%c",b);
		Sleep(200);
	}
}

int USER_PASS_CHECK(char a[],char b[])  
{  
    int flag=0,i=0;
    while(a[i]!='\0'  || b[i]!='\0')
    {  
       if(a[i]!=b[i])  
       {  
           flag=1;  
           break;  
       }  
       i++;  
    }  
    if(flag==0)  
    return RETURN_OK;  
    else  
    return RETURN_NOK;  
}

void Admin_Panel(void)
{	
	EStatus_t Ret_State = RETURN_NOK;
	u8 AdminChoise;
	u16 Transfer_Account_index;
	f64 Money_Transfer;
	do
	{
		printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO ADMIN  WINDOW \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		printf(" \n");
		printf("\n\t\tChoose one of the following options: \n");
		printf("\n\t\t1.Create New Account        press [1]\n");
		printf("\n\t\t2.Open Existing Account     press [2]\n");
		printf("\n\t\t3.Return to main Menu       press [3]\n");		
		printf("\n\t\t4.Exit System               press [4]\n");
		printf("\n----------------------------------------------------------\n");
		printf("\n---> You Choice is: ");
		scanf("%i",&AdminChoise);
		printf("\n");
		switch(AdminChoise)
		{
			
			case _CREATE_NEW_ACC:
					system("cls");
			Ret_State = Create_New_Account();
			if (Ret_State == RETURN_OK)
					{
					printf("\n-------------------------------- Client Has been added successfully --------------------------------\n");
					printf("\n\t\t\t\tAccount no : [%u] is successfuly created\n",++Number_Of_Accounts);

					}
					else{
					printf("\n-------------------------------- Failed to Add The Client ! --------------------------------\n");
			break;
			
			
			
			
			
			case _OPEN_EXISTING_ACC:
			 Account_index=Check_Exisiting_Account();
			u8 Choise4;
			while(Account_index > Number_Of_Accounts )
			{
				printf(" \n");
				printf("\n\t\tChoose one of the following options: \n");
				printf("\n\t\t1.Try Again                   press [1]\n");
				printf("\n\t\t2.Return to the main menu     press [2]\n");
				printf("\n----------------------------------------------------------\n");
				printf("\n---> You Choice is: ");
				scanf("%d",&Choise4);
				printf("\n");
				switch(Choise4)
				{
					case 1:
				    Account_index=Check_Exisiting_Account();
					break;
					
					case 2:
					Admin_Panel();
					break;
				}
			}		
				u8 Choise5;
				system("cls");	
				printf(" \n");
				printf("\n\t\tChoose one of the following options: \n");
				printf("\n\t\t1.Make Transaction        						press [1]\n");
				printf("\n\t\t2.Change Account Status     						press [2]\n");
				printf("\n\t\t3.Get Cash      							press [3]\n");
				printf("\n\t\t4.Deposit in Account            					press [4]\n");
				printf("\n\t\t5.Return to main manu       						press [5]\n");
				printf("\n---> You Choice is: ");
				scanf("%i",&Choise5);
				printf("\n");	
				switch(Choise5)
				{
					case 1:
					Make_Transaction();
					break;
					case 2:
					Change_Account_Status();
					break;
					case 3:
					GetCash();
					break;
					case 4:
					Deposit_In_Account();
					break;
					case 5:
					Admin_Panel();
					break;	

					default:
					break;					
				}
	
			break;
			case 3:
			main();
 			break;
			case 4:
			system("cls");
			exit(0);
			break;
			
			default:
			break;
		}
			Number_Of_Accounts++;
			counter++;
		}	
	}while(AdminChoise!=3);
}


void Client_Panel(void)
{	
	EStatus_t Ret_State = RETURN_NOK;
	u8 ClientChoise;
	u16 Transfer_Account_index;
	f64 Money_Transfer;
	do
	{
		printf(" \n");
		printf("\n\t\tChoose one of the following options: \n")      ;
		printf("\n\t\t1.Make Transaction          		press [1]\n");
		printf("\n\t\t2.Change Account Password   		press [2]\n");
		printf("\n\t\t3.Get Cash			        press [3]\n")      ;
		printf("\n\t\t4.Deposit In Account    	    	press [4]\n")      ;
		printf("\n\t\t5.Return to main Menu       		press [5]\n");
		printf("\n----------------------------------------------------------\n");
		printf("\n---> You Choice is: ");
		scanf("%i",&ClientChoise);
		printf("\n");
		
		switch(ClientChoise)
		{
			
			case 1:
				Make_Transaction();
			break;
			
			case 2:
				Change_Account_Password_client();
			break;	
			case 3:
			GetCash();
			break;
			case 4:
			Deposit_In_Account();
			break;
			case 5:
			main();
			break;

			default:
			break;					
		}
	}while(ClientChoise!=5);
}




EStatus_t Create_New_Account(void)
{
		EStatus_t Ret_State = RETURN_NOK;
		//system("cls");
		printf("Please Enter info of Client [%d]\n",Account_index+1);
		printf("**********************************************************************************\n");
		printf("Full Name: ");
		scanf("%s",&Client[Account_index].Full_Name);
		fflush(stdin);
		printf("\nFull Address: ");
		scanf("%s",&Client[Account_index].Full_Address);
		fflush(stdin);
		printf("\nAge: ");
		scanf("%d",&Client[Account_index].Age);
		fflush(stdin);
		if(Client[Account_index].Age<21)
		{
			printf("\nGuardian National ID: ");
			scanf("%s",&Client[Account_index].Guardian_National_ID);
			fflush(stdin);
		}
		fflush(stdin);
		printf("\nNational ID: ");
		scanf("%s",&Client[Account_index].National_ID);
				fflush(stdin);
		printf("\nBalance: ");
		scanf("%u",&Client[Account_index].Balance);
		fflush(stdin);

		/*automatic set account to active mode*/
		Client[Account_index].Account_Status=Active;
		/*generating random Account ID and password*/
		srand(time(0));
		Client[Account_index].Bank_Account_ID = rand()%(End_ID+1-Start_ID)+Start_ID;
		srand(time(0));
		Client[Account_index].Password = rand()%(End_Password+1-Start_Password)+Start_Password;
							/*giving user the automatated info password and Bank ID aslo indicates successufly process*/
		printf("\n\t \t=============================================================================\n \t \t Bank ID of name [%s] is [%u] Password Is [%u]\n\t \t=============================================================================\n",Client[Account_index].Full_Name,Client[Account_index].Bank_Account_ID,Client[Account_index].Password);
		Ret_State = RETURN_OK;
		Account_index++;
		return Ret_State;
}

u16 Check_Exisiting_Account(void)
{	
		u8 Choise;
		u16 Ret_Value =2000;
			u16 i =0;
			u32 ID_Number;
			printf("\nplease Enter Account ID Number: ");
			scanf("%u",&ID_Number);
			
		while(i<Number_Of_Accounts)
		{
			if (Client[i].Bank_Account_ID==ID_Number )
			{
				Ret_Value =i;
				break;
			}
			i++;
			
		}
		if (Ret_Value == 2000)
		{
			printf("Error: Id not found");	
			Admin_Panel();
			
		}
		else {
			return Ret_Value;

		}


}

void Make_Transaction(void)
{
		u32 Transfer_ID;
		s32 Money_Transfer=0;
		u8 Choise4;
		printf("\n Enter Account ID You Need To transfer the Money : ");
		u16 T_Acc_index = Check_Exisiting_Account();
		while(T_Acc_index > Number_Of_Accounts )
	{
		printf(" \n");
		printf("\n\t\tChoose one of the following options: \n");
		printf("\n\t\t1.Try Again                   press [1]\n");
		printf("\n\t\t2.Return to the main menu     press [2]\n");
		printf("\n----------------------------------------------------------\n");
		printf("\n---> You Choice is: ");
		scanf("%d",&Choise4);
		printf("\n");
		switch(Choise4)
		{
			case 1:
			T_Acc_index=Check_Exisiting_Account();
			break;
			case 2:
			Admin_Panel();
			break;
		}
	}
	
		printf("Please enter amount of money to be transfered: ");
		scanf("%i",&Money_Transfer);
		fflush(stdin);
		if ((Client[Account_index].Account_Status == Active) && (Client[T_Acc_index].Account_Status == Active))	
		{
			if (Client[Account_index].Balance<Money_Transfer)
				printf("\n sorry your current balance isn\'t suffcient");
			else {
				Client[Account_index].Balance-=Money_Transfer;
				Client[T_Acc_index].Balance+=Money_Transfer;
				printf("\nyou have been transfered %u successufly your balance is: %u",Money_Transfer,Client[Account_index].Balance);
			}
		}
		else
		{
			printf("\nYour Account not Active..");
		}

}


void Deposit_In_Account(void)
{
	
	/*decleare varibale to get amount of added money*/
	s32 Added_Money;
	printf("Please Enter Amount of Money to be added: ");
	scanf("%u",&Added_Money);
	/*adding Value to Current Balance*/
	Client[Account_index].Balance+=Added_Money;
	/*printing the result of operation*/
	printf("\nsuccessful operation done your balance is: %u",Client[Account_index].Balance);
}

void GetCash(void)
{
	u32 Amount_Of_Money;
	printf("\nplease enter amount of Money: ");
	scanf("%u",&Amount_Of_Money);
	if (Client[Account_index].Balance>=Amount_Of_Money)
	{
		Client[Account_index].Balance-=Amount_Of_Money;
		printf("\nsuccessful operation done get out %u\n your balance is: %u",Amount_Of_Money,Client[Account_index].Balance);
	}
	else
	{
		printf("\nSorry Insuffcient Balance");
	}
}

void Change_Account_Status(void)
{
	u8 State;
	
	while(1)
	{
		printf(" \n");
		printf("\n\t\tChange your account state to: \n");
		printf("\n\t\t1.Active                      press [1]\n");
		printf("\n\t\t2.Restricted                  press [2]\n");
		printf("\n\t\t2.Closed                      press [3]\n");
		printf("\n----------------------------------------------------------\n");
		printf("\n---> You Choice is: ");
		scanf("%u",&State);
	if (State==Active || State==Restricted || State==Closed)
	{
		Client[Account_index].Account_Status=State;
		printf("Done!\n");
		break;
	}	
	else
		printf("\nYou Have Entered Invalid Number\n");
	}
	Admin_Panel();

}

void Change_Account_Password_client(void)
{

	printf("\nPlease enter New Password : ");
	scanf("%u",&New_Password);
	printf("New password is: %u", New_Password);
	Client[Account_index].Password = New_Password;
	printf("\noperation is Done! your new password %u\n",Client[Account_index].Password);
	

}