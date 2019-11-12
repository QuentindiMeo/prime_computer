/*
** PERSONAL PROJECT, 2018
** prime_compute
** File description:
** prime computer headers
*/

#ifndef PRIME_H_
#define PRIME_H_

#include "my.h"

typedef enum {
    START = 0,
    END = 1,
    FIND = 2,
    DIGITS = 3,
    SLOW = 4,
    UNTIL = 5,
    SILENT = 6,
    STORE = 7,
    OSTART = 'S',
    OEND = 'E',
    OFIND = 'F',
    ODIGITS = 'd',
    OSLOW = 's',
    OUNTIL = 'u',
    OSILENT = '-',
    OSTORE = 'D',
} settings_id_t;

typedef enum {
    MAX = 2147483647,
} default_t;

int digits_ok(uint *settings, uint nb);

uint write_result(uint nth, uint nb, int id, uint *settings);

uint read_last_line(int id);

uint adjust(char *optarg, uint val);
int get_settings(int ac, char **av, uint *settings);
uint *setup(void);

int help(void);

#endif
