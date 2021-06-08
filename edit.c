#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int i, j;
int menu_exit;
void menu();
int atm();
void close();
struct date
{
    int month, day, year;
};
struct
{

    char name[60];
    int acc_no;
    int pin;
    char ifsc[60];
    char upih[30];
    char upip[30];
    char acc_type[10];
    double phone;
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

} add, update; /*Allows you to refer to the struct using different access points*/

void edit(void)
{
    int choice, test = 0;
    char agree[10];
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d", &update.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %s %s %s %d %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.upih, &add.upip, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        if (add.acc_no == update.acc_no)
        {
            test = 1;
        redo:
            printf("\nWhich information do you want to change?\n[1] UPI_Handler\n[2]UPI_Password\n[3] Phone\n\n");
            printf("Enter choice:");
            scanf("%d", &choice);

            //CONSTRUCTION IN PROGRESS PLEASE DO NOT EXECUTE THIS FILE
            if (choice == 1)
            {
                printf("Your current UPI_Handler : %s\n", add.upih);
            retry:
                printf("Are you sure you want to change your upi handler[Y/N]? ");
                scanf("%s", agree);
                if (strcmp(agree, "Y") == 0)
                {
                    printf("Enter you new UPI handler : ");
                    scanf("%s", update.upih);
                    fprintf(newrec, "%d %s %d/%d/%d %s %s %s %d %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, update.upih, add.upip, add.pin, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                    system("cls");
                    printf("Changes saved!");
                }
                else if (strcmp(agree, "N") == 0)
                {
                    goto redo;
                }
                else
                {
                    printf("This entry is invalid");
                    goto retry;
                }
            }
            else if (choice == 2)
            {
                printf("Your current UPI_password : %s\n", add.upip);
                printf("Are you sure you want to change your upi password[Y/N]? ");
                scanf("%s", agree);
                if (strcmp(agree, "Y") == 0)
                {
                    printf("Enter you new UPI password : ");
                    scanf("%s", update.upip);
                    fprintf(newrec, "%d %s %d/%d/%d %s %s %s %d %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, add.upih, update.upip, add.pin, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                    system("cls");
                    printf("Changes saved!");
                }
                else if (strcmp(agree, "N") == 0)
                {
                    goto redo;
                }
                else
                {
                    printf("This entry is invalid");
                    goto retry;
                }
            }
            else if (choice == 3)
            {
                printf("Your current Phone : %lf\n", add.phone);
                printf("Are you sure you want to change your upi password[Y/N]? ");
                scanf("%s", agree);
                if (strcmp(agree, "Y") == 0)
                {
                    printf("Enter you new Phone : ");
                    scanf("%lf", &update.phone);
                    fprintf(newrec, "%d %s %d/%d/%d %s %s %s %d %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, add.upih, add.upip, add.pin, update.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                    system("cls");
                    printf("Changes saved!");
                }
                else if (strcmp(agree, "N") == 0)
                {
                    goto redo;
                }
                else
                {
                    printf("This entry is invalid");
                    goto retry;
                }
            }
        }

        else
            fprintf(newrec, "%d %s %d/%d/%d %s %s %s %d %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, add.upih, add.upip, add.pin, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

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
