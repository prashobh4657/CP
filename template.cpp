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
vector<int> prefixMin(vector<int> &a) 
{
    int n = a.size();
    vector<int> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
        prefix[i] = min(prefix[i - 1] , a[i]);
    return prefix;
}
vector<int> suffixMax(vector<int> &a)
{
    int n = a.size();
    vector<int> suffix(n);
    suffix[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suffix[i] = max(suffix[i + 1] , a[i]);
    return suffix;
}

/*
vector<vector<int>> prefix_2d(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> pre_2d(n, vector<int>(m)); //pre_2d[i][j] denotes sum of all numbers inside rectangle fromed by (0,0) to (i,j);
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
int getSum(int r1,int c1,int r2,int c2,vector<vector<int>> &pre_2d) // Sum of numbers in matrix having top left at (r1,c1) and bottom right at (r2,c2);
{
    int a, b, c, d; a = b = c = d = 0;
    a = pre_2d[r2][c2];
    if (r1 - 1 >= 0)
        b = pre_2d[r1 - 1][c2];
    if (c1 - 1 >= 0)
        c = pre_2d[r2][c1 - 1];
    if (r1 - 1 >= 0 && c1 - 1 >= 0)
        d = pre_2d[r1 - 1][c1 - 1];
    int sum = a - b - c + d;
    return sum;
}
vector<string> getWords(string &sentence){
    int n=sentence.size();
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        if(sentence[i]!=' ')
        {
            string temp;
            while(sentence[i]!=' '&&i<n)
                temp.push_back(sentence[i++]);
            v.push_back(temp);
        }
    }
    return v;
}

*/
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
    int ans = 0; int base=1;
    for (int i = 0; i < s.size(); i++)
    {
        ans += base * (s[i] - '0');
        base*=2;
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
vector<int> primeFactors(int n) //isPrime() also required;
{
    vector<int> v;
    for (int i = 2; i * i <= n; i++) // sqrt is imp;
    {
        if (n % i == 0 && isPrime(i))
            v.push_back(i);
    }
    return v;
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
for (int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
*/
vector<int>binaryV(int n) //Returns binary representation vector of integer n;
{
        vector<int>v(64);
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
int AM(int x, int y) {return ((x % mod) + (y % mod)) % mod;}
int SM(int x, int y) {return ((x % mod) - (y % mod) + mod) % mod;}
int MM(int x, int y) {return ((x % mod) * (y % mod) * 1ll) % mod;}
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
int DM(int x, int y){return ((x % mod) * (modInverse(y, mod) % mod)) % mod;}


vector <int> dijkstra(vector<vector<pair<int, int>>> &adj, int S) //S=source; //adj=Directed acyclic graph
{
    int n = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    vector<int>dis(n, 1e9);
    dis[S] = 0;
    pq.push({ 0,S });
    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (int j = 0;j < adj[node].size();j++)   // S----->node----> adj[node][j] (Relax its neighbours);
        {
            int adjNode = adj[node][j].first;
            int edgewt = adj[node][j].second;
            if (distance + edgewt < dis[adjNode])
            {
                dis[adjNode] = distance + edgewt;
                pq.push({ dis[adjNode],adjNode });
            }
        }
    }
    return dis;
}

/*
vector<vector<int>> transpose(m,vector<int>(n)); //transposing so that any column can be get using vector;
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    transpose[i][j]=grid[j][i];
}
*/

int maxSubarraySum(vector<int> &a) //Kadane's;
{
    int n=a.size();
    int curr_sum=0;
    int max_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        curr_sum+=a[i];
        if(curr_sum<0)
        curr_sum=0;
        max_sum=max(max_sum,curr_sum);
    }
    if(max_sum==0)  // If all elements are negative then answer should that negative having least magnitude
    return *max_element(a.begin(),a.end()); 
    return max_sum;
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
// Sum of digit ==> https://practice.geeksforgeeks.org/problems/sum-of-digits1742/1 
// isSubsequence (For both array and string) ==> https://leetcode.com/problems/is-subsequence/description/ (Just pick the latest submission);
// LCS, LIS (lower_bound submission);

// later add seive to this;
// TC of map vs unordered map : https://www.geeksforgeeks.org/map-vs-unordered_map-c/
