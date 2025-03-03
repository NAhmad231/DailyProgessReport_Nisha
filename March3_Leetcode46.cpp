// APPROACH - 1 [ USING EXTRA DATA STRUCTURE / SPACE ]

/* COMPLEXITY : 
    T.C = O(N! X N ) == O(N!)
    S.C = O(N+N = O(N)
*/

class Solution {
public:
    void recurPermutations(vector<vector<int>>&ans, vector<int>&ds, vector<bool>&visited, vector<int>& nums  ){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0 ; i<nums.size() ; i++){
            if(!visited[i]){ // if not visited
                ds.push_back(nums[i]);
                visited[i] = true;
                recurPermutations(ans , ds , visited , nums);
                // backtrack
                visited[i] = false; // mark as unvisited
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<bool>visited(nums.size() , false);

        recurPermutations(ans , ds , visited , nums);

        return ans;
    }
};


// APPROACH - 2 [ WITHOUT EXTRA SPACE ]
/* COMPLEXITY : 
    T.C = O(N! X N ) == O(N!)
    S.C =  O(1)
*/
class Solution {
public:
    void recurPermutations(vector<vector<int>>&ans ,int idx, vector<int>& nums  ){
        if(idx == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=idx ; i<nums.size() ; i++){
           swap(nums[idx] , nums[i]);
           recurPermutations(ans , idx+1 , nums);
           swap(nums[idx] , nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        recurPermutations(ans  ,0 , nums);

        return ans;
    }
}
