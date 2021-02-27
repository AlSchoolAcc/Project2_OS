#include <stdio.h>
#include <pthread.h>
#include "programs.h"

void Professor() {
  int i;
	for(i = 0; i < 2; i++) {
		
    AnswerStart(&i);
		AnswerDone(&i);
	}
}
