#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>
#include "procs.h"



/*These two will be moved later on*/
static long get_cpu_count(void) {
    return sysconf(_SC_NPROCESSORS_ONLN);
}
static void print_kernel_info(void) {
    struct utsname u;
    if (uname(&u) == 0) {
        printf("sk.Kernel: %s %s (%s)\n", u.sysname, u.release, u.machine);
    }
}

int main(void) {
    printf("CPUs online: %ld\n", get_cpu_count());
    print_kernel_info();

    puts("\nProcesses (PID  NAME):");
    print_processes(0); 

    return 0;
}

