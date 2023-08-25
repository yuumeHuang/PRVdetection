# 定义变量
CC = g++        # 编译器
CFLAGS = -g -Wall   # 编译选项
TARGET = main    # 目标可执行文件名
SRC = main.cpp   # 源文件
 
# 构建规则
all: $(TARGET)
 
$(TARGET): $(SRC)
    $(CC) $(CFLAGS) -o $(TARGET) $(SRC)
 
clean:
    rm -f $(TARGET)