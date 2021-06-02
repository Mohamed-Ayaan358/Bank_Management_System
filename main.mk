a.exe: new_acc.o main.o
	gcc new_acc.o main.o

new_acc.o: new_acc.c header.h
	gcc -c new_acc.c

main.o: main.c header.h
	gcc -c main.c