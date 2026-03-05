CXX:= g++
SRC:= glut_deng_main.cpp
OUTPUT:= main.exe
CFLAGS:= -lfreeglut -lopengl32 -lglu32 -o $(OUTPUT)

all:
	$(CXX) $(SRC) $(CFLAGS)
