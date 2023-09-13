#include <iostream>
#include <iomanip>
using namespace std;

int syracuse(int n, int countdown, int &highest){

    cout << n << endl;
    if (countdown == 0){
        cout << "Sequence was aborted early." << endl;
        return 0;
    }

    if(n == 1){
        return 0;
    }

    highest = max(highest, n);
    if (n % 2 == 0){
        syracuse(n/2, countdown - 1, highest);
    } else{
        syracuse(((3*n) + 1)/2, countdown - 1, highest);
    }
}

int main(){
    int start_n;
    int lim;
    bool start_invalid = true;
    bool limit_invalid = true;

    while(start_invalid){
        cout << "Enter the starting number: ";
        cin >> start_n;

        if (start_n > 1){
            start_invalid = false;
        }
    }

    while(limit_invalid){
        cout << "Enter the limit of terms: ";
        cin >> lim;

        if (lim > 1) {
            limit_invalid = false;
        }
    }

    int highest = start_n;
    syracuse(start_n, lim, highest);

    cout << "Highest number reached: " << highest << endl;

    return 0;

}