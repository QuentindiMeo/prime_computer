#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../include/my.h"

int read_last_line(int id);

static void writing_result(int fd, char *nth, char *nb)
{
    lseek(fd, 0, SEEK_END);
    write(fd, "  P-", 4);
    write(fd, nth, my_strlen(nth));
    write(fd, ":\t", 2);
    if (my_strlen(nth) < 3)
        write(fd, "\t", 1);
    write(fd, nb, my_strlen(nb));
    write(fd, "\n", 1);
}

static int write_result(int nth, uint nb)
{
    int fd = open("calculations_prime", O_CREAT | O_WRONLY);
    char *n_th = my_itoa(++nth);
    char *number = my_itoa(nb);

    fchmod(fd, 0666);
    printf("  P-%d:\t%c%d\n", nth, nth > 99 ? '\0' : '\t', nb);
    writing_result(fd, n_th, number);
    free(n_th);
    free(number);
    close(fd);
    return (nth);
}

static int help(void)
{
    printf("\n\n"
           "A prime number is a number that can only be divided by "
           "1 or itself.\n"
           "This program is a prime numbers computer. This program is limited "
           "to the size of\na 32-bit integer,  which  means  it  will  stop  "
           "calculating  after  it  reached\na prime number higher than "
           "2147483647.\n"
           "A slower version of this program is available here aswell. "
           "The program is called\n\"prime_computer\". "
           "Try it out for human-readable speed.\n"
           "\n\n");
    return (0);
}

int main(int argc, char **argv)
{
    int nth = read_last_line(1) + 1;
    uint ctr = 0;

    if (argc == 2 &&
        (my_str_isequal(argv[1], "-h") || my_str_isequal(argv[1], "--help")))
        return (help());
    for (uint nb = read_last_line(2) + 1; 2147483647; nb++) {
        for (int dvdr = 2; 1.99 * dvdr < nb; dvdr++) {
            if (ctr)
                continue;
            if (nb % dvdr == 0)
                ctr++;
        }
        if (!ctr)
            nth = write_result(nth, nb);
        ctr = 0;
    }
}
