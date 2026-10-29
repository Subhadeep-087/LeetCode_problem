class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
    string s, vector<string>& queries) {
    vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

    int L = 1;
    while ((1 << L) <= n) L++;

    vector<vector<int>> up(L, vector<int>(n));
    vector<int> tin(n), tout(n), depth(n), mask(n);
    vector<int> bit(n + 1);
    int timer = 0;

    auto add = [&](int i, int x) {
        for (++i; i <= n; i += i & -i) bit[i] ^= x;
    };

    auto get = [&](int i) {
        int x = 0;
        for (++i; i > 0; i -= i & -i) x ^= bit[i];
        return x;
    };

    vector<array<int, 3>> st = {{0, 0, 0}};
    while (!st.empty()) {
        auto [u, p, state] = st.back();
        st.pop_back();

        if (state == 1) {
            tout[u] = timer - 1;
            continue;
        }

        tin[u] = timer++;
        up[0][u] = p;
        for (int j = 1; j < L; j++)
            up[j][u] = up[j - 1][up[j - 1][u]];

        mask[u] = (p == u ? 0 : mask[p]) ^ (1 << (s[u] - 'a'));

        st.push_back({u, p, 1});
        for (int v : g[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            st.push_back({v, u, 0});
        }
    }

    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int d = depth[u] - depth[v];
        for (int j = 0; j < L; j++)
            if (d >> j & 1) u = up[j][u];

        if (u == v) return u;

        for (int j = L - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }
        return up[0][u];
    };

    vector<bool> ans;

    for (auto& q : queries) {
        string op;
        int u;
        char c;
        stringstream ss(q);
        ss >> op >> u >> c;

        if (op == "update") {
            int delta = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
            add(tin[u], delta);
            add(tout[u] + 1, delta);
            s[u] = c;
        } else {
            int v = c - '0';
            stringstream qs(q);
            qs >> op >> u >> v;

            int w = lca(u, v);
            int x = (mask[u] ^ get(tin[u])) ^
                    (mask[v] ^ get(tin[v])) ^
                    (1 << (s[w] - 'a'));

            ans.push_back((x & (x - 1)) == 0);
        }
    }

    return ans;
}
};
