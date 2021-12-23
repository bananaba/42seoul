void *memset(void *ptr, int value, size_t n)
{
    while (n > 0)
        *((char *)ptr + --n) = value;
    return (ptr);
}