class Solution {
    void root(unordered_map<string, pair<string, double>>& parents, string const& s) {
        // bind s to the root node
        if (parents.count(s) == 0) return;  // safe guard
        auto& ps = parents[s];
        while (parents[ps.first].first != ps.first) {  // parent is not root
            ps.second *= parents[ps.first].second;
            ps.first = parents[ps.first].first;  // upclimb parent
        }
    }
   
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, pair<string, double>> parents;  // <A, <B, A/B>>
        // build union find
        for (size_t i = 0; i < equations.size(); ++i) {
            string const& A = equations[i][0];
            string const& B = equations[i][1];
            double k = values[i];
            if (parents.count(A) == 0 && parents.count(B) == 0) {
                parents.emplace(A, make_pair(B, k));
                parents.emplace(B, make_pair(B, 1.));
            } else if (parents.count(A) == 0) {
                parents.emplace(A, make_pair(B, k));
            } else if (parents.count(B) == 0) {
                parents.emplace(B, make_pair(A, 1. / k));
            } else {
                root(parents, A);
                root(parents, B);
                parents[parents[A].first] = {parents[B].first, k * parents[B].second / parents[A].second};
            }
        }
        // search
        vector<double> ans;
        for (auto const& a : queries) {
            auto const& M = a[0];
            auto const& N = a[1];
            if (parents.count(M) == 0 || parents.count(N) == 0) {
                ans.push_back(-1.);
                continue;
            }
            root(parents, M);
            root(parents, N);
            if (parents[M].first != parents[N].first) {
                ans.push_back(-1.);
            } else {
                ans.push_back(parents[M].second / parents[N].second);
            }
        }
        return ans;
    }
};
