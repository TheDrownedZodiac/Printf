/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-12-05 - 09:52 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: d_bourrage
 */

#include "fonction.h"
#include <unistd.h>

static int comp(int i, const char *pattern)
{
    int k;

    k = 0;
    while (pattern[i + 1] != 'd') {
        k = (k + (pattern[i + 1] - '0')) * 10;
        i += 1;
    }
    k /= 10;
    return k;
}

static int bour_1(int src, int fd, const char *pattern, int i)
{
    int k;
    int n;

    n = 0;
    k = comp(i, pattern);
    if (k <= nb_len(src)) {
        n += stu_dputs(src, fd);
        return n;
    }
    k -= nb_len(src);
    n += stu_dputs(src, fd);
    while (k > 0) {
            n += write(fd, " ", 1);
            k -= 1;
    }
    return n;
}

static int bour_2(int src, int fd, const char *pattern, int i)
{
    int k;
    int l;
    int n;

    l = nb_len(src);
    if (pattern[i] == '+') {
        n = write(fd, &pattern[i], 1);
        i += 1;
        l += 1;
    }
    k = comp(i, pattern);
    if (k <= nb_len(src)) {
        n += stu_dputs(src, fd);
        return n;
    }
    k -= l;
    while (k > 0) {
        n += write(fd, "0", 1);
        k -= 1;
    }
    n += stu_dputs(src, fd);
    return n;
}

static int bour_3(int src, int fd, const char *pattern, int i)
{
    int n;

    n = bour(src, fd, pattern, i);
    return n;
}

int d_bourrage(int src, int fd, const char *pattern, int i)
{
    int n;

    n = 0;
    if (src < 0) {
        src = -src;
        n += d_bourrage_ne(src, fd, pattern, i);
        return n;
    }
    if (pattern[i] == '-') {
        n += bour_1(src, fd, pattern, i);
    } else if ((pattern[i] == '+' && pattern[i + 1] == '0') ||
               pattern[i] == '0') {
        n += bour_2(src, fd, pattern, i);
    } else {
        n += bour_3(src, fd, pattern, i);
    }
    return n;
}
