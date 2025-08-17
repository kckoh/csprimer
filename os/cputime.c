#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <sys/resource.h>

#define SLEEP_SEC 3
#define NUM_MULS 100000000
#define NUM_MALLOCS 100000
#define MALLOC_SIZE 1000

/*
1. Research needed syscals and lib functions
2. print pid getpid #include <unistd.h> sched_getcpu
3. determine elasped real time  gettimeofday
4. determine elasped time on CPU both user and system
*/
// TODO define this struct
struct profile_times {
  pid_t process_id;
  int cpu;
  
};

// TODO populate the given struct with starting information
void profile_start(struct profile_times *t) {
  t->process_id = getpid();
  t->cpu = sched_getcpu();
}

// TODO given starting information, compute and log differences to now
void profile_log(struct profile_times *t) {
  struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        printf("[pid %d] [CPU %d] User CPU time: %ld.%06ld sec System CPU time System CPU time: %ld.%06ld sec\n ",
               t->process_id,  t->cpu,
              usage.ru_utime.tv_sec, usage.ru_utime.tv_usec,
              usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
    }
}

int main(int argc, char *argv[]) {
  struct profile_times t;
  
  // TODO profile doing a bunch of floating point muls
  float x = 1.0;
  profile_start(&t);
  for (int i = 0; i < NUM_MULS; i++)
    x *= 1.1;
  profile_log(&t);

  // TODO profile doing a bunch of mallocs
  profile_start(&t);
  void *p;
  for (int i = 0; i < NUM_MALLOCS; i++)
    p = malloc(MALLOC_SIZE);
    profile_log(&t);

  // TODO profile sleeping
  profile_start(&t);
  sleep(SLEEP_SEC);
  profile_log(&t);
}



/*
Thought process
1. use apropos to find the necessary sys calls
2. apropos -s 2 3 -> it filters only syscalls and c lib
3. man times -> in see also getrusage -> asked chatgpt to find how to use getrusage
4. implement the basic profile_log

*/