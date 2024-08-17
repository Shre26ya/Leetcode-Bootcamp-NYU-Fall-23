class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int maxlen = 0;  // Initialize maxlen to 0
        int len;

        map<char, int> myMap;  // Use char as the key type

        while (r < n) {
            if (myMap[s[r]] != 0) {
                if (myMap[s[r]] >= l + 1) {
                    l = myMap[s[r]];
                }
            }

            len = r - l + 1;
            maxlen = max(len, maxlen);
            myMap[s[r]] = r + 1;  // Store r + 1 to avoid conflict with the default value 0
            r++;
        }

        return maxlen;
    }
};

