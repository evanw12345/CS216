EXEC = Lab9
HEADERS = card.h deck.h SortedLinkedList.h rank.h
	#(listing all header files here, separated by space)
OBJECTS = card.o deck.o SortedLinkedList.o rank.o Lab9.o
	#(listing all of your object files here, separated by space)
$(EXEC): $(OBJECTS)
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -i *.o $(EXEC)