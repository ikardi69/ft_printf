#include <libc.h>
#include "libftprintf_bonus.h"

int main()
{
	//char *str = "printf = hell";
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
	//printf("size is = %d\n", ft_printf("%d\n", -42));
	// printf("printf size is = %d\n", printf("%d\n", -42));
	//ft_printf ("%s", str);
	//unsigned int i = 6;

	//printf("ft size = %d\n", ft_printf("ft %.5d\n", -12));
	//printf("pf size = %d\n", printf("pf %.5d\n", -12));
	// printf("ft size = %d\n", ft_printf("%-5s\n", "hello"));
	// printf("pf size = %d\n", printf("%-5s\n", "hello"));
	// printf("ft size = %d\n", ft_printf("%02d\n", 1234));
	// printf("pf size = %d\n", printf("%02d\n", 1234));
	// printf("ft size = %d\n", ft_printf("%01X\n", 0x1A));
	// printf("pf size = %d\n", printf("%01X\n", 0x1A));
	// printf("ft size = %d\n", ft_printf("%05u\n", 42));
	// printf("pf size = %d\n", printf("%05u\n", 42));
	//printf("%.2s\n", NULL);
	// printf("ft size = %d\n", ft_printf("%#X\n", 255));
	// printf("pf size = %d\n", printf("%#X\n", 255));
	// printf("ft size = %d\n", ft_printf("% d\n", 42));
	// printf("pf size = %d\n", printf("% d\n", 42));
	printf("ft size = %d\n", ft_printf("% +d\n", 0));
	printf("pf size = %d\n", printf("% +d\n", 0));
	
	return (0);
}