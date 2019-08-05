/*************************************************************************
	> File Name:    tt.cpp
	> Author:       candy7 
	> Mail:         bc970321@163.com
	> Created Time: 2019年07月26日 星期五 16时38分33秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;




int main() {
    int a[1005] = {0};
    int n, x, num = 0;
    cin >> n;
    int max = -1;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (a[x] == 0 ) {
            num ++;
            a[x] = 1;
        }
        if (max < x) max = x;
    }
    cout << num << endl;
    for (int i = 0; i <= max; i++) {
        if (a[i] != 0) {
            cout << i;
            if (i != max) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}



