CPP  = g++.exe 
WINDRES = windres.exe
RES  = 
OBJ  = ParserTest.o $(RES)
LINKOBJ  = ParserTest.o $(RES)
LIBS =  -L"D:\MinGW\lib" -lboost_unit_test_framework -l -pg
INCS =  -I"D:\MinGW\include" 
BIN  = ParserTest.exe
CXXFLAGS = $(CXXINCS)   -pg -g3
CFLAGS = $(INCS)   -pg -g3
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before ParserTest.exe all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "ParserTest.exe" $(LIBS)

ParserTest.o: ParserTest.cpp
	$(CPP) -c ParserTest.cpp -o ParserTest.o $(CXXFLAGS)