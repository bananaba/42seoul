#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    int i;

    i = 0;
    if (!*s)
        return (0);
    substr = (char *)malloc(sizeof(char) * (len + 1));
    if (!substr)
        return (0);
    while (s[i] && i < start)
        i++;
    while (!s[i] && len > 0)
        substr[i - start] = s[i++];
    substr[i] = 0;
    return (substr);
}