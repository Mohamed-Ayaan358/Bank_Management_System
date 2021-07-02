#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include "Header.h"

int UPI(char* x)
{
    FILE* ptr;
    FILE* f;
    FILE* f2;
    FILE* f3;
    ptr = fopen("record.dat", "a+");
    int count, count_2, count_3, len, cha, len_1, d;
    count = count_2 = count_3 = len = cha = d = 0;
    char ch, name[100], usernam[110], pass[9], accnt_no[11], ifsc_cd[12], phone_1[11], upih[16], upip[9], new_upih[16], new_upip[9], upip_ch[9], upip_ch2[9];
    float amnt, credit, upi_amnt, new_amnt, new_credit;
    amnt = credit = upi_amnt = new_amnt = new_credit = 0.000000;
    credit = 100000;
    char to_name[100], to_accnt_no[11], to_ifsc_cd[12];
    float to_amnt = 0.000000;
    system("CLS");
    while (fscanf(ptr, "%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF) /*fscanf is used to read data from a particular file in this case ptr*/
    {
        char temp_usrname[100], phone[11];
        strcpy(temp_usrname, "ANYM@");
        if (strcmp(strcat(temp_usrname, add.name), x) == 0)
        {
            strcpy(phone, add.phone);
            strcpy(phone_1, phone);
            len_1 = strlen(x);
        }
    }
    f = fopen("online_rec.dat", "a+");
    f2 = fopen("UPI.dat", "a+");
    f3 = fopen("Transaction.dat", "a+");
    system("CLS");
    while (fscanf(f, "%s %s %s %s %f %f %s %s\n", &usernam, &pass, &accnt_no, &ifsc_cd, &amnt, &credit, &upih, &upip) != EOF)
    {
        if (strcmp(usernam, x) == 0)
        {
            new_amnt = amnt;
            if (strcmp(upih, "NA") == 0)
            {
                printf("\nUPI account doesnt exist.\n");
                Sleep(2000);
            lj: printf("\nWould you like to register for an UPI account ? (y/n)");
                scanf(" %c", &ch);
                if (ch == 'y' || ch == 'Y')
                {
                lb: printf("\nEnter a password to secure UPI transactions: ");
                    scanf("%s", &new_upip);
                    len = strlen(new_upip);
                    if (len > 8)
                    {
                        printf("\nLength of the password cannot exceed 8 characters.\n");
                        goto lb;
                    }
                    else
                    {
                        printf("\nCreating UPI Account....\n");
                        Sleep(3000);
                        printf("\nUPI Account successfully created !!!\n");
                        Sleep(3000);
                        system("CLS");
                        strcpy(new_upih, "ANYM@");
                        strcat(new_upih, phone_1);
                        printf("\nUPI Account Details:\n");
                        printf("\nUPI Handler: %s", new_upih);
                        printf("\nUPI Registered Mobile Number: %s\n", phone_1);
                        fprintf(f2, "%s %s %s\n", usernam, new_upih, new_upip);
                    }
                }
                else if (ch == 'n' || ch == 'N')
                {
                    printf("\nYou cannot perform UPI Transactions without an UPI Account. Returning to Dashboard.\n");
                    Sleep(3000);
                    break;
                }
                else
                {
                    printf("\nPlease enter a valid option.\n");
                    goto lj;
                }
                break;
            }
            else
            {
                printf("\nEnter the amount to be withdrawn: ");
                scanf("%f", &upi_amnt);
                if (upi_amnt >= (amnt - 1000))
                {
                    Sleep(3000);
                    printf("\nLow account balance. Transaction Failed.\n");
                    count_2++;
                }
                else
                {
                hk: printf("\nEnter your UPI password: ");
                    scanf("%s", &upip_ch);
                    len = strlen(upip_ch);
                    while (fscanf(f2, "%s %s %s\n", &usernam, &new_upih, &new_upip) != EOF)
                    {
                        if (strcmp(upip_ch, new_upip) == 0)
                        {
                            break;
                        }
                        else
                        {
                            count_3++;
                        }
                    }
                    if (count_3 > 3)
                    {
                        printf("\nIncorrect password.\n");
                        goto hk;
                    }
                    amnt -= upi_amnt;
                    new_amnt = amnt;
                    Sleep(3000);
                    printf("\nTransaction Complete.\n");
                    printf("\nRemaining Balance (Savings Account): Rupees %.2f\n", new_amnt);
                }
                fclose(f);
                count_2++;
                f = fopen("online_rec.dat", "r+");
                while (fscanf(f, "%s ", &usernam) != EOF)
                {
                    if (strcmp(x, usernam) == 0)
                    {
                        int h = strlen(usernam);
                        fseek(f, -h - 1, SEEK_CUR);
                        fprintf(f, "%s %s %s %s %.2f %.2f %s %s", usernam, pass, accnt_no, ifsc_cd, new_amnt, credit, new_upih, new_upip);
                        fseek(f, 0, SEEK_END);
                        break;
                    }
                }
                fprintf(f3, "%s %.2f\n", new_upih, upi_amnt);
                fclose(f3);
                break;
            }

        }
    }
    fclose(f);
    f = fopen("online_rec.dat", "r+");
    if (count_2 == 0)
    {
        while (fscanf(f, "%s ", &usernam) != EOF)
        {
            if (strcmp(x, usernam) == 0)
            {
                int h = strlen(usernam);
                fseek(f, -h - 1, SEEK_CUR);
                fprintf(f, "%s %s %s %s %.2f %.2f %s %s", usernam, pass, accnt_no, ifsc_cd, new_amnt, credit, new_upih, new_upip);
                fseek(f, 0, SEEK_END);
                break;
            }
        }
    }
    fclose(f);
}
