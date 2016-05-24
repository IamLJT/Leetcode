/*
题目：Find Median from Data Stream
要求：Median is the middle value in an ordered integer list. If the size of 
the list is even, there is no middle value. So the median is the mean of the 
two middle value.

题目大意：找有序整数列的中位数，奇数个数为中间值，偶数个数则是中间两位数平均值。

思路：因为要多次计算，所以不能每次寻找中位数的时候计算一遍所有的数，用一个小
顶堆和一个大顶堆存放数字即可，小顶堆的数均不小于大顶堆的数，并且大顶堆数的个数
不少于小顶堆的数。
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
public:
    void addNum(int num) 
	{
		small.push(num);
		large.push(-small.top());//用负数来表示则是小顶堆
		small.pop();
		if(small.size()<large.size())
		{
			small.push(-large.top());
			large.pop();
		}
    }

    double findMedian() 
	{
        return small.size()>large.size()
			? small.top() :
			(small.top()-large.top())/2.0;
    }
private:
	priority_queue<long> small, large;
	//	默认情况下priority_queue为大顶堆
	//	small为较小的数堆，为大顶堆， large为较大的数堆，为小顶堆
};

int main()
{
	MedianFinder MF;
	MF.addNum(1);
	cout << MF.findMedian() << endl;
	MF.addNum(3);
	cout << MF.findMedian() << endl;
	MF.addNum(2);
	cout << MF.findMedian() << endl;
	system("pause");
	return 0;
}