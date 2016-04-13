#include <stdio.h>
 
int main(void)
{
	int op, eax, ebx, ecx, edx, i;
 
	op = 0;
	__asm__("cpuid" \
			: "=b"(ebx), \
			"=c"(ecx), \
			"=d"(edx) \
			: "a"(op));
	printf("Vendor ID: ");
	printf("%c%c%c%c", ebx & 0xff, (ebx >> 8) & 0xff, (ebx >> 16) & 0xff,
			(ebx >> 24) & 0xff);
	printf("%c%c%c%c", edx & 0xff, (edx >> 8) & 0xff, (edx >> 16) & 0xff,
			(edx >> 24) & 0xff);
	printf("%c%c%c%c", ecx & 0xff, (ecx >> 8) & 0xff, (ecx >> 16) & 0xff,
			(ecx >> 24) & 0xff);
	printf("\n");
 
	printf("Processor brand: ");
	for(op = 0x80000002; op < 0x80000005; op++) {
 		__asm__("cpuid" \
 				: "=a"(eax), \
 				"=b"(ebx), \
 				"=c"(ecx), \
 				"=d"(edx) \
 				: "0"(op));
 		printf("%c%c%c%c", eax & 0xff, (eax >> 8) & 0xff, (eax >> 16) & 0xff,
				(eax >> 24) & 0xff);
		printf("%c%c%c%c", ebx & 0xff, (ebx >> 8) & 0xff, (ebx >> 16) & 0xff,
				(ebx >> 24) & 0xff);
		printf("%c%c%c%c", ecx & 0xff, (ecx >> 8) & 0xff, (ecx >> 16) & 0xff,
				(ecx >> 24) & 0xff);
		printf("%c%c%c%c", edx & 0xff, (edx >> 8) & 0xff, (edx >> 16) & 0xff,
				(edx >> 24) & 0xff);
	}
	printf("\n");
}
