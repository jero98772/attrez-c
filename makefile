CFLAGS = -g -Wall -Wextra -pedantic -std=c18
CXXFLAGS = -std=c++17

INCL_DIR = include
SRC_DIR = src
TEST_DIR = test


test_tools.o: $(TEST_DIR)/test_tools.c $(TEST_DIR)/test_tools.h
	$(CC) -c $(filter-out %.h,$^) $(CFLAGS) -iquote $(TEST_DIR)	


# MVEC-------------------------------------------
mvec_test: test_tools.o $(TEST_DIR)/mvec_test.c \
	$(INCL_DIR)/mstruct/mvec.h
	$(CC) -o $@ $(filter-out %.h,$^) $(CFLAGS) -iquote $(INCL_DIR) 


vec_test: $(TEST_DIR)/vec_test.cpp
	$(CXX) -o $@ $(filter-out %.h,$^) $(CXXFLAGS) 


.PHONY: mvec_clean
mvec_clean: mvec_test vec_test
# -----------------------------------------------


# MDLLIST----------------------------------------
mdll_test: $(TEST_DIR)/mdll_test.c $(INCL_DIR)/mstruct/mdll.h 
	$(CC) -o $@ $(filter-out %.h,$^) $(CFLAGS) -iquote $(INCL_DIR) 


.PHONY: mdll_clean
mdll_clean: mdll_test
# -----------------------------------------------


# MEPUTIL----------------------------------------
meputil.o: $(SRC_DIR)/malg/meputil.c $(INCL_DIR)/malg/meputil.h
	$(CC) -c $(filter-out %.h,$^) $(CFLAGS) -iquote $(INCL_DIR)


meputil_test: test_tools.o meputil.o $(TEST_DIR)/meputil_test.c \
	$(INCL_DIR)/mstruct/mvec.h 
	$(CC) -o $@ $(filter-out %.h,$^) $(CFLAGS) -iquote $(INCL_DIR) -lm


.PHONY: meputil_clean
meputil_clean: meputil.o meputil_test
# -----------------------------------------------


# MEPSORT----------------------------------------
mepsort_test: test_tools.o meputil.o $(TEST_DIR)/mepsort_test.c \
	$(INCL_DIR)/malg/mepsort.h 
	$(CC) -o $@ $(filter-out %.h,$^) $(CFLAGS) -iquote $(INCL_DIR)


.PHONY: mepsort_clean
mepsort_clean: mepsort_test
# -----------------------------------------------


# MVEB-------------------------------------------
mveb.o: $(SRC_DIR)/mstruct/mveb.c $(INCL_DIR)/mstruct/mveb.h
	$(CC) -c $(filter-out %.h,$^) $(CFLAGS) -iquote $(INCL_DIR)


mveb_test: test_tools.o meputil.o mveb.o $(TEST_DIR)/mveb_test.c \
	$(INCL_DIR)/malg/mepsort.h
	$(CC) -o $@ $(filter-out %.h,$^) $(CFLAGS) -iquote $(INCL_DIR)


.PHONY: mveb_clean
mveb_clean: mveb.o mveb_test
# -----------------------------------------------


# MVIB-------------------------------------------
mbiv.o: $(SRC_DIR)/mstruct/mbiv.c $(INCL_DIR)/mstruct/mbiv.h
	$(CC) -c $(filter-out %.h,$^) $(CFLAGS) -iquote $(INCL_DIR)


mbiv_test: test_tools.o meputil.o mbiv.o $(TEST_DIR)/mbiv_test.c
	$(CC) -o $@ $(filter-out %.h,$^) $(CFLAGS) -iquote $(INCL_DIR)


.PHONY: mbiv_clean
mbiv_clean: mvib.o mvib_test
# -----------------------------------------------


# HASHTABLE--------------------------------------
hash_test: meputil.o $(TEST_DIR)/hash_test.c
	$(CC) -o $@ $(filter-out %.h,$^) $(CFLAGS) -iquote $(INCL_DIR)


# -----------------------------------------------

.PHONY: ghcs_clean
gchs_clean: 
	rm -f $$(find -iname "*.h.gch")

.PHONY: clean_all
clean_all: gchs_clean
	rm -f *_test *.o

%_clean:
	rm -f $^


