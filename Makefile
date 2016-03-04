MOVE = mv
DIR_INC = ./include
DIR_OBJ = ./obj
#DIR_BIN = ./bin
CC = gcc
CFLAGS = -g -Wall -I${DIR_INC}

TARGET = main
#BIN_TARGET = ${DIR_BIN}/${TARGET}



DIRS_Spk   += src
DIRS_Spk   += src/linked_list
DIRS_Spk   += src/two_pointers


DIR_FILES  = $(foreach dir, $(DIRS_Spk),$(wildcard $(dir)/*.c))
DIR_OBJS   = $(patsubst %.c,%.o,$(DIR_FILES))


$(ALL):$(TARGET)

$(TARGET):$(DIR_OBJS)
	$(CC) -o $(TARGET) $(DIR_OBJS) $(CFLAGES)
	-$(MOVE) $(DIR_OBJS) ./$(DIR_OBJ)
	
.PHONY:clean
clean:
	find ${DIR_OBJ} -name *.o | xargs rm -rf {}
	rm -rf ${TARGET}
	#rm -rf ${DIR_BIN}/${TARGET}

