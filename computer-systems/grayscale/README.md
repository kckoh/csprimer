if i utilize the the continuous memory, i can use the cache line to improve the performance.

code:
 for (x = 0; x < width; x++) {
    for (y = 0; y < height; y++) {
      offset = 3 * (y * width + x);

the memory is accessed through offset and it accesses in a column major rather than row major, which does not utilize the cache. This happens automatically.

Testing
without optimization:
1. 0.191s
2. 0.197s
3. 0.226s
4. 0.175
5. 0.221s
1.005/5 = 0.201

with optimization:
1. 0.145s
2. 0.158s
3. 0.152s
4. 0.148s
5. 0.143s
0.746/5 = 0.149

(0.201 - 0.149)/0.201 = 0.052/0.201 = 0.26

