#include "ft_printf.h"
#include "limits.h"

int main()
{
    // ft_printf(" %p %p ", 0, 0);

    // printf("ft size = %d\n", ft_printf(" %2p \n", -1));
    // printf("pf size = %d\n", printf(" %2p \n", -1));
    // printf("ft size = %d\n", ft_printf(" %-9p %-10p \n", LONG_MIN, LONG_MAX));
    // printf("pf size = %d\n", printf(" %-9p %-10p \n", LONG_MIN, LONG_MAX));
    // printf("ft size = %d\n", ft_printf("ft | %-11p %-12p \n", INT_MIN, INT_MAX));
    // printf("pf size = %d\n", printf("pf | %-11p %-12p \n", INT_MIN, INT_MAX));
    // printf("ft size = %d\n", ft_printf("ft | %-13p %-14p \n", ULONG_MAX, -ULONG_MAX));
    // printf("pf size = %d\n", printf("pf | %-13p %-14p \n", ULONG_MAX, -ULONG_MAX));
    // printf("ft size = %d\n", ft_printf(" %-1p %-2p \n", 0, 0));
    // printf("pf size = %d\n", printf(" %-1p %-2p \n", 0, 0));

    // printf("ft size = %d\n", ft_printf("ft | %-5u \n", -15));
    // printf("pf size = %d\n", printf("pf | %-5u \n", -15));
    // ft_printf(" %-6u ", -16);
    // ft_printf(" %-1u ", -99);
    // ft_printf(" %-12u ", LONG_MIN);
    // ft_printf(" %-14u ", ULONG_MAX);
    // ft_printf(" %-15u ", 9223372036854775807LL);
    // ft_printf(" %-9u %-10u %-11u %-12u %-13u %-14u %-15u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    // ft_printf(" %-1x ", 0);
    // ft_printf(" %-2x ", -1);
    // ft_printf(" %-3x ", 1);
    // ft_printf(" %-4x ", 9);
    // ft_printf(" %-1x ", 10);
    // ft_printf(" %-2x ", 11);
    // ft_printf(" %-3x ", 15);
    // ft_printf(" %-4x ", 16);
    // ft_printf(" %-5x ", 17);
    // ft_printf(" %-1x ", 99);
    // ft_printf(" %-2x ", 100);
    // ft_printf(" %-3x ", 101);
    // ft_printf(" %-1x ", -9);
    // ft_printf(" %-2x ", -10);
    // ft_printf(" %-3x ", -11);
    // ft_printf(" %-4x ", -14);
    // ft_printf(" %-5x ", -15);
    // ft_printf(" %-6x ", -16);
    // ft_printf(" %-1x ", -99);
    // ft_printf(" %-2x ", -100);
    // ft_printf(" %-3x ", -101);
    // ft_printf(" %-9x ", INT_MAX);
    // ft_printf(" %-10x ", INT_MIN);
    // ft_printf(" %-11x ", LONG_MAX);
    // ft_printf(" %-12x ", LONG_MIN);
    // ft_printf(" %-13x ", UINT_MAX);
    // ft_printf(" %-14x ", ULONG_MAX);
    // ft_printf(" %-15x ", 9223372036854775807LL);
    // ft_printf(" %-9x %-10x %-11x %-12x %-13x %-14x %-15x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    // ft_printf(" %-1X ", 0);
    // ft_printf(" %-2X ", -1);
    // ft_printf(" %-3X ", 1);
    // ft_printf(" %-4X ", 9);
    // ft_printf(" %-1X ", 10);
    // ft_printf(" %-2X ", 11);
    // ft_printf(" %-3X ", 15);
    // ft_printf(" %-4X ", 16);
    // ft_printf(" %-5X ", 17);
    // ft_printf(" %-1X ", 99);
    // ft_printf(" %-2X ", 100);
    // ft_printf(" %-3X ", 101);
    // ft_printf(" %-1X ", -9);
    // ft_printf(" %-2X ", -10);
    // ft_printf(" %-3X ", -11);
    // ft_printf(" %-4X ", -14);
    // ft_printf(" %-5X ", -15);
    // ft_printf(" %-6X ", -16);
    // ft_printf(" %-1X ", -99);
    // ft_printf(" %-2X ", -100);
    // ft_printf(" %-3X ", -101);
    // ft_printf(" %-9X ", INT_MAX);
    // ft_printf(" %-10X ", INT_MIN);
    // ft_printf(" %-11X ", LONG_MAX);
    // ft_printf(" %-12X ", LONG_MIN);
    // ft_printf(" %-13X ", UINT_MAX);
    // ft_printf(" %-14X ", ULONG_MAX);
    // ft_printf(" %-15X ", 9223372036854775807LL);
    // ft_printf(" %-9X %-10X %-11X %-12X %-13X %-14X %-15X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    // ft_printf(" %04d ", -14);
    // ft_printf(" %05d ", -15);
    // ft_printf(" %06d ", -16);
    // ft_printf(" %010d ", INT_MIN);
        //  printf("ft size = %d\n", ft_printf(" %010d ", -16));
        //  printf("pt size = %d\n", printf(" %010d ", -16));
        //  printf("ft size = %d\n", ft_printf(" %010d ", INT_MIN));
        //  printf("pt size = %d\n", printf(" %010d ", INT_MIN));
    // ft_printf(" %011d ", LONG_MAX);
    // ft_printf(" %013d ", UINT_MAX);
    // ft_printf(" %014d ", ULONG_MAX);
    // ft_printf(" %015d ", 9223372036854775807LL);
    // ft_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    // ft_printf(" %05i ", -15);
    // ft_printf(" %06i ", -16);
    // ft_printf(" %01i ", -99);
    // ft_printf(" %011i ", LONG_MAX);
    // ft_printf(" %012i ", LONG_MIN);
    // ft_printf(" %014i ", ULONG_MAX);
    // ft_printf(" %015i ", 9223372036854775807LL);
    // ft_printf(" %09i %010i %011i %012i %013i %014i %015i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    // ft_printf(" %01u ", 0);
    // ft_printf(" %05u ", -15);
    // ft_printf(" %06u ", -16);
    // ft_printf(" %01u ", -99);
    // ft_printf(" %012u ", LONG_MIN);
    // ft_printf(" %014u ", ULONG_MAX);
    // ft_printf(" %015u ", 9223372036854775807LL);
    // ft_printf(" %09u %010u %011u %012u %013u %014u %015u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    // ft_printf(" %.9d ", INT_MIN);
    // ft_printf(" %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    // ft_printf(" %.9i ", INT_MIN);
    // ft_printf(" %.8i %.9i %.10i %.11i %.12i %.13i %.14i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    // printf("ft size = %d\n", ft_printf(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
    // printf("pt size = %d\n", printf(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
    // ft_printf(" %#x ", 0);
    // ft_printf(" %#x ", LONG_MIN);
    // ft_printf(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    // ft_printf(" %#X ", 0);
    // ft_printf(" %#X ", LONG_MIN);
    // ft_printf(" %#X %#X %#X %#X %#X %#X %#X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    printf("ft size = %d\n", ft_printf(" % s % s % s % s % s ", " - ", "", "4", "", "2 "));
    printf("pt size = %d\n", printf(" % s % s % s % s % s ", " - ", "", "4", "", "2 "));
    // ft_printf(" % s ", "-");
    // ft_printf(" % s % s ", "", "-");
    // ft_printf(" % s % s ", " - ", "");
    // ft_printf(" % s % s % s % s ", " - ", "", "4", "");
    // ft_printf(" % s % s % s % s % s ", " - ", "", "4", "", "2 ");

}