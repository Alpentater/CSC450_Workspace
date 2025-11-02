/*
Module 8: Portfolio Project
11/2/2025
CSC 450: Programming III
Alex Carpenter

This program just creates two seperate threads that will be used as counters.
One thread will count from 0 to 20, and the other thread will count from 20 to 0.
*/

public class PortfolioProject {
	// Making a new object "mutex" to serve the same purpose as "mutex" did in the C++ version of this program
	Object mutex = new Object(); 

	//Condition variable check to continue the 2nd thread
	boolean firstThreadDone = false; 

	//The shared counter integer being altered throughout the program.
	int counter = 0;

	/* ============================================================================================================================
	* Interestingly enough, I could not for the life of me get the countup and countdown functions to work as regular voided functions 
	* like I could in the C++ version of this program. Java requires threads as a class with a run() method, much a like a regular 
	* class would require a main() function. I... do not like this...
	==============================================================================================================================*/

	//This subclass will serve as thread/function that will count up. (From 0 to 20).
	class CountUp extends Thread {
		//The 'run()' is what java needs for threads, like a main() function for a program.
        public void run() {
        	//This is the equivalent of mutexing, as done in the previous C++ program
            synchronized (mutex) {
            	 //A simple for loop that increases the 'counter' variable by one 20 times.
                for (int i = 0; i <= 20; i++) {
                	//Incrementing the counter (making it match i)
                	counter = i;
                	//Printing the counter value to the console.
                    System.out.println("Count Up Thread: " + i);
                }
                firstThreadDone = true; // Notify that counting up is complete
                mutex.notify(); // Wake up the waiting thread
            }
        }
	}

	//This subclass will serve as thread/function that will count down. (From 20 to 0).
	class CountDown extends Thread {
		//The 'run()' is what java needs for threads, like a main() function for a program.
        public void run() {
        	//This is the equivalent of mutexing, as done in the previous C++ program
            synchronized (mutex) {
            	//This while loop makes sure the count down thread waits for the first to finish.
                while (!firstThreadDone) {
 					try {
 						//This must be encapsulated within a try/catch block.
                        mutex.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }

                //Once the 'firstThreadDone' is set to true, the mutex no longer waits and continues
                //synchronizing this thread encapsulating the for loop below that alters the shared
                //counter resource.
                for (int i = 20; i >= 0; i--) {
                	//Printing the counter value to the console.
                    System.out.println("Count Down Thread: " + i);
                }
            }
        }
	}

	//Main function, main entry point.
	public static void main(String[] args) {
		//Creating an instance of this class to call the threads with below.
        PortfolioProject pp = new PortfolioProject();

        //Declaring the two threads.
        Thread upThread = pp.new CountUp();
        Thread downThread = pp.new CountDown();

        // Start both threads (down will wait until up completes)
        upThread.start();
        downThread.start();

        System.out.println("Done!");
    }
}