//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1339/problem/A)
 **题目大意：**
 给出一个图形，下面是n=1、2、3、4的时候：
 
 
 现在需要把上面的图形染色，由若干个菱形组成；
 问，有多少种染色方法？
 
 
 **输入：**
 第一行，整数𝑡表示有t个样例数量 (1≤𝑡≤1000)
 接下来每个样例一行，整数𝑛  (1≤𝑛≤10^9).
 
 **输出：**
 每个样例一行，染色的方法数量。
 
 **Examples**
 **input**
 2
 2
 1
 **output**
 2
 1
 
 
 **题目解析：**
 找规律的问题，先从n=1开始考虑，只有一种方案；
 n=2的时候，我们可以采用染色方案1，将第一个竖着的菱形染色；也可以先上下斜着放，将第二个竖着的菱形染色；
 同理n=3时，有将第1、2、3个菱形染色的方案；
 总结规律， ans=n；
 
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
const int N = 1000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;


struct Node {
    int first, second;
    
    bool operator<(const Node &tmp) const
    {
        if (first != tmp.first) return first < tmp.first;
        else return second < tmp.second;
    };
    Node(int first, int second):first(first), second(second){};
    Node(){};
}node[N];

bool cmp(int a, int b) {
    return a > b;
}

int a[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << n << endl;
    }   
    
    return 0;
}
