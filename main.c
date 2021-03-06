#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include "programs.h"

#define NUM_OF_STUDENTS 5
int officeSize = 3;
int professorDone = 0;

sem_t mutex;

void main(int argc, char **argv){
 sem_init(&mutex, 0, 1);
  long i;
  pthread_t students[NUM_OF_STUDENTS];
  pthread_t professor;
  for(i = 0; i < NUM_OF_STUDENTS;i++){
  pthread_create(&students[i], NULL, (void *)Student, (void *)i);
  pthread_create(&professor, NULL, (void *)Professor, NULL);
  pthread_join(students[i], NULL);
  }
 sem_destroy(&mutex);
}
