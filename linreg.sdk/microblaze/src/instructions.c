#include "mb_interface.h"
#include "xil_printf.h"

#define OPCODE_RESET   4
#define OPCODE_STORE_X 0
#define OPCODE_STORE_Y 1
#define OPCODE_STORE_T 2
#define OPCODE_STORE_A 5
#define OPCODE_COMPUTE 3

unsigned int reset()
{
	unsigned int inst = 0; // don't care
	inst = ((OPCODE_RESET << 29) | inst);

	//xil_printf("\nInstruction 0x%08x: reset coprocessor registers and state", inst);
	putfsl(inst, 0);

	return inst;
}

unsigned int store_x(int x, unsigned int i, unsigned int j)
{
	unsigned int inst = (x & 0x007fffff);
	inst = ((j << 23) & 0x03800000) | inst;
	inst = ((i << 26) & 0x1C000000) | inst;
	inst = (OPCODE_STORE_X << 29) | inst;

	putfsl(inst, 0);
	//xil_printf("\nInstruction 0x%08x: stored X[%d][%d] = 0x%08x = %d", inst, i, j, x, x);

	return inst;
}

unsigned int store_y(int y, unsigned int i)
{
	unsigned int inst = (y & 0x03ffffff);
	inst = ((i << 26) & 0x1C000000) | inst;
	inst = (OPCODE_STORE_Y << 29) | inst;

	putfsl(inst, 0);
	//xil_printf("\nInstruction 0x%08x: stored Y[%d] = 0x%08x = %d", inst, i, y, y);

	return inst;
}

unsigned int store_t(int t, unsigned int i)
{
	unsigned int inst = (t & 0x03ffffff);
	inst = ((i << 26) & 0x1C000000) | inst;
	inst = (OPCODE_STORE_T << 29) | inst;

	putfsl(inst, 0);
	//xil_printf("\nInstruction 0x%08x: stored T[%d] = 0x%08x = %d", inst, i, t, t);

	return inst;
}

unsigned int store_a(int a)
{
	unsigned int inst = (a & 0x03ffffff);
	inst = (OPCODE_STORE_A << 29) | inst;

	//xil_printf("\nInstruction 0x%08x: stored alpha = 0x%08x = %d", inst, a, a);
	putfsl(inst, 0);

	return inst;
}

unsigned int compute(unsigned int iter)
{
	unsigned int inst = iter;
	inst = (OPCODE_COMPUTE << 29) | inst;

	putfsl(inst, 0);
	//xil_printf("\nInstruction 0x%08x: issued iteration %d of gradient descent", inst, iter);

	return inst;
}
