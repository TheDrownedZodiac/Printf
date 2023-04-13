/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-12-01 - 15:26 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: write number
 */

#include <unistd.h>
#include "fonction.h"

int stu_dputs(int nbr, int fd)
{
    int k;
    int l;
    char m;
    int n;

    n = 0;
    if (nbr < 0) {
        n += write(fd, "-", 1);
        nbr = -nbr;
    }
    k = nb_len(nbr);
    while (k > 0) {
        l = get_digit(nbr, k - 1);
        m = '0' + l;
        n += write(fd, &m, 1);
        k -= 1;
    }
    return n;
}
