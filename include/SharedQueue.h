#ifndef SHAREDQUEUE_H
#define SHAREDQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template<class T>
class SharedQueue {
private:
    std::queue<T> trades;
    std::mutex mtx;
    std::condition_variable cv;
    bool finished = false;

public:
    void push(const T& item);

    T pop();

    void finish();

    bool is_finished();
};

#endif