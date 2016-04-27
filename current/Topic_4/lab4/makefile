lab3test: BST_node.o bs_tree.o lab_3_unit_test.o 
	g++ -Wall -g -o BST_node BST_node.o bs_tree.o lab_3_unit_test.o 

lab3Utest: lab_3_unit_test.cpp
	g++ -Wall -g -c lab_3_unit_test.cpp

BSTNode: BST_node.cpp
	g++ -Wall -g -c BST_node.cpp
	
bs_tree: bs_tree.cpp
	g++ -Wall -g -c bs_tree.cpp
	
clean:
	rm *.o BST_node
	