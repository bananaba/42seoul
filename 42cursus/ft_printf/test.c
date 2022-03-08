#include <stdio.h>

int main()
{
	int a = printf("%+d|\n", 0);
	printf("a : %d\n", a);
	a = printf("%9223372036854775820d\n", 42);
	printf("a : %d\n", a);
	printf("%lld\n", (long long)9223372036854775808);
	return 0;
}
