CC = gcc
MOVE = mv

DIR_INC = ./include
DIR_OBJ = ./obj


CFLAGS = -g -Wall -I$(DIR_INC)


TARGET = main


DIRS_SRC   += src
DIRS_SRC   += src/linked_list
#DIRS_SRC   += src/two_pointers
DIRS_SRC   += src/array
DIRS_SRC   += src/queue
DIRS_SRC   += src/stack


DIR_FILES  = $(foreach dir, $(DIRS_SRC),$(wildcard $(dir)/*.c))
DIR_OBJS   = $(patsubst %.c,%.o,$(DIR_FILES))


$(ALL):$(TARGET)

$(TARGET):$(DIR_OBJS)
	$(CC) -o $(TARGET) $(DIR_OBJS) $(CFLAGES)
	-$(MOVE) $(DIR_OBJS) ./$(DIR_OBJ)
	

.PHONY:clean
clean:
	find ${DIR_OBJ} -name *.o | xargs rm -rf {}
	rm -rf ${TARGET}
