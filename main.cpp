#include <iostream>
#include <array>

#include "./src/Sort.h"
#include "./test/TestArr.h"
#include "./test/SortPerformance.h"

int main() {

    // // 生成随机数组
    // TestArr randArr(10);
    // randArr.generateRanArr(0, 1000);
    // randArr.printArr();

    // //生成用于测试各种排序的数组
    // TestArr bubbleSortArr(randArr);
    // TestArr mergeSortArr(randArr);

    // // BubbleSort1(arr, 9);
    // // BubbleSort(bubbleSortArr.getArr(), bubbleSortArr.getLength());
    // Test test;
    // test.testBubbleSort();

    // bubbleSortArr.printArr();

    Test test(10);
    // Test test;
    test.generateRanArr(0, 1000);
    std::cout << "产生的随机数组为: ";
    test.printArr();
    std::cout << std::endl;
    test.testBubbleSort();
    std::cout << "BubbleSort runtime: " << test.getBubblePerformance() << "ms" << std::endl;
    test.testShellSort();
    std::cout << "ShellSort runtime: " << test.getShellPerformance() << "ms" << std::endl;

    return 0;
}
