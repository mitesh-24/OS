#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
	pid_t pid;
	pid = fork();
	if(pid>0)               //parent process
	{
		sleep(30);
		printf("parent process id %d ",getpid());
		printf("in parent process\n");	
	}
	else if(pid==0)        //child process
	{
		printf("child process id %d ",getpid());
		printf("in child process\n");
	}
	return 1;
}
