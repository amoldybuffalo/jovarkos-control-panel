CC = gcc
OUTPUT = jovarkos-control-panel
all: build

build:
	$(CC) -o $(OUTPUT) main.c utils.c hash_map.c  `pkg-config --cflags --libs gtk+-3.0`
clean: 
	rm $(OUTPUT) 
run: build
	./$(OUTPUT)

