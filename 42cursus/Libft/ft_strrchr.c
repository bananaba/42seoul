char *ft_strrchr(const char *str, int c)
{
    char *ret;

    ret = 0;
    while (*str != 0)
    {
        if (*str == c)
            ret = str;
        str++;
    }
    return (ret);
}