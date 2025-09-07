#define _GNU_SOURCE
#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "procs.h"

static int is_pid_dir(const char *s) {
    if (!*s) return 0;
    for (const unsigned char *p = (const unsigned char*)s; *p; ++p)
        if (!isdigit(*p)) return 0;
    return 1;
}

void print_processes(int max_lines) {
    DIR *d = opendir("/proc");
    if (!d) { perror("opendir /proc"); return; }

    int printed = 0;
    struct dirent *ent;
    while ((ent = readdir(d))) {
        if (!is_pid_dir(ent->d_name)) continue;

        int pid = atoi(ent->d_name);

        char path[256];
        snprintf(path, sizeof path, "/proc/%d/comm", pid);
        FILE *f = fopen(path, "r");
        if (!f) continue;

        char comm[128] = {0};
        if (fgets(comm, sizeof comm, f)) {
            comm[strcspn(comm, "\n")] = '\0';
            printf("%5d  %s\n", pid, comm);
        }
        fclose(f);

        if (max_lines > 0 && ++printed >= max_lines) break;
    }
    closedir(d);
}
