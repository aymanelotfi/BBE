//
// Created by medk on 10/9/24.
//

#ifndef BBE_EXCHANGE_H
#define BBE_EXCHANGE_H

#include <map>
#include <string>
#include <thread>

#include "Parser.h"
#include "SharedQueue.h"
#include "Trade.h"
#include "OrderBook.h"

class Exchange{
private:
    std::map<std::string, std::unique_ptr<OrderBook>> _order_books; 
    std::unique_ptr<Parser> _md_feed_parser;
    SharedQueue<Trade> _md_feed_queue;

    std::thread _stream_thread;
    std::thread _exchange_thread;

public:
    explicit Exchange(const std::string& MD_path);

    void startExchange();

    void runExchange();

    void endExchange();

    ~Exchange();
};

#endif //BBE_EXCHANGE_H
