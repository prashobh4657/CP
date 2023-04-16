#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

//Here a.size() must be >=1 otherwise will give run-time error as n would be zero and run-time error will be on line : vector<int> prefix(0);
vector<int> prefix(vector<int> &a) 
{
    int n = a.size();
    vector<int> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i];
    return prefix;
}
vector<int> suffix(vector<int> &a)
{
    int n = a.size();
    vector<int> suffix(n);
    suffix[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] + a[i];
    return suffix;
}
vector<vector<int>> prefix_2d(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> pre_2d(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                pre_2d[i][j] = v[i][j];
            else if (i == 0)
                pre_2d[i][j] = v[i][j] + pre_2d[i][j - 1];
            else if (j == 0)
                pre_2d[i][j] = v[i][j] + pre_2d[i - 1][j];
            else
                pre_2d[i][j] = v[i][j] + pre_2d[i - 1][j] + pre_2d[i][j - 1] - pre_2d[i - 1][j - 1];
        }
    }
    return pre_2d;
}
vector<int> factors(int n)
{
    vector<int> f;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            f.push_back(i);
            if (i * i != n)
                f.push_back(n / i);
        }
    }
    sort(f.begin(), f.end());
    return f;
}
int binaryToDecimal(string s)
{
    reverse(s.begin(), s.end());
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
        ans += pow(2, i) * (s[i] - '0');
    return ans;
}
string decimalToBinary(int n)
{
    string s;
    while (n)
    {
        s.push_back((n % 2) + '0');
        n >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}
bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

/* To build n*64 where v[i] denotes 64-bit representation of a[i]
  vector<vector<int>> v(n, vector<int>(64, 0));
        for (int i = 0; i < n; i++)
        {
            int temp = a[i];
            int p = 63;
            while (temp)
            {
                v[i][p--] = temp % 2;
                temp = temp / 2;
            }
        }
        // for (int i = 0; i < v.size(); i++)
        //     cout << v[i] << endl;
*/
bool isvowel(char z)
{
    z = tolower(z);
    if (z == 'a' || z == 'e' || z == 'i' || z == 'o' || z == 'u')
        return true;
    return false;
}
int power(int x, int y, int p) // Modular exponentiation ==> pow(x,y)%p;
{
    int res = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
            res = ((res % p) * (x % p)) % p;
        y = y >> 1;
        x = ((x % p) * (x % p)) % p;
    }
    return res % p;
}
vector<int> primeFactors(int n)
{
    vector<int> ans;
    int i = 2;
    while (n > 1)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            n /= i;
        }
        else
            i++;
    }
    return ans;
}


int32_t main()
{
    fio;
    int t;
    cin >> t;
    while (t > 0)
    {
        t--;
    }
    return 0;
}
// Kadanes' algorithm ==> Pick from GFG Submission;
// Sum of digit ==> https://practice.geeksforgeeks.org/problems/sum-of-digits1742/1 
// isSubsequence (For both array and string) ==> https://leetcode.com/problems/is-subsequence/description/ (Just pick the latest submission);
// LCS, LIS (lower_bound submission);

// later add seive to this;
