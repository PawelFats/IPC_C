#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void exit_handler(void);

int main(int argc, char *argv[])
{
	pid_t pid;
	int rv;
		
	printf("\n");
	
	switch(pid = fork())
	{
		case -1:
			 perror("fork()\n");
			 exit(EXIT_FAILURE);
		
		case 0:
			printf("CHILD process ID: %d\n", getpid());
			
			for (int i = 0; i <argc; i++)
			{
				printf("CHILD: Arguments ch%d: %s\n", i, argv[i]);
			}
			
			exit(EXIT_SUCCESS);
			
		
		default:
			sleep(1);
			printf("\n");
			
			printf("PARENT process ID: %d\n", getpid());
			
			for (int i = 0; i <argc; i++)
			{
				printf("PARENT: Arguments %d: %s\n", i, argv[i]);
			}
			
			printf("\n");
			wait(&rv);
			printf("PARENT: RETURN STATUS FOR CHILD - %d\n", WEXITSTATUS(rv));
			printf("\n");
	
	}
	
	exit_handler;

	return 0;
}

void exit_handler(void) 
{
	printf("Program completed!\n");
}
