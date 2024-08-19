//Approach-2 (Bottom Up + Maths)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    //Approach-3 : Using Maths
    int minSteps(int n) {
        /*
            Let's take an example to understand this beautiful approach
            n = 27
            
            Let's suppose we have currently # A = 3   (by some copy paste operation) 
            Let steps to reach this 3 was  = steps_to_reach_3_A_initially
            
            Now, you see that my target 27 is divisible by 3.
            So, we can copy these 3 As and paste them (9-1)  times 
			(why (9-1) times ? 27/3 = 9 and 1 time it was already there which we had copied, So, (9-1) = 8
            Here you had to copy them (takes 1 step), and then paste them 8 times (takes 8 steps)
            
            Total steps = steps_to_reach_3_A_initially + 1_copy + 8_times
            
            Now, you can do better actually, 
            Let's say this time you have currently # A = 9   (by some copy paste operation)
            Let steps to reach this 3 was  = steps_to_reach_3_A_initially
            
            So, we can copy these 9 As and paste them (3-1) times
			(why (3-1) times ? 27/9 = 3 and 1 time it was already there which we had copied, So, (3-1) = 2
            Here you had to copy them (takes 1 step), and then paste them 2 times (takes 2 steps)
            
            Total steps = steps_to_reach_9_A_initially + 1_copy + 2_times
            
            Isn't that an amazing improvement
            So, what we'll do is that, we start looking for factors of 'n' which can help me reach target
            as fast as possible.
            So, the best way will be to start from largest factors = n/2 and then decrement it to find the right
            answer. In case you find a factor which divides 'n', that will definitely give me optimal (minimum step)
            to reach 'n' because we started from largest factor and we hence we can stop right there
        */
        
        //since, there is already 1 A on notepad
        if(n == 1)
            return 0;
        
        //copy A, and then paste A
        if(n == 2)
            return 2;
        
        vector<int> t(n+1, 0);
        //t[i] = min steps to obtain i As on screen
        t[0] = 0; 
        t[1] = 0;
        t[2] = 2;
        
        for(int i = 3; i<=n; i++) {
            
            int factor = i/2; //start from largest factor
            while(factor >= 1) {
                if(i%factor == 0) {
                    //wow, largest factor and that will give me optimal solution.
                    //stop right there
                    int steps_to_reach_factor = t[factor];
                    int copy_that_first       = 1;
                    int paste_frequency       = (i/factor) - 1;
                    //Why -1 above ?
                    /*
                        Because factor # of As was already there.
                        Example : Already have    = 3 As
                                  Target          = 9 As
                                  factor          = 3
                                  paste_frequency = 9/3 = 3
                                  Since we already havd 3 As, we will not paste 'paste_frequency' (i.e. 3 As) times
                                  but (paste_frequency-1) times;
                                  
                    */
                    t[i] = t[factor] + copy_that_first + paste_frequency;
                    break;
                }
                factor--;
            }
        }
        
        return t[n];
    }
};
