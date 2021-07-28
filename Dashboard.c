#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include "Header.h"

int dashboard(char *x)
{
    int ch = 0;
    char cha;
lb: system("CLS");
    printf("\n\n");
    pprint(" ");
    printf("\b\b\b\b\b\b\b\b\xB2\xB2\xB2\xB2\xB2 CHOOSE FROM THE FOLLOWING OPTIONS: \xB2\xB2\xB2\xB2\xB2\n\n");
    pprint(" ");
    printf("\b\b\b\b[1] UPI\n");
    pprint(" ");
    printf("\b\b\b\b[2] NEFT\n");
    pprint(" ");
    printf("\b\b\b\b[3] Balance Enquiry\n");
    pprint(" ");
    printf("\b\b\b\b[4] Profile\n");
    pprint(" ");
    printf("\b\b\b\b[5] Exit\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        system("CLS");
        UPI(x);
        break;

    case 2:
        system("CLS");
        NEFT(x);
        break;

    case 3:
        system("CLS");
        balance_enq(x);
        break;

    case 4:
        system("CLS");
        profile(x);
        break;

    case 5:
        system("CLS");
        return 0;
        break;

    default:
        printf("\nEnter a valid option.\n");
        goto lb;
    }
hk: printf("\n\n");
    pprint(" ");
    printf("\b\b\b\b\b\bWould you like to return to the main menu ? (y/n) ");
    scanf(" %c", &cha);
    if (cha == 'y' || cha == 'Y')
    {
        goto lb;
    }
    else if (cha == 'n' || cha == 'N')
    {
        return 0;
    }
    else
    {
        printf("\n");
        pprint(" ");
        printf("\b\b\b\b\b\bEnter a valid option.\n");
        goto hk;
    }
}
