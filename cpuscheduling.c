#include <stdio.h>
#include <string.h>

struct process {
    char pid[10];
    int at, bt, pr;
    int wt, tat, completed;
};

int main() {
    int n, time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", p[i].pid, &p[i].at, &p[i].bt, &p[i].pr);
        p[i].completed = 0;
    }

    while (completed < n) {
        int idx = -1;
        int max_pr = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].completed == 0) {
                if (p[i].pr > max_pr) {
                    max_pr = p[i].pr;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            p[idx].wt = time - p[idx].at;
            time += p[idx].bt;
            p[idx].tat = p[idx].wt + p[idx].bt;
            p[idx].completed = 1;
            total_wt += p[idx].wt;
            total_tat += p[idx].tat;
            completed++;
        } else {
            time++;
        }
    }

    printf("\nWaiting Time:\n");
    for (int i = 0; i < n; i++)
        printf("%s %d\n", p[i].pid, p[i].wt);

    printf("\nTurnaround Time:\n");
    for (int i = 0; i < n; i++)
        printf("%s %d\n", p[i].pid, p[i].tat);

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
