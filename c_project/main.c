#include <stdbool.h>
#include "hal.h"

static inline uint32_t simple_plugin(uint32_t input_1, uint32_t input_2){
	uint32_t output;
	asm volatile(".insn r CUSTOM_0, 0x0, 0x0, %0, %1, %2" : "=r" (output) : "r" (input_1), "r" (input_2));
	return output;
}

int main(void)
{
	printf("HELLO WORLD\n");
	uint32_t  a = 12;
	uint32_t  result_1 = 0;
	uint32_t  result_2 = 0;

	while (1) {
		result_1 = a + result_1 + 2;
		printf("C-calculation:\n");
		printf("result_1 = %d\n", result_1);
		result_2 = simple_plugin(a, result_2);
		printf("Simple Plugin:\n");
		printf("result_2 = %d\n", result_2);
	}
	return 0;
}
