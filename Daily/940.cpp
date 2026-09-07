  class Solution {
public:
    int distinctSubseqII(std::string s) {
        const int MOD = 1e9 + 7;
        
        std::vector<long> dp(26, 0);
        
        for (char c : s) {
            int charIndex = c - 'a';
            
          
            long total = 1;
            for (int count : dp) {
                total = (total + count) % MOD;
            }
            
           
            dp[charIndex] = total;
        }
        
        
        long result = 0;
        for (int count : dp) {
            result = (result + count) % MOD;
        }
        
        return result;
    }
};
