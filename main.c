

 /*======================================================================================
===========================   - Main.c			 ===========================
===========================   - Created:01/09/2022			 ===========================
===========================   - Author: Abdelrahman_Kandil   ===========================
===========================   - Version : _1_				 ===========================
===========================   - Note :
									  *-
									  *-
 ======================================================================================*/ 
 /***
 *      __  __          _____ _   _        ______ _____ _      ______     _____ 
 *     |  \/  |   /\   |_   _| \ | |      |  ____|_   _| |    |  ____|   / ____|
 *     | \  / |  /  \    | | |  \| |      | |__    | | | |    | |__     | |     
 *     | |\/| | / /\ \   | | | . ` |      |  __|   | | | |    |  __|    | |     
 *     | |  | |/ ____ \ _| |_| |\  |      | |     _| |_| |____| |____   | |____ 
 *     |_|  |_/_/    \_\_____|_| \_|      |_|    |_____|______|______| (_)_____|
 *                                                                              
 *                                                                              
 */
/*===========  Include HEADER FILE USED IN PROJECT ===========*/
 #include"Bank.h"
 
/*===========  Global Variables  ===========*/
New_Account_t Client[1000];
u16 Number_Of_Accounts=0;
u8 counter=0;
u16 Account_index = 0;
u32 ID_Number;
u16 Client_Password;
u16 New_Password;
u8 intro_c=0;
int main (void)
{

	 Admin_t Admin1={"Abdelrahman","123"};
	 Admin_t Admin2={"ITI","123"};
	 Admin_t Admin_from_user;
	 EStatus_t Status;

	u8 HelloChoise ;
	u8 System_Flag = 1;
	u8 i =0;
	u8 z;
	u8 check=0;
		system("color 0a");
		system("cls");
	if (intro_c ==0)
	{
		intro();
		intro_c++;
		system("cls");
	}
	BankWellcome();
	u8 Choise4;
	scanf("%i",&HelloChoise);
	fflush(stdin);
	do {
		
	
	switch(HelloChoise)
{
	case  _ADMIN_CHOICE_ :
	for ( i =0; i<_MAX_INPUT_TRYS_; i++)
	{
		printf("\nUsername : ");
		scanf("%s",&Admin_from_user.username);
		fflush(stdin);
		printf("Password : ");
		scanf("%s",&Admin_from_user.password);
				fflush(stdin);

		if(((USER_PASS_CHECK(Admin1.username,Admin_from_user.username))&&USER_PASS_CHECK(Admin1.password,Admin_from_user.password))||((USER_PASS_CHECK(Admin2.username,Admin_from_user.username))&& USER_PASS_CHECK(Admin2.password,Admin_from_user.password)))
		{
			printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2      WELCOME %s     \xB2\xB2\xB2\xB2\xB2\xB2\xB2",Admin_from_user.username);
			System_Flag = 0 ;
			break;
		}
		else 
		{
			if(i<_MAX_INPUT_TRYS_ -1 || i<_MAX_INPUT_TRYS_ -2 || i< _MAX_INPUT_TRYS_-3 || i<_MAX_INPUT_TRYS_-4)
			{
				fflush(stdin);
				printf("\nError : Wrong username or password Please Try again bearing in mind that you only have %i attempts to enter Please Run Program Again\n\n",_MAX_INPUT_TRYS_-i-2);	
			}
		}
	}
	if(i==_MAX_INPUT_TRYS_ )
	{
		fflush(stdin);

		printf("\n Error : Closing Program,Maximum Limit Wrong Username/Password please Call The Bank\n");
				exit(0);
	}
		Admin_Panel();

		break;
		case _CLEINT_CHOICE_:
			printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO CLIENT  WINDOW \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			printf("\nplease enter Account ID Number: ");
			scanf("%u",&ID_Number);
			printf("\nplease enter Account Password: ");
			scanf("%u",&Client_Password);
			
			for (z=0;z<Number_Of_Accounts;++z)
			{
				if (Client[z].Bank_Account_ID==ID_Number && Client[z].Password==Client_Password)
				{
					Account_index=z;
					check = 1;
					break;
				}
			}
			if (check!=1)
			{
				
				printf("\nyou've enter invalid ID or password\n");
				printf(" \n");
				printf("\n\t\tChoose one of the following options: \n");
				printf("\n\t\t1.Return to the main menu     			 press [1]\n");
				printf("\n\t\t2.exit system     		     		 press [2]\n");
				printf("\n----------------------------------------------------------\n");
				printf("\n---> You Choice is: ");
				scanf("%d",&Choise4);
				printf("\n");
				if (Choise4 == 1)
				{
					main();
				}
				if (Choise4 == 2)
				{
					System_Flag = 0;
					exit(0);
				}
			}
		Client_Panel();
		break;
		case _EXIT_:
		printf("\n-------------------------------- Close The Program !! !!--------------------------------\n");
		System_Flag = 0;
		exit(0);
		break;
		default:
		printf("\n\t\t\tWrong Choice .. GoodBye ....");
		exit(0);
}
	}while(System_Flag != 0);



	return 0 ;
}