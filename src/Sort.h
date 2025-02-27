/**
 * @brief Sort.h
 * @date 2025-02-26
 */

#ifndef SORT_H__
#define SORT_H__

#include <iostream>

/**
 * @brief 冒泡排序
 */
void BubbleSort(int arr[], const int n) {
    int i, j;
    int temp = 0;

    for (i = 0; i < n - 1; ++i) {
        bool flag = false;
        for (j = n - 1; j > i; --j) {
            // j 从倒数第二个开始，j >= i 用于控
            // 制每次循环需要交换的次数。
            if (arr[j - 1] > arr[j]) {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                flag = true;
            }
        }
        if (flag == false) return ;

        // for (int i = 0; i < n; ++i) {
        //     std::cout << arr[i] << " ";
        // }
        // std::cout << std::endl;
    }
}

/**
 * 希尔排序
 */
void ShellSort(int *arr, const int n) {
    int d, i, j, temp;
    for(d = n / 2; d >= 1; d /= 2) {
        for(i = d; i < n; ++i) {
            if (arr[i] < arr[i - d]) {
                temp = arr[i];
                for(j = i - d; j >= 0 && temp < arr[j]; j -= d)
                    arr[j + d] = arr[j];
                arr[j + d] = temp;
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     std::cout << arr[i] << " ";
        // }
        // std::cout << std::endl;
    }
}

/**
 * 直接插入排序
 */
void InsertSort(int *arr, const int n) {
    int i, j, temp;

    for (i = 1; i < n; ++i) {
        if(arr[i] < arr[i - 1]) {
            temp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > temp; --j)
                arr[j + 1] = arr[j];
            arr[j + 1] = temp;
        }

        // for (int i = 0; i < n; ++i) {
        //     std::cout << arr[i] << " ";
        // }
        // std::cout << std::endl;
    }
}

#endif
