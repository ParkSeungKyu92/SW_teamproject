CC = gcc
OUTPUT = libfuncs.a
OBJ = getch.o menu.o menu_long.o
$(OUTPUT) : $(OBJ)
	ar rv $(OUTPUT) $(OBJ)
%.o : %.c
	$(CC) -c -I../include $< -o $@
clean : 
	rm *.o $(OUTPUT) 
