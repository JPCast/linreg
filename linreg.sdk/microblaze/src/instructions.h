#ifndef SRC_INSTRUCTIONS_H_
#define SRC_INSTRUCTIONS_H_

unsigned int reset();
unsigned int store_x(int x, unsigned int i, unsigned int j);
unsigned int store_y(int y, unsigned int i);
unsigned int store_t(int t, unsigned int i);
unsigned int store_a(int a);
unsigned int compute(unsigned int iter);

#endif
