# Компилятор 
CC = gcc 
RM = rm 
# Опции компиляции 
CFLAGS = -std=c99 -Wall -Werror -pedantic 
 
test.exe: test.o my_snprintf.o my_string.o  
	$(CC) -o test.exe test.o my_snprintf.o my_string.o

test.o: test.c func.h  
	$(CC) $(CFLAGS) -c test.c

my_snprintf.o: my_snprintf.c func.h  
	$(CC) $(CFLAGS) -c my_snprintf.c 

my_string.o: my_string.c func.h  
	$(CC) $(CFLAGS) -c my_string.c

clean:  
	$(RM) *.o *.exe
