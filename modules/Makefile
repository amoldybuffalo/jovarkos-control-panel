CC = gcc
OUTPUT = $(m).so
INPUT = $(m).c
all:
	$(CC) -o $(OUTPUT) -shared -fPIC  $(INPUT)  `pkg-config --cflags --libs gtk+-3.0`


