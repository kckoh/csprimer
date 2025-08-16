#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define STARTING_BUCKETS 8
#define MAX_KEY_SIZE 20
/*
hashmap -> a key, value datastructure
dict = {}
dict['a'] = 2
hash the key and get a number -> hash % mod to store the value 
collision -> if there is a collision, do open addressing
open addressing -> find an empty spot (+1) and store the data there

keys array
val array
hash the keys -> store the keys in there
at the same time, store the values in the val array
[0,1,2,3,4,5,6,7]

what if they are all full?

*/

typedef struct Hashmap {
void **key_buckets;
void **val_buckets;
int bucket_size;
} Hashmap;

Hashmap *Hashmap_new(){
  Hashmap *h = malloc(sizeof(Hashmap));
  h->bucket_size = STARTING_BUCKETS;
  h->key_buckets = malloc(h->bucket_size * sizeof(void *));
  h->val_buckets = malloc(h->bucket_size * sizeof(void *));
  return h;
}
// returns hashed index given the string 
unsigned int simple_hash_index(const char *str, int bucket_size) {
    unsigned int hash = 0;
    while (*str) {
        hash += (unsigned char)(*str);
        str++;
    }
    return hash % bucket_size;
}



void Hashmap_set(Hashmap * h, char *key, void * val_ptr){
  // hash
  unsigned int hash = simple_hash(key);
  // get the index
  unsigned int index = hash % h->bucket_size;
  h->key_buckets[index] = key;
  h->val_buckets[index] = val_ptr;

}

void Hashmap_get (Hashmap *h, char *key) {
  unsigned int hash = simple_hash(key);
  
  if (h->key_buckets[index])

}

void Hashmap_delete(Hashmap *h, const char *keys){

}

void Hashmap_free(Hashmap *h) {

}





int main() {
  Hashmap *h = Hashmap_new();

  // basic get/set functionality
  int a = 5;
  float b = 7.2;
  Hashmap_set(h, "item a", &a);
  Hashmap_set(h, "item b", &b);
  assert(Hashmap_get(h, "item a") == &a);
  assert(Hashmap_get(h, "item b") == &b);

  // using the same key should override the previous value
  int c = 20;
  Hashmap_set(h, "item a", &c);
  assert(Hashmap_get(h, "item a") == &c);

  // basic delete functionality
  Hashmap_delete(h, "item a");
  assert(Hashmap_get(h, "item a") == NULL);

  // handle collisions correctly
  // note: this doesn't necessarily test expansion
  int i, n = STARTING_BUCKETS * 10, ns[n];
  char key[MAX_KEY_SIZE];
  for (i = 0; i < n; i++) {
    ns[i] = i;
    sprintf(key, "item %d", i);
    Hashmap_set(h, key, &ns[i]);
  }
  for (i = 0; i < n; i++) {
    sprintf(key, "item %d", i);
    assert(Hashmap_get(h, key) == &ns[i]);
  }

  Hashmap_free(h);
  /*
     stretch goals:
     - expand the underlying array if we start to get a lot of collisions
     - support non-string keys
     - try different hash functions
     - switch from chaining to open addressing
     - use a sophisticated rehashing scheme to avoid clustered collisions
     - implement some features from Python dicts, such as reducing space use,
     maintaing key ordering etc. see https://www.youtube.com/watch?v=npw4s1QTmPg
     for ideas
     */
  printf("ok\n");
}
