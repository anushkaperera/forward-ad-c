#include <stdio.h>
#include <assert.h>
#include "../include/forward-ad-c.h"

int main() {
    printf("...\n");
    DualVar *a = dvar_create(2);
    DualVar *b = dvar_create(2);
    DualVar *r = dvar_create(2);
    DualVar *r2 = dvar_create(2);
    a->value = 1.0;
    a->grad[0] = 1.0;
    a->grad[1] = 0.0;
    b->grad[0] = 0.0;
    b->grad[1] = 1.0;
    b->value = 2.0;
    r = dvar_add(a, b);
    r2 = dvar_add(r, b);
    printf("%f %f %f\n", r2->value, r2->grad[0], r2->grad[1]);
    if (a) {
        dvar_free(a);
    }
    if (b) {
        dvar_free(b);
    }
    if (r) {
        dvar_free(r);
    }
    return 0;
}
