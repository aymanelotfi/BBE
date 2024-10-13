#include "TraderQueue.h"

#include <mutex>

void TraderQueue::addTrade(Trade trade) {
    std::cout << "Adding trade" << std::endl;
    std::unique_lock<std::mutex> lock(mtx);
    trades.push(trade);
    lock.unlock();
    cv.notify_all();
}

Trade TraderQueue::getTrade() {
    if(trades.empty()){
        return Trade();
    }
    Trade trade = trades.front();
    trades.pop();
    return trade;
}

bool TraderQueue::empty() {
    return trades.empty();
}


