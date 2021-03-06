#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "programs.h"

void Professor() {
  //pthread_t professor = (pthread_t)malloc(sizeof(professor));
  //pthread_create(&professor, NULL, (void *)AnswerStart, (void *)i);
  int i;
    AnswerStart(&i);
    AnswerDone(&i);
    sem_post(&mutex);
}
