class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        int res = 0;
        int score = 0;
        sort(tokens.begin(), tokens.end());

        int l = tokens.size() - 1;
       int  r = 0;

        while(r <= l){
            if(power >= tokens[r]){
                power -= tokens[r];
                r += 1;
                score += 1;
                res = max(res, score);
            }

            else if(score > 0){
                power += tokens[l];
                l -= 1;
                score -= 1;
            }

            else
             break;
        }
        
        return res;
    }
};
