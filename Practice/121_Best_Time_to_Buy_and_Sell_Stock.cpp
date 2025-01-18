class Solution {
public:
    int maxProfit(vector<int>& Arr) {
       // Write your code here.
	int maxProfiti = 0;
	int mini = Arr[0];
	
	for(int i=1;i<Arr.size();i++){
        int curProfit = Arr[i] - mini;
        maxProfiti = max(maxProfiti,curProfit);
        mini = min(mini,Arr[i]);
        }
	return maxProfiti;
}
};
