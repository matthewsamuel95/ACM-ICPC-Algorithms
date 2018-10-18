#include <bits/stdc++.h>

using namespace std;

struct jogador{
    int pontuacao;
    string nome;
};

struct Hash{
    int qtd, TAM;
    jogador **item;
};

Hash *new_hash(int TAM){
    Hash * ha = new Hash;
    if(ha!=NULL){
        ha->TAM = TAM;
        // lembrar de tentar usar new hash[];
        ha->item = (jogador**) malloc(TAM*sizeof(jogador*));
        if(ha->item==NULL){
            free(ha);
            return NULL;
        }
        ha->qtd=0;
        for(int i=0;i<ha->TAM;i++){
            ha->item[i]=NULL;
        }
    }
    return ha;
}

void delete_hash(Hash *ha){
    if(ha!=NULL){
        for(int i=0;i<ha->TAM;i++){
            if(ha->item[i]!=NULL)
                free(ha->item[i]);
        }
        free(ha->item);
        free(ha);
    }
}

int string_converter(string& s){
    int i, valor=7, str;
    str = s.size();
    for(i=0;i<str;i++){
        valor = (valor*31) + (int) s[i];
    }
    return valor;
}

int key_divide(string& chave, int TAM){
    int key;
    key = string_converter(chave);
    return (key & 0x7FFFFFFF) % TAM;
}

int linear_probing(int pos, int i, int TAM){
    return ((pos+i) & 0x7FFFFFFF) % TAM;
}

int insert(Hash *ha, string y, int x){
    if(ha==NULL || ha->qtd==ha->TAM)
        return 0;
    string chave = y;
    int i, pos, newpos;
    pos = key_divide(chave, ha->TAM);
    for(i=0;i<ha->TAM;i++){
        newpos = linear_probing(pos, i, ha->TAM);
        if(ha->item[newpos]==NULL){
            jogador temp;
            temp.pontuacao = x;
            temp.nome = y;
            jogador *player;
            player = new jogador;
            *player = temp;
            ha->item[newpos] = player;
            ha->qtd++;
            return 1;
        }
        else if(ha->item[newpos]->nome == y){
          ha->item[newpos]->pontuacao = ha->item[newpos]->pontuacao + x;
          return 1;
        }
    }
    return 0;
}
int find(Hash *ha, string& s){
    if(ha==NULL){
        return 0;
    }
    else{
        int i, pos, newpos;
        pos = key_divide(s, ha->TAM);
        for(i=0;i<ha->TAM;i++){
            newpos = linear_probing(pos, i, ha->TAM);
            if(ha->item[newpos]==NULL){
                return 0;
            }
            else if(ha->item[newpos]->nome == s){
                    return ha->item[newpos]->pontuacao;
            }
        }
        return 0;
    }
}


int  main(void){
    Hash *tabela = new_hash(142700), *fin = new_hash(142700);
    string win[10000];
    int n, i, point[10000];
    string  aux, name[10000];
    cin >> n;
    int MAX=INT_MIN, pont, t=0, j;
        for(i=0;i<n;i++){
        cin >> name[i] >> point[i];
        insert(tabela, name[i], point[i]);
        //cout << name[i] << "   " << pont << " pts" << endl;
        }
    for(i=0;i<n;i++){
            pont = find(tabela, name[i]);
            if(pont>MAX){
                MAX = pont;
            }
        }
    for(i=0;i<n;i++){
        pont = find(tabela, name[i]);
        if(pont>=MAX){
            win[t] = name[i];
            t++;
        }
    }
    string rola;
    bool key=true;
    //cout << MAX << endl;
    for(i=0;i<n && key!=false;i++){
        insert(fin, name[i], point[i]);
        pont = find(fin, name[i]);
        if(pont>=MAX){
            for(j=0;j<t;j++){
                if(win[j]==name[i]){
                    rola = name[i];
                    key = false;
                    break;
                }
            }
        }
    }
    cout << rola << endl;

    delete_hash(tabela);
        return 0;
}
