#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "header.h"

int i, j;
int kicker = 0, kp = 0;
int menu_exit;
void menu();
void close();

void see(void)
{
    int choice, test = 0;
    char agree[10];
    FILE *old;
    old = fopen("record.dat", "r");
    printf("\nEnter the account number of the customer whose critical information you want to change:");
    scanf("%ld", &update.acc_no);
    while (fscanf(old, "%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        if (add.acc_no == update.acc_no)
        {
        pinredo:
            printf("\nEnter the pin of the account: \n");
            scanf("%d", &update.pin);
            if (add.pin == update.pin)
            {
                test = 1;
                //printf("%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, add.pin, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                printf("Account number : %lld\n", add.acc_no);
                printf("Name of account holder : %s\n", add.name);
                printf("Date of birth of account holder : %d/%d/%d\n", add.dob.day, add.dob.month, add.dob.year);
                printf("IFSC of account holder : %s\n", add.ifsc);
                printf("Pin of account holder : %d\n", add.pin);
                printf("The phone number of the account holder : %s\n", add.phone);
                printf("The account type of the account holder : %s\n", add.acc_type);
                printf("The amount of the account holder : %f\n", add.amt);
                printf("Date of deposit of account holder : %d/%d/%d\n", add.deposit.day, add.deposit.month, add.deposit.year);
            }
            else
            {
                kp = kp + 1;
                if (kp != 3)
                {
                    printf("That was the incorrect pin");
                    Sleep(3000);
                    system("cls");
                    goto pinredo;
                }
                else if (kp == 3)
                {
                    printf("You have crossed the limit on the number of attempts");
                    Sleep(3000);
                    menu();
                }
            }
        }
    }
    fclose(old);
    if (test != 1)
    {
        system("cls");
        printf("\nThis account does not exist \a\a\a");
        kicker = kicker + 1;
        if (kicker == 3)
        {
            printf("You have crossed the limit on the number of attempts");
            Sleep(3000);
            menu();
        }
    see_error:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &menu_exit);
        system("cls");
        if (menu_exit == 0)
            see();
        else if (menu_exit == 1)
            menu();
        else if (menu_exit == 2)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto see_error;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &menu_exit);
        system("cls");
        if (menu_exit == 1)
        {
            menu();
        }
        else if (menu_exit == 0)
        {
            close();
        }
    }
}
