EXEC = Lab11
HEADERS = SortingList.h building.h 
	#(listing all header files here, separated by space)
OBJECTS = SortingList.cpp building.cpp Lab11.cpp
	#(listing all of your object files here, separated by space)
$(EXEC): $(OBJECTS)
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -f *.o $(EXEC)