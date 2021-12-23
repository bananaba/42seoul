void *ft_memchr(void *str, int c, size_t n)
{
    int i;

    i = 0
    while (i < n)
    {
        if (*((char *)str + i) == c)
            return ((char *)str + i);
        i++;
    }
    return (0);
}