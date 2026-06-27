class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN, sold = 0, rest = 0;
        for (int price : prices) {
            int prev_sold = sold;
            sold = hold + price;
            hold = max(hold, rest - price);
            rest = max(rest, prev_sold);
    }
    return std::max(sold, rest);
        
    }
};



    

