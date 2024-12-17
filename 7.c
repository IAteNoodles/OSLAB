#include <stdio.h>
#include <stdbool.h>
#define MAX_FRAMES 3

void printFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1)
            printf(" X");
        else
            printf(" %d", frames[i]);
    }
    printf("\n");
}

int search(int key, int frames[], int n) {
    for (int i = 0; i < n; i++)
        if (frames[i] == key)
            return i;
    return -1;
}

int fifoPageReplacement(int pageReferences[], int n, int capacity) {
    int frames[capacity];
    int pageFaults = 0;
    int frameIndex = 0;
    for (int i = 0; i < capacity; i++)
        frames[i] = -1;
    for (int i = 0; i < n; i++) {
        printf("Referencing page %d: ", pageReferences[i]);
        if (search(pageReferences[i], frames, capacity) == -1) {
            frames[frameIndex] = pageReferences[i];
            frameIndex = (frameIndex + 1) % capacity;
            pageFaults++;
            printFrames(frames, capacity);
        } else {
            printf("Page %d is already in memory.\n", pageReferences[i]);
        }
    }
    return pageFaults;
}

int lruPageReplacement(int pageReferences[], int n, int capacity) {
    int frames[capacity];
    int pageFaults = 0;
    for (int i = 0; i < capacity; i++)
        frames[i] = -1;
    for (int i = 0; i < n; i++) {
        printf("Referencing page %d: ", pageReferences[i]);
        int index = search(pageReferences[i], frames, capacity);
        if (index == -1) {
            int leastRecentlyUsed = n;
            int victimIndex;
            for (int j = 0; j < capacity; j++) {
                int k;
                for (k = i - 1; k >= 0; k--)
                    if (frames[j] == pageReferences[k])
                        break;
                if (k < leastRecentlyUsed) {
                    leastRecentlyUsed = k;
                    victimIndex = j;
                }
            }
            frames[victimIndex] = pageReferences[i];
            pageFaults++;
            printFrames(frames, capacity);
        } else {
            printf("Page %d is already in memory.\n", pageReferences[i]);
        }
    }
    return pageFaults;
}

int main() {
    int pageReferences[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pageReferences) / sizeof(pageReferences[0]);
    int capacity = MAX_FRAMES;
    printf("FIFO Page Replacement:\n");
    int fifoFaults = fifoPageReplacement(pageReferences, n, capacity);
    printf("Total Page Faults for FIFO: %d\n\n", fifoFaults);
    printf("LRU Page Replacement:\n");
    int lruFaults = lruPageReplacement(pageReferences, n, capacity);
    printf("Total Page Faults for LRU: %d\n", lruFaults);
    return 0;
}
