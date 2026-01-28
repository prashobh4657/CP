#include <bits/stdc++.h>
using namespace std;
#define int long long int
// #define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
template <typename T>
istream &operator>>(istream &input, vector<T> &v)
{
    for (auto &i : v)
        cin >> i;
    return input;
}
template <typename T>
ostream &operator<<(ostream &output, vector<T> &v)
{
    for (auto &i : v)
        cout << i << " ";
    return output;
}

// Here a.size() must be >=1 otherwise will give run-time error as n would be zero and run-time error will be on line : vector<int> prefix(0);
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
vector<int> prefixMin(vector<int> &a)
{
    int n = a.size();
    vector<int> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
        prefix[i] = min(prefix[i - 1], a[i]);
    return prefix;
}
vector<int> prefixMax(vector<int> &a)
{
    int n = a.size();
    vector<int> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
        prefix[i] = max(prefix[i - 1], a[i]);
    return prefix;
}
vector<int> suffixMax(vector<int> &a)
{
    int n = a.size();
    vector<int> suffix(n);
    suffix[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suffix[i] = max(suffix[i + 1], a[i]);
    return suffix;
}
vector<int> suffixMin(vector<int> &a)
{
    int n = a.size();
    vector<int> suffix(n);
    suffix[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suffix[i] = min(suffix[i + 1], a[i]);
    return suffix;
}
vector<int> prefixXor(vector<int> &a)
{
    int n = a.size();
    vector<int> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] ^ a[i];
    return prefix;
}
int rangeXor(vector<int> &prefixXor, int l, int r) {
    if (l == 0) return prefixXor[r];
    return prefixXor[r] ^ prefixXor[l - 1];
}


 int lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b; 
}

vector<int> prefixLCM(vector<int> &a)
{
    int n = a.size();
    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] = lcm(pref[i - 1], a[i]);
    return pref;
}

vector<int> suffixLCM(vector<int> &a)
{
    int n = a.size();
    vector<int> suff(n);
    suff[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suff[i] = lcm(suff[i + 1], a[i]);
    return suff;
}

vector<int> prefixGCD(vector<int> &a)
{
    int n = a.size();
    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] = __gcd(pref[i - 1], a[i]);
    return pref;
}

vector<int> suffixGCD(vector<int> &a)
{
    int n = a.size();
    vector<int> suff(n);
    suff[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suff[i] = __gcd(suff[i + 1], a[i]);
    return suff;
}

// Build 2D Prefix Sum Matrix
vector<vector<int>> buildPrefix2D(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> pre(n, vector<int>(m, 0)); // pre[i][j] = sum from (0,0) to (i,j)

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            pre[i][j] = v[i][j];
            if (i > 0)
                pre[i][j] += pre[i - 1][j];
            if (j > 0)
                pre[i][j] += pre[i][j - 1];
            if (i > 0 && j > 0)
                pre[i][j] -= pre[i - 1][j - 1];
        }
    }
    return pre;
}

// Query Submatrix Sum Using Prefix Matrix
int getSum2D(int r1, int c1, int r2, int c2, vector<vector<int>> &pre)
{
    int total = pre[r2][c2];
    if (r1 > 0)
        total -= pre[r1 - 1][c2];
    if (c1 > 0)
        total -= pre[r2][c1 - 1];
    if (r1 > 0 && c1 > 0)
        total += pre[r1 - 1][c1 - 1];
    return total;
}

vector<string> getWordsFromSentence(string &sentence)
{
    int n = sentence.size();
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        if (sentence[i] != ' ')
        {
            string temp;
            while (sentence[i] != ' ' && i < n)
                temp.push_back(sentence[i++]);
            v.push_back(temp);
        }
    }
    return v;
}

