/*
 *  This is a weighted quick union algorithm.
*/
#include<iostream>
#include<vector> 

using namespace std;

#define whatis(x) cout<<#x<<": "<<x<<endl
#define MAX 10000007

//For storing the root element
//For storing the size of the root element
int id[MAX];
int sz[MAX];

// initializing all the values of id[i] to i.
// initializing all the values of sz[i] to 1;
void initiate(){
    for(int i = 0; i<MAX; i++ ) {
        id[i] = i;
        sz[i] = 1;
    }
}

// joining two nodes
void join(int p, int q) {
    
    while(id[p] != p ) p = id[p];
    while(id[q] != q)  q = id[q];
        
    if( p == q ) return ;

    if(sz[p] < sz[q]) { id[p] = q ; sz[q] += sz[p]; }
    else {              id[q] = p;  sz[p] += sz[q]; 
    }

}

//Checking if the pair of nodes is already joined or not
bool check_join( int p, int q) {
    
    
    while(id[p] != p ) p = id[p];
    while(id[q] != q ) q = id[q];
    
    
    if(p == q) return true;
    else return false;
}

//Example to show how it works
void example() {
    
    int p[][2] = { 
        {1, 2}, 
        {2, 3}, 

    };

    int check[][2] = {
        {1, 3}, {1, 7}
    };
    
    for(int i = 0; i<2; i++){
        join(p[i][0], p[i][1]);
    }

    for(int i = 0 ; i<2; i++ ) {
        cout<<check_join(check[i][0], check[i][1])<<endl;
    }

}

/*
1  as 1 and 3 are already joined.
0  as 1 and 7 are not joined.
*/

int main() {
    initiate(); //initiating id ans sz array above

    example(); // Taking an example

    return 0;
}
