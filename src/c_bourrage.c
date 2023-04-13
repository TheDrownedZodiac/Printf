/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-12-05 - 09:52 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: c_bourrage
 */

#include "fonction.h"
#include <unistd.h>

static int bour_1(char src, int fd, const char *pattern, int i)
{
    int k;
    int n;

    n = 0;
    k = 0;
    while (pattern[i + 1] != 'c') {
        k = (k + (pattern[i + 1] - '0')) * 10;
        i += 1;
    }
    k /= 10;
    if (k <= 1) {
        n += stu_cputs(src, fd);
        return n;
    }
    n += stu_cputs(src, fd);
    while (k > 1) {
        n += write(fd, " ", 1);
        k -= 1;
    }
    return n;
}

static int bour_2(char src, int fd, const char *pattern, int i)
{
    int k;
    int n;

    n = 0;
    k = 0;
    while (pattern[i + 1] != 'c') {
        k = (k + (pattern[i + 1] - '0')) * 10;
        i += 1;
    }
    k /= 10;
    if (k <= 1) {
        n += stu_cputs(src, fd);
        return n;
    }
    while (k > 1) {
        n += write(fd, " ", 1);
        k -= 1;
    }
    n += stu_cputs(src, fd);
    return n;
}

int c_bourrage(char src, int fd, const char *pattern, int i)
{
    int n;

    n = 0;
    if (pattern[i] == '-') {
        n += bour_1(src, fd, pattern, i);
    } else {
        n += bour_2(src, fd, pattern, i);
    }
    return n;
}
