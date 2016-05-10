#include <iostream>
#include <string>
using namespace std;
string reverseVowels(string s) {
        string s0=s;
        int *num = (int*)malloc(sizeof(int) * s.size());
        int top=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]== 'u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]== 'U')
            {
                num[top++] = i;
            }
        }
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]== 'u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]== 'U')
            {
                s[i] = s0[num[--top]];
            }
        }
		
        return s;
    }
int main()
{
	string s = "I am an apple!";
	cout << "Begin: " << s << endl
		<< "End: " << reverseVowels(s) << endl;

	system("pause");
	return 0;
}