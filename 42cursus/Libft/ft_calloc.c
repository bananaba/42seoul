#include <stdlib.h>

void *calloc(size_t nmemb, size_t size)
{
    void *temp;
    int index;

    index = 0;
    temp = mallco(size * nmemb);
    if (!temp)
        return (0);
    while (index < size * nmemb)
        *((char *)temp + index) = 0;
    return (temp);
}