#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "programs.h"

#define NUM_OF_STUDENTS 5

void main(int argc, char **argv){
  int i;
  pthread_t students[NUM_OF_STUDENTS];
  for(i = 0; i < NUM_OF_STUDENTS;i++){
    Student(i);
  }
}
