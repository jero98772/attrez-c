CFLAGS = -Wall -Wextra -pedantic -std=c18
CXXFLAGS = -std=c++17

test_tools.o: test_tools.h test_tools.c
	gcc $(CFLAGS) -c test_tools.c

# MVEC-------------------------------------------
mvec_test: test_tools.o ../mstruct/mvec.h mvec_test.c
	gcc $(CFLAGS) -o mvec_test test_tools.o mvec_test.c

mvec_test_cpp: ../mstruct/mvec.h mvec_test.c
	g++ $(CXXFLAGS) -o mvec_test_cpp test_tools.o mvec_test.c

vec_comp: vec_test.cpp
	g++ $(CXXFLAGS) -o vec_comp vec_test.cpp

mvec_clean:
	rm -f mvec_test mvec_test_cpp vec_comp

# -----------------------------------------------

# AMGRAPH----------------------------------------
meam_test: test_tools.o ../mstruct/meam.h meam_test.c
	gcc $(CFLAGS) -o meam_test test_tools.o meam_test.c

meam_clean:
	rm -f meam_test

# -----------------------------------------------

# MDLLIST----------------------------------------
mdll_test: ../mstruct/mdll.h mdll_test.c
	gcc $(CFLAGS) -o mdll_test mdll_test.c

mdll_clean:
	rm -f mdll_test

# -----------------------------------------------

# MEPMISC----------------------------------------
meputil.o: ../malg/meputil.c ../malg/meputil.h
	gcc $(CFLAGS) -c ../malg/meputil.c

# -----------------------------------------------

# MEPSORT----------------------------------------
mepsort_test: test_tools.o meputil.o ../malg/mepsort.h mepsort_test.c
	gcc $(CFLAGS) -o mepsort_test test_tools.o meputil.o mepsort_test.c

mepsort_clean:
	rm -f mepsort_test

# -----------------------------------------------

# MVEB-------------------------------------------
mveb.o: ../mstruct/mveb.h ../mstruct/mveb.c
	gcc $(CFLAGS) -c ../mstruct/mveb.c

mveb_test: test_tools.o meputil.o mveb.o ../malg/mepsort.h mveb_test.c
	gcc $(CFLAGS) -o mveb_test test_tools.o meputil.o mveb.o mveb_test.c

mveb_clean:
	rm -f mveb_test

# -----------------------------------------------


clean-all:
	rm -f *_test *.o

