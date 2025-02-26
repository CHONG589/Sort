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
template<typename T>
void BubbleSort1(T arr[], const int n) {
    int i, j;
    int temp = 0;

    for (i = 0; i < n - 1; ++i) {
        // i 用于控制每次循环需要交换的次数
        // 如第一次循环需要交换 n - 1 次，之后每
        // 循环一次就会减少一次
        for (j = n - 2; j >= i; --j) {
            // j 从倒数第二个开始，j >= i 用于控
            // 制每次循环需要交换的次数。
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * 冒泡排序优化版
 */
template<typename T>
void BubbleSort(T arr[], const int n) {
    int k = n;

    // 如果一个循环下来，一次都没有交换相邻的元素，
    // 那么说明数组已经有序，不用再交换了。
    bool swaped;
    do {
        swaped = false;
        for (int i = 1; i < k; ++i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swaped = true;
            }
        }
        --k;
    } while(swaped);
}

#endif
