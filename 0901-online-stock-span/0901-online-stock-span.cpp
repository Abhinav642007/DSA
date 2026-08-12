class StockSpanner {
public:
    stack<int> s;
    vector<int> ans;
    StockSpanner() {
        
    }
    
    int next(int price) {
        ans.push_back(price);
        int i = ans.size()-1;
        while (s.size() > 0 && ans[s.top()] <= ans[i]) {
                s.pop();
            }
        int span;

        if(s.size()==0) span=i+1;
        else span = i-s.top();

        s.push(i);
        return span;


    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */