/*
** PERSONAL PROJECT, 2019
** prime_computer
** File description:
** prime computer detectors
*/

#include <stdlib.h>
#include "../include/prime.h"
#include "../include/my.h"

uint adjust(char *optarg, uint val)
{
    for (int i = 0; optarg[i]; i++)
        if (optarg[i] != '0' && val == 0)
            return (MAX);
    return (val);
}

char *is_find_alone(int a, char c)
{
    if (a || c != END_OF_ARGS) {
        my_putstr("-F and --find must be used alone.\n");
        my_putstr("Try './tictactoe --help' for other information.\n");
        return (NULL);
    }
    return ("-");
}

int digits_ok(uint *settings, uint nb)
{
    if (my_strlen(my_itoa(nb)) >= settings[DIGITS])
        return (FALSE);
    return (TRUE);
}
