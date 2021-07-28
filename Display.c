#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include "Header.h"

int display(char *x)
{
    FILE *f;
    f = fopen("online_rec.dat", "a+");
    int len = 0;
    char usernam[110], pass[9], accnt_no[11], ifsc_cd[14], upih[16], upip[9];
    float amnt, credit;
    amnt = credit = 0.000000;
    credit = 100000;
    system("CLS");
    while (fscanf(f, "%s %s %s %s %f %f %s %s\n", &usernam, &pass, &accnt_no, &ifsc_cd, &amnt, &credit, &upih, &upip) != EOF)
    {
        if (strcmp(x, usernam) == 0)
        {
            printf("\nAccount Details:\n");
            printf("\nUsername: %s", usernam);
            printf("\nAccount Number: %s", accnt_no);
            printf("\nIFSC Code: %s", ifsc_cd);
            printf("\nSavings Account Balance: Rupees %.2f", amnt);
            printf("\nReady Credit: Rupees %.2f", credit);
            printf("\nUPI Handler: %s\n", upih);
            printf("\nYou are required to login again.\n\n");
            system("pause");
            break;
        }
    }
    fclose(f);
    return 0; // Add condition for login in main
}
