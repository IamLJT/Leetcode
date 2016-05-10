#include <iostream>
#include <vector>
using namespace std;
int left(vector<int> height,int mid)
{
	int num=mid, n0=mid, res=mid;
	for(int i=mid-1;i>=0;i--)
	{
		if(height[i]<height[mid])
		{
			n0=i;
			num=mid-i-1;
			for(int j=n0-1;j>=0;j--)
			{
				if(height[j]<height[n0])
					n0=j;
				else
					num++;
			}
			if(num<res)
				res=num;
			num=mid;
		}
	}
	return res;
}
int Right(vector<int> height,int mid)
{
	int num=height.size()-mid, n0=mid, res=height.size()-mid;
	for(int i=mid+1;i<height.size();i++)
	{
		if(height[i]<height[mid])
		{
			n0=i;
			num=i-mid-1;
			for(int j=n0+1;j<height.size();j++)
			{
				if(height[j]<height[n0])
					n0=j;
				else
					num++;
			}
			if(num<res)
				res=num;
			num=height.size()-mid;
		}
	}
	return res;
}
int main()
{
	vector<int> height;
	int n;
	cin >> n;
	while(scanf("%d", &n)!=EOF && getchar()!='\n')
		height.push_back(n);
	height.push_back(n);
	int Result = height.size();
	for(int i=0;i<height.size();i++)
	{
		if(Result > (left(height, i)+Right(height, i)))
			Result = left(height, i)+Right(height, i);
	}
	cout << Result << endl;
	system("pause");
	return 0;
}
