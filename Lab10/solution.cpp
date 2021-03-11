#include <iostream>

#include <cstdlib>

#include <chrono>
#include <iomanip>

using namespace std;

int get_memory_usage_kb(long* vmrss_kb, long* vmsize_kb);

int* runningSum(int* nums, int size){
  
  for(int i = 1; i < size; i++){
  
    nums[i] = nums[i] + nums[i - 1];
  } 
  	
	return nums;
}

void print_arr(int* nums, int size){
	for (int i = 0; i < size; ++i)
		cout << nums[i] << " ";
	cout << endl;
}

int main(int argc, char const *argv[])
{
	//variables for memory calculation
    long vmrss, vmsize;

	int arr1[4] = {1,2,3,4};
	int arr2[5] = {1,1,1,1,1};
	int arr3[5] = {3,1,2,10,1};

	//get time stamp before testing
    auto start = chrono::high_resolution_clock::now(); 

	int* num1 = runningSum(arr1,4);
	int* num2 = runningSum(arr2,5);
	int* num3 = runningSum(arr3,5);

	//get time stamp after testing
    auto end = chrono::high_resolution_clock::now(); 

    cout << endl;
	cout << "Test 1..." << endl;
	cout << "Expected: 1 3 6 10" << endl;
	cout << "Actural: ";
	print_arr(num1, 4);

	cout << endl;
	cout << "Test 2..." << endl;
	cout << "Expected: 1 2 3 4 5"  << endl;
	cout << "Actural: ";
	print_arr(num2, 5);
    
    cout << endl;
	cout << "Test 3..." << endl;
	cout << "Expected: 3 4 6 16 17" << endl;
	cout << "Actural: ";
	print_arr(num3, 5);

	//calculate and print time taken
    double time_taken =  
      chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
    time_taken *= 1e-9; 
  
    cout << endl;
	cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 
    

    //calculate total memory usage
    get_memory_usage_kb(&vmrss, &vmsize);
    printf("Current memory usage: VmRSS = %6ld KB, VmSize = %6ld KB\n", vmrss, vmsize);


	return 0;
}