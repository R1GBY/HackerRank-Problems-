#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

typedef struct _pi { 
float real_pi; 
int n; 
} pi_number; 

void *myfunc(void *vptr) {
    pi_number *my = (pi_number *)
    malloc(sizeof(pi_number));

    pi_number pi;
    pi = *((pi_number *)vptr);


    if(pi.n == -1991643855){ //for balancing loop value
        pi.n = 1;
    }

    my->n = pi.n; 

    sleep(1);


    if(my->n == 1){ //first value is 1
        my->real_pi = 4*1;
    }
    else if(my->n % 2 == 0){  //if it is an even loop number, decrease the result amount of calculation
        my->real_pi = pi.real_pi; 
        my->real_pi -= 4*(pow(1, my->n) / (2 * my->n -1)); 
    }
    else{ //if it is an odd loop number, decrease the result amount of calculation
        my->real_pi = pi.real_pi;
        my->real_pi += 4*(pow(1, my->n) / (2 * my->n -1));
    }
    my->n++; //increment the loop number
    pthread_exit((void*)my); //return the argument and exit thread
}


int main() {

    pthread_t pid;
    pthread_t first_pid;

    pi_number pi;
    void *vptr;

    int n;

    printf("Lutfen kac tur yakinsanacagini giriniz. \n");
    scanf("%d", &n);

    for(int i  = 0; i < n; i++){ //loop as much as loop number

        pthread_create(&pid, NULL, myfunc, vptr); 
        pthread_join(pid, &vptr); 

        pi = *((pi_number *)vptr); 
        if(pi.n % 2 == 0)
            printf("pi value: %f loop number: %u \n", pi.real_pi, pi.n - 1); //printing struct variables
    }
    free(vptr); //free the allocation
    return 0;
}