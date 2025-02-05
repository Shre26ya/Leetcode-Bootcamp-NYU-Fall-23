class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        int n = s1.length();
        if(s1 == s2){
            return true;
        }

        int diff = 0;
        int firstIndx = 0;
        int secondIndx = 0;

        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                diff++;
            

            if(diff > 2){
                return false;
            }

            else if(diff == 1){
                firstIndx = i;
            }

            else{
                secondIndx = i;
            }
        }
        }

        return s1[firstIndx] == s2[secondIndx] && s1[secondIndx] == s2[firstIndx];
        
    }


};
