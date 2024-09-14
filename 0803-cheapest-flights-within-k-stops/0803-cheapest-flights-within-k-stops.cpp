class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dis(n, 1e9);
        set<pair<int,pair<int,int>>> st;

        st.insert({-1, {src, 0}});
        dis[src] = 0;

        while(!st.empty()){
            auto it = *(st.begin());
            int stops = it.first;
            int u = it.second.first;
            int disU = it.second.second;
            st.erase(it);

            if(stops >= k){
                continue;
            }

            for(pair<int, int> p : adj[u]){
                int v = p.first, edgW = p.second;
                if(dis[v] > (disU + edgW)){
                    dis[v] = disU + edgW;
                    st.insert({stops + 1, {v, dis[v]}});
                }
            }
        }

        if(dis[dst] == 1e9){
            return -1;
        }

        return dis[dst];
    }
};