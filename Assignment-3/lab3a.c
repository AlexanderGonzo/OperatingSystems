#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#include <math.h>


#define NUMOFSTUDENTS 3
#define RATE 0.25
static int scholarship = 4000;
static int totalRewarded;
static void *threadFunction(void *id);

int main(){
    long i;
    int j;
    pthread_t tid[3];

    // Let us create three threads
    for (i = 0; i < NUMOFSTUDENTS; i++){
        pthread_create(&tid[i], NULL, threadFunction, (void *)i);
    }
    for(j = 0; j < NUMOFSTUDENTS; j++){
        pthread_join(tid[j], NULL);
    }
    printf("Total rewarded: %d\n", totalRewarded);

    return 0;
}
static void *threadFunction(void *id){

    int studentID = (long)id;
    int reward;

    while(1){

        if (scholarship < 1){
            return 0;
        }
        reward = ceil(scholarship * RATE);
        scholarship = scholarship - ceil(scholarship * RATE);
        totalRewarded = totalRewarded + reward;
        if(reward >= 1 && scholarship >= 1){

        printf("%c= %d\n", 'A' + studentID, reward);
        
        }
    }
    pthread_exit(NULL);
}