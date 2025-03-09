#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "brightness.h"
#include "cli/help.h"
#include <string.h>

#define OPTION_HELP 'h'
#define OPTION_BRIGHTNESS 'b'
#define OPTION_TEMPERATURE 't'

void brightness(char *arg);

int main(int argc, char **argv) {

    // Define options
    static struct option long_option[] = {
        { "help", no_argument, 0, OPTION_HELP },
        { "brightness", required_argument, 0, OPTION_BRIGHTNESS },
    };

    // Parse options
    int option_index = 0;
    char c;
    while ((c = getopt_long(argc, argv, "hb:", long_option, &option_index)) != -1) {
        switch (c) {
            case OPTION_HELP:
                help();
                break;
            case OPTION_BRIGHTNESS:
                brightness(optarg);
                break;
        }
    }

    return 0;
}

void brightness(char *arg) {
    float brightness;

    // Convert argument to float
    if (arg[strlen(arg)-1] == '%') {
        brightness = atoi(arg) / 100.0;
    } else {
        brightness = atof(arg);
    }

    if (arg[0] == '+' || arg[0] == '-') {
        brightness = brightness_get() + brightness;
    }

    if (brightness < 0) {
        brightness = 0;
    } else if (brightness > 1) {
        brightness = 1;
    }

    printf("%.2f\n", brightness);

    brightness_set(brightness);
}

