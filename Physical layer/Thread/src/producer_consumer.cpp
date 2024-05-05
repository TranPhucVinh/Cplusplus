#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <unistd.h>

using namespace std;

#define RANGE 1000000

void producer_func();
void consumer_func();

std::mutex 					_mutex;
std::condition_variable 	cv;

// A vector buffer to store the value "produced" by the producer thread
// and to be "consumed" by the consumer thread
vector<int> vec_buf;

int main()
{
    std::thread producer(producer_func), consumer(consumer_func);
    producer.join();
    consumer.join();
    return 0;
}

void producer_func()
{
    int value = 0;
    while(1){
        // As with unique_lock the mutex is automatically unlocked when 
        // the unique_lock object goes out of its scope, we must put this block
        // of code inside the {} to form its scope
        {
            std::unique_lock<std::mutex> thread1_lock(_mutex);
            vec_buf.push_back(value);
            cv.notify_one();  // Notify consumer thread
        }
        sleep(2);
        value += 1;
    }
}

void consumer_func(){
    while(1){
        std::unique_lock<std::mutex> thread2_lock(_mutex);
        cv.wait(thread2_lock);
        cout << vec_buf.back() << endl;
        vec_buf.pop_back();// Pop out the last member of the vector after reading it
    }
}