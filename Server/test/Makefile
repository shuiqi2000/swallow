CPP  = gcc.exe 
CC   = gcc.exe 
WINDRES = windres.exe
RES  = 
OBJ  = Test.o $(RES)
LINKOBJ  = Test.o $(RES)
LIBS =  -L"d:/Dev-Cpp/lib" -lstdc++ -pg
INCS =  -I"d:/Dev-Cpp/include" 
CXXINCS =  -I"d:/Dev-Cpp/lib/gcc/mingw32/3.4.2/include"  -I"d:/Dev-Cpp/include/c++/3.4.2/backward"  -I"d:/Dev-Cpp/include/c++/3.4.2/mingw32"  -I"d:/Dev-Cpp/include/c++/3.4.2"  -I"d:/Dev-Cpp/include" 
BIN  = Test.exe
CXXFLAGS = $(CXXINCS)   -pg -g3
CFLAGS = $(INCS)   -pg -g3
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before Test.exe all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "Test.exe" $(LIBS)

Test.o: Test.cpp
	$(CPP) -c Test.cpp -o Test.o $(CXXFLAGS)


