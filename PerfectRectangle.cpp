/*
题目：Perfect Rectangle
要求：Given N axis-aligned rectangles where N > 0, determine if they all 
together form an exact cover of a rectangular region.
Each rectangle is represented as a bottom-left point and a top-right point. 
For example, a unit square is represented as [1,1,2,2]. (coordinate of 
bottom-left point is (1, 1) and top-right point is (2, 2)).
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cmp(vector<int> n1, vector<int> n2)
{
	if(n1[0]<n2[0])
		return 1;
	else if(n1[0]==n2[0]&&n1[1]<n2[1])
		return 1;
	return 0;
}

bool isRectangleCover(vector<vector<int>>& rectangles) 
{
	vector<vector<int>> rect(rectangles);
	sort(rect.begin(),rect.end(),cmp);

	int len=rect.size();

	int n=0;
	int high;	//	记录最高位置
	for(int i=1; i<len; i++)
	{
		if(rect[i][0]==rect[i-1][0])				//	第一种大情况：两方块左对齐
		{
			if(rect[i][1]!=rect[i-1][3])			//	不能重叠或间隔开
			{
				return false;
			}
			else									//	分三种情况：上面的矩形长度大于下面的和下面的矩形长度大于上面，以及长度完全相等的
			{
				if(rect[i][2]==rect[i-1][2])
				{
					rect[i][0]=rect[i-1][0];
					rect[i][1]=rect[i-1][1];
				}
				else
				{
					vector<int> temp(4,0);
					if(rect[i][2]>rect[i-1][2])
					{
						temp[0]=rect[i-1][2];
						temp[1]=rect[i-1][3];
						temp[2]=rect[i][2];
						temp[3]=rect[i][3];
						rect[i-1][2]=rect[i-1][2];
						rect[i-1][3]=rect[i][3];
					}
					else
					{
						temp[0]=rect[i][2];
						temp[1]=rect[i-1][1];
						temp[2]=rect[i-1][2];
						temp[3]=rect[i-1][3];
						rect[i-1][2]=rect[i][2];
						rect[i-1][3]=rect[i][3];
					}
					rect.erase(rect.begin()+i);
					int pos=upper_bound(rect.begin()+i,rect.end(),temp)-rect.begin();
					rect.insert(rect.begin()+pos,temp);
					//	由于有插入删除的操作，复杂度会很高，如何优化？
					i--;
				}
			}
		}
		else if(rect[i][0]==rect[i-1][2]&&rect[i][1]==rect[i-1][1])
		{
			n++;
			if(n==1)
			{
				high=rect[i-1][3];
			}
			else
			{
				if(high!=rect[i-1][3])
					return false;
			}
		}
		else
		{
			return false;
		}
	}
	n++;
    if(n==1)
    {
    	high=rect.back()[3];
    }
    else
    {
    	if(high!=rect.back()[3])
    		return false;
    }
	return true;
}

int main()
{
	vector<vector<int>> rect;

	//int a[]={1,1,3,3};
	//int b[]={3,1,4,2};
	//int c[]={3,2,4,4};
	//int d[]={1,3,2,4};
	//int e[]={2,3,3,4};

	int a[]={1,1,3,3};
	int b[]={3,1,4,2};
	int c[]={1,3,2,4};
	int d[]={2,2,4,4};

	rect.push_back(vector<int>(a,a+4));
	rect.push_back(vector<int>(b,b+4));
	rect.push_back(vector<int>(c,c+4));
	rect.push_back(vector<int>(d,d+4));
	//rect.push_back(vector<int>(e,e+4));

	cout << isRectangleCover(rect) << endl;

	system("pause");
	return 0;
}