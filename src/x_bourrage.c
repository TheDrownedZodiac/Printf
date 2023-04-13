/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-12-05 - 09:52 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: d_bourrage
 */

#include "fonction.h"
#include <unistd.h>

static int bour_1(char *src, int fd, const char *pattern, int i)
{
    int k;
    int n;

    n = 0;
    k = 0;
    while (pattern[i + 1] != 'p') {
        k = (k + (pattern[i + 1] - '0')) * 10;
        i += 1;
    }
    k /= 10;
    if (k <= hexa(src)) {
        n += stu_xputs(src, fd);
        return n;
    }
    k -= hexa(src);
    n += stu_xputs(src, fd);
    while (k > 0) {
            n += write(fd, " ", 1);
            k -= 1;
    }
    return n;
}

static int bour_2(char *src, int fd, const char *pattern, int i)
{
    int k;
    int n;

    n = write(fd, &pattern[i], 1);
    k = 0;
    while (pattern[i + 2] != 'p') {
        k = (k + (pattern[i + 2] - '0')) * 10;
        i += 1;
    }
    k /= 10;
    if (k <= hexa(src)) {
        n += stu_xputs(src, fd);
        return n;
    }
    k -= hexa(src) + 1;
    while (k > 0) {
        n += write(fd, "0", 1);
        k -= 1;
    }
    n += stu_xputs(src, fd);
    return n;
}

static int bour_3(char *src, int fd, const char *pattern, int i)
{
    int k;
    int l;
    int n;

    n = 0;
    k = 0;
    l = i;
    while (pattern[i + 1] != 'p') {
        k = (k + (pattern[i + 1] - '0')) * 10;
        i += 1;
    }
    k /= 10;
    if (k <= hexa(src)) {
        n += write(fd, &pattern[l], 1) + stu_xputs(src, fd);
        return n;
    }
    k -= hexa(src) + 1;
    while (k > 0) {
        n += write(fd, " ", 1);
        k -= 1;
    }
    n += write(fd, &pattern[l], 1) + stu_xputs(src, fd);
    return n;
}

int x_bourrage(char *src, int fd, const char *pattern, int i)
{
    int n;

    n = 0;
    if (pattern[i] == '-') {
        n += bour_1(src, fd, pattern, i);
    } else if (pattern[i] == '+' && pattern[i + 1] == '0') {
        n += bour_2(src, fd, pattern, i);
    } else {
        n += bour_3(src, fd, pattern, i);
    }
    return n;
}
