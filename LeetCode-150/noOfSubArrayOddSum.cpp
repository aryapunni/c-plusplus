//Given an array of integers arr, return the number of 
//subArrays with an odd sum.
//Since the answer can be very large, return it modulo 109 + 7.


#include<iostream>
#include<vector>
using namespace std;


int numOfSubArrays(vector<int>& arr) {

    int odd = 0;
    int even = 0;
    int result = 0;
    int modulo = (int)1e9+7; 

    for (int num : arr) {

        // even += 1;

        if(num % 2) {
            swap(odd, even);
            odd += 1;
 
            
        }
        else {
            even += 1;
        }
        
        result = (result + odd)%10000000007;
    
    }


    cout << "odd: " << odd << " result " << result << endl;

    return result;

       
}

int main(void) {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    //1, [1,2], [1,2,4] [1,2,4,3] [1,2,4,3,8] [1,2,4,3,8,2]
    //2, []

    int result = numOfSubArrays(arr);

    cout << "result: " << result << endl;
    return 0;
}