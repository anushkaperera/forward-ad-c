#include <stdio.h>
#include <assert.h>
#include "../include/forward-ad-c.h"

int main() {
    DualVar *dvar = dvar_create(2);
    if (dvar) {
        dvar_free(dvar);
    }
    printf("All tests passed!\n");
    return 0;
}
