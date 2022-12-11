// :80 <enter>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<double,double> pdd;
#define SQ(i) ((i)*(i))
#define MEM(a, b) memset(a, (b), sizeof(a))
#define SZ(i) int(i.size())
#define FOR(i, j, k, in) for (int i=j ; i<(k) ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=(k) ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REP1(i,j) FOR(i, 1, j+1, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define ALL(_a) _a.begin(),_a.end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define X first
#define Y second
#ifdef jayinnn
#define TIME(i) Timer i(#i)
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,deque<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
class Timer {
private:
    string scope_name;
    chrono::high_resolution_clock::time_point start_time;
public:
    Timer (string name) : scope_name(name) {
        start_time = chrono::high_resolution_clock::now();
    }
    ~Timer () {
        auto stop_time = chrono::high_resolution_clock::now();
        auto length = chrono::duration_cast<chrono::microseconds>(stop_time - start_time).count();
        double mlength = double(length) * 0.001;
        debug(scope_name, mlength);
    }
};
#else
#define TIME(i)
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
#endif

const ll MOD = 1000000007;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int iNF = 0x3f3f3f3f;
const ll MAXN = 505;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


vector<int> p(MAXN);

void init(){
    for(int i=0;i<MAXN;i++){
        p[i] = i;
    }
}

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y){
    p[find(x)] = find(y);
}

class edge{
public:
    edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
    friend ostream &operator<<(ostream &os, const edge& e) {
        return os << "(" << e.u << ", " << e.v << ", " << e.w << ")";
    }
    int u, v, w;

};

bool cmp(const edge& a, const edge& b){
    return a.w < b.w;
}

void solve(int v, int e, int w){
    init();
    vector<edge> total;
    for(int i=0;i<e;i++){
        int uu, vv, ww;
        cin >> uu >> vv >> ww;
        total.push_back(edge(uu, vv, ww));
    }
    vector<bool> strong(v, false);
    int tmp;
    for(int i=0;i<w;i++){
        cin >> tmp;
        strong[tmp] = true;
    }
    vector<edge> par;
    vector<edge> rem;
    for(auto i: total){
        if(!strong[i.u] && !strong[i.v]){
            par.push_back(i);
        }
    }
    sort(ALL(par), cmp);
    sort(ALL(total), cmp);
    // debug(par, total);
    ll ans = 0;
    for(auto i: par){
        if(find(i.u) != find(i.v)){
            merge(i.u, i.v);
            ans += i.w;
        }
    }
    int idx = -1;
    for(int i=0;i<v;i++){
        if(strong[i] == false){
            if(idx == -1){
                idx = find(i);
            } else if(idx != find(i)){
                cout << -1 << endl;
                return;
            }
        }
    }
    for(auto i: total){
        if(find(i.u) != find(i.v)){
            merge(i.u, i.v);
            ans += i.w;
        }
    }
    idx = find(0);
    for(int i=0;i<v;i++){
        if(idx != find(i)){
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int v, e, w;
    while(cin >> v >> e >> w){
        solve(v, e, w);
    }

    return 0;
}
