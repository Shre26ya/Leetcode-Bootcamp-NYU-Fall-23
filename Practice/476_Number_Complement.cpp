class Solution {
public:
    int findComplement(int num) {
        int i = 0;
        int compliment = 0;

        while(num){

            if(!(num&1)){
                compliment |= (1 << i);
            }

            num >>=1;
            i++;
        }
        
        return compliment;
    }
};
