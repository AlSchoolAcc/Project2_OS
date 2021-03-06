#include<semaphore.h>

extern sem_t mutex[];
extern int officeSize;

void Student(int id);

void Professor();

void AnswerStart(void * id);

void AnswerDone(void * id);

void EnterOffice(void * id);

void LeaveOffice(void * id);

void QuestionStart(void * id);

void QuestionDone(void * id);

