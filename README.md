
Small suggested plan for this 

c-monitor/
├── src/
│   ├── main.c           # entry point
│   ├── sysinfo.c        # CPU count, kernel, meminfo
│   ├── cpu.c            # CPU usage from /proc/stat
│   ├── mem.c            # Memory usage from /proc/meminfo
│   ├── tui.c            # Ncurses UI drawing
│   └── procs.c          # Process listing
│
├── include/
│   ├── sysinfo.h
│   ├── cpu.h
│   ├── mem.h
│   ├── tui.h
│   └── procs.h
│
├── build/               # compiled binaries
│
├── Makefile             # build rules
└── README.md            # blog notes / usage
