#pragma once
#include "Trade.h"
#include<queue>
#include<condition_variable>

class TraderQueue {
public:
    std::mutex mtx;
    std::condition_variable cv;

    void addTrade(Trade trade);
    Trade getTrade();
    bool empty();
    void clear();

private:
    std::queue<Trade> trades;
};