OUTPUT = app
OBJ = app.o
CC = gcc
SOURCE = app.c

$(OUTPUT) : $(OBJ)
	$(CC) -o $(OUTPUT) $(OBJ) -L../lib -lfuncs
$(OBJ) : $(SOURCE)
	$(CC) -c -I../include $(SOURCE) -o $(OBJ)
clean :
	rm *.o $(OUTPUT)

