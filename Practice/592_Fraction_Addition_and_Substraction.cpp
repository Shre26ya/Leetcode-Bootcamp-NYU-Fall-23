class Solution {
public:
    string fractionAddition(string epx) {

        int nume = 0;
        int deno = 1;

        int i = 0;
        int n = epx.length();

        while(i < n){
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (epx[i] == '-');

            if(epx[i] == '+' || epx[i] == '-'){
                i++;
            }

            while(i < n && isdigit(epx[i])){
                int val = epx[i] - '0';
                currNume = (currNume*10) + val;
                i++;
            }

            i++;

            if(isNeg == true){
                currNume *= -1;
            }

            while(i < n && isdigit(epx[i])){
                int val = epx[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;
        }

        int GCD = abs(__gcd(nume, deno));

        nume /= GCD;
        deno /= GCD;

        return to_string(nume) + "/" + to_string(deno);
        
    }
};
