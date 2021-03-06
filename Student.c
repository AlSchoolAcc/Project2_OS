#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "programs.h"
void Student(int id) {
  long val = (long)id;
  EnterOffice((void *)val);
  pthread_t student = (pthread_t)malloc(sizeof(student));
  pthread_create(&student, NULL, (void *)QuestionStart, (void *) val);
  //sem_wait(&mutex);
  pthread_create(&student, NULL, (void *)QuestionDone, (void *) val);
  //QuestionDone((void *)val);
  //LeaveOffice((void *)val);
  pthread_create(&student, NULL, (void *)LeaveOffice, (void *) val);
  pthread_join(student, NULL);
}
