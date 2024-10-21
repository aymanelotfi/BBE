#include "TraderQueue.h"

#include <mutex>

void TraderQueue::addTrade(Trade trade) {

    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Producer Thread " << '\n';
    trades.push(trade);
    lock.unlock();
    cv.notify_all();
}

Trade TraderQueue::getTrade() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this]() { return !trades.empty()||finished; });
    if(trades.empty() && finished){
        return Trade();
    }
    Trade trade = trades.front();
    trades.pop();
    lock.unlock();
    return trade;
}

void TraderQueue::finish(){
    std::unique_lock<std::mutex> lock(mtx);
    finished = true;
    lock.unlock();
    cv.notify_all();
}


bool TraderQueue::is_finished() {
    std::unique_lock<std::mutex> lock(mtx);
    return trades.empty() && finished;
}



