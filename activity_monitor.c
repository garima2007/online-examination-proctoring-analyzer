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

void addActivity(Activity activities[], int *count,
                 int candidate_id,
                 char event_type[],
                 char timestamp[],
                 float duration,
                 char details[]) {

    if (*count >= MAX_ACTIVITIES) {
        printf("Activity storage is full.\n");
        return;
    }

    activities[*count].candidate_id = candidate_id;

    strcpy(activities[*count].event_type, event_type);
    strcpy(activities[*count].timestamp, timestamp);

    activities[*count].duration = duration;

    strcpy(activities[*count].details, details);

    (*count)++;
}

void displayActivities(Activity activities[], int count) {

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

        printf("Details      : %s\n",
               activities[i].details);

        printf("-----------------------------\n");
    }

    printf("\nTotal suspicious activities: %d\n", count);
}

void merge(Activity activities[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    Activity L[n1];
    Activity R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = activities[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = activities[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {

        // Descending order according to duration
        if (L[i].duration >= R[j].duration) {
            activities[k] = L[i];
            i++;
        }
        else {
            activities[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        activities[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        activities[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Activity activities[], int left, int right) {

    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(activities, left, mid);
        mergeSort(activities, mid + 1, right);

        merge(activities, left, mid, right);
    }
}
int main() {

    Activity activities[MAX_ACTIVITIES];

    int count = 0;


    addActivity(
        activities,
        &count,
        101,
        "prolonged_gaze_away",
        "10:32:15",
        7.0,
        "Gaze outside permitted region"
    );


    addActivity(
        activities,
        &count,
        101,
        "tab_switch_detected",
        "10:40:20",
        5.0,
        "Candidate switched from exam window"
    );


    addActivity(
        activities,
        &count,
        102,
        "multiple_faces_detected",
        "10:45:10",
        8.0,
        "More than one face detected"
    );
    
printf("\nActivities before sorting:\n");
displayActivities(activities, count);

mergeSort(activities, 0, count - 1);

printf("\nActivities sorted by duration (highest first):\n");
displayActivities(activities, count);
    displayActivities(activities, count);

    return 0;
}
