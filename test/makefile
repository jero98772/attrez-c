CFLAGS = -g -Wall -Wextra -pedantic -std=c18
CXXFLAGS = -std=c++17

test_tools.o: test_tools.h test_tools.c
	gcc $(CFLAGS) -c test_tools.c

# MVEC-------------------------------------------
mvec_test: test_tools.o ../mstruct/mvec.h mvec_test.c
	gcc $(CFLAGS) -o mvec_test test_tools.o mvec_test.c

mvec_test_cpp: test_tools.o ../mstruct/mvec.h mvec_test.c
	g++ $(CXXFLAGS) -o mvec_test_cpp test_tools.o mvec_test.c

vec_comp: vec_test.cpp
	g++ $(CXXFLAGS) -o vec_comp vec_test.cpp

.PHONY: mvec_clean
mvec_clean:
	rm -f mvec_test mvec_test_cpp vec_comp

# -----------------------------------------------

# MDLLIST----------------------------------------
mdll_test: ../mstruct/mdll.h mdll_test.c
	gcc $(CFLAGS) -o mdll_test mdll_test.c

.PHONY: mdll_clean
mdll_clean:
	rm -f mdll_test

# -----------------------------------------------

# MEPUTIL----------------------------------------
meputil.o: ../malg/meputil.c ../malg/meputil.h
	gcc $(CFLAGS) -c ../malg/meputil.c

meputil_test: test_tools.o meputil.o ../mstruct/mvec.h meputil_test.c 
	gcc $(CFLAGS) -o meputil_test test_tools.o meputil.o meputil_test.c -lm 

.PHONY: meputil_clean
meputil_clean: 
	rm -f meputil_test
# -----------------------------------------------

# MEPSORT----------------------------------------
mepsort_test: test_tools.o meputil.o ../malg/mepsort.h mepsort_test.c
	gcc $(CFLAGS) -o mepsort_test test_tools.o meputil.o mepsort_test.c

.PHONY: mepsort_clean
mepsort_clean:
	rm -f mepsort_test

# -----------------------------------------------

# MVEB-------------------------------------------
mveb.o: ../mstruct/mveb.h ../mstruct/mveb.c
	gcc $(CFLAGS) -c ../mstruct/mveb.c

mveb_test: test_tools.o meputil.o mveb.o ../malg/mepsort.h mveb_test.c
	gcc $(CFLAGS) -o mveb_test test_tools.o meputil.o mveb.o mveb_test.c

.PHONY: mveb_clean
mveb_clean:
	rm -f mveb_test


# -----------------------------------------------

# MVIB-------------------------------------------
mbiv.o: ../mstruct/mbiv.h ../mstruct/mbiv.c
	gcc $(CFLAGS) -c ../mstruct/mbiv.c

mbiv_test: test_tools.o meputil.o mbiv.o mbiv_test.c
	gcc $(CFLAGS) -o mbiv_test test_tools.o meputil.o mbiv.o mbiv_test.c


# -----------------------------------------------

hash_test: meputil.o hash_test.c
	gcc $(CFLAGS) -o hash_test meputil.o hash_test.c

.PHONY: clean-all
clean-all:
	rm -f *_test *.o

