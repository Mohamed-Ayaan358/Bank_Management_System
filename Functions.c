#include "Header.h"
#include<Windows.h>
#include<stdio.h>

FILE *ptr;

void center_orient()
{
	printf("\t\t\t\t\t\t\t\t   ");
}

void pprint(char x)
{
	for (int i = 0; i < 285; i++)
	{
		printf("\n%c\n", x);
	}
}

int login()
{
lb:	system("CLS");
	printf("\nUsername: ");
	scanf("%s",&s.usernm);
	if (strcmp(s.usernm, s.usrnam) != 0)
	{
		s.count++;
		printf("\nUser does not exist.\n");
		Sleep(2000);
		if (s.count > 3)
		{
			system("cls");
			printf("\nNumber of tries exceeded. Please try again later.\n");
			printf("\nYou cannot perform any operations for 10 seconds.\n\n");
			Sleep(10000);
			system("pause");
		}
		goto lb;
	}
	s.count = 0;
	printf("\nPassword: ");
	scanf("%s",&s.pass);
	if ((strcmp(s.pass, s.pass_r)) == 0)
	{
		printf("\nSuccesfully logged in !\n");
	}
	else
	{
		s.count++;
		if (s.count <= 3)
		{
			printf("\nWrong Username or password, please try again.\n");
			Sleep(3000);
			goto lb;
		}
		else
		{
			system("cls");
			printf("\nNumber of tries exceeded. Please try again later.\n");
			printf("\nYou cannot perform any operations for 10 seconds.\n\n");
			Sleep(10000);
			system("pause");
			return 0;
		}
	}
}

int sign_up()
{
	ptr = fopen("record.dat", "ab+");
	s.count_2 = 0;
	system("cls");
	s.cred_bal = 100000;
	center_orient();
	printf("\b\bWelcome to ANONYMOUS BANKING SYSTEMS\n");
	printf("\nEnter your name: ");
	scanf("%s",&add.name);
	fprintf(ptr, "%s\n", add.name);
hl:	printf("\nSet a password to access online banking services: ");
	scanf("%s", &s.pass_r);
	fprintf(ptr, "%s\n", s.pass_r);
	s.len_4 = strlen(s.pass_r);
	if (s.len_4 > 8)
	{
		printf("\nThe password can be only 8 characteds long\n");
		goto hl;
	}
	printf("\nVerifying account details ....\n\n");
	Sleep(4000);
	printf("\t\t\t\t\t\t    Congrats !!!! Your account has been verified and succesfully created.\n");
hj: printf("\nEnter the amount of money you'd like to deposit - (minimum initial amount is Rupees 1000) : ");
	scanf("%lf", &add.amt);
	fprintf(ptr, "%lf\n", add.amt);
	if (add.amt < 1000)
	{
		printf("\nPlease deposit an amount more than Rupees 1000 to keep this account active.\n");
		goto hj;
	}
	system("cls");
	Sleep(3000);
	printf("\nAccount created !! Below are the details of your account.\n");
	strcat(s.usrnam, "ANYM");
	strcat(s.usrnam, add.name);
	printf("\nUsername: %s", s.usrnam);
	fprintf(ptr, "%s\n", s.usrnam);
	add.acc_no = (rand()% (8999999998)) + 1000000000;
	printf("\nAccount Number: %ld", add.acc_no);
	fprintf(ptr, "%ld\n", add.acc_no);
	strcpy(add.ifsc, "ANYM");
	s.ifs_cd = (rand() % (8999998)) + 1000000;
	//strcpy(s.ifsc_cd, s.ifs_cd); The integer isnt being converted to string, tried itoa(), and explicit type casting, fix if possible
	strcpy(add.ifsc, s.ifsc_cd);
	printf("\nIFSC Code: %s", add.ifsc);
	fprintf(ptr, "%d\n", s.ifsc_cd);
	printf("\nSavings Account Balance: %.2lf", add.amt);
	printf("\nReady Credit: %.2lf", s.cred_bal);
	fclose(ptr);
	return 0;
}

