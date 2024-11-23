#include <libc.h>
#include "libftprintf.h"

int main()
{
	//char *str = "printf = hell";
	char *str2 = "ft_printf = hell";
	//int print = printf("%s\n", str);
	int ftprint = ft_printf("%s\n", str2);
	//printf("printf size = %d\n", print);
	printf("ft_print size = %d\n", ftprint);
	printf("strlen size ft = %zu\n", strlen(str2));
	//printf("strlen size = %zu\n", strlen(str));
}