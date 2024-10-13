#include "Parser.h"
#include <iostream>

void consume(TraderQueue& queue) {
    while(true) {
        std::unique_lock<std::mutex> lock(queue.mtx);
        queue.cv.wait(lock, [&queue]() { return !queue.empty(); });
        std::cout << "Consuming new trade :" << std::endl;
        auto trade = queue.getTrade();
        trade.print();
        lock.unlock();
    }
}
int main() {
    TraderQueue queue;
    Parser("../src/test.csv").load(queue);
    std::thread producer_thread ([&queue]() {Parser("../src/test.csv").load(queue);});

    std::thread consumer_thread ([&queue]() {consume(queue);});

    producer_thread.join();
    consumer_thread.join();
}