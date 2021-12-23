#include <stdlib.h>
#include <stdio.h>

char *ft_strchr(const char *str, int c)
{
    while (*str != 0)
    {
        if (*str == c)
            return (str);
        str++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *start;
    char *end;
    char *trim;
    int len;

    start = s1;
    while (*start && ft_strchr(set, *start))
        start++;
    end = start;
    while (*end)
    {
        if (!ft_strchr(set, *end))
            len = end - start + 1;
        end++;
    }
    trim = (char *)malloc(sizeof(char) * (len + 1));
    if (!trim)
        return (0);
    trim[len] = 0;
    while (--len >= 0)
        trim[len] = start[len];
    return (trim);
}

int main()
{
    printf("%s\n", ft_strtrim("abqbc", "abc"));
    printf("%s\n", ft_strtrim("xavocadoyz", "xyz"));
    return 0;
}