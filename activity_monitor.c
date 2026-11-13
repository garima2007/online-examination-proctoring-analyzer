#include <stdio.h>
#include <string.h>
#define MAX_ACTIVITIES 100
typedef struct {
    int candidate_id;
    char event_type[50];
    char timestamp[20];
    float duration;
    char details[100];
} Activity;

int main() {

    Activity activities[MAX_ACTIVITIES];
    int count = 0;

    // Sample Activity 1
    activities[count].candidate_id = 101;
    strcpy(activities[count].event_type, "prolonged_gaze_away");
    strcpy(activities[count].timestamp, "10:32:15");
    activities[count].duration = 7.0;
    strcpy(activities[count].details,
           "Gaze outside permitted region");
    count++;

    activities[count].candidate_id = 101;
    strcpy(activities[count].event_type, "tab_switch_detected");
    strcpy(activities[count].timestamp, "10:40:20");
    activities[count].duration = 5.0;
    strcpy(activities[count].details,
           "Candidate switched from exam window");
    count++;

    activities[count].candidate_id = 102;
    strcpy(activities[count].event_type, "multiple_faces_detected");
    strcpy(activities[count].timestamp, "10:45:10");
    activities[count].duration = 8.0;
    strcpy(activities[count].details,
           "More than one face detected");
    count++;

    printf("\n=== PROCTORING ACTIVITY MONITOR ===\n\n");

    for (int i = 0; i < count; i++) {

        printf("Activity %d\n", i + 1);
        printf("Candidate ID : %d\n",
               activities[i].candidate_id);
        printf("Event        : %s\n",
               activities[i].event_type);
        printf("Timestamp    : %s\n",
               activities[i].timestamp);
        printf("Duration     : %.1f seconds\n",
               activities[i].duration);
        printf("Details      : %s\n\n",
               activities[i].details);
    }

    printf("Total suspicious activities: %d\n", count);

    return 0;
}
