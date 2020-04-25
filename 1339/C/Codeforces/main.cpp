//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1339/problem/B)
 **题目大意：**
 
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 接下来每个样例一行，四个整数𝑎 , 𝑏, 𝑐, 𝑑 (1≤𝑎≤𝑏≤𝑐≤𝑑≤10^9）
 
 **输出：**
 每个样例一行，三个s整数𝑥, 𝑦, 𝑧；
 
 **Examples**
 **input**
 4
 1 3 5 7
 1 5 5 7
 100000 200000 300000 400000
 1 1 977539810 977539810
 **output**
 3 4 5
 5 5 5
 182690 214748 300999
 1 977539810 977539810
 
 
 **题目解析：**
 按照题意，分别可以加上数字1、2、4、8、16、、、
 由于数字递增很快（指数级），可以遇见不会添加很多次；
 那么可以考虑暴力来解决，枚举s=0、1、2、3、4、5、6的情况是否满足要求，每次枚举的复杂度是O（NLogM）；M是数字大小，最多枚举LogM次；
 
 接着，需要找一种能快速验证，当s=k的时候，是否满足要求；
 由贪心的思想，我们知道对于数字a[n]，由于预期a[n]是最大的数字，可以直接将所有的数字加到a[n]上；
 对于数字a[n-1]，我们希望a[n-1]在满足a[n-1]<=a[n]的情况下，尽可能的大；
 同理，我们希望a[n-2]、a[n-3]、、、都是如此的处理；
 
 那么问题变成，如何保证a[i-1]在满足a[i-1]<=a[i]的情况下，a[i-1]尽可能的大？
 答案就是：从大到小的加数字(2^(x-1))，直到数字无法添加，此时数字就是最大；
  
 注意，这里不是从小到大；比如说数字6变成12，如果从大到小有6+4+2=12，但是如果变成从小开始，则会出现取了数字1、2之后，无法取4，最大值就是9；
 
 **思考🤔：**
 
 ************************* 题解 ***********************/
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long lld;
const int N = 100010, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

lld p[N];
lld a[N];

bool check(int n, int k) {
    lld last = llinf;
    for (int i = n - 1; i >= 0; --i) {
        lld tmp = a[i];
        for (int j = k; j >= 1; --j) {
            if (tmp + p[j-1] <= last) {
                tmp += p[j - 1];
            }
        }
        if (tmp > last) {
            return false;
        }
        last = tmp;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    p[0] = 1;
    for (int i = 1; i < 31; ++i) p[i] = p[i-1] * 2;
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        int k = 0;
        while (1) {
            if (check(n, k)) {
                cout << k << endl;
                break;
            }
            k++;
        }
    }   
    
    return 0;
}
