#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include <unistd.h>
#include<stdlib.h>

#define MAXSIZE 27

void die(char *s)
{
	perror(s);
	exit(1);
}

int main()
{
	char c;
	int shmid;
	key_t key = 4567;
	char *shm,*s;

	
	if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
        die("shmget");

	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
        die("shmat");

	s = shm;
	char buff[MAXSIZE];
	printf("Write : ");
	scanf("%[^\n]",buff);
	
    	for(int i=0;i<MAXSIZE;i++){
    		if(buff[i] == '.'){
    			*s++ = buff[i];
    			break;
    		}
    		*s++ = buff[i];
    	}
	
	while (*shm != '$')
        sleep(1);

    	exit(0);
}

