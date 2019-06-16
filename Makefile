CXX = clang++
CXXFLAGS = -Wall -Wextra -g
IDIR = ./include
SRCDIR = ./src
fortune : main.o Board.o Property.o Tile.o
	$(CXX) $(CXXFLAGS) -o fortune main.o Board.o Property.o Tile.o
main.o : main.cpp $(IDIR)/Board.h $(IDIR)/Property.h 
	$(CXX) $(CXXFLAGS) -c main.cpp
Board.o : $(SRCDIR)/Board.cpp $(IDIR)/Board.h $(IDIR)/Property.h $(IDIR)/Tile.h 
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/Board.cpp
Property.o : $(SRCDIR)/Property.cpp $(IDIR)/Board.h $(IDIR)/Property.h $(IDIR)/Tile.h 
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/Property.cpp
Tile.o : $(SRCDIR)/Tile.cpp $(IDIR)/Tile.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/Tile.cpp
clean :
	rm *.o
