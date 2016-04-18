lab4test: Box.o Prize.o assign_3_unit_test.o 
	g++ -Wall -g -o Box Prize.o Box.o assign_3_unit_test.o 

test: assign_3_unit_test.cpp
	g++ -Wall -g -c assign_3_unit_test.cpp
	
Prize: Prize.cpp
	g++ -Wall -g -c Prize.cpp

Box: Box.cpp
	g++ -Wall -g -c Box.cpp
	
clean:
	rm *.o Box