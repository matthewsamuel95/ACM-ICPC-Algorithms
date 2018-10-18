class CuttingRod {

	public int cuttingRod(int[] value, int size) {
		int[] greatSolution = new int[size + 1];
		greatSolution[0] = 0;

		for (int i = 1; i <= size; i++) {
			int max = -1;
			for (int j = 0; j < i; j++) {
				max = Math.max(max, value[j] + greatSolution[i - (j + 1)]);
				greatSolution[i] = max;
				
			}
			System.out.print(greatSolution[i] + " ");
		}
		return greatSolution[size];
	}
}
