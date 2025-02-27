#include <iostream>
#include <array>

#include "./src/Sort.h"
#include "./test/TestArr.h"
#include "./test/SortPerformance.h"

int main() {

    Test test(1000);
    // Test test(10);
    // Test test;
    std::cout << "===============采用随机数组进行测试==============" << std::endl;
    test.generateRanArr(0, 1000);
    // std::cout << "产生的随机数组为: " << std::endl;
    // test.printArr();
    // std::cout << std::endl;

    test.testBubbleSort();
    test.testShellSort();
    test.testInsertSort();
    test.testQuickSort();
    test.testSelectSort();

    std::cout << std::endl;
    std::cout << "BubbleSort runtime: " << test.getBubblePerformance() << "ms" << std::endl;
    std::cout << "ShellSort runtime: " << test.getShellPerformance() << "ms" << std::endl;
    std::cout << "InsertSort runtime: " << test.getInsertPerformance() << "ms" << std::endl;
    std::cout << "QuickSort runtime: " << test.getQuickPerformance() << "ms" << std::endl;
    std::cout << "SelectSort runtime: " << test.getSelectPerformance() << "ms" << std::endl;
    std::cout << std::endl;

    std::cout << "============采用几乎有序的随机数组进行测试===========" << std::endl;
    test.generateNearOrderArr(0, 1000);
    // std::cout << "产生几乎有序的随机数组为: " << std::endl;
    // test.printArr();
    // std::cout << std::endl;

    test.testBubbleSort();
    test.testShellSort();
    test.testInsertSort();
    test.testQuickSort();
    test.testSelectSort();

    std::cout << std::endl;
    std::cout << "BubbleSort runtime: " << test.getBubblePerformance() << "ms" << std::endl;
    std::cout << "ShellSort runtime: " << test.getShellPerformance() << "ms" << std::endl;
    std::cout << "InsertSort runtime: " << test.getInsertPerformance() << "ms" << std::endl;
    std::cout << "QuickSort runtime: " << test.getQuickPerformance() << "ms" << std::endl;
    std::cout << "SelectSort runtime: " << test.getSelectPerformance() << "ms" << std::endl;

    return 0;
}
