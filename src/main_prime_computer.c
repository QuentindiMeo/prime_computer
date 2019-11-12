/*
** PERSONAL PROJECT, 2019
** prime_computer
** File description:
** prime computer main
*/

#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../include/prime.h"
#include "../include/my.h"

static int prime_find(uint nth, uint nb, uint *settings)
{
    uint ctr = 0;

    if (settings[FIND] >= 50000)
        printf("This may take a while...\n");
    for (; nb < MAX && nth < settings[FIND]; nb++) {
        for (int dvdr = 2; 1.99 * dvdr < nb; dvdr++) {
            if (ctr)
                break;
            ctr += ((nb % dvdr == 0) ? 1 : 0);
        }
        nth = (!ctr) ? write_result(nth, nb, 1, settings) : nth;
        ctr = 0;
    }
    if (nb == MAX) {
        printf("Couldn't find the %uth prime number (too big)\n",
                settings[FIND]);
        return (1);
    }
    nth = write_result(--nth, --nb, 0, settings);
    return (SUCCESS);
}

static void prime_loop(uint *settings, uint nth, uint nb)
{
    uint ctr = 0;

    for (; nb < MAX && nb < settings[END] &&
             nth < settings[UNTIL] && digits_ok(settings, nb); nb++) {
        for (int dvdr = 2; 1.99 * dvdr < nb; dvdr++) {
            if (ctr)
                break;
            ctr += ((nb % dvdr == 0) ? 1 : 0);
        }
        if (!ctr)
            nth = write_result(nth, nb, 0, settings);
        ctr = 0;
        usleep(settings[SLOW]);
    }
    if (nb == MAX)
        printf("Calculations stopped. 32-bit integer limit reached.\n");
    else
        printf("Calculations done.\n");
}

static int prime_computer(int ac, char **av)
{
    uint nth = 0;
    uint nb = 2;
    uint *settings = setup();

    if (get_settings(ac, av, settings) == FAILURE)
        return (FAILURE);
    if (settings[FIND] != 0)
        return (prime_find(nth, nb, settings));
    nth = (settings[START] != 0 ? 0 : (read_last_line(1) + 1));
    nb = (settings[START] != 0 ? settings[START] : (read_last_line(2) + 1));
    prime_loop(settings, nth, nb);
    free(settings);
    return (SUCCESS);
}

int main(int argc, char **argv)
{
    if (argc == 2 &&
        (my_str_isequal(argv[1], "-h") || my_str_isequal(argv[1], "--help")))
        return (help());
    return (prime_computer(argc, argv));
}
