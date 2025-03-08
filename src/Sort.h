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

/**
 * 堆排序
 */

//将以 k 下标为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len) {
    //A[0] 暂存子树的根节点
    A[0] = A[k];
    //沿着向下调整该子树，2k 表示左孩子，
    for(int i = 2 * k; i <= len; i *= 2) {
        //右节点存在的情况下，如果左节点小于右节点，
        //那么将下标移到右节点。
        if(i < len && A[i] < A[i+1])
            ++i;
        //如果两个子节点都没有根节点大，不用调整，
        //没有调整，自然就不会影响到大根堆，所以
        //不用再继续查看后面的
        if(A[0] >= A[i]) {
            break;
        }
        else {
            //将大的子节点移到父节点
            A[k] = A[i];
            k = i;
        }
    }
    //根节点最终存放位置
    A[k] = A[0];
}

//建立大根堆
void BuildMaxHeap(int A[], int len) {
    for(int i = len / 2; i > 0; --i)
        HeadAdjust(A, i, len);
}

//堆排序
void HeapSort(int A[], int len) {
    BuildMaxHeap(A, len);
    for(int i = len; i > 1; --i) {
        int temp = A[i];
        A[i] = A[1];
        A[1] = temp;
        HeadAdjust(A, 1, i - 1);
        // for (int i = 1; i <= len; ++i) {
        //     std::cout << A[i] << " ";
        // }
        // std::cout << std::endl;
    }
}

/**
 * 归并排序
 */

void Merge(int A[], int B[], int low, int mid, int high) {
    int i, j, k;
    for(k = low; k <= high; ++k)
        B[k] = A[k];
    for(i = low, j = mid + 1, k = i; i <= mid && j <= high; ++k) {
        if(B[i] <= B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    }
    while(i <= mid) A[k++] = B[i++];
    while(j <= high) A[k++] = B[j++];   
}

void MergeSort(int A[], int B[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        MergeSort(A, B, low, mid);
        MergeSort(A, B, mid + 1, high);
        Merge(A, B, low, mid, high);
        // for (int i = 0; i <= high; ++i) {
        //     std::cout << A[i] << " ";
        // }
        // std::cout << std::endl;
    }
}

#endif
