#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "programs.h"

void EnterOffice(void * id){
  long val = (long int)id;
  printf("Student %ld enters the office\n", val);
}

void LeaveOffice(void * id){
  sem_post(&mutex);
  long val = (long int)id;
  printf("Student %ld leaves the office\n", val);
}
