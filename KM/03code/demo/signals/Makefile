# Makefile  exe程序
TARGET = test
CC=g++
#C 编译器的选项
CFLAGS=-Wall -O2 -g -I. 
# C++ 编译器的选项
CXXFLAGS=$CFLAGS
DEPS=CThread.h
OBJS += CThread.o
OBJS += main.o
#动态库路径            
#LIBPATH  = -L./dynamiclib/libs 
#链接动态库 
ShareLib   = -lpthread 
LIBPATH  = 
 ##头文件路径
CPPFLAGS   = -I .


# Compiles each of the object files as separate targets
#%.o: %.cpp把所有的[.cpp]文件都编译成[.o]文件
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# -o $@ -> Tells make to put the output in a file named after the target
# $^ 	-> all of the file names in $(OBJS) separated by a space
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBPATH) $(ShareLib)

.PHONY: clean

# Target to clean files created during compilation
clean:
	rm -f *.o 

#有一些软件包一次完成四个步骤：
#$(CC) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) example.c   -o example

