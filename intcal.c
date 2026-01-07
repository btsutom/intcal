#include "subf.h"
#include <stddef.h>
#include <stdlib.h>

int intcal(const char *a, const char *b, char t_calc, char **result)
{
    unsigned char *da, *db, *dr = NULL;
    size_t la, lb, lr;

    da = str2digits(a, &la);
    db = str2digits(b, &lb);
    if (!da || !db) return -1;

    switch (t_calc) {
    case 1: /* 加 */
        dr = add_digits(da, la, db, lb, &lr);
        break;
    case 2: /* 減 */
        if (cmp_digits(da, la, db, lb) < 0) return -1;
        dr = sub_digits(da, la, db, lb, &lr);
        break;
    case 3: /* 乗 */
        dr = mul_digits(da, la, db, lb, &lr);
        break;
    case 4: /* 除 */
        dr = div_digits(da, la, db, lb, &lr);
        break;
    case 5: /* 剰余 */
        dr = mod_digits(da, la, db, lb, &lr);
        break;
    default:
        return -1;
    }

    *result = digits2str(dr, lr);

    free(da);
    free(db);
    free(dr);
    return (*result) ? 0 : -1;
}

