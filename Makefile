SOURCES = src/main.c
CFLAGS = -std=c23 -Wall -Wextra -Wpedantic -Werror

default: build

run: build
	./.build.candle

build: $(SOURCES)
	mkdir -p .build
	gcc $(CFLAGS) -o .build/candle $(SOURCES)

clean:
	rm -rf .build

