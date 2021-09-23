#Compiling flags
CC = gcc

#Directory variables for wildcards
EMPTY=
SUBDIR = $(wildcard */*)
SOURCES = $(wildcard $(addsuffix /*.c, $(SUBDIR)))
INCLUDES = $(wildcard $(addsuffix /*.h, $(SUBDIR)))
INC_DIR = ./inc ./HandlingArgs/inc ./BitwiseOperations/inc ./Stack/inc ./List/inc ./Tree/inc
INC_FLAGS = $(addprefix -I, $(INC_DIR))
CPPFLAGS = -DDEBUG_BTREE -DDEBUG_SLIST -DBITS

#Options
help:
	@echo "Sources: $(SOURCES)"
	@echo "Includes: $(INCLUDES)"
	@echo "Options: args | bits | types | cstack | slist | btree | clean"

args:
	$(CC) .\HandlingArgs\src\handling_args.c -o handling_args $(INC_FLAGS)

bits:
	$(CC) .\BitwiseOperations\src\bit_operations.c -o bit_operations $(INC_FLAGS)

types:
	$(CC) .\TypesLength\src\types_length.c -o types_length $(INC_FLAGS) $(CPPFLAGS)

cstack:
	$(CC) .\Stack\src\stack.c -o stack $(INC_FLAGS)

slist: btree.o
	$(CC) .\List\src\slist.c tree.o -o slist $(INC_FLAGS) $(CPPFLAGS)

slist.o: btree.o
	$(CC) -c .\List\src\slist.c -o slist.o $(INC_FLAGS) 

btree:
	$(CC) .\Tree\src\tree.c -o tree $(INC_FLAGS) $(CPPFLAGS)

btree.o:
	$(CC) -c .\Tree\src\tree.c -o tree.o $(INC_FLAGS)

clean: 
	cmd /C del *.exe *.o