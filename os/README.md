## running a c program
ls bytewrite.c | entr sh -c 'gcc bytewrite.c -o bytewrite && ./bytewrite'

## generate a random bytes to a file 
head -c 4097 /dev/urandom > hello.txt


what i don't know
block
sector
