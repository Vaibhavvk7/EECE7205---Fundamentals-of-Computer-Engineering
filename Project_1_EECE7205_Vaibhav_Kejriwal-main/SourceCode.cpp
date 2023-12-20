#include<bits/stdc++.h>

using namespace std;

#define Intmin -1000000007

#define Intmax 1000000007

int sum[5000];

int dp[5000][5000];

int cases(int *arr,int n,int m)

{

  ////base case

  if(n<m)

  return 0;

  ///look up

  if(dp[n][m]!=0)

  return dp[n][m];

  //rec case

  int ans=Intmax;

  int ans2=0;

  for(int i=n-1;i>=m-1;i--) ////i will try to break my group into smaller part 

  {

    ans=min(cases(arr,i,m-1),sum[n]-sum[i]); //////since i am maximising the minimum

    if(ans2<ans)

    {

      ans2=ans;  

    }

  }

  return ans2;

}

int * max_min_grouping(int *arr,int n,int m)

{

  int ans=cases(arr,n,m); ///cases funtion will return how much max sum we can get

  cout<<"after maximising the min sum of group you will get "<<ans<<endl;

  int cm=0;

  int index=0;

  int j=1;

   int *b=new int[n+1]; 

  for(int i=1;i<=n;i++)

  {

    if(j==m)
    {
      b[j]=n-i+1;
      break;
    }
    cm+=arr[i]; 

    index++;

    if(cm>=ans) ////when cm>=ans means now we can move to next group 

    {

      b[j]=index;

      cm=0;

      index=0;

      j++;

    }

  }

  return b;

}

int main()

{

  int n,m; //// n is the size of input and m is the group

  cout<<"Enter size of array and number of groups with a space between them "<<endl;

  cin>>n>>m;

  int *arr=new int[n+1];

  cout<<"Enter array elements :"<<endl;

  for(int i=1;i<=n;i++)

  cin>>arr[i];//////////enter values (input) in arr

  for(int i=0;i<n;i++)

  sum[i]=0; ///////we also build a sum array globally which will store sum from 1 to index

  int count=0;

  for(int i=1;i<=n;i++)

  {  

    sum[i]+=sum[i-1]+arr[i];

  }

  /////now we will dp where dp[i][j] means maximising the min of first i numbers

  ///// into j group

  for(int i=1;i<=n;i++)

  {

      dp[i][1]=sum[i]; 

  }

  int *b=max_min_grouping(arr,n,m); 

  cout<<"Groups and their size from starting is ";

  for(int i=1;i<=m;i++)

  cout<<b[i]<<" ";

  cout<<endl;
   cout << "Grouping of array: ";
  int start = 1;
  for (int i = 0; i <= m; i++) {
    int end = b[i] + start - 1;
    for (int j = start; j <= end; j++) {
      cout << arr[j] << " ";
    }
    cout<<"|";
    start = end + 1;
  }
   if (start < n) {
   
  for (int i = start; i < n; i++) {
   cout << arr[i] << " ";}
  }
  cout << endl;
    return 0;
}
