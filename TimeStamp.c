#include <stdio.h>
 
int main(void)
{
	unsigned long long tsc;
 
	asm("rdtsc" : "=A"(tsc));
	printf("Timestamp counter: %llu\n", tsc);
 
	return 0;
}
