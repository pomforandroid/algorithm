// UnionFind.cpp : Defines the entry point for the application.
//

#include "UnionFind.h"
#include <iostream>
#include "UnionFindTestHelper.h"

using namespace std;

int main()
{
    // 使用10000的数据规模
    int n = 1000000;

    // 虽然isConnected只需要O(1)的时间, 但由于union操作需要O(n)的时间
    // 总体测试过程的算法复杂度是O(n^2)的
    //UnionFindTestHelper::testUF1(n);
    //UnionFindTestHelper::testUF2(n);
    UnionFindTestHelper::testUF3(n);
    UnionFindTestHelper::testUF4(n);

    return 0;
}
