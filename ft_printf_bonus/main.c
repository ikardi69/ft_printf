
//#include <libc.h>
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
	// printf("ft size = %d\n", ft_printf("% +d\n", 0));
	// printf("pf size = %d\n", printf("% +d\n", 0));
	// printf("ft size = %d\n", ft_printf("%- 10d\n", 42));
	// printf("pf size = %d\n", printf("%- 10d\n", 42));
	// double x = 2.4;
	// printf("%d %d %d",5 , x, 1, 5);
	// char *p = NULL;
	// p[0] = 's';
	// printf("%c",p[-1]);
	// printf("ft size = %d\n", ft_printf("String test: %s\n", "Hello World"));
	// printf("pf size = %d\n", printf("String test: %s\n", "Hello World"));
    //void *ptr = (void *)42;
	// printf("ft size = %d\n", ft_printf("ft %-10u\n", 42));
	// printf("pf size = %d\n", printf("pf %-10u\n", 42));
	// printf("ft size = %d\n", ft_printf("pf %-#10X\n", 42));
	// printf("pf size = %d\n", printf("pf %-#10X\n", 42));
   	printf("ft size = %d\n", ft_printf("ft %-10%\n"));
	printf("pf size = %d\n", printf("pf %-10%\n"));
	return (0);
}

