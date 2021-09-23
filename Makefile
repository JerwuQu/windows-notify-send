notify-send.exe: notify-send.c
	$(CC) -std=c99 -O2 -Wall -Werror -o $@ $<

.PHONY: clean
clean:
	rm notify-send.exe
