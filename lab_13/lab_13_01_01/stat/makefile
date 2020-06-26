# Компилятор 
CC = gcc  
# Опции компиляции 
CFLAGS = -std=c99 -Wall -Werror 

app.exe: main.o libmatrix.a
	$(CC) -o app.exe main.o libmatrix.a
	
libmatrix.a: matrix.o
	ar rc libmatrix.a matrix.o
	
matrix.o: matrix.c matrix.h  
	$(CC) $(CFLAGS) -c matrix.c 


clean:
	rm *.o *.exe *.a
