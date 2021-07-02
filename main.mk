a.exe: new_acc.o main1.o view.o edit.o delete.o see.o
	gcc new_acc.o main1.o view.o edit.o delete.o see.o

main1.o: main1.c header.h
	gcc -c main1.c
	
new_acc.o: new_acc.c header.h
	gcc -c new_acc.c

view.o: view.c header.h
	gcc -c view.c

edit.o: edit.c header.h
	gcc -c edit.c

delete.o:delete.c header.h
	gcc -c delete.c

see.o :see.c header.h
	gcc -c see.c