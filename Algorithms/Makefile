#Compiling flags
CC := gcc

#Directory variables for wildcards
MAIN_DIRS := $(wildcard ../*)
MAIN_INCLUDES := $(wildcard $(addsuffix /inc/*.h, $(MAIN_DIRS)))
MAIN_INCLUDES_DIRS := $(dir $(MAIN_INCLUDES))
SUBDIR := $(wildcard */*)
SOURCES := $(wildcard $(addsuffix /*.c, $(SUBDIR)))
OBJECTS := $(SOURCES:.c=.o)
INCLUDES := $(wildcard $(addsuffix /*.h, $(SUBDIR)))
INC_FILES := $(notdir $(INCLUDES))
SRC_FILES := $(notdir $(SOURCES)) 
OBJ_FILES := $(notdir $(OBJECTS))
OUT_FILES := $(OBJ_FILES:.o=)
INCDIRS := $(dir $(INCLUDES))
SRCDIRS := $(dir $(SOURCES))
INC_FLAGS = $(addprefix -I, $(INCDIRS)) $(addprefix -I, $(MAIN_INCLUDES_DIRS))
CPPFLAGS := -DDEBUG_SORT

#Options
help:
	@echo "Maindirs: $(MAIN_DIRS)"
	@echo "Mainincludes: $(MAIN_INCLUDES)"
	@echo "Mainincludes dirs: $(MAIN_INCLUDES_DIRS)"
	@echo "Subdirs: $(SUBDIR)"
	@echo "Include dirs: $(INCDIRS)"
	@echo "Source dirs: $(SRCDIRS)"
	@echo "Includes: $(INCLUDES)"
	@echo "Sources: $(SOURCES)"
	@echo "Objects: $(OBJECTS)"
	@echo "Include files: $(INC_FILES)"
	@echo "Source files: $(SRC_FILES)"
	@echo "Object files: $(OBJ_FILES)"
	@echo "Output files: $(addsuffix .exe, $(OUT_FILES))"
	@echo "Include flags: $(INC_FLAGS)"
	@echo "Options: help | clean | sort"

clean:
	cmd /C del *.exe *.o

all: all.o
	$(CC) $(OBJ_FILES) -o $(OUT_FILES)

all.o:
	$(CC) -c $(SOURCES) -o $(OBJ_FILES) $(INC_FLAGS) $(CPPFLAGS)
