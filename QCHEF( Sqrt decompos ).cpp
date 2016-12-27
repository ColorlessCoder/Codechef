#include<bits/stdc++.h>
#define unt unsigned long long int
#define pdd pair<double ,double>
#define pdl pair<double ,LL>
#define pii pair<int ,int>
#define fr first
#define sc second
#define LL long long int
#define inf 1e15
#define vi vector<int>
using namespace std;
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
int Ans[320][100010];
int A[100010];
int S;
int n,m,q;
int k;
int vis[100010];
int vis2[100010];
int temp[100010];
void precomp()
{
    int b=0;
    k=1;
    for(int i=0;b<n;i++)
    {
        for(int j=b;j<n;j++)
        {
            if(vis[A[j]]!=k) {vis[A[j]]=k;temp[A[j]]=j;}
            if(j==b) Ans[i][j]=0;
            else Ans[i][j]=max(Ans[i][j-1],j-temp[A[j]]);
        }
        k++;
        for(int j=b;j>=0;j--)
        {
            if(vis[A[j]]!=k) {vis[A[j]]=k;temp[A[j]]=j;}
            if(j==b) Ans[i][j]=0;
            else Ans[i][j]=max(Ans[i][j+1],temp[A[j]]-j);
        }
        k++;
        b+=S;
    }
    return;
}
int main()
{
    S=320;
    cin>>n>>m>>q;
    k=0;
    for(int i=0;i<n;i++) scanf("%d",&A[i]);
    //memset(Last,-1,sizeof(-1));
    precomp();
    memset(vis,0,sizeof(vis));
    int a,b;
    k=1;
    while(q--)
    {
        scanf("%d %d",&a,&b);a--,b--;
        int x=a/S;
        int y=b/S;
        int ans=0;
        if(x==y)
        {
            for(int j=a;j<=b;j++)
            {
            if(vis[A[j]]!=k) {vis[A[j]]=k;temp[A[j]]=j;}
            ans=max(ans,j-temp[A[j]]);
            }
            printf("%d\n",ans);
            k++;
            continue;
        }
        for(int i=x+1;i<=y;i++) ans=max(ans,Ans[i][b]);
        for(int i=x+1;i<=y;i++) ans=max(ans,Ans[i][a]);
        int q=y*S;
        int p=(x+1)*S;
        for(int i=b;i>=q;i--)
            if(vis[A[i]]!=k)
            {
                vis[A[i]]=k;
                temp[A[i]]=i;
            }
        for(int i=a;i<p;i++)
            if(vis2[A[i]]!=k)
        {
            vis2[A[i]]=k;
            if(vis[A[i]]==k) ans=max(ans,temp[A[i]]-i);
        }
        k++;
        printf("%d\n",ans);
    }
    return 0;
}
