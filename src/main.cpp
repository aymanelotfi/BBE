#include "Parser.h"
#include <iostream>

void consume(TraderQueue& queue) {
    while(!queue.is_finished()) {
        Trade trade = queue.getTrade();
        trade.print();
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