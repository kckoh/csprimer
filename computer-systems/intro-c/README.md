## How to automatically compile and run C when saved
sudo apt update
sudo apt install entr
cd computer-systems/intro-c
cd os
ls cputime.c | entr sh -c 'gcc cputime.c -o cputime && ./cputime'
ls hashmap.c | entr sh -c 'gcc hashmap.c -o hashmap && ./hashmap'
ls test.c | entr sh -c 'gcc test.c -o test && ./test'