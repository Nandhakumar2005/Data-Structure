#include <stdio.h>

#define MAX 100

struct triplet {
    int row;
    int col;
    int value;
};

int convertToTriplet(int mat[10][10], int m, int n, struct triplet compact[]) {
    int k = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0) {
                compact[k].row = i;
                compact[k].col = j;
                compact[k].value = mat[i][j];
                k++;
            }
        }
    }
    compact[0].row = m;
    compact[0].col = n;
    compact[0].value = k - 1;
    return k;
}

int addTriplets(struct triplet compact1[], struct triplet compact2[], struct triplet sum[]) {
    int i = 1, j = 1, k = 1;
    int total1 = compact1[0].value, total2 = compact2[0].value;

    sum[0].row = compact1[0].row;
    sum[0].col = compact1[0].col;

    while (i <= total1 && j <= total2) {
        if (compact1[i].row < compact2[j].row ||
            (compact1[i].row == compact2[j].row && compact1[i].col < compact2[j].col)) {
            sum[k++] = compact1[i++];
        } else if (compact2[j].row < compact1[i].row ||
                   (compact2[j].row == compact1[i].row && compact2[j].col < compact1[i].col)) {
            sum[k++] = compact2[j++];
        } else {
            int value = compact1[i].value + compact2[j].value;
            if (value != 0) {
                sum[k].row = compact1[i].row;
                sum[k].col = compact1[i].col;
                sum[k].value = value;
                k++;
            }
            i++;
            j++;
        }
    }

    while (i <= total1)
        sum[k++] = compact1[i++];
    while (j <= total2)
        sum[k++] = compact2[j++];

    sum[0].value = k - 1;
    return k;
}

void transpose(struct triplet sum[], struct triplet transpose[]) {
    int k = 1;
    int n = sum[0].col;

    transpose[0].row = sum[0].col;
    transpose[0].col = sum[0].row;
    transpose[0].value = sum[0].value;

    for (int col_index = 0; col_index < n; col_index++) {
        for (int i = 1; i <= sum[0].value; i++) {
            if (sum[i].col == col_index) {
                transpose[k].row = sum[i].col;
                transpose[k].col = sum[i].row;
                transpose[k].value = sum[i].value;
                k++;
            }
        }
    }
}

void printTriplet(struct triplet trip[], int total) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < total; i++) {
        printf("%d\t%d\t%d\n", trip[i].row, trip[i].col, trip[i].value);
    }
}

int main() {
    int m, n;
    int sparse1[10][10], sparse2[10][10];
    struct triplet compact1[MAX], compact2[MAX], sum[MAX], transposeMatrix[MAX];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter elements of sparse matrix 1:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &sparse1[i][j]);

    printf("Enter elements of sparse matrix 2:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &sparse2[i][j]);

    int total1 = convertToTriplet(sparse1, m, n, compact1);
    int total2 = convertToTriplet(sparse2, m, n, compact2);
    int totalSum = addTriplets(compact1, compact2, sum);
    transpose(sum, transposeMatrix);

    printf("\nFirst Sparse Matrix (Triplet Form):\n");
    printTriplet(compact1, total1);

    printf("\nSecond Sparse Matrix (Triplet Form):\n");
    printTriplet(compact2, total2);

    printf("\nSum Matrix (Triplet Form):\n");
    printTriplet(sum, totalSum);

    printf("\nTranspose of Sum Matrix:\n");
    printTriplet(transposeMatrix, totalSum);

    return 0;
}