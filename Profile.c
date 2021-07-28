#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include "Header.h"

int profile(char* x)
{
    FILE* f;
    f = fopen("online_rec.dat", "a+");
    int count, count_2, count_3, count_4, len, cha, len_1, d, h1, d2;
    count = count_2 = count_3 = count_4 = len = cha = d = d2 = 0;
    char ch, name[100], usernam[110], pass[9], accnt_no[11], ifsc_cd[14], phone_1[11], upih[16], upip[9], new_upih[16], new_upip[9], upih_2[16], upip_2[9], temp_accno[12], temp_accno2[12];
    char to_name[100], to_accnt_no[11], to_ifsc_cd[14];
    float amnt, amnt_2, credit, upi_amnt, new_amnt, new_credit;
    amnt = amnt_2 = credit = upi_amnt = new_amnt = new_credit = 0.000000;
    credit = 100000;
    float to_amnt = 0.000000;
    system("CLS");
    while (fscanf(f, "%s %s %s %s %f %f %s %s\n", &usernam, &pass, &accnt_no, &ifsc_cd, &amnt, &credit, &upih, &upip) != EOF)
    {
        if (strcmp(usernam, x) == 0)
        {
            printf("\n\n");
            pprint(" ");
            printf("\b\b\b\b\b\bAccount Details:\n");
            printf("\n");
            pprint(" ");
            printf("\b\b\b\b\b\bUsername: %s", usernam);
            printf("\n");
            pprint(" ");
            printf("\b\b\b\b\b\bAccount Number: %s", accnt_no);
            printf("\n");
            pprint(" ");
            printf("\b\b\b\b\b\bIFSC Code: %s", ifsc_cd);
            printf("\n");
            pprint(" ");
            printf("\b\b\b\b\b\bSavings Account Balance: Rupees %.2f", amnt);
            printf("\n");
            pprint(" ");
            printf("\b\b\b\b\b\bReady Credit: Rupees %.2f", credit);
            printf("\n");
            pprint(" ");
            printf("\b\b\b\b\b\bUPI Handler: %s\n", upih);
            printf("\n");
            pprint(" ");
            printf("\b\b\b\b\b\b");
            system("pause");
            break;
        }
    }
    return 0;
}
