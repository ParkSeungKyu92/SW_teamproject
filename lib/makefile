CC = gcc
OUTPUT = libfuncs.a
OBJ = getch_.o menu.o menu_long.o long_text.o

$(OUTPUT) : $(OBJ)
	ar rv $(OUTPUT) $(OBJ)
%.o : %.c
	$(CC) -c -I../include $< -o $@
clean : 
	rm *.o $(OUTPUT) 
