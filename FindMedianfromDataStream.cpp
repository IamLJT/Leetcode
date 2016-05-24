/*
��Ŀ��Find Median from Data Stream
Ҫ��Median is the middle value in an ordered integer list. If the size of 
the list is even, there is no middle value. So the median is the mean of the 
two middle value.

��Ŀ���⣺�����������е���λ������������Ϊ�м�ֵ��ż�����������м���λ��ƽ��ֵ��

˼·����ΪҪ��μ��㣬���Բ���ÿ��Ѱ����λ����ʱ�����һ�����е�������һ��С
���Ѻ�һ���󶥶Ѵ�����ּ��ɣ�С���ѵ�������С�ڴ󶥶ѵ��������Ҵ󶥶����ĸ���
������С���ѵ�����
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
		large.push(-small.top());//�ø�������ʾ����С����
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
	//	Ĭ�������priority_queueΪ�󶥶�
	//	smallΪ��С�����ѣ�Ϊ�󶥶ѣ� largeΪ�ϴ�����ѣ�ΪС����
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