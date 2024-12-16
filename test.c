#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int i = 0;
	i = write(1, "abcd", 4);
	printf("\n%i\n", i);
	return 0;
}
