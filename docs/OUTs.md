# test's files and their out
### test/hash_test.c 
work, dont have compile errors ,[out look like this](https://pastebin.com/tc9Yj18N)
* **Question**: is [this](https://pastebin.com/tc9Yj18N)  hashtable? isn't a hash supposed to be unique and unrepeatable?

### test/mbiv_test.c
work, dont have compile errors ,[out look like this](https://pastebin.com/ssdFF7qv)

### test/mdll_test.c
work, dont have compile errors ,[out look like this](https://pastebin.com/eN9nFfAC)

### test/mepsort_test.c
work, dont have compile errors ,[out look like this](https://pastebin.com/muH4JdTk) i see is very slow when print , i 
**Question**
I don't think it is slow because it is a mergesort and because it prints a very different average run time on my machine, I am running it in /tmp
is my machine slow or algorith problems?
note with this functions comment or uncomment no have important changes

    bench_time(test1_insort, 1);
    bench_time(test2_insort, 1);
    bench_time(test1_mersort, 1);
    bench_time(test2_mersort, 100);

###  test/meputil_test.c
work, dont have compile errors ,[out look like this](https://pastebin.com/9suMVTFK)

###  test/mveb_test.c
work, dont have compile errors ,[out look like this](https://pastebin.com/nKHhrnmQ)

**Question** in test6() ... while true , why? when finish?

###  test/mvec_test.c
work, dont have compile errors ,[out look like this](https://pastebin.com/LaigNvYC)

###  test/mvec_test.c
work, dont have compile errors ,[out look like this](https://pastebin.com/bxFRMFCZ)
is very fast


## recomendation

-better's names or explained
what is better name ?
specific for general public 
some random examples like :
p to position
t to temperatuere

-is better show all functions with not very big values if some like can change code add very big values or disdable 

## notes about process
i test files with diferents values
the pastebin out is with default values

i try to do littles changes like uncomment functions that may be important in understanding what it is and executing the code like:

file : test/mepsort_test.c

    bench_time(test1_insort, 1);
    bench_time(test2_insort, 1);
    bench_time(test1_mersort, 1);
    bench_time(test2_mersort, 100);

