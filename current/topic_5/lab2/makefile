test: lab_27.o lab_27_unit_test.o;
	g++ -Wall -g -o test lab_27.o lab_27_unit_test.o;
	
unittest: lab_27_unit_test.cpp;
	g++ -Wall -g -c lab_27_unit_test.cpp;
	
lab_27: lab_27.cpp;
	g++ -Wall -g -c lab_27.cpp;
	
make clean:
	rm *.o test;