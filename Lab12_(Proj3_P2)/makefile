EXEC = Lab12
HEADERS = deck.h card.h SortingList.h sortingOperations.h term.h
	#(listing all header files here, separated by space)
OBJECTS = deck.cpp card.cpp SortingList.cpp sortingOperations.cpp term.cpp Lab12.cpp
	#(listing all of your object files here, separated by space)
$(EXEC): $(OBJECTS)
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -f *.o $(EXEC)