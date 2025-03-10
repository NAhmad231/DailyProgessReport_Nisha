// APPROACH - 1 [TLE]
// T.C = O(N^2)  S.C = O(1)

class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' ||  ch == 'i' || ch == 'o' || ch == 'u') return true;
        else return false;
    }
    long long countOfSubstrings(string word, int k) {
        long long count = 0;
        int n = word.size();
        for(int i=0 ; i<n ; i++){
            unordered_set<int>mp;
            int consonantCount = 0;
            for(int j=i ; j<n ; j++){
                if(isVowel(word[j])){
                    mp.insert(word[j]);
                }
                else consonantCount++;

                if(mp.size() == 5 && consonantCount == k) count++;
            }
        }
        return count;
    }
};
