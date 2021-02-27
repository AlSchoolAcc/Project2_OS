#include <stdio.h>
#include <pthread.h>
#include "programs.h"

void QuestionStart(void * id){
  long val = (long int)id;
  printf("Student %ld asks a question\n", val);
}

void QuestionDone(void * id){
  long val = (long int)id;
  printf("Student %ld is satisfied.\n", val);
}
