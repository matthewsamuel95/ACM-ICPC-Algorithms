//Author: Talita Halboth
//This is a solution to problem 963D from codeforces

#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define para(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define paraIni(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rpara(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define unicos(X) (X).erase(unique(all(X)),(X).end())
#define NL <<"\n"
#define EPS 1e-6
#define MOD 1000000007
#define iinf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f



using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int K = 26;
int sz=0;
struct Vertex {
    int next[K];
    int leaf = -1;
    // ancesrtor
    int p = -1;
    // character of the ancestor
    char pch;
    // suffix link
    int link = -1;
    int exit = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

// map <string, int> m;
// map <int, string> m2;
void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (c < 0)
            c = ch - 'A';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = sz++;

}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
        
    }
       
    return t[v].link;
}
int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

int getExit(int v)
{
    if(t[v].exit==-1){
        int u=get_link(v);
        if(u!=0 && t[u].leaf!=-1) t[v].exit=u; 
        else t[v].exit = v==0 ? 0 : getExit(u);
    }
    return t[v].exit;
}
// map <string, int> visitados;
vector <pair<string, int>> entrada;
map <string, pair<int,int>> contaEntrada;
vector<int> posicoesOcorrencias[112345];
int percorreArvore(string s)
{
    int v = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        v = go(v, s[i]);
        if (t[v].leaf != -1 )
        {
            posicoesOcorrencias[t[v].leaf].pb(i);
        }

        int v2 =getExit(v);
        while (v2 != 0 && v2 != -1)
        {
            posicoesOcorrencias[t[v2].leaf].pb(i);
            v2 =getExit(v2);
        }

    }

}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int n;
    cin >> n;
    t[0].exit=-1;
    for (int i = 0; i < n; ++i)
    {
        int sz;
        cin >> sz;
        string s;
        cin >> s;
        add_string(s);
        entrada.pb(mp(s,sz));
    }

    percorreArvore(s);
    for (int i = 0; i < entrada.size(); ++i)
    {
        if(posicoesOcorrencias[i].size() < entrada[i].se )
        {
            cout << -1 << endl;
        }
        else
        {
            int tam = 0;
            int k = entrada[i].se-1;
            tam =posicoesOcorrencias[i][k] - posicoesOcorrencias[i][0];
            // printf("%d\n",tam );
            for (int j = 1; j+k < posicoesOcorrencias[i].size(); ++j)
            {
                if (posicoesOcorrencias[i][j+k] - posicoesOcorrencias[i][j]  < tam)
                    tam = posicoesOcorrencias[i][j+k] - posicoesOcorrencias[i][j];
            }
            cout <<tam+ entrada[i].fi.size() << endl;
        }
    }

  
    return 0;
}
