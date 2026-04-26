//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void) {
//    int arr1[3] = { 1, 2, 3 };
//    int arr2[3] = { 4, 5, 6 };
//    int sz1 = sizeof(arr1) / sizeof(arr1[0]);
//    int sz2 = sizeof(arr2) / sizeof(arr2[0]);
//    int* sm = (int *)malloc((sz1 + sz2) * sizeof(int));
//    for (int i = 0; i < sz1; i++) {
//        sm[i] = arr1[i];
//    }
//    for (int i = 0; i < sz2; i++) {
//        sm[sz1 + i] = arr2[i];
//    }
//
//    for (int i = 0; i < sz1 + sz2; i++) {
//        printf("%d", sm[i]);
//    }
//
//    return 0;
//}