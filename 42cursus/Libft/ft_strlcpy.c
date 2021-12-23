unsigned int ft_strlcpy(char *dest, char *src, unsigned int n)
{
    unsigned int index;

    if (n >= 1)
    {
        index = 0;
        while (index < n - 1 && *(src + index) != '\0')
        {
            *(dest + index) = *(src + index);
            index++;
        }
        while (index < n)
            *(dest + index++) = '\0';
    }
    index = 0;
    while (src[index] != 0)
        index++;
    return (index);
}