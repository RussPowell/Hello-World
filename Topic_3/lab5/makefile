lab4test: sl_node.o sl_list.o sl_node.o lab_5_unit_test.o 
	g++ -Wall -g -o slnode sl_node.o sl_list.o lab_5_unit_test.o 

lab5Utest: lab_5_unit_test.cpp
	g++ -Wall -g -c lab_5_unit_test.cpp
	
SLNode: sl_node.cpp
	g++ -Wall -g -c sl_node.cpp

SLList: sl_list.cpp
	g++ -Wall -g -c sl_list.cpp
	
clean:
	rm *.o slnode