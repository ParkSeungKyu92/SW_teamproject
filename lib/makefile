CC = gcc
OUTPUT = libfuncs.a
OBJ = getch.o menu.o
$(OUTPUT) : $(OBJ)
	ar rv $(OUTPUT) $(OBJ)
%.o : %.c
	$(CC) -c -I../include $< -o $@
clean : 
	rm *.o $(OUTPUT) 
