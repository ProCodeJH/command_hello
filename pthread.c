#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 


void* print_numbers(void* arg) {
	int num = *((int*)arg);
	for(int i = 0; i < 5; i++) {
		printf("Thread %d: %d\n, num,i);
		sleep(1);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[2];
	int thread_args[2] = {1, 2};

	for(int i = 0; i < 2;  i++) {
		int result = pthread_create(&threads[i], NULL, print_numbers, (void*)&thread_args[i];
	if(result) {
	printf("스레드를 생성 하는데, 실패했습니다. 에러 코드: %d\n", result);
	exit(-1);
	}
}
for(int i = 0 ; i < 2; i++) {
pthread_join(threads[i], NULL);
}

printf("모든 스레드가 종료되었습니다.\n");
return 0;
	

