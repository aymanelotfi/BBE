#include "Parser.h"
#include <iostream>
int main() {
    TraderQueue queue;
    Parser parser("../src/test.csv");
    parser.load(queue);
    while(!queue.empty()) {
        auto trade = queue.getTrade();
        trade.print();
    }
}