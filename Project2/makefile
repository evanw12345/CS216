EXEC = Project2
HEADERS = card.h deck.h SortedLinkedList.h rank.h pokerhand.h
	#(listing all header files here, separated by space)
OBJECTS = card.o deck.o SortedLinkedList.o rank.o pokerhand.o PA2.o 
	#(listing all object files here, separated by space)
testPA2Objects = card.o deck.o SortedLinkedList.o rank.o pokerhand.o testPA2.o 
	#(listing all object files for testPA2, separated by space)
$(EXEC): $(OBJECTS)
	g++ $^ -o $@
testPA2: $(testPA2Objects)
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -f *.o $(EXEC)