// primeScore(num) returns the count of distinct prime factors of num.
// The time complexity of the primeScore function is O(root(n)).
int primeScore(int num)
{
    int count = 0;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            count++; // Found a new prime factor
            while (num % i == 0)
                num /= i; // Remove all occurrences of this factor
        }
    }
    if (num > 1)
        count++; // If there's a prime factor > sqrt(num)
    return count;
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
    int base = 1;
    for (int i = 0; i < s.size(); i++)
    {
        ans += base * (s[i] - '0');
        base *= 2;
    }
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
bool isPalindrome(string &s, int i, int j)
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
// Optimisations used:
// 1. Loop only till sqrt(n) → i * i <= n - 1
// 2. Start marking multiples from i * i : Multiples below i * i are already marked by smaller primes
// isPrime(n + 1, true) ==> Intially are prime.
vector<bool> buildSieve(int n) {
    vector<bool> isPrime(n + 1, true);
    if (n >= 0) isPrime[0] = false;
    if (n >= 1) isPrime[1] = false;
    
    for (long long i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (long long j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}
vector<int> primeFactors(int n) // isPrime() also required;
{
    vector<int> v;
    for (int i = 2; i * i <= n; i++) // sqrt is imp;
    {
        if (n % i == 0 && isPrime(i))
            v.push_back(i);
    }
    return v;
}
bool binarysearch(vector<int> &a, int target)
{
    int low = 0;
    int high = a.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
            return true;
        else if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

// To build n*64 where v[i] denotes 64-bit representation of a[i]
vector<vector<int>> buildBinaryMatrix(vector<int> &a)
{
    int n = a.size();
    vector<vector<int>> v(n, vector<int>(64, 0));
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        int p = 63;
        while (temp)
        {
            v[i][p--] = temp % 2;
            temp /= 2;
        }
    }
    return v;
}

vector<int> binaryV(int n) // Returns binary representation vector of integer n;
{
    vector<int> v(64);
    int p = 63;
    while (n)
    {
        v[p--] = n % 2;
        n = n / 2;
    }
    return v;
}
bool isvowel(char z)
{
    z = tolower(z);
    if (z == 'a' || z == 'e' || z == 'i' || z == 'o' || z == 'u')
        return true;
    return false;
}
int power(int x, int y, int mod) // Modular exponentiation ==> pow(x,y)%mod;
{
    int res = 1;
    x %= mod;
    while (y > 0)
    {
        if (y % 2 == 1)
            res = MM(res, x, mod);
        y = y >> 1;
        x = MM(x, x, mod);
    }
    return res;
}

int AM(int x, int y, int mod) { return ((x % mod) + (y % mod)) % mod; }
int SM(int x, int y, int mod) { return ((x % mod) - (y % mod) + mod) % mod; }
int MM(int x, int y, int mod) { return (1LL * (x % mod) * (y % mod)) % mod; }
int modInverse(int A, int M)
{
    int r1 = M;
    int r2 = A;
    int t1 = 0, t2 = 1;
    while (r2 > 0)
    {
        int q = r1 / r2;
        int r = r1 - q * r2;
        r1 = r2;
        r2 = r;
        int t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }
    if (r1 == 1)
        return (t1 + mod) % mod;
    return -1;
}
int DM(int x, int y, int mod)
{
    int inv = modInverse(y, mod);
    if (inv == -1)
        return -1; // Inverse doesn't exist
    return MM(x, inv, mod);
}

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int S) // S=source; //adj=Directed acyclic graph
{
    int n = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n, 1e9);
    dis[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (int j = 0; j < adj[node].size(); j++) // S----->node----> adj[node][j] (Relax its neighbours);
        {
            int adjNode = adj[node][j].first;
            int edgewt = adj[node][j].second;
            if (distance + edgewt < dis[adjNode])
            {
                dis[adjNode] = distance + edgewt;
                pq.push({dis[adjNode], adjNode});
            }
        }
    }
    return dis;
}

// Sum of digit ==> https://practice.geeksforgeeks.org/problems/sum-of-digits1742/1
int sumOfDigits(int n) {
    int sum = 0;
    while (n) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}
int productOfDigits(int n) {
    int product = 1;
    while (n) {
        product *= (n % 10);
        n /= 10;
    }
    return product;
}
vector<int> getDigitsFromNumber(int n) {
    vector<int> digits;
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}
int buildNumberFromDigits(vector<int>& digits) {
    int num = 0;
    for (int i = 0; i < digits.size(); i++) {
        num = num * 10 + digits[i];
    }
    return num;
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

// Transpose of matrix : LQN : 867. Transpose Matrix
// isSubsequence : LQN : 392. Is Subsequence 
// LCS, LIS (lower_bound submission);
// TC of map vs unordered map : https://www.geeksforgeeks.org/map-vs-unordered_map-c/









