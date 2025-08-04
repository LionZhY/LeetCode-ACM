#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 295 数据流的中位数


class MedianFinder {
    priority_queue<int> left; // 大顶堆（默认），存较小的一半
    priority_queue<int, vector<int>, greater<int>> right; // 小顶堆，存较大的一半
    
public:
    MedianFinder() {}
    
    void addNum(int num) {

        if (left.size() == right.size()) // 两边数量相等，直接加入右边
        {
            right.push(num);
            left.push(right.top()); // 右边弹出来最小的一个，加入left
            right.pop();
        }
        else // 左边数量多，直接加入左边，左边弹出来再给右边
        {
            left.push(num);
            right.push(left.top()); // 左边弹出来最大的一个，加入right
            left.pop();
        }        
    }
    
    double findMedian() {
        if (left.size() > right.size()) return left.top();
        else                            return (left.top() + right.top()) / 2.0;

    }
};


int main()
{
    MedianFinder mymid;
    mymid.addNum(1);
    mymid.addNum(2);
    cout << mymid.findMedian() << endl;
    mymid.addNum(3);
    cout << mymid.findMedian() << endl;

    return 0;
}