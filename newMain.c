#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
//#include "programs.h"

#define NUM_OF_STUDENTS 5
#define OFFICE_SIZE 3

int officeBuffer[3];
int officeOcc = 0;
sem_t readyQuestion, askingQuestion, waitingAnswer;
pthread_mutex_t mutex;

void Student(int id);
void Professor();
void QuestionStart(int id);
void QuestionDone(int id);
void AnswerStart(int id);
void AnswerDone(int id);
void EnterOffice(int id);
void LeaveOffice(int id);

void QuestionStart(int id){
  printf("Student %d asks a question\n", id);
}

void QuestionDone(int id){
  printf("Student %d is satisfied\n", id);
}

void AnswerStart(int id) {
  printf("Professor starts to answer question for student %d\n", id);
}

void AnswerDone(int id) {
  printf("Professor is done with answer for student %d\n", id);
}

void EnterOffice(int id){
	pthread_mutex_lock(&mutex);
	if(officeOcc < 3 && officeOcc >= 0){
		printf("Student %d enters the office\n", id);
		officeOcc++;
	}
	pthread_mutex_unlock(&mutex);
}

void LeaveOffice(int id){
	pthread_mutex_lock(&mutex);
	if(officeOcc > 0){
		printf("Student %d leaves the office\n", id);
		officeOcc--;
	}
	pthread_mutex_unlock(&mutex);
}

void Student(int id) {
  int i;
	unsigned int numOfQuestions = (rand() % 5) + 1;
	EnterOffice(id);
  for(i=0; i < numOfQuestions; i++){
		sem_wait(&readyQuestion);
		pthread_mutex_lock(&mutex);
		QuestionStart(id);
		sem_post(&askingQuestion);
		sem_wait(&waitingAnswer);
		QuestionDone(id);
		pthread_mutex_unlock(&mutex);
	}
  LeaveOffice(id);
}

void Professor(int id) {
    while(1){
			sem_post(&readyQuestion);
			sem_wait(&askingQuestion);
			AnswerStart(id);
			AnswerDone(id);
			sem_post(&waitingAnswer);
		}
}

void main(int argc, char **argv){
	srand(time(NULL));
  sem_init(&readyQuestion, 1, 0);
	sem_init(&askingQuestion, 1, 0);
	sem_init(&waitingAnswer, 1, 0);
  pthread_mutex_init(&mutex, NULL);
	long i;
  pthread_t students[NUM_OF_STUDENTS];
  pthread_t professor;
  for(i = 0; i < NUM_OF_STUDENTS;i++){
		pthread_create(&students[i], NULL, (void *)Student, (void *)i);
	  pthread_create(&professor, NULL, (void *)Professor, (void *)i);
  }
  
  //for(i = 0; i < NUM_OF_STUDENTS;i++){
		//pthread_join(students[i], NULL);
		//pthread_join(professor, NULL);
	//}
 sem_destroy(&readyQuestion);
 sem_destroy(&askingQuestion);
 sem_destroy(&waitingAnswer);
 pthread_mutex_destroy(&mutex);
}
