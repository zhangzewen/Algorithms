DIR=$(shell pwd)
UTIL_DIR=$(DIR)/util
REACTOR_DIR=$(DIR)/Reactor

.PHONY: all clean

all:
	@for dir in `ls`;\
	do if [ -d $${dir} ];\
	then make -C $${dir};\
	fi;\
	done;
#	@make -C $(UTIL_DIR)
#	@make -C $(REACTOR_DIR)
#	@make -C ./Dns/

clean:
	@for dir in `ls`;\
	do if [ -d $${dir} ];\
	then make clean -C $${dir} --no-print-directory;\
	fi;\
	done;
	
