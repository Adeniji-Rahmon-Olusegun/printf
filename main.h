#ifndef PRINTFPROJ_H
#define PRINTFPROJ_H

#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int specifier_checker(char f_char, va_list anything_arg);
int printChar(int c);
int printString(char *string);
int printDigit(long number, int base);
int printDigitX(long number, int base);
#endif
