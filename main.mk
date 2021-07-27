a.exe: new_acc.o main1.o view.o edit.o delete.o see.o Balance_Enquiry.o Dashboard.o Display.c Login.o NEFT.o UPI.o main.o Sign_Up.o 
	gcc new_acc.o main1.o view.o edit.o delete.o see.o Balance_Enquiry.o Dashboard.o Display.c Login.o NEFT.o UPI.o main.o Sign_Up.o 

#Bank functions 

main1.o: main1.c Header.h
	gcc -c main1.c
	
new_acc.o: new_acc.c Header.h
	gcc -c new_acc.c

view.o: view.c Header.h
	gcc -c view.c

edit.o: edit.c Header.h
	gcc -c edit.c

delete.o:delete.c Header.h
	gcc -c delete.c

see.o :see.c Header.h
	gcc -c see.c

#Client functions

Balance_Enquiry.o: Balance_Enquiry.c Header.h
	gcc -c Balance_Enquiry.c

Dashboard.o: Dashboard.c Header.h
	gcc -c Dashboard.c

Display.o: Display.c Header.h
	gcc -c Display.c

Login.o: Login.c Header.h
	gcc -c Login.c

NEFT.o: NEFT.c Header.h
	gcc -c NEFT.c

UPI.o: UPI.c Header.h
	gcc -c UPI.c

main.o: main.c Header.h
	gcc -c main.c

Sign_Up.o: Sign_Up.c Header.h
	gcc -c Sign_Up.c