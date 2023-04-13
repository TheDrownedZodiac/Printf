/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-12-01 - 16:38 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: write character
 */

#include <unistd.h>

int stu_cputs(const char c, int fd)
{
    int n;

    n = write(fd, &c, 1);
    return n;
}
