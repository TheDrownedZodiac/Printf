/*
 * E89 Pedagogical & Technical Lab
 * project:     exam
 * created on:  2022-12-01 - 09:18 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: strdup
 */

#include "fonction.h"
#include <stdlib.h>

char *stu_strdup(const char *src)
{
    char *str;

    str = malloc(sizeof(char) * stu_strlen(src));
    stu_strcpy(str, src);
    return str;
}
