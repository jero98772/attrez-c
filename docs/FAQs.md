# FAQs attrez-c
### compile
* **Question** :i am new in c and i try to compile some file like test/hash_test.c
i try run:

		$ gcc test/hash_test.c -o hash
i get out like:

		/usr/bin/ld: /tmp/ccd4QFPW.o: in function `hhh_debugp':
		hash_test.c:(.text+0x5a4): undefined reference to `dec2bstr'
		collect2: error: ld returned 1 exit status
* **Answer** : try add others files linked to hash_test.c ,files like malg/meputil.h  malg/meputil.c
try run in 
		
		$ gcc test/hash_test.c malg/meputil.h  malg/meputil.c  -o hash