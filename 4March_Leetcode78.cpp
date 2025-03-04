// APPROACH - 1 [BACKTRACKING]

/*
  ALGORITHM - 
  EVERY ELEMENT IN THE ARRAY HAS TWO CHOICE
  -> PICK
  -> NOT PICK

  COMPLEXITY -
  T.C = O(2^N)   (TOTAL NO OF SUBSETS)
  S.C = O(2^N)
  
*/

class Solution {
public:
    void recurSubsets(vector<vector<int>>&result, vector<int>ds, vector<int>& nums, int idx ){
        if(idx >= nums.size()){
            result.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        recurSubsets(result, ds, nums, idx+1);
        ds.pop_back();
        recurSubsets(result, ds, nums, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>ds;

        recurSubsets(result, ds, nums, 0);

        return result;
    }
};

// APPROCH -2 [ITERATIVE]

/* 
   ALGORITHM
   1. Start with an empty list of subsets: subsets = [[]]
   2. Iterate through each element `num` in `nums`:
   a. Determine the current size of `subsets`
   b. For each existing subset:
      i.  Create a new subset by adding `num` to it
      ii. Append the new subset to `subsets`
   3. Return `subsets`

   COMPLEXITY -
   T.C = O(2^N)
   S.C = O(2^N * N)

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>subset = {{}};

        for(int num : nums){
            int n = subset.size();
            for(int i=0 ; i<n ; i++){
                vector<int>newSubset = subset[i];
                newSubset.push_back(num);
                subset.push_back(newSubset);
            }
        }

        return subset;
    }
};
