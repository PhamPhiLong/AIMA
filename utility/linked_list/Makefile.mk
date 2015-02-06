CC              = gcc
DEBUG_FLAG      = -g
INC_DIR         = ./../../global_definition
INC_DIR        += ./../asbtract_data_type
SRCS            = linked_list.c 
BUILD_LOG       = build.txt 
OBJ_DIR         = ../build/obj
RELEASE_DIR     = ../build/release
DEBUG_DIR       = ../build/debug
LIB_OBJ_NAME    = linked_list.o
LIB_NAME        = $(patsubst %.o,lib%.a,$(LIB_OBJ_NAME)) 
INC             = $(patsubst %,-I%,$(INC_DIR)) 

CFLAGS  = -Wall -Wextra \
          -std=c89 -pedantic \
          -Wno-missing-braces -Wno-missing-field-initializers -Wformat=2 \
          -Wswitch-default -Wswitch-enum -Wcast-align -Wpointer-arith \
          -Wbad-function-cast -Wstrict-overflow=5 -Wstrict-prototypes -Winline \
          -Wundef -Wnested-externs -Wcast-qual -Wshadow -Wunreachable-code \
          -Wlogical-op -Wfloat-equal -Wstrict-aliasing=2 -Wredundant-decls \
          -Wold-style-definition -Werror \
          -ggdb3 \
          -O0 \
          -fno-omit-frame-pointer -ffloat-store -fno-common -fstrict-aliasing \
          -lm

.PHONY: build
		  
build:          
	$(CC) $(DEBUG_FLAG) -o $(OBJ_DIR)/$(LIB_OBJ_NAME) $(CFLAGS) $(INC) -c $(SRCS) &> $(BUILD_LOG)
	ar rcs $(RELEASE_DIR)/$(LIB_NAME) $(OBJ_DIR)/$(LIB_OBJ_NAME)