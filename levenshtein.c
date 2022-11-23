#include <stdio.h>
#include <stdlib.h>

size_t my_strlen(const char *s)
{
    const char *st;
    for (st = s; *st; ++st)
    {
        continue;
    }
    return (st - s);
}

size_t max(size_t a, size_t b)
{
    if (a >= b)
        return a;
    return b;
}

size_t min(size_t x, size_t y, size_t z)
{
    if ((x <= y) && (x <= z))
        return x;
    else if ((y <= x) && (y <= z))
        return y;
    else
        return z;
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t len1 = my_strlen(s1);
    size_t len2 = my_strlen(s2);
    if ((min(len1, len1, len2) == 0))
        return max(len1, len2);
    if (*s1 == *s2)
        return levenshtein(s1 + 1, s2 + 1);
    size_t x = levenshtein(s1 + 1, s2);
    size_t y = levenshtein(s1, s2 + 1);
    size_t z = levenshtein(s1 + 1, s2 + 1);
    return 1 + min(x, y, z);
}
