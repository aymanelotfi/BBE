#include "Parser.h"
#include <iostream>

void consume(TraderQueue<Trade>& queue) {
    while(!queue.is_finished()) {
        Trade trade = queue.getTrade();
        trade.print();
    } 
}
int main() {
    TraderQueue<Trade> queue;
    std::thread producer_thread ([&queue]() {Parser("../src/test.csv",queue).load();});

    std::thread consumer_thread ([&queue]() {consume(queue);});

    producer_thread.join();
    consumer_thread.join();
}