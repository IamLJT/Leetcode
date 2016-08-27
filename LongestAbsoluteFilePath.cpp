/*
��Ŀ��Longest Absolute File Path
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthLongestPath(string input) 
{
	string temp="";
	int subnum=0;			//	��¼���ڵڼ�Ŀ¼��
	int flagn=0;			//	��¼�Ƿ���\n
	int res0=0;				//	��¼���е������Ŀ¼����
	int direclen=0;			//	����Ŀ¼
	vector<int> subinfo;	//	��¼ÿ��Ŀ¼�µ�λ��
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
		else if(input[i]=='.')		//	����Ҫ��'.'�ż���·������
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
			if(subnum!=0)			//	��\t��\n�Ż����¼���temp�ĳ���
			{
				if(subnum>subinfo.size())	//	���\t�ĸ�����������Ŀ¼�ĸ�������ֱ���ں������
				{
					temp+='/';
					subinfo.push_back(temp.size()-1);
				}
				else						//	������֮ǰ��Ŀ¼ɾ�������ڼ����Ŀ¼����λ��
				{
					temp=temp.substr(0,subinfo[subnum-1]+1);
					int j=subinfo.size()-1;
					for(; j>subnum-1; j--)
						subinfo.pop_back();
				}
			}
			else if(flagn==1)				//	ֻ��\nû��\t���ʾ�Ǹ�Ŀ¼��ֱ�����
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