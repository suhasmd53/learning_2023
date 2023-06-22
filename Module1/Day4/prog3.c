#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void timeDifference(struct Time t1, struct Time t2, struct Time* difference) {
    int seconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int seconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    int diffSeconds = seconds2 - seconds1;

    difference->hours = diffSeconds / 3600;
    difference->minutes = (diffSeconds % 3600) / 60;
    difference->seconds = (diffSeconds % 3600) % 60;
}

int main() {
    struct Time startTime, endTime, difference;

    printf("Enter start time (hours minutes seconds): ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    printf("Enter end time (hours minutes seconds): ");
    scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);

    timeDifference(startTime, endTime, &difference);

    printf("\nTime Difference: %d hours %d minutes %d seconds\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}
