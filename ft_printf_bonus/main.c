#include <libc.h>
#include "libftprintf.h"

int main()
{
	char *str = "printf = hell";
	// char *str2 = "ft_printf = hell";
	// int print = printf("%s\n", NULL);
	// int ftprint = ft_printf("%c\n", NULL);
	// printf("ft_print size = %d\n", ftprint);
	//printf("printf size = %d\n", print);
	//printf("printf size = %d\n", printf("%s\n", str2));
	//printf("strlen size = %zu\n", strlen(str));
	// char *str = "hher";
	// ft_printf("%p\n", NULL);
	// printf("%p\n", NULL);
	// printf("size is = %d\n", ft_printf("%d\n", -42));
	// printf("printf size is = %d\n", printf("%d\n", -42));
	//ft_printf ("%s", str);
	//unsigned int i = 6;
	ft_printf("ft %c\n", 'q');
	printf("pf %c\n", 'q');
	return (0);
}