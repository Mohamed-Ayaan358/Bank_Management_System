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
    int count, count_2, count_3, len, cha, len_1, d, d2, count_lns;
    count = count_2 = count_3 = len = cha = d = d2 = count_lns = 0;
    char ch, chaa, name[100], usernam[110], pass[9], accnt_no[11], ifsc_cd[14], phone_1[11], upih[16], upip[9], new_upih[16], new_upip[9], upip_ch[9], upip_ch2[9], temp_accno[12];
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
    fclose(ptr);
    f2 = fopen("UPI.dat", "r");
    while ((chaa = fgetc(f2)) != EOF)
    {
        if (chaa == '\n')
        {
            count_lns++;
        }
    }
    fclose(f2);
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
                printf("\n\n");
                pprint(" ");
                printf("\b\b\b\b\b\bUPI account doesnt exist.\n");
                Sleep(2000);
            lj: printf("\n");
                pprint(" ");
                printf("\b\b\b\b\b\bWould you like to register for an UPI account ? (y/n)");
                scanf(" %c", &ch);
                if (ch == 'y' || ch == 'Y')
                {
                lb: printf("\n");
                    pprint(" ");
                    printf("\b\b\b\b\b\bEnter a password to secure UPI transactions: ");
                    scanf("%s", &new_upip);
                    len = strlen(new_upip);
                    if (len > 8)
                    {
                        printf("\n");
                        pprint(" ");
                        printf("\b\b\b\b\b\bLength of the password cannot exceed 8 characters.\n");
                        goto lb;
                    }
                    else
                    {
                        printf("\n");
                        pprint(" ");
                        printf("\b\b\b\b\b\bCreating UPI Account....\n");
                        Sleep(3000);
                        printf("\n");
                        pprint(" ");
                        printf("\b\b\b\b\b\bUPI Account successfully created !!!\n");
                        Sleep(3000);
                        system("CLS");
                        strcpy(new_upih, "ANYM@");
                        strcat(new_upih, phone_1);
                        printf("\n");
                        pprint(" ");
                        printf("\b\b\b\b\b\bUPI Account Details:\n");
                        printf("\n");
                        pprint(" ");
                        printf("\b\b\b\b\b\bUPI Handler: %s", new_upih);
                        printf("\n");
                        pprint(" ");
                        printf("\b\b\b\b\b\bUPI Registered Mobile Number: %s\n", phone_1);
                        fprintf(f2, "%s %s %s\n", usernam, new_upih, new_upip);
                    }
                }
                else if (ch == 'n' || ch == 'N')
                {
                    printf("\n");
                    pprint(" ");
                    printf("\b\b\b\b\b\bYou cannot perform UPI Transactions without an UPI Account. Returning to Dashboard.\n");
                    Sleep(3000);
                    break;
                }
                else
                {
                    printf("\n");
                    pprint(" ");
                    printf("\b\b\b\b\b\bPlease enter a valid option.\n");
                    goto lj;
                }
                break;
            }
            else
            {
                printf("\n\n");
                pprint(" ");
                printf("\b\b\b\b\b\bEnter the amount to be withdrawn: ");
                scanf("%f", &upi_amnt);
                if (upi_amnt >= (amnt - 1000))
                {
                    Sleep(3000);
                    printf("\n");
                    pprint(" ");
                    printf("\b\b\b\b\b\bLow account balance. Transaction Failed.\n");
                    count_2++;
                }
                else
                {
                hk: printf("\n");
                    pprint(" ");
                    printf("\b\b\b\b\b\bEnter your UPI password: ");
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
                    if (count_3 > count_lns)
                    {
                        printf("\n");
                        pprint(" ");
                        printf("\b\b\b\b\b\bIncorrect password.\n");
                        goto hk;
                    }
                    amnt -= upi_amnt;
                    new_amnt = amnt;
                    Sleep(3000);
                    printf("\n");
                    pprint(" ");
                    printf("\b\b\b\b\b\bTransaction Complete.\n");
                    printf("\n");
                    pprint(" ");
                    printf("\b\b\b\b\b\bRemaining Balance (Savings Account): Rupees %.2f\n", new_amnt);
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
                fprintf(f3, "%s %s%.2f\n", new_upih, "-", upi_amnt);
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
    ptr = fopen("record.dat", "r+");
    while (fgets(temp_accno, 11, ptr) != EOF)
    {
        if (strcmp(accnt_no, temp_accno) == 0)
        {
            d2 = ftell(ptr);
            break;
        }
    }
    fseek(ptr, 0, SEEK_SET);
    while (fscanf(ptr, "%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.ifsc, &add.pin, &add.phone, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        char a[100];
        sprintf(a, "%ld", add.acc_no);
        if (strcmp(accnt_no, a) == 0)
        {
            int h2 = strlen(a);
            fseek(ptr, d2, SEEK_SET);
            fseek(ptr, -h2, SEEK_CUR);
            fprintf(ptr, "%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, add.pin, add.phone, add.acc_type, new_amnt, add.deposit.day, add.deposit.month, add.deposit.year);
            fseek(ptr, 0, SEEK_CUR);
            break;
        }
    }
    fclose(ptr);
    return 0;
}
