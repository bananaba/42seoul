#include <stdio.h>

void print_splited(char **splited, char *name)
{
	int i;

	printf("print_splited : %s \n", name);
	i = -1;
	if (splited)
	{
		while(splited[++i])
		{
			printf("\t%s[%d]=%s\n", name, i, splited[i]);
		}
	}
	else
	{
		printf("\t is void pointer\n");
	}
	printf("end of print_splited : %s \n", name);

}

int main(int argc, char **argv)
{
	printf("argc = %d\n", argc);
	print_splited(argv, "argv");
	return(0);
}
