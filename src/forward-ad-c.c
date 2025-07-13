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
    if (!dvar) return NULL;
    if (dvar->hessian) {
        for (size_t i = 0; i < dvar->n; ++i) {
            if (dvar->hessian[i]) free(dvar->hessian[i]);
        }
        free(dvar->hessian);
    }
    if (dvar->grad) free(dvar->grad);
    free(dvar);
};

DualVar *dvar_add(const DualVar *a, const DualVar *b) {
    if (!a || !b || a->n != b->n) return NULL;
    DualVar *r = dvar_create(a->n);
    if (!r) return NULL;
    r->value = a->value + b->value;
    for (size_t i = 0; i < a->n; ++i) {
        r->grad[i] = a->grad[i] + b->grad[i];
        for (size_t j = 0; j < a->n; ++j) {
            r->hessian[i][j] = a->hessian[i][j] + b->hessian[i][j];
        }
    }
    return r;
}