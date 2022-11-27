#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){

	pid_t pid = fork();
	
	if (pid > 0)
		printf("Parent has finished with process id : %d !!",getpid());
	
	else if (pid == 0){
		sleep(2);
		printf("Child process is still running on process id %d !!",getpid());
	}
	return 0;
}

