#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include "Header.h"

int main()
{
	int ch, a, b;
	ch = a = b = 0;
lb: system("CLS");
	printf("\nONLINE BANKING SYSTEMS\n");
	printf("\n1.Login\n2.Sign Up\n");
	scanf("%d", &ch);
	if (ch == 1)
	{
		char* p;
		p = login();
		if (p != NULL)
		{
			dashboard(p);
			strcpy(usrnm, "NA");
			printf("\n\nThank You for using our systems\n\n");
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
			printf("\n\nThank You for using our systems\n\n");
			return 0; // Return to main menu
		}
		else
		{
			return 0; // Return to main menu
		}
	}
	else
	{
		printf("\nPlease enter a valid option.\n");
		system("pause");
		goto lb;
	}
}
