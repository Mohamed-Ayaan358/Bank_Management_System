#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "header.h"

void menu()
{
    int choice;
    char password[10] = "pass";
    char check[10];
    system("cls");

    printf("\n\n\t\t\t\t\t\t\t      BANKING MANAGEMENT SYSTEM");
    printf("\n\n\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t[1] Create a new account");
    printf("\n\t\t[2] Update information of existing account");
    printf("\n\t\t[3] Transactions\n\t\t[4] Check the details of existing account");
    printf("\n\t\t[5] Remove existing account\n\t\t[6] View customer's list");
    printf("\n\t\t[7] ATM Feature");
    printf("\n\t\t[8] Exit");

    printf("\n\n\t\t Enter your choice : ");
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
        transact(); //Function to complete transactions
        break;
    case 4:
        see(); //Function to view a particular account
        break;
    case 5:
        erase(); //Function to erase accounts
        break;*/
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
        /*
    case 7:
        close(); //Function to close program
        break;
    }
    */
    }
}
int main()
{
    menu();
    return 0;
}