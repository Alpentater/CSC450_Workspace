/*
Module 7: Portfolio Milestone
11/1/2025
CSC 450: Programming III
Alex Carpenter

This program just creates two seperate threads that will be used as counters.
One thread will count from 0 to 20, and the other thread will count from 20 to 0.
*/

#include <iostream> //Including iostream for console debug outputs.
#include <thread> //Including thread for use of threads of course.
#include <mutex> //Including atomic to make use of mutexing,
#include <condition_variable> //Including for use of condition variables.

std::mutex mtx; //Defining a mutext for protecting the shared counter variable.
int counter = 0; //The counter variable being used throughout the threads.
std::condition_variable cv; //Condition variable needed to check when the first thread is done.
bool firstThreadFinished = false; //What the condition variable checks to continue the 2nd thread

//This function will count up. (From 0 to 20). One of the two threads will use this.
void countUp() {

    //A simple for loop that increases the 'counter' variable by one 20 times.
    for (int i = 0; i <= 20; i++) {

        /* Locking 'counter' with a mutex.Good practice learned from module 5 to make sure no other
        * threads interfere or alter the 'counter' variable at the same time and cause unexpected results! */
        std::lock_guard <std::mutex> lk(mtx);
        
        //Incrementing the counter (making it match i)
        counter = i;

        //Printing the counters value to the console.
        std::cout << "Thread 1 counting up: " << i << '\n';
    }

    //Using condition variable to tell the counting down thread it can start when this one is done.
    //The second thread is basically waiting for "firstThreadFinished" to be true!
    std::lock_guard<std::mutex> lk(mtx);
    firstThreadFinished = true;
    cv.notify_one();
}

//This function will count down. (From 20 to 0). One of the two threads will use this.
void countDown() {
    // Waiting until firstThreadFinished becomes true as explained just above.
    // The 'unique_lock' as far as I understand, is the type of mutex used specifically for condition variables.
    std::unique_lock <std::mutex> lk(mtx);
    cv.wait(lk, [] { return firstThreadFinished; });
    lk.unlock();

    for (int i = 20; i >= 0; i--) {
        /* Locking 'counter' with a mutex.Good practice learned from module 5 to make sure no other
        * threads interfere or alter the 'counter' variable at the same time and cause unexpected results! */
        std::lock_guard <std::mutex> lk2(mtx);

        //Decreasing the counter (making it match i)
        counter = i;

        //Printing the counters value to the console.
        std::cout << "Thread 2 counting down: " << i << '\n';
    }
}

//Main function or main entry point.
int main() {
    //Starting the two different threads for the two different counters.
    std::thread upThread(countUp);
    std::thread downThread(countDown);

    //Waiting them to both finish before continuing on in main.
    upThread.join();
    downThread.join();

    //Our final debug message so we know everything finished succesfully!
    std::cout << "Done!";

    //Obligitory return statement for main function.
    return 0;
}
