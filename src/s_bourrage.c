/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-12-05 - 09:52 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: s_bourrage
 */

#include "fonction.h"
#include <unistd.h>

static int comp(int i, const char *pattern)
{
    int k;

    k = 0;
    while (pattern[i + 1] != 's') {
        k = (k + (pattern[i + 1] - '0')) * 10;
        i += 1;
    }
    k /= 10;
    return k;
}

static int bour_1(char *src, int fd, const char *pattern, int i)
{
    int l;
    int n;
    int k;

    n = 0;
    k = comp(i, pattern);
    l = stu_sputs(src, fd);
    if (k <= l) {
        return l;
    }
    k -= l;
    n += l;
    while (k > 0) {
            n += write(fd, " ", 1);
            k -= 1;
    }
    return n;
}

static int bour_2(char *src, int fd, const char *pattern, int i)
{
    int k;
    int l;
    int n;

    n = 0;
    k = comp(i, pattern);
    if (!src) {
        l = 6;
    } else {
        l = (int) stu_strlen(src);
    }
    if (k <= l) {
        n += stu_sputs(src, fd);
        return n;
    }
    k -= l;
    while (k > 0) {
            n += write(fd, " ", 1);
            k -= 1;
    }
    n += stu_sputs(src, fd);
    return n;
}

int s_bourrage(char *src, int fd, const char *pattern, int i)
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
