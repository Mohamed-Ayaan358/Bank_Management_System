#include<stdio.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#include "Header.h"

int main()
{
lb:	system("CLS");
	center_orient();
	printf("ANONYMOUS BANKING SYSTEMS\n\n");
	center_orient();
	printf("\t\b\b\b\b1.Login \t 2.Sign Up\n");
	scanf_s("%d", &s.ch);
	switch (s.ch)
	{
		case 1:
			s.a = login();
			if (s.a == 0)
			{
				goto lb;
			}
			break;

		case 2:
			sign_up();
			printf("\n\nYou are required to login again.\n\n");
			system("pause");
			system("cls");
			s.b = login();
			if (s.b == 0)
			{
				goto lb;
			}
			break;

		default:
			printf("\nPlease enter a valid option.\n");
			goto lb;
	}
	printf("\n");
	system("pause");
	dashboard();
	center_orient();
	printf("\nTHANK YOU FOR USING OUR SYSTEMS !!!!\n\n");
	return 0;
}
