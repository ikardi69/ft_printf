#include <stdio.h>
#include "libftprintf.h"

int main()
{
	char *str = "hel";
	printf("printf = %p\n", str);
	ft_printf("ft_printf = %p\n", str);
}