#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *run_func(void *arg)
{
    char *t_name = arg;
    for(int i=0; i < 5; i++) {
        printf("%s: %d\n", t_name, i);
    }

    return NULL;
}

int main() {

    pthread_t t1;
    pthread_t t2;
    char *t_name1 = "thread 1";
    char *t_name2 = "thread 2";

    printf("Launching thread\n");

    int status1 = pthread_create(&t1, NULL, run_func, t_name1);
    int status2 = pthread_create(&t2, NULL, run_func, t_name2);
    
    if (status1 < 0 || status2 < 0) {
        printf("--- Error in thread creation! ---");
        exit(0);
    }

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 

    printf("Threads complete!\n");
}