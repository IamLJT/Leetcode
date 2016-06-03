/*
题目：Reverse Words in a String
要求：Given an input string, reverse the string word by word.
*/

#include <iostream>
#include <string>
using namespace std;

void reverseWords(string &s) 
{
    int k;
    for(k=0; s[k]==' '; k++);
    s=s.substr(k);
    reverse(s.begin(), s.end());
    for(k=0; s[k]==' '; k++);
    s=s.substr(k);
    int pos=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==' '&&i>pos)
        {
            reverse(s.begin()+pos, s.begin()+i);
            pos=i+1;
        }
		if(s[pos]==' ')
            s=s.substr(0,pos)+s.substr(pos+1);
    }
	reverse(s.begin()+pos, s.end());
}

int main()
{
	string s="   abc   bac ";
	reverseWords(s);
	cout << s << endl;
	system("pause");
	return 0;
}