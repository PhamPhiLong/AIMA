#   These following marco specify 
#   folders in project
INC_DIR     = asbtract_data_type
INC_DIR    += ./../global_definition
SRC_DIR     = linked_list
OBJ_DIR     = build/obj
RELEASE_DIR = build/release
DEBUG_DIR   = build/debug

#   Specify libraries for linker
#LIBS    = -pthread

#   Specify folders that store
#   included header files
INC     = -I$(INC_DIR)

#   define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS  = -L./lib

# 
CC      = gcc

#   Enable gcc debug flag 
DEBUG_FLAG = -g

#   Enable other flags
CFLAGS  = -Wall -Wextra

#   Specify output name
PROGRAM = linked_list

#   Specify header files to be included
#   and their path name
_API_DEPS    = queue_lib_api.h
API_DEPS = $(patsubst %,$(INC_DIR)/%,$(_API_DEPS))

_IN_DEPS = queue_common.h 
IN_DEPS = $(patsubst %,$(SRC_DIR)/%,$(_IN_DEPS))

#   Specify all object file 
#   by replacing .c by .o in 
#   corresponding source file name
_OBJS    = $(SRCS:.c=.o)
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

#   Specify the source file for this module
SRCS    = linked_list.c \
		  		  

#   Build each object file if any of
#   its source file and corresponding 
#   included header file
#   Note: $^ means the right of ':' , here is $(SRC_DIR)/%.c
#         $@ means the left  of ':' , here is $(OBJ_DIR)/%.o
#         $< means the first item in the dependencies list
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(API_DEPS) $(INC_DEPS) 
	$(CC) -c $< -o $@ $(CFLAGS) $(DEBUG_FLAG) $(INC) 

#   For targets those are not file, add .Phony: target1 target2 ...	
.PHONY: release debug clean rebuild

#   Build release version
release: $(OBJS)
	$(CC) $(LIBS) -o $(RELEASE_DIR)/$(PROGRAM) $^ $(CFLAGS)

#   Build debug version
debug: $(OBJS)
	$(CC) $(LIBS) -o $(DEBUG_DIR)/$(PROGRAM) $^ $(CFLAGS)

#   Delete all object files and output files
clean:
	rm -f $(OBJ_DIR)/*.o $(RELEASE_DIR)/* $(DEBUG_DIR)/*
	clear

rebuild: clean release