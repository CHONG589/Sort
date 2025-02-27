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
void BubbleSort1(int arr[], const int n) {
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
void BubbleSort(int arr[], const int n) {
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
        // for (int i = 0; i < n; ++i) {
        //     std::cout << arr[i] << " ";
        // }
        // std::cout << std::endl;
        --k;
    } while(swaped);
}

/**
 * 希尔排序
 */
void ShellSort(int *arr, const int n) {
    int j = 0;
    int temp = 0;

    //此循环控制增量的值，即取增量值为多少，增量值最小为1
    for (int increment = n / 2; increment > 0; increment /= 2) {
        //下面两个循环是跟直接插入排序差不多，都是控制选取两个值进行
        //比较，只不过增量变为increment
        for (int i = increment; i < n; ++i) {
            //从后面开始选取
            temp = arr[i];
            for (j = i - increment; j >= 0; j -= increment) {
                if (temp < arr[j]) {
                    //temp是存较小的值的，每次比较都是和temp比较，
                    //然后将前面大的值存后面。
                    //j+increment 不能换成i, 只有第一次才是i
                    arr[j + increment] = arr[j];
                }
                else {
                    //遇到temp比较大了，则跳出此循环，将temp的值换
                    //到j+increment，因为temp > j，所以将temp存到
                    //j+increment
                    break;
                }
            }
            arr[j + increment] = temp;
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

    //从第二个数据开始，第一个元素可以认为已经被排序
    for (i = 1; i < n; ++i) {
        //取出一个数据，在已经排好序的序列中从后向前扫描
        temp = arr[i];
        for (j = i; j > 0 && temp < arr[j - 1]; --j) {
            //将前面大的值移到后面
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;

        // for (int i = 0; i < n; ++i) {
        //     std::cout << arr[i] << " ";
        // }
        // std::cout << std::endl;
    }
}

#endif
