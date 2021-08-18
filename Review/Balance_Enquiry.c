#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include "Header.h"

int balance_enq(char *x)
{
	FILE* f;
	char ch, name[100], usernam[110], pass[9], accnt_no[11], ifsc_cd[14], phone[11], upih[16], upip[9];
	float amnt, credit;
	amnt = credit = 0.000000;
	credit = 100000;
	system("CLS");
	f = fopen("online_rec.dat", "a+");
	while (fscanf(f, "%s %s %s %s %f %f %s %s\n", &usernam, &pass, &accnt_no, &ifsc_cd, &amnt, &credit, &upih, &upip) != EOF)
	{
		if (strcmp(usernam, x) == 0)
		{
			printf("\n\n");
			pprint(" ");
			printf("\b\b\b\b\b\bSavings Account Balance: Rupees %.2f", amnt);
			printf("\n");
			pprint(" ");
			printf("\b\b\b\b\b\bReady Credit: Rupees %.2f", credit);
			break;
		}
	}
	return 0;
}
