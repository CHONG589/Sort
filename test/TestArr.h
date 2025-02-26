/**
 * @brief 用于生成测试的数组实例类
 * @date 2025-02-26
 */

#ifndef TESTARR_H__
#define TESTARR_H__

#include <iostream>
#include <cassert>

class TestArr {
public:
    // 当无参构造时，默认数组大小为 10
    TestArr() : length(10) { assert(length > 0); arr = new int[length];}
    TestArr(int n);
    TestArr(int *arr, int n);
    // 拷贝构造函数
    TestArr(const TestArr &testArr);
    ~TestArr() { delete[] arr; } 

    int getLength() { return length; }
    int *getArr() { return arr; }

protected:
    int *arr;
    int length;
};

TestArr::TestArr(int n) : length(n) {
    assert(n > 0);
    arr = new int[n];
}

TestArr::TestArr(const TestArr &testArr) {
    this->arr = new int[testArr.length];
    this->length = testArr.length;
    for (int i = 0; i < this->length; ++i) {
        this->arr[i] = testArr.arr[i];
    }
}

TestArr::TestArr(int *arr, int n) {
    this->arr = new int[n];
    this->length = n;
    for (int i = 0; i < n; ++i) {
        this->arr[i] = arr[i];
    }
}

#endif
