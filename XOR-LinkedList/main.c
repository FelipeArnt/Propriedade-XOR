#include "xor_list.h"

int main(void)
{
    XorList *l = xl_new();
    if (!l) return 1;

    for (int x = 1; x <= 10; ++x)
        xl_append(l, x);

    xl_print_reverso(l);
    xl_free(l);
    return 0;
}
