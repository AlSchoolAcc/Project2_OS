#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "programs.h"

void AnswerStart(void * id) {
  long val = (long int)id;
  printf("Professor starts to answer question for student %ld\n", val);
}

void AnswerDone(void *id) {
  long val = (long int)id;
  printf("Professor is done with answer for student %ld\n", val);
  sem_post(&mutex);
  sem_wait(&mutex);
}

