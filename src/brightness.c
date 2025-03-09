#include "brightness.h"
#include <stdio.h>

float brightness_get() {
    FILE *f_actual = fopen("/sys/class/backlight/intel_backlight/actual_brightness", "r");
    FILE *f_max = fopen("/sys/class/backlight/intel_backlight/max_brightness", "r");

    int actual, max;
    fscanf(f_actual, "%d", &actual);
    fscanf(f_max, "%d", &max);

    float brightness = (float) actual / max;

    fclose(f_actual);
    fclose(f_max);

    return brightness;
}

void brightness_set(float brightness) {
    FILE *f_target = fopen("/sys/class/backlight/intel_backlight/brightness", "w");
    FILE *f_max = fopen("/sys/class/backlight/intel_backlight/max_brightness", "r");

    int max;
    fscanf(f_max, "%d", &max);

    int target = max * brightness;

    fprintf(f_target, "%d\n", target);

    fclose(f_target);
    fclose(f_max);
}

