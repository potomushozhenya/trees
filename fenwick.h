#ifndef fenwick
#define fenwick
#include "vector"


struct FenwickTree {
    std::vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(std::vector<int> const &a) : FenwickTree(a.size()){
        for (int i = 0; i < n; i++) {
            bit[i] += a[i];
            int r = i | (i + 1);
            if (r < n) bit[r] += bit[i];
        }
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
    void print(){
        for (int i = 0; i < n; ++i) {
            std::cout<<bit[i]<<" ";
        }
        std::cout<<std::endl;
    }
};


struct FenwickTreeMin {
    std::vector<int> bit;
    int n;
    const int INF = (int)1e9;

    FenwickTreeMin(int n) {
        this->n = n;
        bit.assign(n, INF);
    }

    FenwickTreeMin(std::vector<int> a) : FenwickTreeMin(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getmin(int r) {
        int ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = std::min(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = std::min(bit[idx], val);
    }
};


struct FenwickTree2D {
    std::vector<std::vector<int>> bit;
    int n, m;

    FenwickTree2D(int n, int m) {
        this->n = n;
        this->m = m;
        bit.assign(n, std::vector<int>(m));
        for (int i=0; i < n; ++i){
            bit[i].assign(m,0);
        }
    }

    FenwickTree2D(std::vector<std::vector<int>> const &a) : FenwickTree2D(a.size(),a[0].size()){

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                bit[i][j] += a[i][j];
                int r1 = i | (i + 1);
                int r2 = j | (j + 1);
                if (r1 < n and r2 < m) {
                    bit[r1][r2] += bit[i][j];
                }
            }
        }
    }

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }

    void print(){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout<<bit[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }
};

#endif