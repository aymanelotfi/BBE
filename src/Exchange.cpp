//
// Created by medk on 10/21/24.
//

#include "Exchange.h"

Exchange::Exchange(const Path &MD_path) : _md_feed_queue(), _md_feed_parser(std::make_unique<Parser>(MD_path, _md_feed_queue)){}

void Exchange::startExchange() {
    _stream_thread = std::thread(&Parser::load, _md_feed_parser.get());
    _exchange_thread = std::thread(&Exchange::endExchange, this);
}

void Exchange::runExchange() {
    while(true){
        const Trade& trade = _md_feed_queue.getTrade();
    }
}

void Exchange::endExchange() {
    _stream_thread.join();
    _exchange_thread.join();
}

Exchange::~Exchange() {
    endExchange();
}
