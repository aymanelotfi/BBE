#include "SharedQueue.h"

template<typename T>
void SharedQueue<T>::push(const T& item) {
    std::unique_lock<std::mutex> lock(mtx);
    trades.push(item);
    lock.unlock();
    cv.notify_all();
}

template<typename T>
T SharedQueue<T>::pop() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this]() { return !trades.empty() || finished; });
    if(trades.empty() && finished) {
        return T();
    }
    T item = trades.front();
    trades.pop();
    lock.unlock();
    return item;
}

template <typename T>
void SharedQueue<T>::finish() {
    std::unique_lock<std::mutex> lock(mtx);
    finished = true;
    lock.unlock();
    cv.notify_all();
}

template<class T>
bool SharedQueue<T>::is_finished() {
    std::unique_lock<std::mutex> lock(mtx);
    return trades.empty() && finished;
}
