#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//#define CORE_MAX 4
#define CPU_HZ 3093054000

//通过设计计算和休息的时间比例，可以调整CPU曲线，但是在多核CPU上要绑定核
int main(int argc, char *argv[])
{
	int percent = 50;
    if(argc == 2){
        int tmp = atoi(argv[1]);
        if(tmp >= 0 && tmp <= 100)
            percent = tmp;
    }

    //banding to core 0
    int cpu_no = 0;
    cpu_set_t cpuset; //cpu set
    pthread_t thread; //thread
    
    thread = pthread_self(); //current thread
    /* Set affinity mask to CORE_MAX-1 */
    CPU_ZERO(&cpuset); 
    CPU_SET(cpu_no, &cpuset);
    /*set affinity to this thread*/ 
    int s = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
    if (s != 0){
        printf("set affinity fails.\n");
        exit(1);
    }
    printf("banding to core %d.\n", cpu_no + 1);
    
    unsigned int i, j;
    float per = percent / 100.0;
    printf("percent: %f\n", per);
    unsigned int work_t =(unsigned int)(CPU_HZ * 45/100.0* per / 100 * 0.4); //10ms
    unsigned int sleep_t = (unsigned int)(10000 * (1-per));
    while(1){
	    //计算
        for(i = 0; i < work_t; i++){
            j++;
        }
	//休息
        usleep(sleep_t); //sleep
    }
    exit(EXIT_SUCCESS);
}
