#include <stdio.h>

#define MAX_P 50
#define MAX_R 50

int main(void) {
    int processes, resources;

    int allocation[MAX_P][MAX_R];
    int maximum[MAX_P][MAX_R];
    int need[MAX_P][MAX_R];

    int available[MAX_R];
    int work[MAX_R];

    int finish[MAX_P] = {0};
    int safeSequence[MAX_P];

    printf("Enter number of processes and resources: ");
    scanf("%d %d", &processes, &resources);

    if (processes <= 0 || processes > MAX_P ||
        resources <= 0 || resources > MAX_R) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    printf("\nEnter Allocation Matrix:\n");

    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);

            if (allocation[i][j] < 0) {
                printf("Invalid allocation.\n");
                return 1;
            }
        }
    }

    printf("\nEnter Maximum Demand Matrix:\n");

    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &maximum[i][j]);

            if (maximum[i][j] < allocation[i][j]) {
                printf("Maximum demand cannot be below allocation.\n");
                return 1;
            }

            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    printf("\nEnter Available Resources:\n");

    for (int j = 0; j < resources; j++) {
        scanf("%d", &available[j]);

        if (available[j] < 0) {
            printf("Invalid available resources.\n");
            return 1;
        }

        work[j] = available[j];
    }

    int count = 0;

    while (count < processes) {
        int found = 0;

        for (int i = 0; i < processes; i++) {
            if (finish[i])
                continue;

            int possible = 1;

            for (int j = 0; j < resources; j++) {
                if (need[i][j] > work[j]) {
                    possible = 0;
                    break;
                }
            }

            if (possible) {
                for (int j = 0; j < resources; j++)
                    work[j] += allocation[i][j];

                safeSequence[count++] = i;
                finish[i] = 1;
                found = 1;
            }
        }

        if (!found)
            break;
    }

    if (count == processes) {
        printf("\nSystem is in a SAFE state.\n");

        printf("Safe Sequence: ");

        for (int i = 0; i < processes; i++)
            printf("P%d%s", safeSequence[i],
                   i == processes - 1 ? "\n" : " -> ");
    } else {
        printf("\nSystem is in an UNSAFE state.\n");
        printf("No safe sequence exists.\n");
    }

    return 0;
}
