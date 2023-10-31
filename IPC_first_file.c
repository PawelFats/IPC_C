#include "stdio.h"
#include <sys/types.h>
#include <unistd.h>


int main()
{
	int pid, ppid, uid;
	
	pid = getpid();
	ppid = getppid();
	uid = getuid();
	
	printf("PID this programm = %d\n", pid);
	
	printf("PPID this programm = %d\n", ppid);
	
	printf("UID this programm = %d\n", uid);
    
	return 0;
}
