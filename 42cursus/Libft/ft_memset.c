#include <stdlib.h>

void *ft_memset(void *b, int c, size_t len)
{
    while (len > 0)
        *((unsigned char *)b + --len) = c;
    return (b);
}
