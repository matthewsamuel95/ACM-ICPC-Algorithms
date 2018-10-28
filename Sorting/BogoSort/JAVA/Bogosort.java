public static void bogoSort(int length, int range) {
	int []array = randomIntArray(length,range);
		
	while (! isSorted(array))
		array = randomArray(array);
		
	for (int i = 0; i < array.length; i++) {
		System.out.print(array[i] + " ");
	}
		
}
	
private static boolean isSorted(int [] array)
{
    for (int i = 0; i < (array.length - 1); ++i) {
    	if (array[i] > array[i+1])
    		return false;
    }
        
    return true;
}
	
private static int [] randomArray(int [] array) {
		 
    int size = array.length;
    int[] indices = new int[size]; 
    for (int i=0; i<size; i++) {
    	indices[i] = i;
    }
	      
    Random random = new Random();
    for (int i = 0; i < size; i++) {
      boolean unique = false;
      int nRandom = 0;
      while (!unique) {
        unique = true;
        nRandom = random.nextInt(size);
        for (int j = 0; j < i; j++) {
          if (indices[j] == nRandom) {
             unique = false;
             break;
          }
        }
      } 
	 
      indices[i] = nRandom; 
    }
	 
    int [] result = new int[size];
        for (int k = 0; k < size; k++) {
    result[indices[k]] = array[k];
    }

    return result;
}
	
private static int[] randomIntArray(int length, int n)
{
  int[] a = new int[length];
  Random generator = new Random();
  for (int i = 0; i < a.length; i++)
  {
      a[i] = generator.nextInt(n);
  }
  return a;
}
