/*
Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads.
 Thread A will call foo() while thread B will call bar().
 Modify the given program to output "foobar" n times.

 

Example 1:

Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously.
 One of them calls foo(), while the other calls bar(). "foobar" is being output 1 time.
Example 2:

Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
*/

//solution
class FooBar {
private:
    int n;
    volatile bool printFooV = true;
    condition_variable cv;
    mutex mtx;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lock(mtx);
        for (int i = 0; i < n; i++) {
            cv.wait(lock,[=]{return printFooV;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            printFooV = false;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lock(mtx);
        for (int i = 0; i < n; i++) {
            cv.wait(lock, [=]{return printFooV == false;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            printFooV = true;
            cv.notify_all();
        }
    }
};