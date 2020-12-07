class Solution {
    static vector<string> split(string const& str) {
        vector<string> ans(3);
        size_t i = str.find(':');
        size_t j = str.find(':', i + 1);
        ans[0] = str.substr(0, i);
        ans[1] = str.substr(i + 1, j - i - 1);
        ans[2] = str.substr(j + 1, string::npos);
        return ans;
    }
   
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        size_t const nlogs = logs.size();
        vector<int> ans(n);
        stack<int> ids;
        auto const args = split(logs[0]);
        ids.push(atoi(args[0].c_str()));
        int last_start = atoi(args[2].c_str());
        for (int ilog = 1; ilog < nlogs; ++ilog) {
            auto const args = split(logs[ilog]);
            // int const id = atoi(args[0].c_str());
            bool const is_start = args[1] == "start";
            int start = atoi(args[2].c_str());
            if (!is_start) ++start;
            if (!ids.empty())
                ans[ids.top()] += start - last_start;
            if (is_start) {
                ids.push(atoi(args[0].c_str()));
            } else {
                ids.pop();
            }
            last_start = start;
        }
        return ans;
    }
};
