#.c文件
SRC = src/background.c src/enemy.c src/main.c src/own_side.c src/slide.c src/font.c src/file.c src/list.c
#.o文件,二进制文件
OBJ = obj/background.o obj/enemy.o obj/main.o obj/own_side.o obj/slide.o obj/font.o obj/file.o obj/list.o
#可执行程序
BIN = bin/a.out
#链接头文件路径
INC = -I include
#链接的库文件
LIB = -l main -l font
#目标：依赖 
$(BIN):$(SRC)
#通过编译将.c文件变成二进制文件
	arm-linux-gcc src/background.c -c -o obj/background.o $(INC)
	arm-linux-gcc src/list.c -c -o obj/list.o $(INC)  
	arm-linux-gcc src/enemy.c -c -o obj/enemy.o $(INC) 
	arm-linux-gcc src/own_side.c -c -o obj/own_side.o $(INC)
	arm-linux-gcc src/slide.c -c -o obj/slide.o $(INC) 
	arm-linux-gcc src/font.c -c -o obj/font.o $(INC) 
	arm-linux-gcc src/file.c -c -o obj/file.o $(INC) 
	arm-linux-gcc src/main.c -c -o obj/main.o $(INC) 
#将所有的二进制文件打包到库文件
	ar rcs lib/libmain.a  $(OBJ)
#生成可执行程序
	arm-linux-gcc $(SRC) -o $(BIN) $(INC) -L lib $(LIB)  -lpthread
