# 生成多个可执行文件

CC = gcc # 设置编译工具
CFLAGS = -g # 设置编译参数

all: main_max main_min

main_max: main_max.c tool.o boar.o
	$(CC) $(CFLAGS)  main_max.c tool.o boar.o -o main_max

main_min: main_min.c tool.o boar.o
	$(CC) $(CFLAGS)  main_min.c tool.o boar.o -o main_min


tool.o: tool.c # 生成tool.o 连接文件
	$(CC)  $(CFLAGS) -c tool.c 
boar.o: boar.c #生成boar.o 连接文件
	$(CC)  $(CFLAGS) -c boar.c
clean:
	rm -rf *.o main_max main_min
