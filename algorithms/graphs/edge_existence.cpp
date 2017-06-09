#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  vector< vector<bool> >graph(N,vector<bool>(N,false));

  int a,b;
  for(int i=0; i<M; i++){
    cin>>a>>b;
    graph[a-1][b-1] = true;
    graph[b-1][a-1] = true;
  }

  int Q; cin>>Q;
  for(int i=0; i<Q; i++){
    cin>>a>>b;
    if(graph[a-1][b-1]){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
}