int UPI()
{
	ptr = fopen("record.dat", "ab+");
	if (s.count_2 == 0)
	{
		s.count_2++;
		system("cls");
	lj:	printf("Would you like to set up an UPI account ? (y/n)");
		scanf(" %c", &s.cha);
		if (s.cha == 'y' || s.cha == 'Y')
		{
			system("cls");
			printf("\nEnter your 10 digit mobile number: ");
			scanf("%s", &add.phone);
			fprintf(ptr, "%s", add.phone);
			strcpy(add.upih, "ANYM@");
			printf("\nUPI Handler : %s%s\n", add.upih, add.phone);
		jk:	printf("\nEnter a UPI password to secure your transactions: ");
			scanf("%s", &add.upip);
			fprintf(ptr, "%s\n", add.upip);
			s.len_3 = strlen(add.upip);
			if (s.len_3 != 6) //Add condition for- checking special characters in password
			{
				printf("\nMaximum length of password 6 characters\n");
				goto jk;
			}
			Sleep(3000);
			center_orient();
			printf("Your UPI Account has been created succesfully !\n");
			return 0;
		}
		else if (s.cha == 'n' || s.cha == 'N')
		{
			system("cls");
			printf("UPI account does not exist.\n\n");
			return 0;
		}
		else
		{
			printf("\nPlease enter a valid input.\n");
			goto lj;
		}
	}
	else
	{
		system("cls");
		printf("\nUPI Handler : %s%s\n", add.upih, add.phone);
	lb:	printf("\nChoose from the following options:\n1.Change Phone Number\n2.Change Password\n3.Return to main menu\n");
		scanf("%d", &s.ch_3);
		switch (s.ch_3)
		{
		case 1:
			system("cls");
			printf("Enter your previous phone number: ");
			scanf("%s", &s.ph_new);
			if (strcmp(s.ph_new, add.phone) == 0)
			{
				printf("\nEnter your new phone number: ");
				scanf("%s", &add.phone);
				fprintf(ptr, "%s\n", add.phone);
				Sleep(2000);
				center_orient();
				printf("Your phone number has been updates succefully !\n");
			}
			break;

		case 2:
			system("cls");
			s.count = 0;
		hk:	printf("Enter your previous password: ");
			scanf("%s", &s.upi_newp);
			if ((strcmp(s.upi_newp, add.upip)) == 0)
			{
				printf("\nEnter your new password: ");
				scanf("%s", &add.upip);
				fprintf(ptr, "%s\n", add.upip);
				Sleep(3000);
				center_orient();
				printf("Your password has been updated sucessfully !\n");
			}
			else
			{
				s.count++;
				if (s.count <= 3)
				{
					printf("\nWrong password entered, please try again.\n");
					Sleep(3000);
					goto hk;
				}
				else
				{
					system("cls");
					printf("\nNumber of tries exceeded. Please try again later.\n");
					printf("\nYou cannot perform any operations for 10 seconds.\n\n");
					Sleep(10000);
					system("pause");
					goto hk;
				}
			}
			break;

		case 3:
			dashboard();
			return 0;
			break;

		default:
			printf("\nPlease enter a valid option.\n");
			goto lb;
		}
	}
	printf("\n");
	system("pause");
hp:	printf("\nWould you like to return to the previous menu ? (y/n) ");
	scanf("  %c", &s.ch_8);
	if (s.ch_8 == 'y' || s.ch_8 == 'Y')
	{
		goto lb;
	}
	else if (s.ch_8 == 'n' || s.ch_8 == 'N')
	{
		return 0;
	}
	else
	{
		printf("\nEnter a valid option.\n");
		goto hp;
	}
	fclose(ptr);
}

int blnc_enq()
{
	system("cls");
	printf("Savings account: Rupees %.2lf", add.amt);
	if (s.cred_bal < 0)
	{
		printf("\nNo credit available. Renews next month"); //Add function for printing date of next month from today here
	}
	else
	{
		printf("\nReady credit: Rupees %.2lf\n", s.cred_bal);
	}
	return 0;
}

