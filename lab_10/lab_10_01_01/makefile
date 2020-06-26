# Компилятор 
CC = gcc 
RM = rm 
# Опции компиляции 
CFLAGS = -std=c99 -Wall -Werror -pedantic 
 
app.exe: main.o cdio.o tasks.o sort.o file.o
	$(CC) -o app.exe main.o cdio.o tasks.o sort.o file.o
	
test.exe: test.o cdio.o tasks.o sort.o file.o 
	$(CC) -o test.exe test.o cdio.o tasks.o sort.o file.o

main.o: main.c app.h  
	$(CC) $(CFLAGS) -c main.c 

cdio.o: cdio.c app.h  
	$(CC) $(CFLAGS) -c cdio.c 

tasks.o: tasks.c app.h  
	$(CC) $(CFLAGS) -c tasks.c
	
sort.o: sort.c app.h  
	$(CC) $(CFLAGS) -c sort.c 

file.o: file.c app.h  
	$(CC) $(CFLAGS) -c file.c
	
clean:  
	$(RM) *.o *.exe
