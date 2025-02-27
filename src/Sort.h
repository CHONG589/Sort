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

/**
 * 快速排序
 */
//划分函数
//用第一个元素将待排序序列划分成左右两个部分
int Partition(int *A, int low, int high) {
    int pivot = A[low];
    while(low < high) {
        while(low < high && A[high] >= pivot) --high;
        A[low] = A[high];
        while(low < high && A[low] <= pivot) ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

//快速排序主体
void QuickSort(int *A, int low, int high) {
    if (low < high) {
        int pivotpos = Partition(A, low, high);
        // std::cout << A[pivotpos] << ": ";
        // for (int i = 0; i <= high; ++i) {
        //     std::cout << A[i] << " ";
        // }
        // std::cout << std::endl;
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}

/**
 * 简单选择排序
 */
void SelectSort(int *A, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j)
            if (A[j] < A[min]) min = j;
        if (min != i) {
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
        // for (int i = 0; i < n; ++i) {
        //     std::cout << A[i] << " ";
        // }
        // std::cout << std::endl;
    }
}

#endif
