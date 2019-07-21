//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1185/problem/C)
 **题目大意：**
 n个人参加测试，测试需要老师和学生一对一进行，同一时刻只能有一个学生在测试，每个人测试的耗时不同；
 现在按照顺序进行测试，已知测试的总时间为m，每个人的测试时间为t[i]；
 想要知道对于第i个人，最少需要直接淘汰前面多少个人，才能有足够的时间让其能在规定时间m内完成测试；（每个人是相对独立的，对于第i个人和第i+1个人，淘汰的人可能各不相同）
 
 输入：
 第一行两个整数𝑛 and 𝑀，分别表示n个人和测试总时间M (1≤𝑛≤100, 1≤𝑀≤100)
 第二行是n个整数t[i]，分别表示n个人的测试时间。(1≤𝑡[𝑖]≤100)
 
 输出：
 对于每个人，输出通过测试，需要淘汰的最少人数；
 
 Examples
 input
 7 15
 1 2 3 4 5 6 7
 output
 0 0 0 0 0 2 3

 样例解释：
 对于前5个人，都不需要淘汰人即可完成测试；
 对于第6个人，可以淘汰第3、4个人，剩下的人可以完成测试；
 对于第7个人，可以淘汰第3、4、5个人，剩下的人可以完成测试；
 
 
 **题目解析：**
 题目的数据范围比较小，可以使用较为粗暴的方式：
 记录前i个人的耗时之和sum，如果sum>m，则对前i个人排序，然后从大的开始淘汰，直到sum<=m即可。
 
 
 
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

int a[N], ans[N];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (sum <= m) {
            ans[i] = 0;
        }
        else {
            sort(a, a + i);
            int tmp = sum;
            while (tmp > m) {
                ++ans[i];
                tmp -= a[i - ans[i]];
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}
