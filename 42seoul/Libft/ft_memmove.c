void *ft_memmove(void *dest, const void *src, size_t n)
{
    int i;

    if (dest <= src)
    {
        i = 0;
        while (i < n)
            *((char *)dest + i) = *((char *)src + i++);
    }
    else
    {
        i = n - 1;
        while (i >= 0)
            *((char *)dest + i) = *((char *)src + i--);
    }
    return (dest);
}