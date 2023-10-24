#ifndef segment
#define segment
#include "vector"

struct SegmentTree{
    std::vector<int> t;
    int n;

    SegmentTree(int n) {
        this->n = n;
        t.assign(4*n, 0);
    }

    SegmentTree(std::vector<int> &a) : SegmentTree(a.size()){
        build(a,1,0,n-1);
    }

    void build (std::vector<int> &a, int v, int tl, int tr) {
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    int sum(int l, int r){
        return sumSubFunction(1,0,n-1,l,r);
    }

    int sumSubFunction (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return sumSubFunction (v*2, tl, tm, l, std::min(r,tm))
               + sumSubFunction (v*2+1, tm+1, tr, std::max(l,tm+1), r);
    }

    void updateSubFunction (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] = new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                updateSubFunction (v*2, tl, tm, pos, new_val);
            else
                updateSubFunction (v*2+1, tm+1, tr, pos, new_val);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    void update(int pos, int new_val){
        updateSubFunction(1,0,n-1,pos, new_val);
    }

};

#endif