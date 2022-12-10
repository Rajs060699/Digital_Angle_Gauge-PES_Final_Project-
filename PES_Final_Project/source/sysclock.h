/*
 * sysclock.h - configuration routines for KL25Z system clock
 *
 * Author Howdy Pierce, howdy.pierce@colorado.edu
 */


#define SYSCLOCK_FREQUENCY (24000000U)

/*
 * Initializes the system clock. You should call this first in your
 * program.
 */
void sysclock_init();

