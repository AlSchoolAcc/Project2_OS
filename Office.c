#include <stdio.h>
#include <pthread.h>
#include "programs.h"

void EnterOffice(void * id){
  long val = (long int)id;
  printf("Student %ld enters the office\n", val);
}

void LeaveOffice(void * id){
  long val = (long int)id;
  printf("Student %ld leaves the office\n", val);
}
