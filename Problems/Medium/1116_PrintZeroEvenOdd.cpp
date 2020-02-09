/*
Suppose you are given the following code:

class ZeroEvenOdd {
  public ZeroEvenOdd(int n) { ... }      // constructor
  public void zero(printNumber) { ... }  // only output 0's
  public void even(printNumber) { ... }  // only output even numbers
  public void odd(printNumber) { ... }   // only output odd numbers
}
The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A will call zero() which should only output 0's.
Thread B will call even() which should only ouput even numbers.
Thread C will call odd() which should only output odd numbers.
Each of the threads is given a printNumber method to output an integer. 
Modify the given program to output the series 010203040506... where the length 
of the series must be 2n.

 

Example 1:

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously. 
One of them calls zero(), the other calls even(), and the last one calls odd(). 
"0102" is the correct output.

Example 2:

Input: n = 5
Output: "0102030405"
*/

//solution
class ZeroEvenOdd {
private:
    int n;
    condition_variable cv;
    mutex m;
    volatile bool printEven = false, printOdd = false, printZero = true, flag = true;
    volatile int evenCount = 0, oddCount = 0;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->evenCount = (n % 2 == 0) ? n : n - 1;
        this->oddCount = (n % 2 == 0) ? n - 1 : n;
        cout<<evenCount<<" "<<oddCount<<endl;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);
        for(int i = 1; i <= n; i++){
            cv.wait(lock, [=]{ return printZero; });
            printNumber(0);
            flag == true ? printOdd = true : printEven = true;
            printZero = false;
            flag = !flag;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);
        for(int i = 2; i <= evenCount; i+=2){
            cv.wait(lock, [=]{ return printEven; });
            printNumber(i);
            printZero = true; printEven = false;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);
        for(int i = 1; i <= oddCount; i+=2){
            cv.wait(lock, [=]{ return printOdd; });
            printNumber(i);
            printZero = true; printOdd = false;
            cv.notify_all();
        }        
    }
};