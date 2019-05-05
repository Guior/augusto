#OBJS specifies which files to compile as part of the project
OBJS = interface.c
#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = interface.out
#This is the target that compiles our executable all :
all:$(OBJS)
	gcc $(OBJS) -w -o $(OBJ_NAME) -lm -liupimglib -liup -L../../../lib/$TEC_UNAME
