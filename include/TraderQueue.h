#pragma once
#include "Trade.h"
#include<queue>
#include<condition_variable>

class TraderQueue {
public:
    void addTrade(Trade trade);
    Trade getTrade();
    bool isEmpty();
    int size();
    void clear();
private:
    std::queue<Trade> trades;
    std::mutex mtx;
};