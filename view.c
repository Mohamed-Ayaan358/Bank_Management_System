#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "header.h"

int i, j;
int menu_exit;
void menu();
void close();

void view_list()
{
    FILE *view;
    view = fopen("record.dat", "r");
    int test = 0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t ACCOUNT_TYPE\t\t\tPHONE\n");
    while (fscanf(view, "%d %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        printf("\n%6d\t %10s\t\t%10s \t\t\t%s", add.acc_no, add.name, add.acc_type, add.phone);
        test++;
    }
    fclose(view);
    if (test == 0)
    {
        system("cls");
        printf("\nNO RECORDS!!\n");
    }

view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &menu_exit);
    system("cls");
    if (menu_exit == 1)
        menu();
    else if (menu_exit == 0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto view_list_invalid;
    }
}
