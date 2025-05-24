// Example functions
int try1(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int try2(int *arr, int n) {
    int sum = 0;
    while (n--) {
        sum += *arr++;
    }
    return sum;
}

