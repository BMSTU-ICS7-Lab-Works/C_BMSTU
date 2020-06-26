# Компилятор 
CC = gcc  
# Опции компиляции 
CFLAGS = -std=c99 -Wall -Werror 

app.exe: main.o matrix.dll
	$(CC) -o app.exe main.o
	
matrix.dll: matrix.o 
	$(CC) -shared matrix.o -Wl,--subsystem,windows -o matrix.dll
	
matrix.o: matrix.c matrix.h  
	$(CC) $(CFLAGS) -D IL_EXPORTS -c matrix.c 
	
main.o: main.c 
	$(CC) $(CFLAGS) -c main.c 

clean:
	rm *.o *.exe *.dll

