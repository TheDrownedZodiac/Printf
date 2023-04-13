/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-12-07 - 11:49 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: hexa
 */

#include "fonction.h"

int hexa(char *src)
{
    int i;
    int nbr;

    nbr = (int) src;
    i = 0;
    while (nbr > 0) {
        nbr /= 16;
        i += 1;
    }
    return i + 2;
}
