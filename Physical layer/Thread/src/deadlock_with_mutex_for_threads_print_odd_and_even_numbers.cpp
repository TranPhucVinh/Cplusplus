#include <iostream>
#include <thread>
#include <mutex>

#define NUMBER  7

using namespace std;

void odd_number(int &int_arg);
void even_number(int &int_arg);

int number = NUMBER;

mutex _mutex;

int main() {
    thread odd_thread(odd_number, ref(number)), even_thread(even_number, ref(number));
    odd_thread.join();
    even_thread.join();

    return 0;
}

void odd_number(int &int_arg) {
    _mutex.lock();
    if ( int_arg > 0) {
        cout << "Odd number: " << int_arg << endl;
        int_arg -= 1;
        _mutex.unlock();
        even_number(int_arg);           
    } else _mutex.unlock();
}

void even_number(int &int_arg) {
    _mutex.lock();
    if ( int_arg > 0) {
        cout << "Even number: " << int_arg << endl;        
        int_arg -= 1;
        _mutex.unlock();
        odd_number(int_arg);
    } else _mutex.unlock();
}
