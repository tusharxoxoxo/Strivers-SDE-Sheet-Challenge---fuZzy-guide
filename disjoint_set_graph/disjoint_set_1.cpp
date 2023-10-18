#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet
{
  vector < int >rank, parent, size;

public:
    DisjointSet (int n)
  {
    rank.resize (n + 1, 0);
    parent.resize (n + 1, 0);
    size.resize (n + 1, 0);

    for (int i = 0; i < n; ++i)
      {
	parent[i] = i;
	size[i] = 1;
      }
  }

  int findUParent (int node)
  {
    if (node == parent[node])
      return node;
    return parent[node] = findUParent (parent[node]);
  }

  void unionByRank (int u, int v)
  {
    int ultimateParentU = findUParent (u);
    int ultimateParentV = findUParent (v);

    if (ultimateParentU == ultimateParentV)
      {
	return;
      }

    if (rank[ultimateParentU] > rank[ultimateParentV])
      {
	parent[ultimateParentV] = ultimateParentU;
      }
    else if (rank[ultimateParentU] < rank[ultimateParentV])
      {
	parent[ultimateParentU] = ultimateParentV;
      }
    else
      {
	parent[ultimateParentV] = ultimateParentU;
	rank[ultimateParentU]++;
      }
  }

};

int
main ()
{

  cout << "i am back to this" << endl;

  DisjointSet ds (7);
  ds.unionByRank (1, 2);
  ds.unionByRank (2, 3);
  ds.unionByRank (4, 5);
  ds.unionByRank (6, 7);
  ds.unionByRank (5, 6);

  //checking wheather 3, 7 belong to the same set or not
  if (ds.findUParent (3) == ds.findUParent (7))
    {
      cout << "Same\n";
      //   cout << "fuck man";
    }
  else
    cout << "Not Same\n";
  ds.unionByRank (3, 7);
  if (ds.findUParent (3) == ds.findUParent (7))
    {
      cout << "Same\n";
      //   cout << "fuck man";
    }
  else
    cout << "Not Same\n";
  // cout << "why is this not gettign printed" << endl;
  return 0;
}

