#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

	pid_t pid;
	int rv;
	
	int num_s = argc - 1;
	int *sides = (int *)malloc(num_s * sizeof(int));
	for (int i = 0; i < num_s; i++)
	{
		sides[i] = atoi(argv[i + 1]);	
	}
	
	switch(pid = fork())
	{
		case -1:
			perror("fork");
			exit(EXIT_FAILURE);
			
		case 0:
			printf("CHILD: process ID: %d\n", getpid());
			
			int s1;
			s1 = sides[0] * sides[1];
			printf("CHILD: square: %d\n", s1);
			
			exit(EXIT_SUCCESS);
			
		default:
			sleep(1);
			printf("\n");
			printf("PARENT: process ID: %d\n", getpid());
			printf("PARENT: child process ID: %d\n", pid);
			
			int s2;
			s2 = sides[2] * sides[3];
			printf("PARENT: square: %d\n", s2);
			
			wait(&rv);
			printf("PARENT: RETURN STATUS FOR CHILD: %d\n", WEXITSTATUS(rv));
	}
			
	return 0;
}
