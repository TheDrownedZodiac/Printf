/*
 * E89 Pedagogical & Technical Lab
 * project:     printf
 * created on:  2022-12-07 - 09:31 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: counter
 */

int counter(int j, const char *pattern)
{
    if (pattern[j + 1] == '+' || pattern[j + 1] == '-') {
        j += 1;
    }
    while (pattern[j] != 'd' && pattern[j] != 'p'
           && pattern[j] != 'c' && pattern[j] != 's') {
        j += 1;
    }
    return j;
}
