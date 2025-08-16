## How to automatically compile and run C when saved
sudo apt update
sudo apt install entr
cd computer-systems/intro-c
ls dynarray.c | entr sh -c 'gcc dynarray.c -o dynarray && ./dynarray'
ls test.c | entr sh -c 'gcc test.c -o test && ./test'