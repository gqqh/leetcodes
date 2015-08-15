#include <stdio.h>
#include <unistd.h>
/*
int main(){
	fork();
	fork() && fork() || fork();
	fork();
	printf("hello %d.\n", getpid());

	return 0;
}//return 20 lines
*/
int main()
{
	/*int i;
	for(i = 0; i < 2; i++){
		fork();
		printf("-");
	}//print 8 '-'s
	*/
	int i;
	for( i = 0; i < 2; i++){
		fork();
		printf("-\n");
	}//print 6 '-'s
	

	return 0;
}
