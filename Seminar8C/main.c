#include <stdio.h>   
#include <stdlib.h> //malloc         
#include <locale.h>



void sort_array(int size, int a[]) {
    int i, j,temp=0;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}


void leftShift(int size, int* arr,int num) {
    int i;
    for (i = num; i < size-1; i++) {
        arr[i] = arr[i + 1];
    }
}

void leftShift2(int size, int* arr, int num) {
    int i;
    for (i = num; i < size-1; i++) {
        arr[i] = arr[i + 1];
    }
}


void sort_even_odd(int n, int a[]) {
    int i,j,count=0;
    for (i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            count++;
        }
    }
    int* arr1 = (int*)malloc(count);
    for (i = 0,j=0; i < n; i++) {
        if (a[i] % 2 != 0) {
            arr1[j++]=a[i];
            leftShift(n,a,i);
        }
    }

    for (i = n-count,j=0; i < n; i++,j++) {
        a[i]=arr1[j];
    }
}


//void sort_even_odd(int n, int a[]) {
//    int i, j, count = 0,temp=0;
//    for (i = 0; i < n; i++) {
//        if (a[i] % 2 != 0) {
//            count++;
//        }
//    }
// 
//    for (i = 0, j = 0; i < n; i++) {
//        if (a[i] % 2 != 0) {
//            temp = a[i];
//            leftShift2(count, a, i);
//            a[count] = temp;
//        }
//    }
//
//    for (i = n - count, j = 0; i < n; i++, j++) {
//        a[i] = arr1[j];
//    }
//}

int find_max_array(int size, int a[]) {
    int i,max=0;
    for (i = 0; i < size; i++) {
        if (a[max] < a[i]) {
            max = i;
        }
    }
    return a[max];
}

int is_two_same(int size, int a[]) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (a[j] == a[i]&&j!=i) {
                return 1;
            }
        }
    }
    return 0;
}

int findMax(int size, int a[]) {
    int i, max = 0;
    for (i = 0; i < size; i++) {
        if (a[max] < a[i]) {
            max = i;
        }
    }
    return max;
}

int findMin(int size, int a[]) {
    int i, min = 0;
    for (i = 0; i < size; i++) {
        if (a[min] > a[i]) {
            min = i;
        }
    }
    return min;
}

void change_max_min(int size, int a[]) {
    int temp = 0, min = findMin(size, a), max = findMax(size, a);
    temp = a[min];
    a[min] = a[max];
    a[max] = temp;
}


int findMatrixNum(int*matrix[],int n,int m) {
    int i,j,sum=0,count=0;
    for (i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    int med = (int)((double)sum / (double)i);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (matrix[i][j] > med) {
                count++;
            }
        }
    }
    return count;
}


int getColor(int n,int m) {
    printf("2\n");
    if (n % 2 == 0) {
        if (m % 2 == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if (m % 2 == 0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    printf("3\n");
}












int main(void)
{
    setlocale(LC_ALL, "Rus");
    
    //1
    printf("Task1\n");
    int i,arr[] = { 20,19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5 };
    for (i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    sort_array(sizeof(arr)/sizeof(int), arr);
    printf("\n");
    for (i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    //2
    printf("Task2\n");
    int arr2[] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    for (i = 0; i < sizeof(arr2) / sizeof(int); i++) {
        printf("%d ", arr2[i]);
    }
    sort_even_odd(sizeof(arr2) / sizeof(int), arr2);
    printf("\n");
    for (i = 0; i < sizeof(arr2) / sizeof(int); i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n\n");


    //3
    printf("Task3\n");
    printf("%d", find_max_array(sizeof(arr2) / sizeof(int), arr2));
    printf("\n\n");


    //4
    printf("Task4\n");
    is_two_same(sizeof(arr2) / sizeof(int), arr2)== 1 ? printf("YES\n") : printf("NO\n");
    printf("\n\n");


    //5
    printf("Task5\n");
    int arr3[] = { 20,19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5 };
    for (i = 0; i < sizeof(arr3) / sizeof(int); i++) {
        printf("%d ", arr3[i]);
    }
    change_max_min(sizeof(arr3) / sizeof(int), arr3);
    printf("\n");
    for (i = 0; i < sizeof(arr3) / sizeof(int); i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n\n");



    //6
    printf("Task6\n");
    printf("Enter quad matrix\n");
    int j,n=0, matrix[5][5];
    char str[100];
    while (n<25) {
        scanf_s("%d", &matrix[n/5][n%5]);
        n++;
    }


    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int sum = 0, count = 0;
    for (i = 0; i < 5; i++) {
        sum += matrix[i][i];
    }
    int med = (int)((double)sum / (double)i);

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] > med) {
                count++;
            }
        }
    }
    printf("\n");
    printf("%d\n", count);
    //printf("%d", findMatrixNum(matrix, 5, 5));
    printf("\n\n");



    //7
    printf("Task7\n");
    char c=0;
    printf("Enter quad (like 'D 5')\n");
    scanf_s("%c %d", &c, 1, &n);
    getColor(n, (int)c-66) == 1 ? printf("Black") : printf("White");
    printf("\n\n");



    return 0;
}