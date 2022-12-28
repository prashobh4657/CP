#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

/*
        vector<int> prefix(n);
        prefix[0]=a[0];
        for(int i=1;i<n;i++)
        prefix[i]=prefix[i-1]+a[i];
        
        vector<int> suffix(n);
        suffix[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
        suffix[i]=suffix[i+1]+a[i];
        
        for(int i=0;i<n;i++)
        cout<<prefix[i]<<" ";cout<<endl;
        for(int i=0;i<n;i++)
        cout<<suffix[i]<<" ";cout<<endl;
*/
bool isvowel(char z)
{
    z=tolower(z);  
    if(z=='a'||z=='e'||z=='i'||z=='o'||z=='u')
    return true;
    return false;
}

int power(int x, int y, int p) //Modular exponentiation ==> pow(x,y)%p;
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
