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

    // 生成一定范围以内的随机数组
    void generateRanArr(const int &left, const int &right);
    // 生成几乎有序的随机数组
    void generateNearOrderArr(const int &left, const int &right);

    void printArr();
    bool isSorted(TestArr *arr);

    void testBubbleSort();
    void testShellSort();
    void testInsertSort();
    void testQuickSort();

private:
    double bubblePerformance;
    double shellPerformance;
    double insertPerformance;
    double quickPerformance;
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
    shellPerformance = (endTime - startTime);
}

void Test::testInsertSort() {
    TestArr insertSortArr(arr, length);
    clock_t startTime = clock();
    InsertSort(insertSortArr.getArr(), insertSortArr.getLength());
    clock_t endTime = clock();

    //验证是否有序
    assert(isSorted(&insertSortArr));
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
    quickPerformance = (endTime - startTime);
}

#endif

