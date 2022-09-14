all: Bank
#	@ Bank.exe

#make rule to generate the final binary
Bank: main.o Bank.o
	@gcc main.o Bank.o -o Bank.exe
	
main.o: main.c
	@gcc -c main.c
	
Bank.o: Bank.c
	@gcc -c Bank.c