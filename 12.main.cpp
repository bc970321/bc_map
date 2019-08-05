/*************************************************************************
	> File Name:    12.main.cpp
	> Author:       candy7 
	> Mail:         bc970321@163.com
	> Created Time: 2019年07月24日 星期三 15时08分31秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include "12.binary_search_tree.h"
using namespace std;
using Arrayint = haizei::BinarySearchTree<int>;

struct A {
    A(int x, int y) : x(x) , y(y) {}
    int x, y;
};

using ArrayA = haizei::BinarySearchTree<A>;

int main() {
    srand(time(0));
    Arrayint arr;
    ArrayA arr2;
    for (int i = 0; i < 20; i++) arr.insert(rand() % 100);
    for (int i = 0; i < 20; i++) arr2.insert(ramd() % 100);
    for (Arrayint::iterator iter = arr.begin(); iter != arr.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}


