#include <bits/stdc++.h>
using namespace std;

struct compare{

    bool operator()(pair<int,int>&p1,pair<int,int>&p2){
        
        return p1.first>p2.first;
        
    }
};
void update(vector<int>&v,vector<int>&ans,int ind,int val){
    int n=v.size();
    int cnt=n/(int)sqrt(n);

    ans[ind/cnt]+=(val-v[ind]);

    v[ind]=val;

}
int query(vector<int>&v,vector<int>&ans,int l,int r){
    int i=0;
    int minn=INT_MAX;
    int n=v.size();
    int cnt=(int)sqrt(n);

    while((l+i)<=r&&(l+i)%cnt!=0){
        minn=min(minn,v[l+i]);
        i++;
    }

    int ub=r/cnt;
    i=(l+i)/cnt;
    while(i<ub){
        minn=min(minn,ans[i]);
        i++;
    }

    i=(r/cnt)*cnt;

    while(i<=r){
        minn=min(minn,v[i]);
        i++;
    }

    return minn;
}
void preprocess(vector<int>&v,vector<int>&ans){
    int n=v.size();
    int cnt=n/(int)sqrt(n);

    for(int i=0;i<n;i++){

        if(i%cnt==0){
            ans[i/cnt]=v[i];
            continue;
        }

        ans[i/cnt]=min(v[i],ans[(i-1)/(int)sqrt(n)]);

    }

}
int main()
{
    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++)
    cin>>v[i];

    vector<int>ans((n+(int)sqrt(n)-1)/(int)sqrt(n));

    preprocess(v,ans);

    char curr;

    int num;
    cin>>num;
    //type 'q' a b for min-query in v[a,b]
    //type 'u' a b to update v[a]=b
    //note: Validity of a and b is not getting checked 
    for(int i=0;i<num;i++){
        cin>>curr;
        

        if(curr=='q'){
            int a,b;
            cin>>a>>b;

            cout<<query(v,ans,a,b)<<endl;
        }
        else if(curr=='u'){
            int a;
            int b;

            cin>>a>>b;

            update(v,ans,a,b);

        }

    }

}
