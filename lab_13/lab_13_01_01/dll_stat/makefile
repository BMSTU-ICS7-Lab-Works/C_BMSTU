# Компилятор 
CC = gcc  
# Опции компиляции 
CFLAGS = -std=c99 -Wall -Werror 

app.exe: main.o matrix.dll
	$(CC) -o app.exe main.o -L. -lmatrix
	
matrix.dll: matrix.o 
	$(CC) -shared matrix.o -Wl,--subsystem,windows -o matrix.dll
	
main.o: main.c matrix.h  
	$(CC) $(CFLAGS) -c main.c 
	
matrix.o: matrix.c matrix.h  
	$(CC) $(CFLAGS) -D IL_EXPORTS -c matrix.c 
	
clean:
	rm *.o *.exe *.dll

