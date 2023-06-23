#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
};

void extractData(struct LogEntry logEntries[], int *numEntries) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the data file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    char *token;
    int entryCount = 0;

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        
        token = strtok(line, ",");
        
        logEntries[entryCount].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strncpy(logEntries[entryCount].sensorNo, token, sizeof(logEntries[entryCount].sensorNo));

        token = strtok(NULL, ",");
        logEntries[entryCount].temperature = atof(token);

        token = strtok(NULL, ",");
        logEntries[entryCount].humidity = atoi(token);

        token = strtok(NULL, ",");
        logEntries[entryCount].light = atoi(token);

        token = strtok(NULL, ",");
        strncpy(logEntries[entryCount].time, token, sizeof(logEntries[entryCount].time));

        entryCount++;
    }

    *numEntries = entryCount;

    fclose(file);
}

void displayData(const struct LogEntry logEntries[], int numEntries) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%d\t%s\n", logEntries[i].entryNo, logEntries[i].sensorNo,
               logEntries[i].temperature, logEntries[i].humidity, logEntries[i].light, logEntries[i].time);
    }
}

int main() {
    struct LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    extractData(logEntries, &numEntries);
    displayData(logEntries, numEntries);

    return 0;
}
