#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

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
int binaryToDecimal(string s)
{
    int ans = 0;
    int p = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        ans += pow(2, p) * (s[i] - '0');
        p++;
    }
    return ans;
}
string decimalToBinary(int n)
{
    string s;
    while (n)
    {
        s.push_back(n % 2);
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
