char *ft_strnstr(const char *big, const char *little, size_t len)
{
    int index;

    while (*little != 0 && *big != 0 && len > 0)
    {
        index = 0;
        while (len - index > 0 && little[index] == big[index])
        {
            index++;
            if (little[index] == 0)
                return (big);
        }
        big++;
        len--;
    }
    return (0);
}