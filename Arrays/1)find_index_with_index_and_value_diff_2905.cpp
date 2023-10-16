Solution 1-:
1)Here we use 2 for loop and check all cases

Code-: Time->O(N^2) Space->O(1)
vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) 
{
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(abs(i-j)>=indexDifference   and abs(nums[i]-nums[j])>=valueDifference)
                return {i,j};
            }     
        }
        return {-1,-1};
}


Solution 2-:
Idea-:
condition for index-:

abs(i-j)>=indexDifference
means-:
(j-i)>=indexDifference
j-indexDifference>=i

means index i is in range -:
(0<=i<=j-indexDifference)

means to be index difference >= bw i and j we have to (j-indexDifference)>=0

suppose indexDifference=2
here j should be start from 2 to make i<=0 

1)for (int i=indexDifference;i<n;i++)


2)Now here we maintain min and max indexs and values 


for eg.
1) 
nums[]={5,1,4,1}
indexDifference=2
valueDifference=4

Dry run -:
1)Intially mini=0, maxi=0;
we first update min and max here min and max at 0 and i at 2 which tells us that we maintain a gap >=2

2)i=2;i<n;i++
i=2

  1.if(nums[mini]>nums[i-d]) means nums[0]>nums[0] we have to update (mini=i-d) 
  nums[0]>nums[0]
  but here mini=0;

  2.if(nums[maxi]<nums[i-d]) 
  nums[0]>nums[0]
  here maxi=0;

  now we reach maxi and mini with indexDifference>=2 
  now if 
  3.nums[maxi]-nums[i]>=valueDifference   then return {maxi,i};
  5-4!>=4

  4. nums[i]-nums[mini]>=4   then return {mini,i}
     4-5>!>=4

i=3

  1. first we maintain maxi and mini till i=1 
    if(nums[mini]>nums[i-d]) means nums[0]>nums[1] we have to update (mini=i-d) 
  nums[0]>nums[1]
  5>1
  mini=1
  

  2.if(nums[maxi]<nums[i-d]) 
  nums[1]>nums[0]
  1>5
  here maxi=0;

  now we reach maxi and mini with indexDifference>=2 
  now if 
  3.nums[maxi]-nums[i]>=valueDifference   then return {maxi,i};
     5-1>=4  so here we return {0,3}

 

Code-: Time->O(N) Space->O(1)
vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
       int n=nums.size();
       int maxi=0;
       int mini=0;
       int d=indexDifference;
       for(int i=d;i<n;i++)
       {
           if(nums[i-d]>nums[maxi])
           maxi=i-d;

           if(nums[i-d]<nums[mini])
           mini=i-d;

           if(nums[maxi]-nums[i]>=valueDifference)
           return {maxi,i};

           if(nums[i]-nums[mini]>=valueDifference)
           return {mini,i};
       }
       return {-1,-1};
    }


  