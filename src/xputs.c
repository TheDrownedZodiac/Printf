/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-12-01 - 15:26 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: write number
 */

#include <unistd.h>
#include "fonction.h"

static int xputs(int nbr, int fd)
{
    int remainder;
    int i;
    char j[16];
    int n;

    n = 0;
    i = 0;
    while (nbr > 0) {
        remainder = nbr % 16;
        if (remainder < 10) {
            j[i] = '0' + remainder;
        } else {
            j[i] = 'a' + (remainder - 10);
        }
        nbr /= 16;
        i += 1;
    }
    j[i] = '\0';
    n += write(fd, "0x", 2);
    while (i > 0) {
        i -= 1;
        n += write(fd, &j[i], 1);
    }
    return n;
}

int stu_xputs(char *str, int fd)
{
    int n;
    int nbr;

    n = 0;
    if (!str) {
        n += write(fd, "(nil)", 5);
        return n;
    }
    nbr = (int) str;
    n += xputs(nbr, fd);
    return n;
}
