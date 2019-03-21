/** Implementation of a memoized (dynamic) solution of the Fibonacci sequence in Linear time complexity **/
  int FiboDP(int n){
      if(n<0) {
        System.out.println("Please enter a positive integer");
      }
      int memo[] = new int[n];
      memo[0] = 0;
      memo[1] = 1;
      memo[2] = 1;
      for(int i = 0; i< n; i++){
          memo[i] = -1;
      }
      if(memo[n] != -1) {
          return memo[n];
      }
      else {
          int f = FiboDP(n-1)+FiboDP(n-2);
          memo[n] = f;
      }
      return f;
  }
  public static void main(String[] args) {
      System.out.println(FiboDP(50));
  }
