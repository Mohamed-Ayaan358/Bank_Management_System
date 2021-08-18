#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include "Header.h"

int NEFT(char *x)
{
    FILE* ptr;
    FILE* f;
    FILE* f2;
    FILE* f3;
    FILE *f4;
    ptr = fopen("record.dat", "a+");
    int count, count_2, count_3, count_4, len, cha, len_1, d, h1, d2;
    count = count_2 = count_3 = count_4 = len = cha = d = d2 = 0;
    char ch, name[100], usernam[110], pass[9], accnt_no[11], ifsc_cd[14], phone_1[11], upih[16], upip[9], new_upih[16], new_upip[9], upih_2[16], upip_2[9], temp_accno[12], temp_accno2[12];
    char to_name[100], to_accnt_no[11], to_ifsc_cd[14];
    float amnt, amnt_2, credit, upi_amnt, new_amnt, new_credit;
    amnt = amnt_2 = credit = upi_amnt = new_amnt = new_credit = 0.000000;
    credit = 100000;
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
    f = fopen("online_rec.dat", "a+");
    system("CLS");
    while (fscanf(f, "%s %s %s %s %f %f %s %s\n", &usernam, &pass, &accnt_no, &ifsc_cd, &amnt, &credit, &upih, &upip) != EOF)
    {
        if (strcmp(usernam, x) == 0)
        {
            char upih_ch[16], upip_ch[9];
            strcpy(upih_ch, upih);
            strcpy(upip_ch, upip);
            strcpy(upih_2, upih_ch);
            strcpy(upip_2, upip_ch);
            amnt_2 = amnt;
            new_amnt = amnt;
            new_credit = credit;
        hj: printf("\n");
            pprint(" ");
            printf("\b\b\b\b\b\bChoose the account from which the transaction has to be made:\n");
            printf("\n");
            pprint(" ");
            printf("\b\b\b\b[1] Savings\n");
            pprint(" ");
            printf("\b\b\b\b[2] Current\n");
            scanf("%d", &cha);
            switch (cha)
            {
            case 1:
                f3 = fopen("Transaction.dat", "a+");
                system("CLS");
                printf("\n\n");
                pprint(" ");
                printf("\b\b\b\b\b\bEnter the name of the benificiary: ");
                scanf("%s", &to_name);
                printf("\n");
                pprint(" ");
                printf("\b\b\b\b\b\bEnter the account number of the benificiary: ");
                scanf("%s", &to_accnt_no);
                printf("\n");
                pprint(" ");
                printf("\b\b\b\b\b\bEnter the IFSC code of the benificiary: ");
                scanf("%s", &to_ifsc_cd);
                printf("\n");
                pprint(" ");
                printf("\b\b\b\b\b\bEnter the amount to be transferred: ");
                scanf("%f", &to_amnt);
                if (to_amnt >= (amnt - 1000))
                {
                    Sleep(3000);
                    printf("\n");
                    pprint(" ");
                    printf("\b\b\b\b\b\bLow account balance. Transaction failed.\n");
                    break;
                }
                else
                {
                    amnt -= to_amnt;
                    new_amnt = amnt;
                    Sleep(3000);
                    printf("\n");
                    pprint(" ");
                    printf("\b\b\b\b\b\bTransaction complete.\n");
                    printf("\n");
                    pprint(" ");
                    printf("\b\b\b\b\b\bRemaining balance (Savings Account): Rupees %.2f", amnt);
                    fprintf(f3, "%s %s %s %s %.2f %.2f\n", usernam, to_name, to_accnt_no, to_ifsc_cd, -to_amnt, amnt);
                    fclose(f3);
                    ptr = fopen("record.dat", "r+");
                    while (fgets(temp_accno2, 11, ptr) != EOF)
                    {
                        if (strcmp(accnt_no, temp_accno2) == 0)
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
                }
                break;

            case 2:
                f3 = fopen("Transaction.dat", "a+");
                system("CLS");
                printf("\n\n");
                pprint(" ");
                printf("\b\b\b\b\b\bEnter the name of the benificiary: ");
                scanf("%s", &to_name);
                printf("\n");
                pprint(" ");
                printf("\b\b\b\b\b\bEnter the account number of the benificiary: ");
                scanf("%s", &to_accnt_no);
                printf("\n");
                pprint(" ");
                printf("\b\b\b\b\b\bEnter the IFSC code of the benificiary: ");
                scanf("%s", &to_ifsc_cd);
                printf("\n");
                pprint(" ");
                printf("\b\b\b\b\b\bEnter the amount to be transferred: ");
                scanf("%f", &to_amnt);
                if (to_amnt >= (credit - 1000))
                {
                    Sleep(3000);
                    printf("\n");
                    pprint(" ");
                    printf("\b\b\b\b\b\bLow account balance. Transaction failed.\n");
                    break;
                }
                else
                {
                    credit -= to_amnt;
                    new_credit = credit;
                    Sleep(3000);
                    printf("\n");
                    pprint(" ");
                    printf("\b\b\b\b\b\bTransaction complete.\n");
                    printf("\n");
                    pprint(" ");
                    printf("\b\b\b\b\b\bRemaining balance (Current Account): Rupees %.2f", credit);
                    fprintf(f3, "%s %s %s %s %.2f %.2f\n", usernam, to_name, to_accnt_no, to_ifsc_cd, -to_amnt, credit);
                    fclose(f3);
                }
                break;

            default:
                printf("\Please enter a valid option\n");
                goto hj;
            }
            break;
        }
    }
    fclose(f);
    f = fopen("online_rec.dat", "r+");
    while (fscanf(f, "%s ", &usernam) != EOF)
    {
        if (strcmp(x, usernam) == 0)
        {
            int h = strlen(usernam);
            fseek(f, -h - 1, SEEK_CUR);
            fprintf(f, "%s %s %s %s %.2f %.2f ", usernam, pass, accnt_no, ifsc_cd, new_amnt, new_credit);
            fseek(f, 0, SEEK_END);
            break;
        }
    }
    fclose(f);
    f = fopen("online_rec.dat", "r+");
    f3 = fopen("Transaction.dat", "a+");
    f4 = fopen("online_rec.dat", "r+");
    while (fscanf(f4, "%s ", &usernam) != EOF)
    {
        char temp_usrnam[100] = "ANYM@";
        if (strcmp(strcat(temp_usrnam, to_name), usernam) == 0)
        {
            h1 = ftell(f4);
            count_4++;
        }
    }
    if (count_4 > 0)
    {
        while (fscanf(f, "%s %s %s %s %f %f %s %s\n", &usernam, &pass, &accnt_no, &ifsc_cd, &amnt, &credit, &upih, &upip) != EOF)
        {
            if (strcmp(to_accnt_no, accnt_no) == 0)
            {
                amnt_2 = amnt + to_amnt;
                int h = strlen(usernam);
                fseek(f, h1, SEEK_SET);
                fseek(f, -h - 1, SEEK_CUR);
                fprintf(f, "%s %s %s %s %.2f %.2f", usernam, pass, accnt_no, ifsc_cd, amnt_2, credit);
                fprintf(f3, "%s %s %s%.2f %.2f\n", usernam, x, "+", to_amnt, credit);
                fseek(f, 0, SEEK_END);
                break;
            }
        }
        ptr = fopen("record.dat", "r+");
        while (fgets(temp_accno, 11, ptr) != EOF)
        {
            if (strcmp(to_accnt_no, temp_accno) == 0)
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
            if (strcmp(to_accnt_no, a) == 0)
            {
                amnt_2 = add.amt + to_amnt;
                int h2 = strlen(a);
                fseek(ptr, d2, SEEK_SET);
                fseek(ptr, -h2, SEEK_CUR);
                fprintf(ptr, "%ld %s %d/%d/%d %s %d %s %s %f %d/%d/%d", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.ifsc, add.pin, add.phone, add.acc_type, amnt_2, add.deposit.day, add.deposit.month, add.deposit.year);
                fseek(ptr, 0, SEEK_CUR);
                break;
            }
        }
        fclose(ptr);
    }
    fclose(f);
    fclose(f4);
}
