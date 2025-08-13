## How to automatically compile and run C when saved
sudo apt update
sudo apt install entr
ls dynarray.c | entr sh -c 'gcc dynarray.c -o dynarray && ./dynarray'