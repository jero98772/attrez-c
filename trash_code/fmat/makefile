CFLAGS = -std=c18
CXXFLAGS = -std=c++17


test: fmat_test.c fmat.h
	gcc $(CFLAGS) -o test fmat_test.c

test-cpp: fmat_test.c fmat.h
	g++ $(CXXFLAGS) -o test-cpp fmat_test.c

fmot-comp: fmot_comp.cpp
	g++ $(CXXFLAGS) -o fmot-comp fmot_comp.cpp

clean: 
	rm -f test test-cpp fmot-comp
