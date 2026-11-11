#include <stdio.h>
#include <string.h>
typedef struct {
    int candidate_id;
    char event_type[50];
    char timestamp[20];
    float duration;
    char details[100];
} Activity;

int main() {

    Activity event;

    event.candidate_id = 101;
    strcpy(event.event_type, "prolonged_gaze_away");
    strcpy(event.timestamp, "10:32:15");
    event.duration = 7.0;
    strcpy(event.details, "Gaze detected outside permitted region");

    printf("=== Activity Monitor ===\n\n");

    printf("Candidate ID : %d\n", event.candidate_id);
    printf("Event        : %s\n", event.event_type);
    printf("Timestamp    : %s\n", event.timestamp);
    printf("Duration     : %.1f seconds\n", event.duration);
    printf("Details      : %s\n", event.details);

    return 0;
}
