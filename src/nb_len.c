/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-12-01 - 15:45 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: nb len
 */

int nb_len(int nb)
{
    int counter;

    counter = 1;
    while (nb >= 10) {
        nb = nb / 10;
        counter = counter + 1;
    }
    return (counter);
}
