int ft_atoi(char *str)
{
    int index;
    int temp1;
    int temp2;

    index = 0;
    temp1 = 1;
    temp2 = 0;
    while ((str[index] >= 9 && str[index] <= 13) || str[index] == ' ')
        index++;
    while (str[index] == '+' || str[index] == '-')
    {
        if (str[index] == '-')
            temp1 *= -1;
        index++;
    }
    while (str[index] >= '0' && str[index] <= '9')
    {
        temp2 = temp2 * 10 + str[index] - '0';
        index++;
    }
    return (temp1 * temp2);
}