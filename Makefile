CC      = cc
# -Wall -Wextra: good warnings
# -O2: small optimization
# -g: debug symbols (you can remove in release)
# -Iinclude: tells compiler where headers live
CFLAGS  = -Wall -Wextra -O2 -g -Iinclude

SRC     = src/main.c src/procs.c
BIN     = monitor

# Default target: build the binary
$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $@

.PHONY: run clean debug
# Run and show only the first 20 lines (useful when printing a lot)
run: $(BIN)
	./$(BIN) | head -n 20

# A debug build with sanitizers (handy if you start malloc'ing later)
debug:
	$(CC) -Wall -Wextra -O0 -g -fsanitize=address,undefined -fno-omit-frame-pointer -Iinclude $(SRC) -o $(BIN)

clean:
	rm -f $(BIN)
