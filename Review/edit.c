#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "header.h"

int i, j;
int menu_exit;
void menu();
void close();

void edit(void)
{
    int choice, test = 0;
    char agree[10];
    FILE *old, *editrec;
    old = fopen("record.dat", "r");
    editrec = fopen("edit.dat", "w");

    printf("\nEnter the account number of the customer whose critical information you want to change:");
    scanf("%d", &update.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %s %s %s %d %s %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.upih, &add.upip, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        if (add.acc_no == update.acc_no)
        {
            test = 1;
        redo:
            printf("\nWhich information do you want to change?\n[1] Name\n[2] Date_of_birth\n[3] Phone\n\n");
            printf("Enter choice:");
            scanf("%d", &choice);

            if (choice == 1)
            {
                printf("Your current Name is : %s\n", add.name);
            retry:
                printf("Are you sure you want to change your Name[Y/N]? ");
                scanf("%s", agree);
                if (strcmp(agree, "Y") == 0)
                {
                    printf("Enter you new Name : ");
                    scanf("%s", &update.name);
                    fprintf(editrec, "%d %s %d/%d/%d %s %s %s %d %s %s %f %d/%d/%d\n", add.acc_no, update.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, add.upih, add.upip, add.pin, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                    system("cls");
                    printf("Changes saved!");//Put pin option here and keep error limit to 3
                }
                else if (strcmp(agree, "N") == 0)
                {
                    goto redo;
                }
                else
                {
                    printf("This entry is invalid\n");
                    goto retry;
                }
            }
            else if (choice == 2)
            {
                printf("Your current Date_of_birth : %d/%d/%d \n", add.dob.day, add.dob.month, add.dob.year);
                printf("Are you sure you want to change your Date_of_birth[Y/N]? ");
                scanf("%s", agree);
                if (strcmp(agree, "Y") == 0)
                {
                    printf("Enter you new Date_of_birth : ");
                    scanf("%d/%d/%d", &update.dob.day, &update.dob.month, &update.dob.year);
                    fprintf(editrec, "%d %s %d/%d/%d %s %s %s %d %s %s %f %d/%d/%d\n", add.acc_no, add.name, update.dob.day, update.dob.month, update.dob.year, add.ifsc, add.upih, add.upip, add.pin, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                    system("cls");
                    printf("Changes saved!");
                }
                else if (strcmp(agree, "N") == 0)
                {
                    goto redo;
                }
                else
                {
                    printf("This entry is invalid\n");
                    goto retry;
                }
            }
            else if (choice == 3)
            {
                printf("Your current Phone number: %s\n", add.phone);
                printf("Are you sure you want to change your Phone number[Y/N]? ");
                scanf("%s", agree);
                if (strcmp(agree, "Y") == 0)
                {
                    printf("Enter you edit Phone number: ");
                    scanf("%s", &update.phone);
                    fprintf(editrec, "%d %s %d/%d/%d %s %s %s %d %s %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, add.upih, add.upip, add.pin, update.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                    system("cls");
                    printf("Changes saved!");
                }
                else if (strcmp(agree, "N") == 0)
                {
                    goto redo;
                }
                else
                {
                    printf("This entry is invalid\n");
                    goto retry;
                }
            }
        }

        else
            fprintf(editrec, "%d %s %d/%d/%d %s %s %s %d %s %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, add.upih, add.upip, add.pin, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
    }
    fclose(old);
    fclose(editrec);
    remove("record.dat");
    rename("edit.dat", "record.dat");

    if (test != 1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
    edit_error:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &menu_exit);
        system("cls");
        if (menu_exit == 0)
            edit();
        else if (menu_exit == 1)
            menu();
        else if (menu_exit == 2)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto edit_error;
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
