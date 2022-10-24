class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1){
            sort(stones.begin(), stones.end());
            int maxx1 =  stones.back(); stones.pop_back();
            int maxx2 =  stones.back(); stones.pop_back();
            if (maxx1 - maxx2 > 0){
                stones.push_back(maxx1 - maxx2);
            }
        }
        return stones.size() == 1 ? stones[0] : 0;
    }
};
