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

} add, update, check, rem, transact; /*Allows you to refer to the struct using different access points*/

void edit(void)
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d", &update.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %s %s %s %pin %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.upih, &add.upip, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        test = 1;
        printf("\nWhich information do you want to change?\n[1] UPI_Handler\n[2] Phone\n[3] UPI_Password\n\n");
        printf("Enter choice:");
        scanf("%d", &choice);

        //CONSTRUCTION IN PROGRESS PLEASE DO NOT EXECUTE THIS FILE
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if (test != 1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
    edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &menu_exit);
        system("cls");
        if (menu_exit == 0)
            edits();
        else if (menu_exit == 1)
            main();
        else if (menu_exit == 2)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &menu_exit);
        system("cls");
        if (menu_exit == 1)
            menu();
        else
            close();
    }
}
