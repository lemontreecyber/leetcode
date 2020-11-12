class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        size_t const nsks = req_skills.size();  // <= 15
        size_t const nppl = people.size();  // <= 60
        vector<int> ppl(nppl);
        for (size_t i = 0; i < nppl; ++i) {
            int& ppli = ppl[i];
            for (string& skill : people[i])
                for (size_t k = 0; k < nsks; ++k)
                    if (skill == req_skills[k]) {
                        ppli |= 1 << k;
                        break;
                    }
        }
        size_t const m = 1 << nsks;
        vector<pair<int, long>> dp(m);  // dp[mask sks] = <#ppl, mask ppl>
        for (size_t i = 0; i < nppl; ++i)
            dp[ppl[i]] = make_pair(1, 1l << i);
        for (size_t state = 1; state < m; ++state) {
            if (dp[state].first == 0) continue;
            int first = dp[state].first;
            long second = dp[state].second;
            for (size_t i = 0; i < nppl; ++i) {
                int next = state | ppl[i];
                if (next == state) continue;  // already in team
                if (dp[next].first == 0 || dp[next].first > first + 1) {
                    dp[next] = make_pair(first + 1, second | 1l << i);
                }
            }
        }
        long req_ppl = dp[m - 1].second;
        vector<int> ans;
        for (size_t i = 0; i < nppl; ++i)
            if (req_ppl >> i & 1l)
                ans.push_back(i);
        return ans;
    }
};
