/*#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "header.h"

int i, j;
int menu_exit;
int ki = 0, kip = 0;
void menu();
void close();

void delete (void)
{
    FILE *old, *newrec;
    int test = 0;
    old = fopen("record.dat", "r");
    newrec = fopen("del.dat", "w");
    printf("Enter the account number of the customer you want to delete:");
    scanf("%d", &rem.acc_no); /*
    while (fscanf(old, "%d %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        if (add.acc_no == update.acc_no)
        {
        pinredo:
            printf("\nEnter the pin of the account: ");
            scanf("%d", &rem.pin);
            if (add.pin == rem.pin)
            {
            }
            else
            {
                kip = kip + 1;
                if (kip != 3)
                {
                    printf("That was the incorrect pin");
                    Sleep(3000);
                    system("cls");
                    goto pinredo;
                }
                else if (kip == 3)
                {
                    printf("You have crossed the limit on the number of attempts");
                    Sleep(3000);
                    menu();
                }
            }
        }
        }
while (fscanf(old, "%d %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
{

    if (add.acc_no != rem.acc_no)
        fprintf(newrec, "%d %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year);

    else
    {
        test++;
        printf("\nRecord deleted successfully!\n");
    }
}

fclose(old);
fclose(newrec);
remove("record.dat");
rename("del.dat", "record.dat");
if (test == 0)
{
    system("cls");
    printf("\nThis account does not exist \n\a\a\a");
    ki = ki + 1;
    if (ki == 3)
    {
        printf("You have crossed the limit on the number of attempts");
        Sleep(3000);
        menu();
    }
invalid:
    printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
    scanf("%d", &menu_exit);

    if (menu_exit == 0)
        delete ();

    else if (menu_exit == 1)
        menu();
    else if (menu_exit == 2)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto invalid;
    }
}
else
{
    printf("\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &menu_exit);
    system("cls");
    if (menu_exit == 1)
        menu();
    else
        close();
}
}This code needs further work to improve the functionality
*/
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "header.h"

int i, j;
int menu_exit;
void menu();
void close();

void delete (void)
{
    FILE *old, *newrec;
    int test = 0;
    old = fopen("record.dat", "r");
    newrec = fopen("del.dat", "w");
    printf("Enter the account number of the customer you want to delete:");
    scanf("%d", &rem.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        if (add.acc_no != rem.acc_no)
            fprintf(newrec, "%d %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year);

        else
        {
            test++;
            printf("\nRecord deleted successfully!\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("del.dat", "record.dat");
    if (test == 0)
    {
        printf("\nRecord not found!!\a\a\a");
    invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &menu_exit);

        if (menu_exit == 0)
            delete ();

        else if (menu_exit == 1)
            menu();
        else if (menu_exit == 2)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &menu_exit);
        system("cls");
        if (menu_exit == 1)
            menu();
        else
            close();
    }
}