int NEFT_trans()
{
	ptr = fopen("record.dat", "ab+");
lh:	system("cls");
	printf("Choose from which account would you like to perform a NEFT transaction:\n1.Savings Account\n2.Current Account\n");
	scanf("%d", &s.ch_4);
	switch (s.ch_4)
	{
		case 1:
			system("cls");
			printf("Enter the name of the beneficiary: ");
			scanf("%s", &s.to_custnm);
		hj:	printf("\nEnter the beneficiary account number: ");
			scanf("%d", &s.to_accntno);
			/*
			s.len_5 = strlen((char)s.to_accntno);
			if (s.len_5 < 10)
			{
				printf("\nEnter a valid account number.\n");
				goto hj;
			}
			*/
		hk:	printf("\nEnter the beneficiary IFSC Code: ");
			scanf("%s", &s.to_ifscd);
			s.len_6 = strlen(s.to_ifscd);
			if (s.len_6 < 11)
			{
				printf("\nEnter a valid IFSC code.\n");
				goto hk;
			}
			printf("\nEnter the amount to be transferred: ");
			scanf_s("%lf", &s.to_amnt);
			if (s.to_amnt > (add.amt - 1000))
			{
				Sleep(3000);
				printf("\nLow account balance. Transaction Failed.\n");
				return 0;
			}
			else
			{
				add.amt -= s.to_amnt;
				Sleep(3000);
				center_orient();
				printf("Transcation Complete.\n");
				printf("\nBalance in Savings account: %.2lf\n", add.amt);
				fprintf(ptr, "%lf\n", add.amt);
				return 0;
			}
			break;

		case 2:
			system("cls");
			printf("Enter the name of the beneficiary: ");
			scanf("%s", &s.to_custnm);
		hl:	printf("\nEnter the beneficiary account number: ");
			scanf("%ld", &s.to_accntno);
			/*
			s.len_7 = strlen((char)s.to_accntno);
			if (s.len_7 < 10)
			{
				printf("\nEnter a valid account number.\n");
				goto hl;
			}
			*/
		hp:	printf("\nEnter the beneficiary IFSC Code: ");
			scanf("%s", &s.to_ifscd);
			s.len_8 = strlen(s.to_ifscd);
			if (s.len_8 < 11)
			{
				printf("\nEnter a valid IFSC code.\n");
				goto hp;
			}
			printf("\nEnter the amount to be transferred: ");
			scanf_s("%lf", &s.to_amnt);
			if (s.to_amnt > (s.cred_bal - 1000))
			{
				Sleep(3000);
				printf("\nLow account balance. Transaction Failed.\n");
				return 0;
			}
			else
			{
				s.cred_bal -= s.to_amnt;
				Sleep(3000);
				center_orient();
				printf("Transcation Complete.\n");
				printf("\nBalance in Current account: %.2lf\n", s.cred_bal);
				return 0;
			}
			break;

		default:
			printf("\nPlease enter a valid option\n");
			goto lh;
	}
	printf("\n");
	system("pause");
lb:	printf("\nWould you like to return to the previous menu ? (y/n) ");
	scanf("  %c", &s.ch_9);
	if (s.ch_9 == 'y' || s.ch_9 == 'Y')
	{
		goto lh;
	}
	else if (s.ch_9 == 'n' || s.ch_9 == 'N')
	{
		return 0;
	}
	else
	{
		printf("\nEnter a valid option.\n");
		goto lb;
	}
	fclose(ptr);
}

int UPI_trans()
{
	ptr = fopen("record.dat", "ab+");
	system("cls");
	/*
	printf("Enter the name of the beneficiary: ");
	scanf("%s", &s.to_upicustm);
hj:	printf("\nEnter the beneficiary account number: ");
	scanf("%d", &s.to_upiacntno);
	s.len_5 = strlen((char)s.to_accntno);
	if (s.len_5 < 10)
	{
		printf("\nEnter a valid account number.\n");
		goto hj;
	}
hk:	printf("\nEnter the beneficiary mobile number: ");
	scanf("%s", &s.to_phno);
	s.len_9 = strlen(s.to_ifscd);
	if (s.len_9 != 10)
	{
		printf("\nEnter a valid mobile number.\n");
		goto hk;
	}
	*/
	if (s.count_2 != 0)
	{
		printf("\nEnter the amount to be withdrawn: ");
		scanf_s("%lf", &s.to_amnt);
		printf("\nEnter your UPI password: ");
		scanf("%s", s.upi_passch);
		if (strcmp(s.upi_passch, add.upip) == 0)
		{
			if (s.to_amnt > (add.amt - 1000))
			{
				Sleep(3000);
				printf("\nLow account balance. Transaction Failed.\n");
				return 0;
			}
			else
			{
				add.amt -= s.to_amnt;
				Sleep(3000);
				center_orient();
				printf("Transcation Complete.\n");
				printf("\nBalance in Savings account: %.2lf\n", add.amt);
				fprintf(ptr, "%lf\n", add.amt);
				return 0;
			}
		}
		else
		{
			s.count_3++;
			printf("\nWrong UPI Password.\n");
			if (s.count_3 > 3)
			{
				printf("\nYou have exceeded the number of tries. You are being logged out.\n");
				login();
			}

		}
	}
	else
	{
	lb:	printf("\nNo UPI account found. Would you like to register for an UPI account ? (y/n) ");
		scanf("  %c", &s.chaa);
		if (s.chaa == 'y' || s.chaa == 'Y')
		{
			UPI();
		}
		else if (s.chaa == 'n' || s.chaa == 'N')
		{
			printf("\nSorry, you cannot make an UPI transaction without a UPI account.\n");
			return 0;
		}
		else
		{
			printf("\nEnter a valid option.\n");
			goto lb;
		}

	}
	fclose(ptr);
}

