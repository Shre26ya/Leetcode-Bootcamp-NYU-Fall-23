class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        
        int l = 0, r = 0, maxLen = 0;
        int n = arr.size();
        map<int, int> myMap;
        
        while(r < n){
            
            myMap[arr[r]]++;
            
            if(myMap.size() > 2){
                myMap[arr[l]]--;
                
                if(myMap[arr[l]] == 0) 
                myMap.erase(myMap[arr[l]]);
                l++;
            }
            
            if(myMap.size() <= 2)
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        
        return maxLen;
        
    }
