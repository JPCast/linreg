#include "xil_printf.h"

void print_model(int T[], int n)
{
	xil_printf("\nModel is y = ");

	for (unsigned int i = 0; i < n-1; i++) {
		xil_printf("%d*x^%d + ", T[i], i);
	}

	xil_printf("%d*x^%d", T[n-1], n-1);
}

int abs(int i)
{
	return (i < 0 ? -i : i);
}

unsigned int has_converged(int Tnew[], int T[], int n, int threshold)
{
	unsigned int flag = 1;

	for(unsigned int i = 0; i < n; i++) {
		if(abs(Tnew[i] - T[i]) > threshold) {
			flag = 0;
		}
	}

	return flag;
}
