"""Calculate unique pairs of 3 digits which sum to zero.

Author: Ryan Eloff
Contact: ryan.peter.eloff@gmail.com
Date: October 2018
""" 


import numpy as np


def three_sum(num_array):
	num_array = np.sort(num_array)
	n_numbers = len(num_array)
	pair_indices = []
	for i in range(n_numbers):
		for j in range(i+1, n_numbers):
			for k in range(j+1, n_numbers):
				pair_indices.append((i, j, k))
	
	arr_rows =  np.expand_dims(np.expand_dims(num_array, axis=1), axis=2)
	arr_cols =  np.expand_dims(np.expand_dims(num_array, axis=0), axis=2)
	arr_depth = np.expand_dims(np.expand_dims(num_array, axis=0), axis=1)
	arr_three_sum = arr_rows + arr_cols + arr_depth
	
	valid_three_sum_indices = [pair for pair in pair_indices
							   if arr_three_sum[pair] == 0]
	valid_three_sum_pairs = [(num_array[pair[0]], num_array[pair[1]], num_array[pair[2]])
							 for pair in valid_three_sum_indices]
	return np.unique(valid_three_sum_pairs, axis=0)


if __name__ == '__main__':
	num_array = [-1, 0, 1, 2, -1, -4]
	print(three_sum(num_array))
