notify-send.exe: notify-send.c
	$(CC) -std=c99 -O2 -s -Wall -Werror -o $@ $< -static

.PHONY: clean
clean:
	rm notify-send.exe
