struct date
{
	int month, day, year;
};

struct
{
	char name[60];
	int acc_no;
	int pin;
	char ifsc[60];
	char upih[30];
	char upip[30];
	char acc_type[10];
	char phone[11];
	float amt;
	struct date dob;
	struct date deposit;
	struct date withdraw;
}add;

struct var
{
	int a, b;
	int ch, len_su, count;
	char usernm[100], pass_r[9];
	char pass[9], usrnam[100], ifsc_cd[12];
	int ch_1, len_1, len_2, len_3, len_4, count_1, ifs_cd;
	int ch_2;
	int count_2, ch_3;
	char cha, ph_new[11], upi_newp[7];
	int ch_8;
	double cred_bal;
	int ch_4;
	int ch_9;
	int to_accntno, len_5, len_6, len_7, len_8;
	char to_ifscd[12], to_custnm[100];
	double to_amnt;
	char to_upicustm[100], to_phno[11], upi_passch[7], chaa;
	int to_upiacntno, len_9, count_3;
	int ch_10;
	int ch_5;
	char usrnm_ch[100], pass_ch[9];
	int count_4, len_10, count_5;
	int ch_6, ch_7;
}s;

void center_orient();
void pprint(char);
int login();
int sign_up();
int UPI();
int blnc_enq();
int NEFT_trans();
int UPI_trans();
int account_detls();
int dashboard();