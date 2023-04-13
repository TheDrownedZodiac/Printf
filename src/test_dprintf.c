
/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-12-01 - 16:55 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: main
 */

#include <stdio.h>
#include "fonction.h"

int main(void)
{
    char *str;
    int n;
    int m;

    str = "Projet";
    n = 0;
    m = 0;

    dprintf(1, "dprintf :\n\n");

    dprintf(1, "1.0.0 : START>%%<END\n");
    dprintf(1, "1.0.1 : START>%d<END\n", 123456789);
    dprintf(1, "1.0.2 : START>%c<END\n", 'A');
    dprintf(1, "1.0.3 : START>%s<END\n", str);
    dprintf(1, "1.0.4 : START>%p<END\n", str);

    dprintf(1, "\nmon dprintf :\n\n");

    stu_dprintf(1, "1.1.0 : START>%%<END\n");
    stu_dprintf(1, "1.1.1 : START>%d<END\n", 123456789);
    stu_dprintf(1, "1.1.2 : START>%c<END\n", 'A');
    stu_dprintf(1, "1.1.3 : START>%s<END\n", str);
    stu_dprintf(1, "1.1.4 : START>%p<END\n", str);

    dprintf(1, "\nmon dprintf :\n\n");

    n += stu_dprintf(1, "1.2.0 : START>%%<END\n");
    n += stu_dprintf(1, "1.2.1 : START>%d<END\n", 123456789);
    n += stu_dprintf(1, "1.2.2 : START>%c<END\n", 'A');
    n += stu_dprintf(1, "1.2.3 : START>%s<END\n", str);
    n += stu_dprintf(1, "1.2.4 : START>%p<END\n", str);
    stu_dprintf(2, "1.2.5 : START>%d<END\n", n);

    dprintf(1, "\nmon dprintf :\n\n");

    stu_dprintf(1, "2.1.0 : START>%+16d<END\n", 123456789);
    stu_dprintf(1, "2.1.1 : START>%+16c<END\n", 'A');
    stu_dprintf(1, "2.1.2 : START>%+16s<END\n", "Projet");
    stu_dprintf(1, "2.1.3 : START>%+16p<END\n", "Projet");

    dprintf(1, "\nmon dprintf :\n\n");

    stu_dprintf(1, "3.1.0 : START>%-16d<END\n", 123456789);
    stu_dprintf(1, "3.1.1 : START>%-16c<END\n", 'A');
    stu_dprintf(1, "3.1.2 : START>%-16s<END\n", "Projet");
    stu_dprintf(1, "3.1.3 : START>%-16p<END\n", "Projet");

    dprintf(1, "\ndprintf :\n\n");

    dprintf(1, "4.0.0 : START>%16d<END\n", 123456789);
    dprintf(1, "4.0.1 : START>%+16d<END\n", 123456789);
    dprintf(1, "4.0.2 : START>%-16d<END\n", 123456789);
    dprintf(1, "4.0.3 : START>%+016d<END\n", 123456789);
    dprintf(1, "4.0.4 : START>%016d<END\n", 123456789);

    dprintf(1, "\nmon dprintf :\n\n");

    stu_dprintf(1, "4.1.0 : START>%16d<END\n", 123456789);
    stu_dprintf(1, "4.1.1 : START>%+16d<END\n", 123456789);
    stu_dprintf(1, "4.1.2 : START>%-16d<END\n", 123456789);
    stu_dprintf(1, "4.1.3 : START>%+016d<END\n", 123456789);
    stu_dprintf(1, "4.1.4 : START>%016d<END\n", 123456789);

    dprintf(1, "\ndprintf :\n\n");

    dprintf(1, "4.2.0 : START>%16d<END\n", -123456789);
    dprintf(1, "4.2.1 : START>%+16d<END\n", -123456789);
    dprintf(1, "4.2.2 : START>%-16d<END\n", -123456789);
    dprintf(1, "4.2.3 : START>%+016d<END\n", -123456789);
    dprintf(1, "4.2.4 : START>%016d<END\n", -123456789);

    dprintf(1, "\nmon dprintf :\n\n");

    m += stu_dprintf(1, "4.3.0 : START>%16d<END\n", -123456789);
    m += stu_dprintf(1, "4.3.1 : START>%+16d<END\n", -123456789);
    m += stu_dprintf(1, "4.3.2 : START>%-16d<END\n", -123456789);
    m += stu_dprintf(1, "4.3.3 : START>%+016d<END\n", -123456789);
    m += stu_dprintf(1, "4.3.4 : START>%016d<END\n", -123456789);
    stu_dprintf(2, "4.3.5 : START>%016d<END\n", m);

    dprintf(1, "\nmon dprintf :\n\n");

    m = stu_strlen(str);
    stu_dprintf(1, "FINAL : START>La chaîne de caractères : %c%s%c contient %d octets et son adresse est : %p. Mon printf marche à 100%%<END\n", '"', str, '"', m, str);
}
