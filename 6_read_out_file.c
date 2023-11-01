#include <stdio.h>

#define LEN 100

int main(int argc, char * argv[])
{

	FILE *file_ptr;
	
	char str[LEN];
	
	file_ptr = fopen(argv[1], "r");
	
	if(file_ptr != NULL)
	{
		fgets(str, sizeof(str), file_ptr);
		fprintf(stdout, "%s\n", str);
	}
	else
		fprintf(stderr, "ERORR FILE!\n");
		
	return 0;
	
}
