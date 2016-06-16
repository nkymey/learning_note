CUR_SOURCE=${wildcard *.c}
CUR_OBJS=${patsubst %.c, %.o, $(CUR_SOURCE)}
$(CUR_OBJS):%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo $(CC) $(CUR_OBJS)

