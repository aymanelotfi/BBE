#include "TraderQueue.h"

void TraderQueue::addTrade(Trade trade) {
    trades.push(trade);
}

Trade TraderQueue::getTrade() {
    if(trades.empty()){
        return Trade();
    }
    Trade trade = trades.front();
    trades.pop();
    return trade;
}

