#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>

template<class T>
class TraderQueue {
private:
    std::queue<T> trades;
    std::mutex mtx;
    std::condition_variable cv;
    bool finished = false;

public:
    void addTrade(T trade) {
        std::unique_lock<std::mutex> lock(mtx);
        trades.push(trade);
        lock.unlock();
        cv.notify_all();
    }

    T getTrade() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return !trades.empty() || finished; });
        if(trades.empty() && finished) {
            return T();
        }
        T trade = trades.front();
        trades.pop();
        lock.unlock();
        return trade;
    }

    void finish() {
        std::unique_lock<std::mutex> lock(mtx);
        finished = true;
        lock.unlock();
        cv.notify_all();
    }

    bool is_finished() {
        std::unique_lock<std::mutex> lock(mtx);
        return trades.empty() && finished;
    }
};