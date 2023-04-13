/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-12-01 - 16:40 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: write character string
 */

#include <unistd.h>
#include "fonction.h"

int stu_sputs(const char *str, int fd)
{
    int n;

    n = 0;
    if (!str) {
        n += write(fd, "(null)", 6);
        return n;
    }
    n += write(fd, str, stu_strlen(str));
    return n;
}
