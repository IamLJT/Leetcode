/*
Title: Beautiful Arrangement
Question: Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ¡Ü i ¡Ü N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?
*/

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& res, int i, int j)
{
	int tmp = res[i];
	res[i] = res[j];
	res[j] = tmp;
}

int count(int n, vector<int>& res)
{
	if (n <= 0) return 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (res[i] % n == 0 || n%res[i] == 0) {
			// If divisible, it is not neccessary to detect the res[n-1] is divisible by i+1 or not again. Why?
			swap(res, i, n - 1);
			ans += count(n - 1, res);
			swap(res, i, n - 1);
		}
	}
	return ans;
}

int countArrangement(int N) {
	vector<int> res;
	for (int i = 0; i < N; i++)
		res.push_back(i + 1);
	return count(N, res);
}

int main(void)
{
	int N;
	while (cin >> N)
	{
		cout << "There are " << countArrangement(N) << " kinds of beautiful arrangements.\n";
	}
	system("pause");
	return 0;
}