/*
** PERSONAL PROJECT, 2019
** prime_computer
** File description:
** prime computer settings setup
*/

#include <stdlib.h>
#include <getopt.h>
#include "../include/prime.h"
#include "../include/my.h"

static uint limit_slow(int slow)
{
    if (slow > 60000000)
        return (0);
    return (slow);
}

static char *do_switch(char c, char *optarg, uint **settings, int alone)
{
    switch (c) {
    case ODIGITS :
        (*settings)[DIGITS] = adjust(optarg, my_atou(optarg));
        break;
    case OEND :
        (*settings)[END] = adjust(optarg, my_atou(optarg));
        break;
    case OFIND :
        (*settings)[FIND] = my_atou(optarg);
        return (is_find_alone(alone));
        break;
    case OSLOW :
        (*settings)[SLOW] = limit_slow(my_atou(optarg) * 1000);
        break;
    case OSTART :
        (*settings)[START] = my_atou(optarg);
        break;
    case OUNTIL :
        (*settings)[UNTIL] = adjust(optarg, my_atou(optarg));
        break;
    case '?' :
        my_putstr("Try './tictactoe --help' for more information.\n");
        return (NULL);
        break;
    }
    return ("-");
}

static void set_longopts(struct option **longopts)
{
    (*longopts)[0].name = "digits";
    (*longopts)[0].has_arg = 1;
    (*longopts)[0].flag = NULL;
    (*longopts)[0].val = 'd';
    (*longopts)[1].name = "end";
    (*longopts)[1].has_arg = 1;
    (*longopts)[1].flag = NULL;
    (*longopts)[1].val = 'E';
    (*longopts)[2].name = "find";
    (*longopts)[2].has_arg = 1;
    (*longopts)[2].flag = NULL;
    (*longopts)[2].val = 'F';
    (*longopts)[3].name = "start";
    (*longopts)[3].has_arg = 1;
    (*longopts)[3].flag = NULL;
    (*longopts)[3].val = 'S';
    (*longopts)[4].name = "slow";
    (*longopts)[4].has_arg = 1;
    (*longopts)[4].flag = NULL;
    (*longopts)[4].val = 's';
    (*longopts)[5].name = "until";
    (*longopts)[5].has_arg = 1;
    (*longopts)[5].flag = NULL;
    (*longopts)[5].val = 'u';
}

int get_settings(int ac, char **av, uint *settings)
{
    char c = 0;
    struct option *longopts = malloc(sizeof(struct option) * 6);

    set_longopts(&longopts);
    for (int i = 0; c != END_OF_ARGS; i++) {
        c = getopt_long(ac, av, "d:u:E:F:S:", longopts, NULL);
        if (do_switch(c, optarg, &settings, i) == NULL) {
            free(longopts);
            free(settings);
            return (FAILURE);
        }
    }
    free(longopts);
    return (SUCCESS);
}

uint *setup(void)
{
    uint *settings = malloc(sizeof(unsigned int) * 6);

    settings[START] = 0;
    settings[END] = MAX;
    settings[FIND] = 0;
    settings[DIGITS] = MAX;
    settings[SLOW] = 0;
    settings[UNTIL] = MAX;
    return (settings);
}
