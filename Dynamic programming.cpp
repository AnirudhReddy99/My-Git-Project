#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonSubstring(string S1, string S2) {
int n = S1.length();
int m = S2.length();
int length = 0;
int end = 0;
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
for (int i = 1; i <= n; i++) {
for (int j = 1; j <= m; j++) {
if (S1[i - 1] == S2[j - 1]) {
dp[i][j] = dp[i - 1][j - 1] + 1;
if (dp[i][j] > length) {
length = dp[i][j];
end = i - 1;
}
}
}
}
return S1.substr(end - length + 1, length);
}

int main() {
string S1, S2;
cout << "Enter your first string: ";
cin >> S1;
cout << "Enter your second string: ";
cin >> S2;
cout << "The Longest Common Substring: " << longestCommonSubstring(S1, S2) << endl;
return 0;
}
