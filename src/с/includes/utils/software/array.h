#ifndef _ARRAY_H_
#define _ARRAY_H_

void reverseArray(int *arr, int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void findTwoMinIndexes(int *arr, int size, int &min1_idx, int &min2_idx) {
    if (arr[0] < arr[1]) {
        min1_idx = 0;
        min2_idx = 1;
    } else {
        min1_idx = 1;
        min2_idx = 0;
    }

    for (int i = 2; i < size; i++) {
        if (arr[i] < arr[min1_idx]) {
            min2_idx = min1_idx;
            min1_idx = i;
        }
        else if (arr[i] < arr[min2_idx] && i != min1_idx) {
            min2_idx = i;
        }
    }
}

void rewriteColors(int *cols) {
    int mi1, mi2;
    findTwoMinIndexes(cols, 6, mi1, mi2);
    for (int i = 0; i < 6; i++) {
        if (i == mi1 || i == mi2) {
            cols[i] = 1;
        } else {
            cols[i] = 6;
        }
    }
}

#endif