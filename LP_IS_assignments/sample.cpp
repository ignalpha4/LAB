#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin >> t;
    while(t--) {
        
      int a,b,c;


      cin>>a>>b>>c;

      int temp;

      temp=a-c;

      


      int cnt=1;

      if(a==c)
      {
        cout<<1<<endl;
      }
      else
      {
        while(temp>=0)
      {
      		temp=temp-b;
      		cnt++;
      }

      cout<<cnt<<endl;

      }

      
}

     return 0;
}