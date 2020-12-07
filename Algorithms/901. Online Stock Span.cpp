class StockSpanner {
    stack<pair<int, int>> mds;  // <price, span>, monotonic decreasing
   
public:
    StockSpanner() {}
   
    int next(int price) {
        int span = 1;
        while (!mds.empty() && mds.top().first <= price) {
            span += mds.top().second;
            mds.pop();
        }
        mds.emplace(price, span);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

