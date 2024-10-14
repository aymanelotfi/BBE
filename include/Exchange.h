//
// Created by medk on 10/9/24.
//

#ifndef BBE_EXCHANGE_H
#define BBE_EXCHANGE_H

#include <map>
#include <string>

#include "TraderQueue.h"
#include "Trade.h"
#include "OrderBook.h"
#include "Parser.h"

using Ric = std::string;
using Path = std::string;

struct Instrument{
    Ric name;
    Path md_path;

    Instrument(const Ric&& name, const Path&& md_path) : name(name), md_path(md_path) {}
};

class Exchange{
private:
    std::map<Ric, std::unique_ptr<OrderBook>> _order_books;
    std::map<Ric, std::unique_ptr<Parser>> _parsers;
    std::map<Ric, std::unique_ptr<TraderQueue>> _md_feed_queue;

public:
    Exchange() = default;

    void addInstrument(const Ric&& name, const Path&& md_path){
        if(_parsers.contains(name)){
            throw std::invalid_argument("Ric has already been added");
        }
        _parsers.emplace(name, std::make_unique<Parser>(md_path));
        _order_books.emplace(name, std::make_unique<OrderBook>());
        _md_feed_queue.emplace(name, std::make_unique<TraderQueue>());
    }

};

#endif //BBE_EXCHANGE_H
