# attrez-c
Some C data structs and algorithms that I use or find interesting.

> *C and typesafety are like oil and water*
-- Ancient Chinese proverb

## Desiderata
I would be specially thankful for any advice that could be offered in regards to the following:

1. **Performant**: To a reasonable extent, the structs and algs should be optimized in terms of runtime and memory. I'm also interested in the _fastest_ data structs or algorithms for a given use case.
 
2. **EZ 2 Use**: The tools should be "comfortable" to use. To a reasonable extent, the tools should be written so that the user is not encumbered by verbose code.

3. **Well-Documented**: All functions and structures should be documented. There should also be small explanations of how the code works and where one might find more information about the algorithm being used where relevant. 

### STRUCTS INCLUDED
Those marked with (u) are usable as of right now. They are all in constant improvement, however. 
- (u) A vector (somewhat in the style of a C++ `std::vector<>`)
- (u) A Van Emde Boas Tree
- (u) A bitset
- (u) A doubly-linked list
- A hashtable
- A priority queue
- An Aho-Corasick automaton
- A stack and heap using a vector

### TO DO
- Documentation for already existing structs and funcs. 
- A hashtable (Hopscotch & Robinhood)
- A hashtable but concurrent (Hopscotch?)
- A priority queue (Fibonacci heap? Probably?)
- An attempt at a "generalized" Segment-Tree
- Aho-Corasick automaton
- Correct random number functions and improve them with `Generic` macro
- Make a file for default "comparison" functions
