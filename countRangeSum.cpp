#include <iostream>
#include <vector>
#include <string>
using namespace std;
int help(vector<long>& sums, int start, int end, int lower, int upper)
{
	if(end <= start) return 0;
	int mid = (end+start)/2;
	int count = help(sums, start, mid, lower, upper)
				+help(sums, mid, end, lower, upper);
	int m=mid, n=mid, t=mid, len=0;
	vector<long> Cashe(end-start,0);
	for(int i=0,s=0; i<mid; i++,s++)
	{

	}
}