int account_detls()
{
	system("cls");
hk:	printf("Account Owner : %s", add.name);
	printf("\nMobile Number : %s", add.phone);
	printf("\nUPI Handler : %s%s", add.upih, add.phone);
	printf("\nTo view UPI Settings, navigate to the UPI section from the dashboard.\n");
	printf("\nChoose from the following options :\n1.Change Username\n2.Change password\n3.Return to the main menu\n");
	scanf("%d", &s.ch_5);
	switch (s.ch_5)
	{
		case 1:
			system("cls");
			printf("Enter the previous username : ");
			scanf("%s", &s.usrnm_ch);
			if (strcmp(s.usrnam, s.usrnm_ch) == 0)
			{
				printf("\nEnter a new username : ");
				scanf("%s", &s.usrnam);
				fprintf(ptr, "%s\n", s.usrnam);
				Sleep(3000);
				center_orient();
				printf("Username updated !\n");
			}
			else
			{
				s.count_4++;
				if (s.count_4 > 3)
				{
					printf("\nNumber of tries exceeded. You are being logged out.\n");
					login();
				}
			}
			break;

		case 2:
			system("cls");
			printf("Enter the previous password : ");
			scanf("%s", &s.pass_ch);
			if (strcmp(s.pass_ch, s.pass_r) == 0)
			{
			lb:	printf("\nEnter a new password : ");
				scanf("%s", &s.pass_r);
				fprintf(ptr, "%s\n", s.pass_r);
				s.len_10 = strlen(s.pass_r);
				if (s.len_10 > 8 || s.len_10 < 1)
				{
					printf("\nEnter a password of maximum 8 characters.\n");
					goto lb;
				}
				Sleep(3000);
				center_orient();
				printf("Password updated !\n");
				printf("\nYou are being logged out, and need to login again with the updated password.\n");
				Sleep(2000);
				login();
				dashboard();
			}
			else
			{
				s.count_5++;
				if (s.count_5 > 3)
				{
					printf("\nNumber of tries exceeded. You are being logged out.\n");
					login();
				}
			}
			break;

		case 3:
			dashboard();
			return 0;
			break;

		default:
			printf("\nPlease enter a valid option.\n");
			goto hk;
	}
	printf("\n");
	system("pause");
hl:	printf("\nWould you like to return to the previous menu ? (y/n) ");
	scanf("  %c", &s.ch_10);
	if (s.ch_10 == 'y' || s.ch_10 == 'Y')
	{
		goto hk;
	}
	else if (s.ch_10 == 'n' || s.ch_10 == 'N')
	{
		return 0;
	}
	else
	{
		printf("\nEnter a valid option.\n");
		goto hl;
	}
	fclose(ptr);
	return 0;
}

int dashboard()
{
hj:	system("cls");
	center_orient();
	printf("Welcome to your dashboard %s\n", add.name);
	printf("\nChoose from the available options:\n\n1.UPI Money Withdrawl\n2.NEFT Transaction\n3.Balance Enquiry\n4.UPI Details\n5.Account Details\n6.Log Out\n");
	scanf_s("%d", &s.ch_2);
	switch (s.ch_2)
	{
		case 1:
			UPI_trans();
			break;

		case 2:
			NEFT_trans();
			break;

		case 3:
			blnc_enq();
			break;

		case 4:
			UPI();
			break;

		case 5:
			account_detls();
			break;

		case 6:
			return 0;
			break;

		default:
			printf("\nEnter a valid option.\n");
			goto hj;
	}
	printf("\n");
	system("pause");
hk:	printf("\nWould you like to return to the main menu ? (y/n) ");
	scanf("  %c", &s.ch_6);
	if (s.ch_6 == 'y' || s.ch_6 == 'Y')
	{
		Sleep(2000);
		dashboard();
	}
	else if (s.ch_6 == 'n' || s.ch_6 == 'N')
	{
		goto lb;
	}
	else
	{
		printf("\nEnter a valid option.\n");
		goto hk;
	}
lb:	printf("\nWould you like to exit our systems ? (y/n) ");
	scanf( "  %c", &s.ch_7);
	if (s.ch_7 == 'y' || s.ch_7 == 'Y')
	{
		return 0;
	}
	else if (s.ch_7 == 'n' || s.ch_7 == 'N')
	{
		printf("\nReturning to the dashboard.\n");
		Sleep(2000);
		dashboard();
	}
	else
	{
		printf("\nEnter a valid option\n");
		goto lb;
	}
}
