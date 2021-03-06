#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "programs.h"

void QuestionStart(void * id){
  long val = (long int)id;
  printf("Student %ld asks a question\n", val);
 // sem_wait(&mutex);
}

void QuestionDone(void * id){
  long val = (long int)id;
  printf("Student %ld is satisfied.\n", val);
  //sem_post(&mutex);
  //sem_wait(&mutex);
}
