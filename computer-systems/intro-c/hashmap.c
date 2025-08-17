#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define STARTING_BUCKETS 8
#define MAX_KEY_SIZE 8
#define HASH unsigned int
typedef struct Node{
  char* key;
  void *val;
  struct Node *next;
} Node;

typedef struct Hashmap {
  Node **buckets;
  int num_buckets;
} Hashmap;

Hashmap *Hashmap_new(){
  Hashmap *h = malloc(sizeof(Hashmap));
  h->buckets = calloc(STARTING_BUCKETS, sizeof(Node));
  h->num_buckets = STARTING_BUCKETS;
  return h;
}

HASH simple_hash(const char *s){
  unsigned int h = 8351;
  char ch;
  while ((ch = *s++))
    h = (h << 5) + h + ch;
  return h;
}


void *Hashmap_get(Hashmap *h, char *key){

}

void Hashmap_set(Hashmap *h, char *key, void *val){
  // get the hash
  HASH hashed =  simple_hash(key);
  // get the index
  int i = hashed % h->num_buckets;
  
  Node *n = h->buckets[i];
  while (n != NULL) {
    if (n->hash == hash && strncmp(key, n->key, MAX_KEY_SIZE) == 0) {
      n->val = value;
      return;
    }
    n = n->next;
  }
  n = malloc(sizeof(Node));
  n->key = strdup(key);
  n->val = value;
  n->hash = hash;
  n->next = h->buckets[i];
  h->buckets[i] = n;


}

void Hashmap_delete(Hashmap *h, char *key ){

}

void Hashmap_free(Hashmap *h){

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
