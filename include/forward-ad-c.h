#ifndef FORWARD_AD_C_H
#define FORWARD_AD_C_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdlib.h>

typedef struct {
	double value;
	double *grad;
	double **hessian; 
	size_t n;
} DualVar;

DualVar *dvar_create(size_t n);
void dvar_free(DualVar *dvar);

DualVar *dvar_add(const DualVar *a, const DualVar *b);

#ifdef __cplusplus
}
#endif

#endif // FORWARD_AD_C_H
