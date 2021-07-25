#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include "Header.h"

int sign_up()
{
    FILE *ptr;
    FILE *f;
    ptr = fopen("record.dat", "a+");
    f = fopen("online_rec.dat", "a+");
    int len, count;
    len = count = 0;
	char name[100], usernam[110], pass[9], accnt_no[11], ifsc_cd[12], upih[16], upip[9];
    float amnt, credit;
    amnt = credit = 0.000000;
    credit = 100000;
    strcpy(upih, "NA");
    strcpy(upip, "NA");
    system("CLS");
	printf("\nEnter your name: ");
	scanf("%s", &name);
    while (fscanf(ptr, "%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        if (strcmp(name, add.name) == 0)
        {
            sprintf(accnt_no, "%ld", add.acc_no);
            strcpy(ifsc_cd, add.ifsc);
            amnt = add.amt;
        }
        else
        {
            // Add account doesnt exist statement outside while loop, for now count is being used 
            count++;
        }
    }
    if (count >= 3)
    {
        printf("\nAccount doesnt exist. Please create an account with the bank first.\n");
        return 1;
    }
    strcpy(usernam, "ANYM@");
    strcat(usernam, name);
 lb:printf("\nEnter a password to secure your account: ");
    scanf("%s", &pass);
    len = strlen(pass);
    if (len > 8)
    {
        printf("\nMaximum length of password is 8 digits. Please enter a valid password.\n");
        goto lb;
    }
    printf("\nCreating account....\n");
    Sleep(3000);
    printf("\nAccount created successfully\n\n");
    Sleep(3000);
    system("CLS");
    printf("\nAccount Details:\n");
    printf("\nUsername: %s", usernam);
    printf("\nAccount Number: %s", accnt_no);
    printf("\nIFSC Code: %s", ifsc_cd);
    printf("\nSavings Account Balance: Rupees %.2f", amnt);
    printf("\nReady Credit: Rupees %.2f", credit);
    printf("\nUPI Handler: %s\n", upih);
    printf("\nYou are required to login again.\n\n");
    system("pause");
    // display(&usernam[0]); Display function not being called, fix it
    fprintf(f, "%s %s %s %s %.2f %.2f %s %s\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n", usernam, pass, accnt_no, ifsc_cd, amnt, credit, upih, upip);
    count_lines++;
    fclose(ptr);
    fclose(f);
    return 0;
}
