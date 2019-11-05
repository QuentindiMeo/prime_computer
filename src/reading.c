/*
** PERSONAL PROJECT, 2019
** prime_computer
** File description:
** prime computer reading functions
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

static uint get_number(char *str)
{
    int i = my_strlen(str) - 2;
    char *number = NULL;
    uint nb = 0;

    for (; i && str[i] >= '0' && str[i] <= '9'; i--);
    number = my_cut_str(str, i + 1, my_strlen(str) - 2);
    nb = my_atou(number);
    free(number);
    return (nb);
}

static uint get_nth(char *str)
{
    char *n_th = NULL;
    uint nth = 0;

    n_th = my_cut_str(str, 4, 16);
    nth = my_atou(n_th);
    free(n_th);
    return (nth == 0 ? 0 : nth - 1);
}

static void free2(char *tofree1, char *tofree2)
{
    free(tofree1);
    free(tofree2);
}

uint read_last_line(int id)
{
    uint response;
    FILE *stream = fopen("calculations_prime.txt", "r");
    char *buff = NULL;
    size_t buf = 0;
    char *buffer = NULL;
    ssize_t ret_v = 0;

    if (!stream)
        return (id == 1 ? -1 : 1);
    while (ret_v != -1) {
        if (buffer != NULL)
            free(buffer);
        if (buff != NULL)
            buffer = strdup(buff);
        ret_v = getline(&buff, &buf, stream);
    }
    response = (id == 1) ? get_nth(buffer) : get_number(buffer);
    free2(buff, buffer);
    fclose(stream);
    return (response);
}
