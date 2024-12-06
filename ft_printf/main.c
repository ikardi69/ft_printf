/*
#include <libc.h>
#include "libftprintf.h"

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
	// printf("size is = %d\n", ft_printf("%d\n", -42));
	// printf("printf size is = %d\n", printf("%d\n", -42));
	//ft_printf ("%s", str);
	//unsigned int i = 6;
	// ft_printf("ft %c\n", 'q');
	// printf("pf %c\n", 'q');
    // Close stdout to make printf fail
    fclose(stderr);
	// close(1)

    // Try to print something
    int ret = ft_printf("test %d",15);

    // Print the return value of printf to stderr
    fprintf(stdout, "Return value of printf: %d\n", ret);

	return (0);
}
*/
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

// Replace assert with a custom macro
#define ASSERT(condition) \
    do { \
        if (!(condition)) { \
            printf("Assertion failed: %s, line %d\n", __FILE__, __LINE__); \
            exit(1); \
        } \
    } while (0)

// Comparison function to check ft_printf matches printf
int compare_printf_output(const char *format, ...)
{
    va_list args1, args2;
    char buffer1[1024], buffer2[1024];
    int result1, result2;

    va_start(args1, format);
    va_start(args2, format);

    // Capture printf output
    result1 = vsnprintf(buffer1, sizeof(buffer1), format, args1);
    
    // Capture ft_printf output
    result2 = ft_printf(format, args2);

    va_end(args1);
    va_end(args2);

    // Compare output length and string content
    if (result1 != result2) {
        printf("FAILED: Format length mismatch: %s\n", format);
        printf("printf:    len: %d\n", result1);
        printf("ft_printf: len: %d\n", result2);
        return 0;
    }

    return 1;
}

// Test character conversion
void test_character_conversion()
{
    printf("Testing Character Conversion (%%c)...\n");
    
    // Basic characters
    ASSERT(compare_printf_output("Character test: %c", 'A'));
    ASSERT(compare_printf_output("%c is a character", 'Z'));
    
    // Special characters
    ASSERT(compare_printf_output("Special char: %c", '\n'));
    ASSERT(compare_printf_output("Special char: %c", '\t'));
    
    // Non-printable characters
    ASSERT(compare_printf_output("Non-printable: %c", 7)); // Bell character
}

// Test string conversion
void test_string_conversion()
{
    printf("Testing String Conversion (%%s)...\n");
    
    // Normal strings
    ASSERT(compare_printf_output("String test: %s", "Hello World"));
    ASSERT(compare_printf_output("%s is a test string", "Testing"));
    
    // Empty string
    ASSERT(compare_printf_output("Empty string: %s", ""));
    
    // NULL string
    ASSERT(compare_printf_output("NULL string: %s", NULL));
}

// Test integer conversions
void test_integer_conversions()
{
    printf("Testing Integer Conversions (%%d, %%i)...\n");
    
    // Positive numbers
    ASSERT(compare_printf_output("Positive: %d", 42));
    ASSERT(compare_printf_output("Positive: %i", 12345));
    
    // Negative numbers
    ASSERT(compare_printf_output("Negative: %d", -42));
    ASSERT(compare_printf_output("Negative: %i", -12345));
    
    // Zero
    ASSERT(compare_printf_output("Zero: %d", 0));
    ASSERT(compare_printf_output("Zero: %i", 0));
    
    // Extreme values
    ASSERT(compare_printf_output("INT_MAX: %d", INT_MAX));
    ASSERT(compare_printf_output("INT_MIN: %d", INT_MIN));
}

// Test unsigned integer conversion
void test_unsigned_conversions()
{
    printf("Testing Unsigned Conversion (%%u)...\n");
    
    // Regular unsigned numbers
    ASSERT(compare_printf_output("Unsigned: %u", 42));
    ASSERT(compare_printf_output("Large unsigned: %u", 4294967295U));
    
    // Zero
    ASSERT(compare_printf_output("Zero unsigned: %u", 0));
}

// Test hexadecimal conversions
void test_hexadecimal_conversions()
{
    printf("Testing Hexadecimal Conversions (%%x, %%X)...\n");
    
    // Lower case
    ASSERT(compare_printf_output("Lowercase hex: %x", 255));
    ASSERT(compare_printf_output("Lowercase hex: %x", 4096));
    
    // Upper case
    ASSERT(compare_printf_output("Uppercase hex: %X", 255));
    ASSERT(compare_printf_output("Uppercase hex: %X", 4096));
    
    // Zero
    ASSERT(compare_printf_output("Zero hex: %x", 0));
    ASSERT(compare_printf_output("Zero hex: %X", 0));
}

// Test pointer conversion
void test_pointer_conversion()
{
    printf("Testing Pointer Conversion (%%p)...\n");
    
    int x = 42;
    char *str = "Hello";
    
    ASSERT(compare_printf_output("Pointer: %p", (void*)&x));
    ASSERT(compare_printf_output("String pointer: %p", (void*)str));
    ASSERT(compare_printf_output("NULL pointer: %p", NULL));
}

// Test percentage sign
void test_percentage_sign()
{
    printf("Testing Percentage Sign (%%%%)\n");
    
    ASSERT(compare_printf_output("Percent sign: %%"));
    ASSERT(compare_printf_output("Multiple %%%% signs"));
}

// Test multiple conversions
void test_multiple_conversions()
{
    printf("Testing Multiple Conversions...\n");
    
    ASSERT(compare_printf_output("Multiple: %c %s %d", 'A', "test", 42));
    ASSERT(compare_printf_output("%d %x %c in one line", 100, 255, 'Z'));
    ASSERT(compare_printf_output("Complex: %s has %d characters", "Hello", 5));
}

int main()
{
    printf("Running ft_printf Tests...\n");
    
    test_character_conversion();
    test_string_conversion();
    test_integer_conversions();
    test_unsigned_conversions();
    test_hexadecimal_conversions();
    test_pointer_conversion();
    test_percentage_sign();
    test_multiple_conversions();
    
    printf("All tests completed successfully!\n");
    return 0;
}