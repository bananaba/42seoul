#include "libft.h"

size_t ft_strlcat(char *dest, char *src, size_t size)
{
    unsigned int index;
    unsigned int d_len;
    unsigned int s_len;

    d_len = ft_strlen(dest);
    s_len = ft_strlen(src);
    index = 0;
    while (d_len + index < size - 1 && *(src + index) != 0 && size >= 1)
    {
        *(dest + d_len + index) = *(src + index);
        index++;
    }
    *(dest + d_len + index) = 0;
    if (d_len >= size)
        return (size + s_len);
    else
        return (d_len + s_len);
}