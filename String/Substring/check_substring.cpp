#include <iostream>
#include <string>

using namespace std;

bool isSubstr(string a, string b){
        bool is =0;
        if(b.find(a) != std::string::npos){
            is =1;
        }
        return is;
}      
//check if string a is substring of b
int main(){
    string a,b;
    cin >> a;
    cin >> b;

    if(isSubstr(a,b)){
        cout << "yes"<<endl;
    }else{
        cout << "no"<<endl;
    }


    return 0;
}