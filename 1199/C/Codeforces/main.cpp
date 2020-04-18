
//
//  main.cpp
//  Codeforces
//
//  Created by loyinglin.
//  Copyright loyinglin. All rights reserved.

/************************** 题解 **********************
 [题目链接](http://codeforces.com/contest/1199/problem/C)
 **题目大意：**
 MP3文件是一个个整数组成，假设是n个非负整数；
 数组中假如有K个不同的整数，那么每个数字需要𝑘=⌈log2𝐾⌉的bits来存储，那么整个文件需要的体积是n𝑘；
 
 为了压缩MP3文件，我们可以选择两个数字l和r（l<r），然后对数组进行处理，如果数字在[l, r]中间则保持不变，小于l则变为l，大于r则变为r；
 容易知道，改变的数字越多，MP3的音质则会越差。
 现在已知硬盘上的空间有Ibytes（1byte=8bits），现在想知道最少改变多少个数字，可以使得该文件可以放置到硬盘；
 
 
 输入：
 第一行是两个整数 𝑛 and 𝐼 (1≤𝑛≤4⋅1e5, 1≤𝐼≤1e8)
 第二行是n个整数  𝑎𝑖 (0≤𝑎𝑖≤1e9)
 
 
 输出：
 一个数字，表示最少的文字修改个数。

 
 Examples
 input
 6 1
 2 1 2 3 4 3
 output
 2
 input
 6 2
 2 1 2 3 4 3
 output
 0
 
 
 **题目解析：**

 遍历一遍数组，我们可以知道K，然后计算得到k，最后计算体积nk；
 如果体积不够，则我们需要改变数字；
 按照题目的规则，我们改变的肯定是数组中最小或者最大的元素，数字的先后顺序没有意义，我们将数字进行一个排序；

 由体积来反推，当我们知道Ibytes的总体积之后，我们可以估算出每个字的平均体积是(I*8/n)；
 根据题意，我们知道数组中最多能有2^(I*8/n)个不同的数字，因为I比较大，这里为了避免超过int，我们可以认为最多有100w个不同的数字；
 
 这样，当数组排好序之后，我们也知道数组中存在K个不同的数字，那么可以先预处理出每个数字的个数，然后枚举k个连续的不同数字的起始坐标x，在(x, x+K)之内的数字个数。
 
 整体的时间复杂度是O(NlogN)，耗时主要是排序。
 
 注意：
 TLE 一次，用了cin；改为scanf可以避免；（因为数字都很大，用cin耗时比较长）
 RE  一次，判断数组长度时候没有用vec.size，而是用了n；
 
 
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
const int N = 401000, M = 3010100, inf = 0x7fffffff;
const lld llinf = 0x7fffffff7fffffffll;

vector<int> vec;
map<int, int> cnt;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m;
    cin >> n >> m;
    int k = pow(2, min(20, m * 8 / n));
    // k different numbers
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        cnt[t]++;
        if (cnt[t] == 1) {
            vec.push_back(t);
        }
    }
    sort(vec.begin(), vec.end());
    int sum = 0, maxSum = 0;
    for (int i = 0; i < vec.size() && i < k; ++i) {
        sum += cnt[vec[i]];
    }
    maxSum = sum;
    for (int i = k; i < vec.size(); ++i) {
        sum += cnt[vec[i]] - cnt[vec[i - k]];
        maxSum = max(maxSum, sum);
    }
    cout << n - maxSum << endl;

    return 0;
}
