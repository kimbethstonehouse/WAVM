#include <stdio.h>
#include <stdlib.h>

void printSequence(int sequence[], int sequenceLength) {
    for (int i = 0; i < sequenceLength; i++) { printf("%d ", sequence[i]); }
    printf("\n");
}

void reverseMibonacci(int sequence[], int sequenceLength) {
    int start = 0;
    int end = sequenceLength-1;
    int temp;

    while (start < end) {
        temp = sequence[start];
        sequence[start] = sequence[end];
        sequence[end] = temp;
        start++;
        end--;
    }
}

// Driver code. You shouldn't need to modify this.
int main() {
    FILE *filePointer = fopen("task1.txt", "r");

    int maxLength = 100;
    int sequenceLength = 0;
    int *sequence = malloc(sizeof(int) * (maxLength + 1));

    for (int i = 0; i < maxLength; i++) {
        if (fscanf(filePointer, "%d ", &sequence[i]) == 1) sequenceLength++;
        else {
            sequence[i] = -1;
            break;
        }
    }

    fclose(filePointer);

    reverseMibonacci(sequence, sequenceLength);
    printSequence(sequence, sequenceLength);

    return 0;
}
