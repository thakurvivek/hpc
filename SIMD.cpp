#include "stdafx.h"
string get_cpu_name()
{
	  uint32_t data[4] = { 0 };
	  /*asm(
			  "cpuid\n\t"
			  "mov"(data[0])", ebx\n\t"
			  "mov"(data[4])", edx\n\t"
			  "mov"(data[8])", ecx"
			  );
			  */
asm ("cpuid"
		                : "=a" (_eax),
				                  "=b" (_ebx),
						                    "=c" (_ecx),
								                      "=d" (_edx)
										                      : "a" (op));
	  return string((const char*)data);
}

int main(int argc, char* argv[]){
	cout << get_cpu_name();
}
