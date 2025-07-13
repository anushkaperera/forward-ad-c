#include "forward-ad-c.h"

DualVar *dvar_create(size_t n) {
    DualVar *dvar = (DualVar *)malloc(sizeof(DualVar));
    dvar->n = n;
    if (!dvar) return NULL;
    dvar->value = 0.0;
    dvar->grad = (double *)malloc(n, sizeof(double));
    if (!dvar->grad) {
        free(dvar);
        return NULL;
    };
    dvar->hessian = (double **)malloc(n * sizeof(double *));
    if (!dvar->hessian) {
        free(dvar);
        free(dvar->grad);
        return NULL;
    };
    return dvar;
};

void dvar_free(DualVar *dvar) {
    if (!dvar) return;
    for (size_t i = 0; i < dvar->n; ++i) {
        free(dvar->hessian[i]);
    }
    free(dvar->hessian);
    free(dvar->grad);
    free(dvar);
};