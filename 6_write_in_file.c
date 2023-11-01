#include <stdio.h>

#define LEN 100

int main(int argc, char * argv[])
{

	FILE *file_ptr;
	
	char str[LEN];
	
	file_ptr = fopen(argv[1], "w");
	
	if(file_ptr != NULL)
	{
		fputs(argv[2], file_ptr);
	}
	else
		fprintf(stderr, "ERORR FILE!\n");
		
	return 0;
	
}
