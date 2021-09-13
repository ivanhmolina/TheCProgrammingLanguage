#Compiling flags
CC = gcc

#Directory variables for wildcards
SUBDIR = $(wildcard */*)
SOURCES = $(wildcard $(addsuffix /*.c, $(SUBDIR)))
INCLUDES = $(wildcard $(addsuffix /*.h, $(SUBDIR)))
INC_DIR = ./inc ./HandlingArgs/inc ./BitwiseOperations/inc
INC_FLAGS = $(addprefix -I, $(INC_DIR))
CPPFLAGS = -DBITS

#Options
help:
	@echo "Sources: $(SOURCES)"
	@echo "Includes: $(INCLUDES)"

args:
	$(CC) .\HandlingArgs\src\handling_args.c -o handling_args $(INC_FLAGS)

bits:
	$(CC) .\BitwiseOperations\src\bit_operations.c -o bit_operations $(INC_FLAGS)

types:
	$(CC) .\TypesLength\src\types_length.c -o types_length $(INC_FLAGS) $(CPPFLAGS)

clean: 
	cmd /C del *.exe