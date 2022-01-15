#include <stdlib.h>

int ft_memcmp(const void *str1, const void *str2, size_t n)
{
    unsigned char c1;
    unsigned char c2;

    while (n-- > 0)
    {
        if (*(char *)str1 != *(char *)str2)
        {
            c1 = *(char *)str1;
            c2 = *(char *)str2;
            return (c1 - c2);
        }
        (char *)str1++;
        (char *)str2++;
    }
    return (0);
}