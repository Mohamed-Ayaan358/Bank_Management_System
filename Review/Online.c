#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include "Header.h"

int online()
{
	int ch, a, b;
	ch = a = b = 0;
lb: system("CLS");
	printf("\n\n");
	pprint(" ");
	printf("\b\b\b\b\xB2\xB2\xB2\xB2\xB2 ONLINE BANKING SYSTEMS \xB2\xB2\xB2\xB2\xB2\n");
	printf("\n");
	pprint(" ");
	printf("\b\b\b\b [1] Login\n");
	pprint(" ");
	printf("\b\b\b\b [2] Sign Up\n");
	scanf("%d", &ch);
	if (ch == 1)
	{
		char* p;
		p = login();
		if (p != NULL)
		{
			dashboard(p);
			strcpy(usrnm, "NA");
			printf("\n\n");
			pprint(" ");
			printf("\b\b\b\b\b\bThank You for using our systems\n\n");
			return 0; // Return to main menu
		}
		else
		{
			return 0; // Return to main menu
		}
	}
	else if (ch == 2)
	{
		b = sign_up();
		if (b == 0)
		{
			char* p;
			p = login();
			if (p != 0)
			{
				dashboard(p);
			}
			else
			{
				return 0;
			}
			printf("\n\n");
			pprint(" ");
			printf("\b\b\b\b\b\bThank You for using our systems\n\n");
			return 0; // Return to main menu
		}
		else
		{
			return 0; // Return to main menu
		}
	}
	else
	{
		printf("\n");
		pprint(" ");
		printf("\b\b\b\b\b\bPlease enter a valid option.\n");
		system("pause");
		goto lb;
	}
}
