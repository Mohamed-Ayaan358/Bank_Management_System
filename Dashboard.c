#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include "Header.h"

int dashboard(char *x)
{
    int ch = 0;
    char cha;
lb: printf("\nChoose from the following options:\n\n1.UPI\n2.NEFT\n3.Balance Enquiry\n4.Profile\n5.Exit\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        UPI(x);
        break;

    case 2:
        NEFT(x);
        break;

    case 3:
        balance_enq(x);
        break;
    }
    /*
hk: printf("\n\nWould you like to return to the main menu ? (y/n) ");
    scanf("%c", &cha);
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
        printf("\nEnter a valid option.\n");
        goto hk;
    }
    */
}
