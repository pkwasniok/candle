#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#define OPTION_HELP 'h'
#define OPTION_BRIGHTNESS 'b'
#define OPTION_TEMPERATURE 't'

void help() {
    printf("usage: candle [options]\n");
    printf("    options:\n");
    printf("        -h, --help           Print this help message\n");
    printf("        -b, --brightness     Get/set display brightness\n");
    printf("        -t, --temperature    Get/set display temperature\n");
}

void brightness() {
    printf("50%%\n");
}

void temperature() {
    printf("5500K\n");
}

int main(int argc, char **argv) {

    // Define options
    static struct option long_option[] = {
        { "help", no_argument, 0, OPTION_HELP },
        { "brightness", no_argument, 0, OPTION_BRIGHTNESS },
        { "temperature", no_argument, 0, OPTION_TEMPERATURE },
    };

    // Parse options
    int option_index = 0;
    char c;
    while ((c = getopt_long(argc, argv, "htb:", long_option, &option_index)) != -1) {
        switch (c) {
            case OPTION_HELP:
                help();
                break;
            case OPTION_BRIGHTNESS:
                brightness();
                break;
            case OPTION_TEMPERATURE:
                temperature();
                break;
        }
    }

    return 0;
}

