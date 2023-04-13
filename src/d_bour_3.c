/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-12-12 - 09:50 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: bourage
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

static char *signe_assignation(const char *pattern, int *i)
{
    char *c;

    c = " ";
    if (pattern[*i + 1] == '+') {
        *i += 1;
        c = "+";
    }
    return c;
}

static void space_filler(int *n, int *k, int fd)
{
    while (*k > 0) {
        *n += write(fd, " ", 1);
        *k -= 1;
    }
}


int bour(int src, int fd, const char *pattern, int i)
{
    int k;
    int n;
    char *c;

    n = 0;
    i -= 1;
    c = signe_assignation(pattern, &i);
    k = comp(i, pattern);
    if (k <= nb_len(src)) {
        if (pattern[i] == '+') {
            n += write(fd, c, 1);
        }
        n += stu_dputs(src, fd);
        return n;
    }
    k -= nb_len(src) + 1;
    space_filler(&n, &k, fd);
    n += write(fd, c, 1) + stu_dputs(src, fd);
    return n;
}
