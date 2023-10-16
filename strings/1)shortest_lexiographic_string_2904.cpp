Note-:
Here we learn how we can compare string to find the smallest string.
for eg.
s1="1101" =>13
s2="1110"=>14

here we need string where no. of k is 3 and smallest string and if two string are of equal length then 
lexiographic smallest we need.
o/p -> "1101"


Test case for equal len but we need smallest string
S="1101011"
k=3
Here -> smallest len is 4 
There is two substring of len 4 -:
1)"1101" ->13
2)"1011" ->14

So our answer is ->"1101"

Solution 1-:
Steps-:
1)In first traversal we find the smallest possible length of substring where 1s are k.
2)Now in second traversal we find the smallest substring if there is 2 or more of length same as we see in 
  up test case.


Code-:
tring shortestBeautifulSubstring(string s, int k) {
        //here we find the smallest possible length
        int n=s.length();
        int len=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=i;j<n;j++)
            {
               if(s[j]=='1')
               count++;

               if(count==k)
               {
                  len=min(len,j-i+1);
                  break;
               }
              
            }
        }
        cout<<len<<" ";
       
        //2 now we find the substring of len length with smallest string
        string ans="";
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=i;j<n;j++)
            {
                if(s[j]=='1')
                count++;

                if(count==k)
                {
                    if(len==j-i+1)
                    {
                        if(ans=="")
                        ans=s.substr(i,len);
                        else
                        ans=min(ans,s.substr(i,len));
                    }
                    break;
                }
            }
        }
        return ans;
    }