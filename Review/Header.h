struct date
{
    int month, day, year;
};
struct
{

    char name[60];
    long int acc_no;
    int pin;
    char ifsc[60];
    char acc_type[10];
    char phone[11];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

} add, update, check, rem, transact; /*Allows you to refer to the struct using different access points*/

void new_acc();
void view_list();
void edit();
void delete();

char usrnm[110];

void new_acc();
void view_list();
void edit();
void delete ();
void see();
char *login();
int sign_up();
int display(char *x);
int dashboard(char *x);
int UPI(char *x);
int NEFT(char *x);
int balance_enq(char* x);
int online();
int profile(char *x);
void pprint(char *x);
