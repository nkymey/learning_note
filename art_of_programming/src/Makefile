CUR_SOURCE=${wildcard *.c}
CUR_OBJS=${patsubst %.c, %.o, $(CUR_SOURCE)}

build_obj:$(CUR_OBJS)

$(CUR_OBJS):%.o:%.c
	@$(CC) $(CFLAGS) -o $@ -c $^
	@echo $(CC) $(CUR_OBJS)
