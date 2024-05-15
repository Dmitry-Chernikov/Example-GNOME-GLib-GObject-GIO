#ifndef __KOTES_H__
#define __KOTES_H__

typedef double (*int_fun)(double);

double Kotes(int_fun f, double a, double b, int n);

#endif
