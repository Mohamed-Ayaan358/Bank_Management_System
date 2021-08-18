#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include "Header.h"


char *login()
{
    FILE *f;
    char ch;
    int count_lns = 0;
    f = fopen("online_rec.dat", "r");
    while ((ch = fgetc(f)) != EOF)
    {
        if (ch == '\n')
        {
            count_lns++;
        }
    }
    f = fopen("online_rec.dat", "a+");
    char usernam[110], pass[9], accnt_no[11], ifsc_cd[14], upih[16], upip[9];
    int count = 0;
    float amnt, credit;
    amnt = credit = 0.000000;
    credit = 100000;
    system("CLS");
	char usernm[100], pass_ch[9];
    printf("\n\n");
    pprint(" ");
	printf("\b\b\b\bUSERNAME: ");
	scanf("%s", &usernm);
    while (fscanf(f, "%s %s %s %s %f %f %s %s\n", &usernam, &pass, &accnt_no, &ifsc_cd, &amnt, &credit, &upih, &upip) != EOF)
    {
        if (strcmp(usernam, usernm) == 0)
        {
        lb: pprint(" ");
            printf("\b\b\b\bPASSWORD: ");
            scanf("%s", &pass_ch);
            if (strcmp(pass_ch, pass) == 0)
            {
                printf("\n");
                pprint(" ");
                printf("\b\b\b\bSuccessfully logged in.\n");
                Sleep(3000);
                strcpy(usrnm, usernam);
                return &usrnm[0];
            }
            else
            {
                pprint(" ");
                printf("\b\b\b\bWrong username or password entered. Please try again.\n\n");
                goto lb;
            }
        }
        else
        {
            // Add user does not exist statement outside while loop, for now count is being used
            count++;
        }
    }
    if (count >= count_lns)
    {
        pprint(" ");
        printf("\b\b\b\bUser does not exist\n");
        return 0;
    }
    fclose(f);
}
