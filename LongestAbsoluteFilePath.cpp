/*
题目：Longest Absolute File Path
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthLongestPath(string input) 
{
	string temp="";
	int subnum=0;			//	记录是在第几目录下
	int flagn=0;			//	记录是否有\n
	int res0=0;				//	记录已有的最长绝对目录长度
	int direclen=0;			//	几个目录
	vector<int> subinfo;	//	记录每个目录下的位置
	for(int i=0; i<input.size(); i++)
	{
		if(input[i]=='\n')
		{
			flagn=1;
			i++;
			while(input[i]=='\t')
			{
				i++;
				subnum++;
			}
			i--;
		}
		else if(input[i]=='.')		//	必须要有'.'才计入路径长度
		{
			temp+=input[i];
			while(++i<input.size()&&input[i]!='\n')
				temp+=input[i];
			i--;
			if(temp.size()>res0)
				res0=temp.size();
		}
		else
		{
			if(subnum!=0)			//	有\t或\n才会重新计算temp的长度
			{
				if(subnum>subinfo.size())	//	如果\t的个数大于已有目录的个数，则直接在后面添加
				{
					temp+='/';
					subinfo.push_back(temp.size()-1);
				}
				else						//	否则则将之前的目录删除到现在计算的目录个数位置
				{
					temp=temp.substr(0,subinfo[subnum-1]+1);
					int j=subinfo.size()-1;
					for(; j>subnum-1; j--)
						subinfo.pop_back();
				}
			}
			else if(flagn==1)				//	只有\n没有\t则表示是根目录，直接清空
			{
				temp.clear();
				subinfo.clear();
			}
			temp+=input[i];
			subnum=0;
			flagn=0;
		}
	}
	return res0;
}
int main()
{
	string s="a\n\tb.txt\na2\n\tb2.txt";
	cout << lengthLongestPath(s) << endl;
	system("pause");
	return 0;
}