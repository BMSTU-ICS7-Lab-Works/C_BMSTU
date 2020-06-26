# Компилятор 
CC = gcc 
RM = rm 
# Опции компиляции 
CFLAGS = -std=c99 -Wall -Werror -pedantic 
 
app.exe: main.o cdio.o process.o mu.o  
	$(CC) -o app.exe main.o cdio.o process.o mu.o

test.exe: test.o cdio.o process.o mu.o  
	$(CC) -o test.exe test.o cdio.o process.o mu.o 

main.o: main.c main.h  
	$(CC) $(CFLAGS) -c main.c 

cdio.o: cdio.c main.h  
	$(CC) $(CFLAGS) -c cdio.c 

process.o: process.c main.h  
	$(CC) $(CFLAGS) -c process.c

mu.o: mu.c main.h  
	$(CC) $(CFLAGS) -c mu.c

test.o: test.c main.h  
	$(CC) $(CFLAGS) -c test.c 

clean:  
	$(RM) *.o *.exe
