#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

int i, j;
int main_exit;
void menu();
int atm();
void close();
struct date
{
    int month, day, year;
};
struct
{

    char name[60];
    int acc_no, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

} add, upd, check, rem, transaction;

float interest(float t, float amount, int rate)
{
    float SI;
    SI = (rate * t * amount) / 100.0;
    return (SI);
}
void fordelay(int j)
{
    int i, k;
    for (i = 0; i < j; i++)
        k = i;
}

void new_acc()
{
    printf("new");
}