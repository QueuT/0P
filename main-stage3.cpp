/*
 * main-stage3.cpp
 *
 * Includes the main() function for the stack project (stages 2 & 3).
 *
 * This code is included in the build target "run-stage3-main", and
 * in the convenience targets "stage2", and "stage3".
 */

#include <iostream>

#include "stack-stage3.h"
#include <chrono>
using namespace std;


double time_n_pushes(unsigned n) {
    stack<unsigned> s;
    // get starting clock value
    auto start_time = chrono::system_clock::now();
    // do the n pushes
    for (unsigned i = 0; i < n; i++) {
        s.push(i);
        }
    // get ending clock value
    auto stop_time = chrono::system_clock::now();
    // compute elapsed time in seconds
    chrono::duration<double> elapsed = stop_time - start_time;
    return elapsed.count();
}

int main() {
    double trials = 0;
        cout << "How many trials? " << endl;
        cin >> trials;
    for (unsigned n = 10000; n <= 100000; n += 10000) {
        double total_push_time = 0;

        

        for (double i=0; i<trials; i++) { // 100 trials
            
            total_push_time += (time_n_pushes(n)* 1000000000); //convert to seconds to nanoseconds. 
             
        }
        
        
        double avg_time_per_push = total_push_time / (trials*n); // Average time per push
        
        cout << "The average time per push for " << n << " pushes after " 
             << trials << " trials is: " 
             << avg_time_per_push << " naonseconds." << endl;
    }
    return 0;
}
    