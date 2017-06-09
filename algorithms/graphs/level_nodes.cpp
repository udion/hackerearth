#include<bits/stdc++.h>
using namespace std;

int main(){
  int N; cin>>N;
  vector< vector<int> >graph(N,vector<int>());

  int a,b;
  for(int i=0; i<N-1; i++){
    cin>>a>>b;
    graph[a-1].push_back(b-1);
    graph[b-1].push_back(a-1);
  }

  int X; cin>>X;

  //performing bfs and counting the level_nodes
  vector<int>lvl_counts(X,0);
  vector<bool> visited(N,false);
  queue<int> qu;
  int lvl = 0;

  //intialisations
  lvl_counts[0] = 1;
  visited[0] = true;
  qu.push(0);

  while(!qu.empty()){
    int next_lvl_count = 0;
    for(int u=0; u<lvl_counts[lvl]; u++){
      int v = qu.front();
      qu.pop();
      for(auto itr=graph[v].begin(); itr != graph[v].end(); itr++){
        if(!visited[*itr]){
          next_lvl_count++;
          qu.push(*itr);
          visited[*itr] = true;
        }
      }
    }
    lvl++;
    lvl_counts[lvl] = next_lvl_count;

    //no need for bfs on whole tree stop when get the answer
    if(lvl == X-1){
      cout<<lvl_counts[lvl]<<endl;
      break;
    }
  }
  return 0;
}
