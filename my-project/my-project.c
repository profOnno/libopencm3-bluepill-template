#include "../my-common-code/api.h"
#include <stdint.h>
//#include "../my-common-code/api-asm.h"

int main(void) {
	/* add your own code */
	uint32_t rev = 0xaabbccdd;
//	rev = rev_bytes(rev);
	return my_func(rev);
}
