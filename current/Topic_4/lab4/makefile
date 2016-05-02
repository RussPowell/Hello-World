lab3test: bst_node.o bs_tree.o lab_3_unit_test.o 
	g++ -Wall -g -o bst_node bst_node.o bs_tree.o lab_3_unit_test.o 

lab3Utest: lab_3_unit_test.cpp
	g++ -Wall -g -c lab_3_unit_test.cpp

bst_node: BST_node.cpp
	g++ -Wall -g -c BST_node.cpp
	
bs_tree: bs_tree.cpp
	g++ -Wall -g -c bs_tree.cpp
	
clean:
	rm *.o bst_node
	