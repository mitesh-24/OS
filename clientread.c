#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
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
	
	if ((shmid = shmget(key, MAXSIZE, 0666)) < 0)
        die("shmget");

	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
        die("shmat");

	for (s = shm; *s != '\0'; s++){
		if(*s == '.'){
			putchar(*s);
			break;
		}
		putchar(*s);
	}
        
       putchar('\n');

	 *shm = '$';

    exit(0);
}

