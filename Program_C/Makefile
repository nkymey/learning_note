ROOT_DIR=$(shell pwd)

#设置头文件路径
DIR_INC = $(ROOT_DIR)/include


#设置编译器
CC=gcc
CFLAGS = -g -Wall -I${DIR_INC}

BIN = app_test

export CC BIN ROOT_DIR CFLAGS

mk_files := $(shell find . -name "makefile" -o -name "Makefile" | awk '{if($$1 != "./Makefile") print $$1}')
#dirs := $(dir $(mk_files))
 
.PHONY: all
all:make_obj build_app 

make_obj:
	@for i in $(mk_files); do make -C `dirname $$i`; done

build_app:
	@$(CC) -o $(BIN) $(shell find . -name *.o)
	@echo "Building app is done."

clean:
	@find . -name *.o | xargs rm -rf
	@find . -name *.exe | xargs rm -rf
	@find . -name $(BIN) | xargs rm -rf
