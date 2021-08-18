#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "header.h"

int i, j;
int kick = 0, kickpin = 0;
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
    scanf("%ld", &update.acc_no);
    while (fscanf(old, "%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        if (add.acc_no == update.acc_no)
        {
        pinredo:
            printf("\nEnter the pin of the account: ");
            scanf("%d", &update.pin);
            if (add.pin == update.pin)
            {
                test = 1;
            redo:
                printf("\nWhich information do you want to change?\n[1] Name\n[2] Date_of_birth\n[3] Phone\n[4] Pin\n\n");
                printf("Enter choice:");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    printf("Your current Name is : %s\n", add.name);
                retryn:
                    printf("Are you sure you want to change your Name[Y/N]? ");
                    scanf("%s", agree);
                    if (strcmp(agree, "Y") == 0 || strcmp(agree, "y") == 0)
                    {
                        printf("Enter your new Name : ");
                        scanf("%s", &update.name);
                        fprintf(editrec, "%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", add.acc_no, update.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, add.pin, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                        system("cls");
                        printf("Changes saved!");
                    }
                    else if (strcmp(agree, "N") == 0 || strcmp(agree, "n") == 0)
                    {
                        goto redo;
                    }
                    else
                    {
                        printf("This entry is invalid\n");
                        goto retryn;
                    }
                }
                else if (choice == 2)
                {
                    printf("Your current Date_of_birth : %d/%d/%d \n", add.dob.day, add.dob.month, add.dob.year);
                retrydob:
                    printf("Are you sure you want to change your Date_of_birth[Y/N]? ");
                    scanf("%s", agree);
                    if (strcmp(agree, "Y") == 0 || strcmp(agree, "y") == 0)
                    {
                        printf("Enter your new Date_of_birth : ");
                        scanf("%d/%d/%d", &update.dob.day, &update.dob.month, &update.dob.year);
                        fprintf(editrec, "%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", add.acc_no, add.name, update.dob.day, update.dob.month, update.dob.year, add.ifsc, add.pin, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                        system("cls");
                        printf("Changes saved!");
                    }
                    else if (strcmp(agree, "N") == 0 || strcmp(agree, "n") == 0)
                    {
                        goto redo;
                    }
                    else
                    {
                        printf("This entry is invalid\n");
                        goto retrydob;
                    }
                }
                else if (choice == 3)
                {
                    printf("Your current Phone number: %s\n", add.phone);
                retryphone:
                    printf("Are you sure you want to change your Phone number[Y/N]? ");
                    scanf("%s", agree);
                    if (strcmp(agree, "Y") == 0 || strcmp(agree, "y") == 0)
                    {
                        printf("Enter you new Phone number: ");
                        scanf("%s", &update.phone);
                        fprintf(editrec, "%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, add.pin, update.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                        system("cls");
                        printf("Changes saved!");
                    }
                    else if (strcmp(agree, "N") == 0 || strcmp(agree, "n") == 0)
                    {
                        goto redo;
                    }
                    else
                    {
                        printf("This entry is invalid\n");
                        goto retryphone;
                    }
                }
                else if (choice == 4)
                {
                    printf("Your current Phone number: %d\n", add.pin);
                retrypin:
                    printf("Are you sure you want to change your Pin[Y/N]? ");
                    scanf("%s", agree);
                    if (strcmp(agree, "Y") == 0 || strcmp(agree, "y") == 0)
                    {
                        printf("Enter your new Pin  ");
                        scanf("%d", &update.pin);
                        fprintf(editrec, "%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, update.pin, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                        system("cls");
                        printf("Changes saved!");
                    }
                    else if (strcmp(agree, "N") == 0 || strcmp(agree, "n") == 0)
                    {
                        goto redo;
                    }
                    else
                    {
                        printf("This entry is invalid\n");
                        goto retrypin;
                    }
                }
            }
            else
            {
                kickpin = kickpin + 1;
                if (kickpin != 3)
                {
                    printf("That was the incorrect pin");
                    Sleep(3000);
                    system("cls");
                    goto pinredo;
                }
                else if (kickpin == 3)
                {
                    printf("You have crossed the limit on the number of attempts");
                    Sleep(3000);
                    menu();
                }
            }
        }

        else
            fprintf(editrec, "%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, add.pin, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
    }
    fclose(old);
    fclose(editrec);
    remove("record.dat");
    rename("edit.dat", "record.dat");

    if (test != 1) //Used to say accnt does not even exist
    {
        system("cls");
        printf("\nThis account does not exist \a\a\a");
        kick = kick + 1;
        if (kick == 3)
        {
            printf("You have crossed the limit on the number of attempts");
            Sleep(3000);
            menu();
        }
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
