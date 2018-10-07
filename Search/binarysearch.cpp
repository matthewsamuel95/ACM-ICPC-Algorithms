#include<iostream>
#include<math.h>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

int counter = 0;

int binarySearch(vector<int> &arr, unsigned int low, unsigned int high, int num){

	if(low > high)
		return -1;
	else
	{
		int mid = (low + high) / 2;
		counter++;

		if(arr[mid] == num)
			return mid;
		else if(arr[mid] < num)
				return binarySearch(arr, mid + 1, high, num);
		else
				return binarySearch(arr, low, mid, num);
		}
}

int main(int argc, char*argv[]){
	int x;
	vector<int> arr;
	int result;
	string line, line2;
	fstream file;
	ifstream infile(argv[1]);
	file.open(argv[2], ios::out);


	getline(infile, line);
	istringstream buffer{line};

	while(buffer >> x){
		arr.push_back(x);

		if(buffer.peek() == ',') // >> std::ws)
			buffer.ignore();
	}
	sort(arr.begin(), arr.end());
	int y;
	while(infile >> y)
	{
		result = binarySearch(arr, 1, arr.size() + 1, y);
		(result == -1) ? file<<to_string(y)+" not found"<<endl : file<<to_string(y)+" found at position "<<result<<" after "<<counter<<" comparisons"<<endl;
	}
	// sort(arr.begin(), arr.end());

}
