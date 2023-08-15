#include<iostream>

using namespace std;

// Breakdown:
// What is the maximal sum subsequence of length m
// sol: we use prefix sum

// what are top k maximal sum subsequence of length m
// sol: we compute with a sliding window and sort

// What is the maximum sum possible by choosing k subsequences of length m?
// sol: it's maximum of either choosing k subsequences in an array of length n - 1
// or choosing k - 1 subsequnces in a array of length n - m + sum of sequence starting at n - m - 1 to n - 1

#define lli long long int

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	lli psum[n + 1] = {0};
	lli sum = 0;

	for (int i = 1; i <= n; i++) {
		int b;
		cin >> b;
		sum += b;
		psum[i] = sum;
	}

	lli dp[k + 1][n + 1];

	for (int i = 0; i <= k; i++)
	for (int j = 0; j <= n; j++) dp[i][j] = 0;

	for (int i = 1; i <= k; i++) {
		for (int j = i * m; j <= n; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + psum[j] - psum[j - m]); 
		}
	}

	cout << dp[k][n];
}
