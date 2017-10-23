/*computes the modular multiplicative inverse:
 * let x,n be any positive integers
 * we want to compute m so that:
 * (m*x)%n=1
 * i.e. the multiplicative inverse mod n
 */

#include <iostream>

int inverse(int x, int n){
    int t=0;
    int r=n;
    int newt=1;
    int newr=x;
    while(newr!=0){
        int quot=r/newr;
        int tmp=newt;
        newt=t-quot*newt;
        t=tmp;
        tmp=newr;
        newr=r-quot*newr;
        r=tmp;
    }
    if(r>1){
        return -1;
    }
    if(t<0){
        t+=n;
    }
    return t;
}


int main(int argc, char** argv){
    if(argc!=3){
        std::cout<<"usage is: mmi x n\nwhere x denotes the given number and n denotes the mod"<<std::endl;
        return -1;
    }
    int x=std::stoi(argv[1]);
    int n=std::stoi(argv[2]);
    int result=inverse(x,n);
    if(result==-1){
        std::cout<<"not invertible"<<std::endl;
        return -1;
    }
    std::cout<<"inverse is: "<<result<<std::endl;
    return 0;
}
