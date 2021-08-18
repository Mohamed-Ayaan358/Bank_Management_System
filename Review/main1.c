#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "Header.h"

void close();
int j;

void menu()
{
    int choice;
    char password[10] = "pass";
    char check[10];
ch: system("cls");
    printf("\n\n");
    pprint(" ");
    printf("\b\b\b\b\b\bBANKING MANAGEMENT SYSTEM\n");
    printf("\n");
    pprint(" ");
    printf("\b\b\b\b\b\b\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\n");
    printf("\n");
    pprint(" ");
    printf("\b\b\b\b[1] Create a new account");//DONE
    printf("\n");
    pprint(" ");
    printf("\b\b\b\b[2] Update information of existing account"); //DONE
    printf("\n");
    pprint(" ");
    printf("\b\b\b\b[3] Transactions");
    printf("\n");
    pprint(" ");
    printf("\b\b\b\b[4] Check the details of existing account");
    printf("\n");
    pprint(" ");
    printf("\b\b\b\b[5] Remove existing account");
    printf("\n");
    pprint(" ");
    printf("\b\b\b\b[6] View customer's list"); //DONE       //MAYBE TRY OUT A UPI TRANSACTION SYSTEM
    printf("\n");
    pprint(" ");
    printf("\b\b\b\b[7] Exit\n");
    printf("\n");
    pprint(" ");
    printf("\b\b\b\bEnter your choice : ");
    scanf("%d", &choice);

    system("cls");
ret:
    switch (choice)
    {
    case 1:
        printf("Enter the password: ");
        scanf("%s", check);
        if (strcmp(check, password) == 0)
        {
            new_acc(); //Function to make accounts
        }
        else
        {
            printf("That was incorrect ");
            goto ret;
        }

        break;
    case 2:
        edit(); //Function to edit accounts
        break;
        /*
    case 3:
        transact(); //Function to view all transactions transactions
        break;*/

    case 4:
        printf("Enter the password: ");
        scanf("%s", check);
        if (strcmp(check, password) == 0)
        {
            see();
        }
        else
        {
            printf("That was incorrect "); //Function to view a list of accounts
            goto ret;
        }
        break; //Function to view a particular account

    case 5:
        printf("Enter the password: ");
        scanf("%s", check);
        if (strcmp(check, password) == 0)
        {
            delete (); //Function to remove accounts
        }
        else
        {
            printf("That was incorrect ");
            goto ret;
        } //Function to erase accounts
        break;
    case 6:
        printf("Enter the password: ");
        scanf("%s", check);
        if (strcmp(check, password) == 0)
        {
            view_list();
        }
        else
        {
            printf("That was incorrect "); //Function to view a list of accounts
            goto ret;
        }
        break;

    case 7:
        printf("Have a good day");
        Sleep(3000);
        //close(); //Function to close program
        break;

    default:
        printf("Please enter one of the following options");
        Sleep(5000);
        goto ch;
    }
}
int main()
{
    char cha;
    int ch;
lb: system("CLS");
    printf("\n\n");
    pprint(" ");
    printf("\b\b\b\b\b\b\xB2\xB2\xB2\xB2\xB2 WELCOME TO ANONYMOUS BANKING SYSTEMS \xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\n");
    pprint(" ");
    printf("\b\b\b\bCHOOSE YOUR MODE OF BANKING:\n");
    printf("\n");
    pprint(" ");
    printf("\b\b\b\b[1] BANK\n");
    pprint(" ");
    printf("\b\b\b\b[2] ONLINE BANKING\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        menu();
        break;

    case 2:
        online();
        break;

    default:
        printf("\n");
        pprint(" ");
        printf("\b\b\b\bPlease enter a valid option\n");
        Sleep(2000);
        goto lb;
    }
hk: printf("\n\n");
    pprint(" ");
    printf("\b\b\b\b\b\bWould you like to return to the main menu ? (y/n) ");
    scanf(" %c", &cha);
    if (cha == 'y' || cha == 'Y')
    {
        goto lb;
    }
    else if (cha == 'n' || cha == 'N')
    {
        return 0;
    }
    else
    {
        printf("\n");
        pprint(" ");
        printf("\b\b\b\b\b\bEnter a valid option.\n");
        goto hk;
    }
    return 0;
}
