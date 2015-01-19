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

          
	gcc -g $(CFLAGS) -I ./../asbtract_data_type -I ./../../global_definition -I ./linked_list -c ./linked_list/linked_list.c &> build.txt