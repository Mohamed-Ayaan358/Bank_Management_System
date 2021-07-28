#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include "Header.h"

void pprint(char *x)
{
	for (int i = 0; i < 70; i++)
	{
		printf("%s", x);
	}
}
