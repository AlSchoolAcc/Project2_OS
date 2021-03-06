#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include "programs.h"

#define NUM_OF_STUDENTS 5
int officeSize = 3;

sem_t mutex[NUM_OF_STUDENTS];

void main(int argc, char **argv){
 sem_init(&mutex[0], 0, 1);
  int i;
  pthread_t students[NUM_OF_STUDENTS];
  for(i = 0; i < NUM_OF_STUDENTS;i++){
    Student(i);
    Professor();
  }
 sem_destroy(&mutex);
}
