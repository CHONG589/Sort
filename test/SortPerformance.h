/**
 * @brief 测试排序性能
 * @date 2025-02-26
 */

#ifndef SORTPERFORMANCE_H__
#define SORTPERFORMANCE_H__

#include <iostream>
#include <ctime>
#include <cassert>

#include "./TestArr.h"
#include "../src/Sort.h"

/**
 * 对应的排序要拷贝对应的数组进行测试
 * 
 * 无参构造默认生成大小为10的数组，默认范围0 - 100
 * 
 * 构造好之后这里也要有生成随机数组、接近有序数组等的函数，
 * 它是调用TestArr中的函数。
 * 
 * 然后是测试对应排序的函数
 */

class Test : public TestArr {
public:
    Test() : TestArr(), bubblePerformance(0) { }
    Test(int n) : TestArr(n) { bubblePerformance = 0; }

    double getBubblePerformance() { return bubblePerformance; }
    double getShellPerformance() { return shellPerformance; }
    double getInsertPerformance() { return insertPerformance; }
    double getQuickPerformance() { return quickPerformance; }
    double getSelectPerformance() { return selectPerformance; }
    double getHeapPerformance() { return heapPerformance; }

    // 生成一定范围以内的随机数组
    void generateRanArr(const int &left, const int &right);
    // 生成几乎有序的随机数组
    void generateNearOrderArr(const int &left, const int &right);

    void printArr();
    bool isSorted(TestArr *arr);
    bool isHeapSorted(TestArr *arr);

    void testBubbleSort();
    void testShellSort();
    void testInsertSort();
    void testQuickSort();
    void testSelectSort();
    void testHeapSort();

private:
    double bubblePerformance;
    double shellPerformance;
    double insertPerformance;
    double quickPerformance;
    double selectPerformance;
    double heapPerformance;
};

void Test::generateRanArr(const int &left, const int &right) {
    assert(left <= right);
    srand(time(0));
    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % (int)(right - left + 1) + left;
    }
}

void Test::generateNearOrderArr(const int &left, const int &right) {
    assert(left <= right);
    int posx, posy = 0;
    for (int i = 0; i < length; ++i) {
        arr[i] = i + (right - left);
    }
    srand(time(0));
    for (int j = 0; j < length / 2; ++j) {
        posx = rand() % length;
        posy = rand() % length;
        if (posx == posy)
            --j;
        else    
            std::swap(arr[posx], arr[posy]);
    }
}

void Test::printArr() {
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

bool Test::isSorted(TestArr *arrObj) {
    for(int i = 0; i < arrObj->getLength() - 1; ++i) {
        if (arrObj->getArr()[i] > arrObj->getArr()[i + 1]) {
            std::cout << "Array is not Sorted!!!" << std::endl;
            return false;
        }
    }
    return true;
}

void Test::testBubbleSort() {
    TestArr bubbleSortArr(arr, length);
    clock_t startTime = clock();
    BubbleSort(bubbleSortArr.getArr(), bubbleSortArr.getLength());
    clock_t endTime = clock();

    //验证是否有序
    assert(isSorted(&bubbleSortArr));
    std::cout << "BubbleArr is sorted..." << std::endl;
    // bubblePerformance = (double(endTime - startTime) / CLOCKS_PER_SEC);
    bubblePerformance = (endTime - startTime);
}

void Test::testShellSort() {
    TestArr shellSortArr(arr, length);
    clock_t startTime = clock();
    ShellSort(shellSortArr.getArr(), shellSortArr.getLength());
    clock_t endTime = clock();

    //验证是否有序
    assert(isSorted(&shellSortArr));
    std::cout << "ShellArr is sorted..." << std::endl;
    shellPerformance = (endTime - startTime);
}

void Test::testInsertSort() {
    TestArr insertSortArr(arr, length);
    clock_t startTime = clock();
    InsertSort(insertSortArr.getArr(), insertSortArr.getLength());
    clock_t endTime = clock();

    //验证是否有序
    assert(isSorted(&insertSortArr));
    std::cout << "InsertArr is sorted..." << std::endl;
    insertPerformance = (endTime - startTime);
}

void Test::testQuickSort() {
    TestArr quickSortArr(arr, length);
    clock_t startTime = clock();
    int n = quickSortArr.getLength();
    QuickSort(quickSortArr.getArr(), 0, n - 1);
    clock_t endTime = clock();

    //验证是否有序
    assert(isSorted(&quickSortArr));
    std::cout << "QuickArr is sorted..." << std::endl;
    quickPerformance = (endTime - startTime);
}

void Test::testSelectSort() {
    TestArr selectSortArr(arr, length);
    clock_t startTime = clock();
    SelectSort(selectSortArr.getArr(), selectSortArr.getLength());
    clock_t endTime = clock();

    //验证是否有序
    assert(isSorted(&selectSortArr));
    std::cout << "selectArr is sorted..." << std::endl;
    selectPerformance = (endTime - startTime);
}

bool Test::isHeapSorted(TestArr *arrObj) {
    for(int i = 1; i < arrObj->getLength() - 1; ++i) {
        if (arrObj->getArr()[i] > arrObj->getArr()[i + 1]) {
            std::cout << "Array is not Sorted!!!" << std::endl;
            return false;
        }
    }
    return true;
}

void Test::testHeapSort() {
    TestArr HeapSortArr(length+1);
    std::copy(arr, &arr[length], &(HeapSortArr.getArr()[1]));
    clock_t startTime = clock();
    HeapSort(HeapSortArr.getArr(), HeapSortArr.getLength());
    clock_t endTime = clock();

    //验证是否有序
    assert(isHeapSorted(&HeapSortArr));
    std::cout << "HeapArr is sorted..." << std::endl;
    heapPerformance = (endTime - startTime);
}

#endif

