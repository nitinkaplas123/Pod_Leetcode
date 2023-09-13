 0 1 2 3 4 5 6
[3,3,3,3,3,1,3]

Idea-:
1)First we make map<int,vector<int>>m.
2)Here we store the length as a key and index as a value.
3)After storing the key value in map we check if the m[val].length==val means the length is full
  so here we complete the 1st set of values.
4)So now we have to store in a 2D vector as a ans and at same time have to erase that key from map.
5) At last we return the ans of 2D vector.


Code-:  Time Complexity ->O(n) Space =>O(n)
vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
       vector<vector<int>>v;
       int n=groupSizes.size();
       unordered_map<int,vector<int>>m;
       for(int i=0;i<n;i++)
       {
           int val=groupSizes[i];
           m[val].push_back(i);
           if(m[val].size()==val)
           {
               v.push_back(m[val]);
               m.erase(val);
           }
       }
       return v;
    }