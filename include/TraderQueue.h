#pragma once
#include "Trade.h"
#include<queue>
#include<condition_variable>

class TraderQueue {
public:
    std::mutex mtx;
    std::condition_variable cv;
    bool finished = false;
    void addTrade(Trade trade);
    Trade getTrade();
    bool empty();
    void clear();
    void finish();
    bool is_finished();

private:
    std::queue<Trade> trades;
};