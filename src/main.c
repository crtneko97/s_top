#include <stdio.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <sys/utsname.h>

long get_cpu_count(void);
void print_kernel_info(void);


int main(void)
{
	printf("%ld\n", get_cpu_count());
	print_kernel_info();

	return 0;
}


long get_cpu_count(void)
{
	return sysconf(_SC_NPROCESSORS_ONLN);
}


void print_kernel_info(void)
{
	struct utsname u;
  if (uname(&u) == 0)
	{
        printf("Kernel: %s %s (%s)\n", u.sysname, u.release, u.machine);
	}
}
