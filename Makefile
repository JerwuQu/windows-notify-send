# Makefile for notify-send
CC=gcc

all: notify-send.exe

notify-send.exe: notify-send.c
	gcc -o $@ $<

.PHONY: clean

clean:
	rm notify-send.exe
