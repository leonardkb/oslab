//
//  main.c
//  fifo
//
//  Created by leonard kb on 08/06/2023.
//
#include <stdio.h>

int main() {
    int n, pg[10], frame, fr[10], hit = 0, k = 0, fault = 0, flag = 0, i, j;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the number of pages:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pg[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frame);

    for (i = 0; i < frame; i++) {
        fr[i] = -1;
    }

    printf("Reference String\tPage Frames\n");

    for (i = 0; i < n; i++) {
        flag = 0;

        for (j = 0; j < frame; j++) {
            if (fr[j] == pg[i]) {
                flag = 1;
                hit++;
            }
        }

        if (flag == 0) {
            fr[k] = pg[i];
            k = (k + 1) % frame;
            fault++;
        }

        printf("%d\t\t", pg[i]);

        for (j = 0; j < frame; j++) {
            printf("%d ", fr[j]);
        }

        printf("\n");
    }

    printf("\nTotal number of faults: %d\n", fault);
    printf("Total number of hits: %d\n", hit);

    printf("\nLast Frame:\n");
    for (i = 0; i < frame; i++) {
        printf("%d\t", fr[i]);
    }
    printf("\n");

    return 0;
}
