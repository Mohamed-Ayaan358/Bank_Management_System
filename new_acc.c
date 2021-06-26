#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "header.h"

int i, j;
int menu_exit;
void menu();
void close();

void new_acc()
{
    int choice;
    FILE *ptr;

    ptr = fopen("record.dat", "a+");
    system("cls"); /*It clears out the cmd page*/

    printf("\t\t\t==== ADD RECORD  ====");
    printf("\n\n\n Enter today's date(dd/mm/yyyy):");
    scanf("%d/%d/%d", &add.deposit.day, &add.deposit.month, &add.deposit.year);
account_no:
    printf("\n Enter the account number:");
    scanf("%d", &check.acc_no);

    while (fscanf(ptr, "%d %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    /*fscanf is used to read data from a particular file in this case ptr*/
    {
        if (check.acc_no == add.acc_no)
        {
            printf("Account number already in use!");
            Sleep(3000);
            goto account_no; /*Allows for jump to account_No if number does not exist*/
        }
    }
    add.acc_no = check.acc_no;
    printf("\n Enter a 4 digit pin:");
    scanf("%d", &add.pin);
    printf("\n Enter the name:");
    scanf("%s", add.name);
    printf("\n Enter the date of birth(dd/mm/yyyy): ");
    scanf("%d/%d/%d", &add.dob.day, &add.dob.month, &add.dob.year);
    system("cls");
    printf("\n Enter the IFSC code: ");
    scanf("%s", add.ifsc);
    printf("\n Enter the phone number: ");
    scanf("%s", &add.phone);
    printf("\n Enter the amount to deposit: ");
    scanf("%f", &add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s", add.acc_type);

    fprintf(ptr, "%d %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, add.pin, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);

    fclose(ptr);
    printf("\nAccount created successfully");
add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &menu_exit);
    system("cls");
    if (menu_exit == 1)
        menu();
    else if (menu_exit == 0)
        close(); /*It deallocates the file and stops the program*/
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}