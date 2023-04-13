/*
 * E89 Pedagogical & Technical Lab
 * project:     Immersion
 * created on:  2022-10-05 - 11:19 +0200
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: Extraire un chiffre
 */

int get_digit(int nb, int index)
{
    while (index > 0) {
        nb = nb / 10;
        index = index - 1;
    }
    nb = nb % 10;
    return(nb);
}
