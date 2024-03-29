CXX = clang++
CXXFLAGS = -Wall -Wextra -g
IDIR = ./include
SRCDIR = ./src
fortune : main.o Board.o Property.o Tile.o GenericPlayer.o ComputerPlayer.o HumanPlayer.o Game.o
	$(CXX) $(CXXFLAGS) -o fortune main.o Board.o Property.o Tile.o \
		GenericPlayer.o ComputerPlayer.o HumanPlayer.o Game.o
main.o : main.cpp $(IDIR)/Board.h $(IDIR)/Property.h 
	$(CXX) $(CXXFLAGS) -c main.cpp
Board.o : $(SRCDIR)/Board.cpp $(IDIR)/Board.h $(IDIR)/Property.h $(IDIR)/Tile.h 
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/Board.cpp
Property.o : $(SRCDIR)/Property.cpp $(IDIR)/Tile.h 
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/Property.cpp
Tile.o : $(SRCDIR)/Tile.cpp $(IDIR)/Tile.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/Tile.cpp
GenericPlayer.o : $(SRCDIR)/GenericPlayer.cpp $(IDIR)/GenericPlayer.h $(IDIR)/Property.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/GenericPlayer.cpp
ComputerPlayer.o : $(SRCDIR)/ComputerPlayer.cpp $(IDIR)/ComputerPlayer.h $(IDIR)/GenericPlayer.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/ComputerPlayer.cpp
HumanPlayer.o : $(SRCDIR)/HumanPlayer.cpp $(IDIR)/HumanPlayer.h $(IDIR)/GenericPlayer.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/HumanPlayer.cpp
Game.o : $(SRCDIR)/Game.cpp $(IDIR)/Game.h $(IDIR)/Board.h $(IDIR)/GenericPlayer.h $(IDIR)/ComputerPlayer.h \
	$(IDIR)/HumanPlayer.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/Game.cpp
clean :
	rm *.o
