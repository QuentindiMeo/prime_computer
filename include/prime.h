/*
** PERSONAL PROJECT, 2018
** prime_compute
** File description:
** prime computer headers
*/

#ifndef PRIME_H_
#define PRIME_H_

typedef enum {
    START = 0,
    END = 1,
    FIND = 2,
    DIGITS = 3,
    SLOW = 4,
    OSTART = 'S',
    OEND = 'E',
    OFIND = 'F',
    ODIGITS = 'd',
    OSLOW = 's',
} settings_id_t;

typedef enum {
    MAX = 2147483647,
} default_t;

char *is_find_alone(int is_alone);
int digits_ok(unsigned int *settings, unsigned int nb);

void writing_result(int fd, char *nth, char *nb);
unsigned int write_result(unsigned int nth, unsigned int nb, int id);

unsigned int read_last_line(int id);

unsigned int adjust(char *optarg, unsigned int val);
int get_settings(int ac, char **av, unsigned int *settings);
unsigned int *setup(void);

int help(void);

#endif
