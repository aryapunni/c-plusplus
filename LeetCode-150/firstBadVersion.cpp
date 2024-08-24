//You are a product manager and currently leading a team to develop a new product. 
//Unfortunately, the latest version of your product fails the quality check. 
//Since each version is developed based on the previous version, 
//all the versions after a bad version are also bad.
//Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
//which causes all the following ones to be bad.
//You are given an API bool isBadVersion(version) which returns whether version is bad. 
//Implement a function to find the first bad version. 
//You should minimize the number of calls to the API.


#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;



    bool isBadVersion (int version) {

        if(version > 0) {
            return true;
        }
        else {
            return false;
        }

    }

    int firstBadVersion(int n) {

        int badVersion = -1;

        int start = 1;
        int end = n;
        int mid = 0;

        while(start <= end) {

            mid = (start + end)/2;
            cout << mid << endl;
            if(isBadVersion(mid) == true) {

                end = mid - 1;
                badVersion = mid;

            }
            else {
                start = mid + 1;
            }
            

            cout << badVersion << endl;


        }

        if(isBadVersion(badVersion) == true) {

            return badVersion;

        }
        else {
            return badVersion + 1;
        }

        
    }

    

int main(void) {

    
    int badVersion = firstBadVersion(8);

    cout << "badVersion = " << badVersion << endl;


    return 0;
}