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
    int count, count_2, count_3, len, cha, len_1, d, h1;
    count = count_2 = count_3 = len = cha = d = 0;
    char ch, name[100], usernam[110], pass[9], accnt_no[11], ifsc_cd[12], phone_1[11], upih[16], upip[9], new_upih[16], new_upip[9], upih_2[16], upip_2[9];
    char to_name[100], to_accnt_no[11], to_ifsc_cd[12];
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
        hj: printf("\nChoose the account from which the transaction has to be made:\n1.Savings\n2.Credit\n");
            scanf("%d", &cha);
            switch (cha)
            {
            case 1:
                f3 = fopen("Transaction.dat", "a+");
                system("CLS");
                printf("\nEnter the name of the benificiary: ");
                scanf("%s", &to_name);
                printf("\nEnter the account number of the benificiary: ");
                scanf("%s", &to_accnt_no);
                printf("\nEnter the IFSC code of the benificiary: ");
                scanf("%s", &to_ifsc_cd);
                printf("\nEnter the amount to be transferred: ");
                scanf("%f", &to_amnt);
                if (to_amnt >= (amnt - 1000))
                {
                    Sleep(3000);
                    printf("\nLow account balance. Transaction failed.\n");
                    break;
                }
                else
                {
                    amnt -= to_amnt;
                    new_amnt = amnt;
                    Sleep(3000);
                    printf("\nTransaction complete.\n");
                    printf("\nRemaining balance (Savings Account): Rupees %.2f", amnt);
                    fprintf(f3, "%s %s %s %s %.2f %.2f\n", usernam, to_name, to_accnt_no, to_ifsc_cd, -to_amnt, amnt);
                    fclose(f3);
                }
                break;

            case 2:
                f3 = fopen("Transaction.dat", "a+");
                system("CLS");
                printf("\nEnter the name of the benificiary: ");
                scanf("%s", &to_name);
                printf("\nEnter the account number of the benificiary: ");
                scanf("%s", &to_accnt_no);
                printf("\nEnter the IFSC code of the benificiary: ");
                scanf("%s", &to_ifsc_cd);
                printf("\nEnter the amount to be transferred: ");
                scanf("%f", &to_amnt);
                if (to_amnt >= (credit - 1000))
                {
                    Sleep(3000);
                    printf("\nLow account balance. Transaction failed.\n");
                    break;
                }
                else
                {
                    credit -= to_amnt;
                    new_credit = credit;
                    Sleep(3000);
                    printf("\nTransaction complete.\n");
                    printf("\nRemaining balance (Current Account): Rupees %.2f", credit);
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
        }
    }
    while (fscanf(f, "%s %s %s %s %f %f %s %s\n", &usernam, &pass, &accnt_no, &ifsc_cd, &amnt, &credit, &upih, &upip) != EOF)
    {
        if (strcmp(to_accnt_no, accnt_no) == 0) 
        {
            printf("\n%s", usernam);
            system("pause");
            amnt_2 = amnt + to_amnt;
            int h = strlen(usernam);
            fseek(f, h1, SEEK_SET);
            fseek(f, -h - 1, SEEK_CUR);
            fprintf(f, "%s %s %s %s %.2f %.2f ", usernam, pass, accnt_no, ifsc_cd, amnt_2, credit);
            fprintf(f3, "%s %s %s%.2f %.2f\n", usernam, x, "+", to_amnt, credit);
            fseek(f, 0, SEEK_END);
            break;
        }
    }
    fclose(f);
    fclose(f4);
}
