#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int parent[N];
int size[N];

void make(int v)
{
   parent[v] = v;
   size[v] = 1;
}

int find(int v)
{
   if(v==parent[v]) {
      return v;
   }
   return find(parent[v]);
}

void Union(int a, int b){
   int v = find(a);
   int u = find(b);
   
   if(v != u){
      if(size[v] < size[u])
         swap(v, u);
      parent[u] = v;
      size[v] += size[u];
   }
}

int main(){
   cout << "hello" << endl;
   int n, m;
   cin >> n >> m;

   vector <pair<int, pair<int, int>> >edge;

   for(int i=0; i<m; i++){
      int u, v, wt;
      cin >> u >> v >> wt;
      edge.push_back({wt, {u, v}});
   }
   sort(edge.begin(), edge.end());

   for(int i=1; i<=n; i++){
      make(i);
   }

   int totalWeight = 0;
   for(auto &edge : edge){
      int wt = edge.first;
      int u = edge.second.first;
      int v = edge.second.second;

      if(find(u)==find(v)) continue;
      Union(u, v);
      totalWeight += wt;
      cout << u << " " << v << endl;
   }
   cout << totalWeight << endl;

   return 0;
}