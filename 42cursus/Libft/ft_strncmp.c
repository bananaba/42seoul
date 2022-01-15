#include <stdlib.h>

int ft_strncmp(char *s1, char *s2, size_t n)
{
    unsigned char c1;
    unsigned char c2;
    unsigned int i;

    i = 0;
    if (n == 0)
        return (0);
    while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i] && i < n - 1)
        i++;
    c1 = s1[i];
    c2 = s2[i];
    return (c1 - c2);
}