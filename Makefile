SOURCES = src/main.c src/cli/help.c src/brightness.c
CFLAGS = -std=c23 -Wall -Wextra -Wpedantic -Werror

default: build

run: build
	./.build.candle

build: $(SOURCES)
	mkdir -p .build
	gcc $(CFLAGS) -o .build/candle $(SOURCES)

clean:
	rm -rf .build

