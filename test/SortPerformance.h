/**
 * @brief 测试排序性能
 * @date 2025-02-26
 */

#ifndef SORTPERFORMANCE_H__
#define SORTPERFORMANCE_H__

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

    // 生成一定范围以内的随机数组
    void generateRanArr(const int &left, const int &right);
    // 生成几乎有序的随机数组
    void generateNearOrderArr();
    
    void printArr();
    bool isSorted(TestArr *arr);

    void testBubbleSort();
    void testShellSort();

private:
    double bubblePerformance;
    double shellPerformance;
};

void Test::generateRanArr(const int &left, const int &right) {
    assert(left <= right);
    srand(time(0));
    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % (int)(right - left + 1) + left;
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
    // bubblePerformance = (double(endTime - startTime) / CLOCKS_PER_SEC);
    shellPerformance = (endTime - startTime);
}

#endif

