class FiboDP{

    int lookup[] = new int[100];

    void init(){
        for(int i = 0; i< 100; i++){
            lookup[i] = -1;
        }
    }

    int fibo(int n){
        if(lookup[n]==-1){
            if(n<=1){
                lookup[n]=n;
            }else{
                lookup[n] = fibo(n-1)+fibo(n-2);
            }
        }
        return lookup[n];
    }
    public static void main(String[] args) {
        FiboDP fb  = new FiboDP();
        fb.init();
        System.out.println(fb.fibo(30));
    }
}