/*
#include <stdio.h>
#include <limits.h>
#include "libftprintf_bonus.h"

// Declare your ft_printf function here

int main() {
    // Test cases for each conversion
    printf("Testing '%%c':\n");
    ft_printf("Character: %c\n", 'A');
    ft_printf("Character: %c\n", '\0');
    ft_printf("Character with text: This is %c in a sentence.\n", 'Z');
    
    printf("\nTesting '%%s':\n");
    ft_printf("String: %s\n", "Hello, world!");
    ft_printf("Empty string: %s\n", "");
    ft_printf("NULL string: %s\n", (char *)NULL);

    printf("\nTesting '%%p':\n");
    int x = 42;
    ft_printf("Pointer: %p\n", &x);
    ft_printf("NULL pointer: %p\n", (void *)NULL);

    printf("\nTesting '%%d' and '%%i':\n");
    ft_printf("Integer: %d\n", 12345);
    ft_printf("Negative Integer: %d\n", -12345);
    ft_printf("Smallest int: %d\n", INT_MIN);
    ft_printf("Largest int: %d\n", INT_MAX);

    printf("\nTesting '%%u':\n");
    ft_printf("Unsigned int: %u\n", 12345);
    ft_printf("Largest unsigned int: %u\n", UINT_MAX);

    printf("\nTesting '%%x' and '%%X':\n");
    ft_printf("Hexadecimal (lowercase): %x\n", 0xabcdef);
    ft_printf("Hexadecimal (uppercase): %X\n", 0xABCDEF);
    ft_printf("Zero in hex (lowercase): %x\n", 0);
    ft_printf("Zero in hex (uppercase): %X\n", 0);

    printf("\nTesting '%%%%':\n");
    ft_printf("Percent sign: %%\n");
    ft_printf("Percent sign with text: Start %% middle %% end.\n");

    printf("\nTesting multiple arguments/conversions:\n");
    ft_printf("Multiple: %c %s %p %d %u %x %X %%\n", 'A', "Test", &x, -42, 42U, 0x42, 0x42);

    printf("\nTesting mixed text and conversions:\n");
    ft_printf("This is a number: %d. And this is a string: %s.\n", 123, "Hello!");
    ft_printf("Hex: %x, Unsigned: %u, Char: %c.\n", 255, 12345, 'Z');

    return 0;
}
*/
/*
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libftprintf_bonus.h"


void test_printf(const char *desc, const char *format, ...) {
    va_list args1, args2;
    int ret_original, ret_ft;

    // Print test description
    printf("=== Test: %s ===\n", desc);

    // Start variadic arguments
    va_start(args1, format);
    va_start(args2, format);

    // Test original printf
    printf("Original printf:\n");
    ret_original = vprintf(format, args1);
    printf("\n");

    // Test ft_printf
    printf("ft_printf:\n");
    ret_ft = ft_printf(format, args2);
    printf("\n");

    // Compare return values
    printf("Return values:\n");
    printf("Original: %d, ft_printf: %d\n", ret_original, ret_ft);
    if (ret_original == ret_ft) {
        printf("✅ Match!\n\n");
    } else {
        printf("❌ Mismatch!\n\n");
    }

    // End variadic arguments
    va_end(args1);
    va_end(args2);
}

int main() {
    // Test simple conversions
    test_printf("Single character", "%c", 'A');
    test_printf("String", "%s", "Hello, world!");
    test_printf("Pointer", "%p", &main);
    test_printf("Decimal number", "%d", 42);
    test_printf("Negative decimal", "%d", -42);
    test_printf("Unsigned integer", "%u", 42);
    test_printf("Hexadecimal (lowercase)", "%x", 0xdeadbeef);
    test_printf("Hexadecimal (uppercase)", "%X", 0xDEADBEEF);
    test_printf("Percent sign", "%%");

    // Test combinations of conversions
    test_printf("Combination of formats", "Char: %c, String: %s, Int: %d, Hex: %x, Percent: %%", 'A', "Test", 42, 0x42);

    // Test edge cases
    test_printf("Smallest integer", "%d", INT_MIN);
    test_printf("Largest integer", "%d", INT_MAX);
    test_printf("Largest unsigned integer", "%u", UINT_MAX);
    test_printf("Null string", "%s", (char *)NULL);
    test_printf("Zero value", "%d", 0);

    // Test identical conversions
    test_printf("Series of %d", "%d %d %d %d", 1, 2, 3, 4);
    test_printf("Series of %s", "%s %s %s", "one", "two", "three");
    test_printf("Series of mixed conversions", "%c %c %c", 'A', 'B', 'C');

    // Stress test with a long format string
    test_printf("Long format string", "Int: %d, Unsigned: %u, Hex (lower): %x, Hex (upper): %X, Pointer: %p, String: %s", 
                42, 42U, 0xdeadbeef, 0xDEADBEEF, &main, "Long test!");

    return 0;
}
*/
/*
#include <stdio.h>
#include "libftprintf_bonus.h"
#include <limits.h>

// Color codes for test output
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

// Test result tracking
int total_points = 0;
int max_points = 0;

// Macro for running tests with different flags
#define TEST_FLAG(type, value, flag, expected_ft, expected_std) \
    do { \
        char ft_buf[1024], std_buf[1024]; \
        int ft_ret = ft_printf(flag type, value); \
        int std_ret = printf(flag type, value); \
        snprintf(ft_buf, sizeof(ft_buf), flag type, value); \
        snprintf(std_buf, sizeof(std_buf), flag type, value); \
        \
        printf("Testing " flag type ": ", value); \
        if (ft_ret == std_ret && strcmp(ft_buf, std_buf) == 0) { \
            printf(GREEN "PASS" RESET "\n"); \
            total_points++; \
        } else { \
            printf(RED "FAIL" RESET "\n"); \
            printf("  ft_printf output: %s (ret: %d)\n", ft_buf, ft_ret); \
            printf("  printf output:    %s (ret: %d)\n", std_buf, std_ret); \
        } \
        max_points++; \
    } while(0)

void test_bonus_flags() {
    printf("\n--- Bonus Flags Tests ---\n");

    // Test positive integers with various flags
    int pos_int = 42;
    
    // Test '+' flag (force sign on positive numbers)
    TEST_FLAG("d", pos_int, "%+d", pos_int, pos_int);
    TEST_FLAG("d", pos_int, "%+10d", pos_int, pos_int);
    TEST_FLAG("d", pos_int, "%-+10d", pos_int, pos_int);
    
    // Test space flag (space before positive numbers)
    TEST_FLAG("d", pos_int, "% d", pos_int, pos_int);
    TEST_FLAG("d", pos_int, "% 10d", pos_int, pos_int);
    TEST_FLAG("d", pos_int, "%- d", pos_int, pos_int);
    
    // Test '#' flag for hex and octal
    TEST_FLAG("x", pos_int, "%#x", pos_int, pos_int);
    TEST_FLAG("X", pos_int, "%#X", pos_int, pos_int);
    
    // Combinations of flags
    TEST_FLAG("d", pos_int, "%+ d", pos_int, pos_int);
    TEST_FLAG("d", pos_int, "%+10d", pos_int, pos_int);
    TEST_FLAG("x", pos_int, "%#10x", pos_int, pos_int);
    TEST_FLAG("X", pos_int, "%#-10X", pos_int, pos_int);

    // Negative integers 
    int neg_int = -42;
    
    TEST_FLAG("d", neg_int, "%+d", neg_int, neg_int);
    TEST_FLAG("d", neg_int, "% d", neg_int, neg_int);
    TEST_FLAG("d", neg_int, "%#d", neg_int, neg_int);
    
    // Special case: zero with '#' flag
    TEST_FLAG("x", 0, "%#x", 0, 0);
    TEST_FLAG("X", 0, "%#X", 0, 0);

    // Bonus calculation
    printf("\n--- Test Results ---\n");
    printf("Points earned: %d/%d\n", total_points, max_points);
    if (total_points == max_points) {
        total_points += 2;
        printf(GREEN "BONUS: All flags working perfectly! +2 points\n" RESET);
    }
}

void detailed_flag_test() {
    int val = 42;
    
    printf("Basic width tests:\n");
    printf("Standard printf: |%10d|\n", val);
    ft_printf("Your printf:    |%10d|\n", val);
    
    printf("\nPlus flag tests:\n");
    printf("Standard printf: |%+d|\n", val);
    ft_printf("Your printf:    |%+d|\n", val);
    
    printf("\nWidth with plus flag:\n");
    printf("Standard printf: |%+10d|\n", val);
    ft_printf("Your printf:    |%+10d|\n", val);
    
    printf("\nSpace flag tests:\n");
    printf("Standard printf: |% d|\n", val);
    ft_printf("Your printf:    |% d|\n", val);
    
    printf("\nHex prefix tests:\n");
    printf("Standard printf: |%#x|\n", val);
    ft_printf("Your printf:    |%#x|\n", val);
    
    printf("\nComplex flag combination:\n");
    printf("Standard printf: |%+-10d|\n", val);
    ft_printf("Your printf:    |%+-10d|\n", val);
}

int main() {
    //test_bonus_flags();
    detailed_flag_test();
    return 0;
}
*/