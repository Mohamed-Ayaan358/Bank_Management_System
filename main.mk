a.exe: new_acc.o main.o view.o edit.o
	gcc new_acc.o main.o view.o edit.o

new_acc.o: new_acc.c header.h
	gcc -c new_acc.c

view.o: view.c header.h
	gcc -c view.c

edit.o: edit.c header.h
	gcc -c edit.c

main.o: main.c header.h
	gcc -c main.c