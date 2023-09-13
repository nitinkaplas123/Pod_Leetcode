s = "aaabbbcc"

Steps-:
1)Here first we make a count array of 26 because charcter is of 26 and in array store the frequency in it.
2)Now make a hashset for storing the unique freq there and make a ans variable which increases when we delete.
3)Now run the whole count array and checking if that particular freq is present in hashset or not.
  Case1 -: Freq is present
  here we ans++ and decrease the freq-- 
  when this loop end then insert the freq into hashset for further iteartion.

  Case2-: Freq is not present
  Means no need for deletion 
  simply insert the freq in hashset


Code-:  Time Complexity ->O(n)  Space->O(n)
 int minDeletions(string s) {
        int count[26]={0};
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'a']++;
        }
        
        unordered_set<int>s1;
        int ans=0;
        for(int i=0;i<26;i++)
        {
            int freq=count[i];
            while(freq>0 and s1.find(freq)!=s1.end())
            {
                ans++;
                freq--;
            }
            s1.insert(freq);
        }
        return ans;
    }
