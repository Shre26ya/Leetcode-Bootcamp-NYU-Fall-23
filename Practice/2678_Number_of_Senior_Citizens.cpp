class Solution {
public:
    int countSeniors(vector<string>& details) {
int count = 0;
        for (const auto& detail : details) {
            int age = (detail[11] - '0') * 10 + (detail[12] - '0'); // Extract and convert age
            if (age > 60) {
                count++;
            }
        }
        return count;

        
    }
};
