#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool find_triplet( int arr[], int arr_size, int value ) {
	unordered_map<int, int> map;
	
	for ( int i = 0; i < arr_size; i++ )
		map[arr[i]] = i;
		
	for ( int i = 0; i < arr_size - 1; i++ )
		for ( int j = i + 1; j < arr_size; j++ ) {
			int sum = value - ( arr[i] + arr[j] );
			
			if ( map.find( sum ) != map.end() )
				if ( map[sum] != i && map[sum] != j ) {
					cout << '(' << arr[i] << ", " << arr[j] << ", " << sum << ')' << endl; 
					return true;
				}
		}
	return false;
}

int main()
{
	int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int arr_size = sizeof( arr ) / sizeof( arr[0] );
	int value = 10;
	
	return find_triplet( arr, arr_size, value );
}
