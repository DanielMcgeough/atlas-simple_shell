#include "main_shell.h"

/*
 * _memset- sets a specified number of bytes in given memory to
 * a specified value.
 *
 * @mem: pointer to the first byte in memory to be set.
 *
 * @val: the value to be set for each byte.
 *
 * @bytes: the number of bytes in memory to be set.
 *
 * Return: a pointer to the string.
 */

void *_memset(void *mem, int val, size_t bytes)
{
	unsigned char *ptr;

	ptr = mem;
	while (bytes-- > 0)
		*ptr++ = (unsigned char)val;
	return (mem);
}
