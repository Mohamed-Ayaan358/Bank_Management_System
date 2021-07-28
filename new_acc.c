#include <windows.h>
#include <stdio.h>
#include <time.h>
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
    FILE* ptr;
    srand(time(0));
    ptr = fopen("record.dat", "a+");
    system("cls"); /*It clears out the cmd page*/

    printf("\t\t\t==== ADD RECORD  ====");
account_no:
    check.acc_no = (rand() % (9000000000)) + 1000000000;

    while (fscanf(ptr, "%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF) /*fscanf is used to read data from a particular file in this case ptr*/
    {
        if (check.acc_no == add.acc_no)
        {
            printf("Account number already in use!");
            Sleep(3000);
            goto account_no; /*Allows for jump to account_No if number does not exist*/
        }
    }
    add.acc_no = check.acc_no;
    add.pin = (rand() % (9000)) + 1000;
    printf("\n\n\n Enter today's date(dd/mm/yyyy):");
    scanf("%d/%d/%d", &add.deposit.day, &add.deposit.month, &add.deposit.year);
    printf("\n Enter the name:");
    scanf("%s", add.name);
    printf("\n Enter the date of birth(dd/mm/yyyy): ");
    scanf("%d/%d/%d", &add.dob.day, &add.dob.month, &add.dob.year);
    system("cls"); /*
    printf("\n Enter the IFSC code: ");
    scanf("%s", add.ifsc);*/

    char a[50] = "ANYM";
    char c[12];
    long long int b = (rand() % (90000000)) + 10000000;
    sprintf(c, "%lld", b);
    strcat(a, c);
    strcpy(add.ifsc, a);

    printf("\n Enter the phone number: ");
    scanf("%s", &add.phone);
    printf("\n Enter the amount to deposit: ");
    scanf("%f", &add.amt);
    char ch[20];
    printf("\nType of account:\n\t#Saving[S]\n\t#Current[C]\n\t#Fixed1(for 1 year)[F1]\n\t#Fixed2(for 2 years)[F2]\n\t#Fixed3(for 3 years)[F3]\n\n\tEnter your choice:");
    scanf("%s", ch);
    if (strcmp(ch, "S") == 0)
    {
        strcpy(add.acc_type, "Saving");
    }
    else if (strcmp(ch, "C") == 0)
    {
        strcpy(add.acc_type, "Current");
    }
    else if (strcmp(ch, "F1") == 0)
    {
        strcpy(add.acc_type, "Fixed1");
    }
    else if (strcmp(ch, "F2") == 0)
    {
        strcpy(add.acc_type, "Fixed2");
    }
    else if (strcmp(ch, "F3") == 0)
    {
        strcpy(add.acc_type, "Fixed3");
    }
    fprintf(ptr, "%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, add.pin, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);

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
