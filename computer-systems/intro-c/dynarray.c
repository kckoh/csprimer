#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define STARTING_CAPACITY 8

typedef struct DA {
  // TODO define our struct
  void **arr;
  int capacity;
  int current;
} DA;


DA* DA_new (void) {
  // TODO allocate and return a new dynamic array
  DA * da = malloc(sizeof(DA));
  da->capacity = STARTING_CAPACITY;
  da->current = 0;
  da->arr = malloc(STARTING_CAPACITY * sizeof(void*));
  return da;
}

int DA_size(DA *da) {
  // TODO return the number of items in the dynamic array
  return da->current;
}

void DA_push (DA* da, void* x) {
  // TODO push to the end
  // check the capacity
  // if capacity == current + 1
  // increase the da->arr and reallocate and append it to the end
  // otherwise, add it to the end
  if(da->capacity == da->current){
    da->capacity = da->capacity * 2;
    da->arr = realloc(da->arr, da->capacity * sizeof(void *));
  }
  da->arr[da->current] = x;
  da->current++;
}

void *DA_pop(DA *da) {
  // TODO pop from the end
  if(da->current == 0){
    return NULL;
  }
  void *pop = da->arr[da->current - 1];
  da->current--;
  return pop;
}

void DA_set(DA *da, void *x, int i) {
  // TODO set at a given index, if possible
  da->arr[i] = x;
}

void *DA_get(DA *da, int i) {
  // TODO get from a given index, if possible
  return da->arr[i];
}


void DA_free(DA *da) {
  // TODO deallocate anything on the heap
  free(da->arr);
  free(da);
}

int main() {
    DA* da = DA_new();

    assert(DA_size(da) == 0);

    // basic push and pop test
    int x = 5;
    float y = 12.4;
    DA_push(da, &x);
    DA_push(da, &y);
    assert(DA_size(da) == 2);
    printf("%p\n", &y);
    assert(DA_pop(da) == &y);
    assert(DA_size(da) == 1);

    assert(DA_pop(da) == &x);
    assert(DA_size(da) == 0);
    assert(DA_pop(da) == NULL);

    // basic set/get test
    DA_push(da, &x);
    DA_set(da, &y, 0);
    assert(DA_get(da, 0) == &y);
    DA_pop(da);
    assert(DA_size(da) == 0);

    // expansion test
    DA *da2 = DA_new(); // use another DA to show it doesn't get overriden
    DA_push(da2, &x);
    int i, n = 100 * STARTING_CAPACITY, arr[n];
    for (i = 0; i < n; i++) {
      arr[i] = i;
      DA_push(da, &arr[i]);
    }
    assert(DA_size(da) == n);
    for (i = 0; i < n; i++) {
      assert(DA_get(da, i) == &arr[i]);
    }
    for (; n; n--)
      DA_pop(da);
    assert(DA_size(da) == 0);
    assert(DA_pop(da2) == &x); // this will fail if da doesn't expand

    DA_free(da);
    DA_free(da2);
    printf("OK\n");
}
