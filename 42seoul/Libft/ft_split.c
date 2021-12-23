#include <stdlib.h>

int str_count(char *str, char *charset)
{
    int i;
    int count;
    char *temp;

    count = 0;
    temp = str - 1;
    while (*str != 0)
    {
        i = -1;
        while (charset[++i] != 0)
        {
            if (charset[i] == *str)
            {
                if (str - temp > 1)
                    count++;
                temp = str;
                break;
            }
        }
        str++;
    }
    if (str - temp > 1)
        count++;
    return (count);
}

int char_count(char *str, char *charset)
{
    int index1;
    int index2;

    index1 = -1;
    while (str[++index1] != 0)
    {
        index2 = -1;
        while (charset[++index2] != 0)
        {
            if (charset[index2] == str[index1])
                break;
        }
        if (charset[index2] == str[index1])
            break;
    }
    return (index1);
}

char *rm_charset(char *str, char *charset)
{
    int index;
    int status;

    status = 1;
    while (*str != 0)
    {
        index = -1;
        while (charset[++index] != 0)
        {
            if (charset[index] == *str)
            {
                str++;
                status = 0;
                break;
            }
            status = 1;
        }
        if (status == 1)
            break;
    }
    return (str);
}

char **ft_split(char *str, char *charset)
{
    char **output;
    char *temp;
    int index1;
    int index2;

    output = (char **)malloc(sizeof(char *) * (str_count(str, charset) + 1));
    if (output == 0)
        return (0);
    index1 = -1;
    temp = str;
    while (++index1 < str_count(str, charset))
    {
        temp = rm_charset(temp, charset);
        output[index1] = (char *)malloc(1 * (char_count(temp, charset) + 1));
        if (output[index1] == 0)
            return (0);
        index2 = -1;
        while (++index2 < char_count(temp, charset))
            output[index1][index2] = temp[index2];
        output[index1][index2] = 0;
        temp += index2;
    }
    output[index1] = 0;
    return (output);
}