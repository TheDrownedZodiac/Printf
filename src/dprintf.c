/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-12-01 - 16:56 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: printf
 */

#include <stdarg.h>
#include "fonction.h"

static int d_dprintf(int *i, int fd, const char *pattern, va_list *args)
{
    int n;
    int j;

    n = 0;
    if (pattern[*i + 1] == 'd') {
        n += stu_dputs(va_arg(*args, int), fd);
        *i += 2;
        return n;
    }
    j = counter(*i, pattern);
    if (pattern[j] == 'd') {
        n += d_bourrage(va_arg(*args, int), fd, pattern, *i + 1);
        *i += j - *i + 1;
    }
    return n;
}

static int c_dprintf(int *i, int fd, const char *pattern, va_list *args)
{
    int n;
    int j;

    n = 0;
    if (pattern[*i + 1] == 'c') {
        n += stu_cputs(va_arg(*args, int), fd);
        *i += 2;
        return n;
    }
    if (pattern[*i + 1] == '+' || pattern[*i + 1] == '-') {
        j = counter(*i, pattern);
        if (pattern[j] == 'c') {
            n += c_bourrage(va_arg(*args, int), fd, pattern, *i + 1);
            *i += j - *i + 1;
        }
    }
    return n;
}

static int s_dprintf(int *i, int fd, const char *pattern, va_list *args)
{
    int n;
    int j;

    n = 0;
    if (pattern[*i + 1] == 's') {
        n += stu_sputs(va_arg(*args, char *), fd);
        *i += 2;
        return n;
    }
    if (pattern[*i + 1] == '+' || pattern[*i + 1] == '-') {
        j = counter(*i, pattern);
        if (pattern[j] == 's') {
            n += s_bourrage(va_arg(*args, char *), fd, pattern, *i + 1);
            *i += j - *i + 1;
        }
    }
    return n;
}

static int x_dprintf(int *i, int fd, const char *pattern, va_list *args)
{
    int n;
    int j;

    n = 0;
    if (pattern[*i + 1] == 'p') {
        n += stu_xputs(va_arg(*args, char *), fd);
        *i += 2;
        return n;
    }
    if (pattern[*i + 1] == '+' || pattern[*i + 1] == '-') {
        j = counter(*i, pattern);
        if (pattern[j] == 'p') {
            n += x_bourrage(va_arg(*args, char *), fd, pattern, *i + 1);
            *i += j - *i + 1;
        }
    }
    return n;
}

int stu_dprintf(int fd, const char *pattern, ...)
{
    va_list args;
    int i;
    int n;

    va_start(args, pattern);
    i = 0;
    n = 0;
    while (pattern[i] != '\0') {
        if (pattern[i] == '%') {
            if (pattern[i + 1] == '%') {
                n += stu_cputs('%', fd);
                i += 2;
            } else {
                n += d_dprintf(&i, fd, pattern, &args);
                n += c_dprintf(&i, fd, pattern, &args);
                n += s_dprintf(&i, fd, pattern, &args);
                n += x_dprintf(&i, fd, pattern, &args);
            }
        } else {
            n += stu_cputs(pattern[i], fd);
            i += 1;
        }
    }
    va_end(args);
    return n;
}
