#include <iostream>
#include <thread>
#include <mutex>

#define NUMBER  7

using namespace std;

int shared_value = NUMBER;
std::recursive_mutex _rec_mtx;

void odd_number(int &lval);
void even_number(int &lval);

int main()
{
    std::thread thread_odd_num(odd_number, std::ref(shared_value)), thread_even_num(even_number, std::ref(shared_value));
    thread_odd_num.join();
	thread_even_num.join();
    return 0;
}

void odd_number(int &lval){
	_rec_mtx.lock();
	if (lval > 0) {
		cout << "Odd number: " << lval << endl;
		
		lval -= 1;
		even_number(lval);
	}
	_rec_mtx.unlock();
}

void even_number(int &lval) {
	_rec_mtx.lock();
    if (lval > 0) {
        cout << "Even number: " << lval << endl;

        lval -= 1;
        odd_number(lval);
    }
	_rec_mtx.unlock();
}
