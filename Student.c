#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "programs.h"

void Student(int id) {
  long val = (long)id;
  pthread_t student = (pthread_t)malloc(sizeof(student));
  int rc = pthread_create(&student, NULL, (void *)QuestionStart, (void *) val);
  pthread_join(student, NULL);
}
