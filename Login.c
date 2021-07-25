#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include "Header.h"


char *login()
{
    FILE *f;
    f = fopen("online_rec.dat", "a+");
    char usernam[110], pass[9], accnt_no[11], ifsc_cd[12], upih[16], upip[9];
    int count = 0;
    float amnt, credit;
    amnt = credit = 0.000000;
    credit = 100000;
    system("CLS");
	char usernm[100], pass_ch[9];
	printf("\nUsername: ");
	scanf("%s", &usernm);
    while (fscanf(f, "%s %s %s %s %f %f %s %s\n", &usernam, &pass, &accnt_no, &ifsc_cd, &amnt, &credit, &upih, &upip) != EOF)
    {
        if (strcmp(usernam, usernm) == 0)
        {
        lb: printf("\nPassword: ");
            scanf("%s", &pass_ch);
            if (strcmp(pass_ch, pass) == 0)
            {
                printf("\nSuccessfully logged in.\n");
                strcpy(usrnm, usernam);
                return &usrnm[0];
            }
            else
            {
                printf("\nWrong username or password entered. Please try again.\n");
                goto lb;
            }
        }
        else
        {
            // Add user does not exist statement outside while loop, for now count is being used
            count++;
        }
    }
    if (count >= count_lines)
    {
        printf("\nUser does not exist\n");
        return 0;
    }
    fclose(f);
}
