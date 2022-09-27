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
const ll MAXN = 100005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



class Aud{
public:
    string name;
    int h, w, i, e;
    Aud() {}
    Aud(string name_, int h_, int w_, int i_, int e_): name(name_), h(h_), w(w_), i(i_), e(e_) {}

    int max_(){
        vector<pii> a = {
            {h, 0},
            {w, 1},
            {i, 2},
            {e, 3}
        };
        sort(ALL(a));
        return a[3].second;
    }

};


struct AudComp {
    explicit AudComp(string s_) 
    : s(s_) {}

    bool operator ()(Aud const& a, Aud const& b) const {
        for(int i=0;i<4;i++){
            if(s[i] == 'H'){
                if(a.h != b.h) return a.h > b.h;
            } else if(s[i] == 'W'){
                if(a.w != b.w) return a.w > b.w;
            } else if(s[i] == 'E'){
                if(a.e != b.e) return a.e > b.e;
            } else if(s[i] == 'I'){
                if(a.i != b.i) return a.i > b.i;
            }
        }

        return a.name < b.name;
    }

    string s;
};

void solve(){
    int n;
    cin >> n;
    vector<string> s(4);
    for(int i=0;i<4;i++) cin >> s[i];
    vector<Aud> a(n);
    vector<vector<Aud>> g(4);
    for(int i=0;i<n;i++){
        cin >> a[i].name >> a[i].h >> a[i].w >> a[i].i >> a[i].e;
    }
    for(int i=0;i<n;i++){
        g[a[i].max_()].push_back(a[i]);
    }
    for(int i=0;i<4;i++){
        sort(ALL(g[i]), AudComp(s[i]));
    }
    for(int i=0;i<4;i++){
        cout << "Group " << (char)(i + 'A') << ":";
        if((int)g[i].size() == 0) cout << " No Audience" << endl;
        else {
            cout << endl;
            for(auto j: g[i]){
                cout << j.name << endl;
            }
        }
    }
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
