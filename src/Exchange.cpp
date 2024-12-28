#include "Exchange.h"

Exchange::Exchange(const std::string &MD_path) : _md_feed_queue(), _md_feed_parser(std::make_unique<Parser>(MD_path, _md_feed_queue)){}

void Exchange::startExchange() {
    _stream_thread = std::thread(&Parser::stream, _md_feed_parser.get());
    _exchange_thread = std::thread(&Exchange::runExchange, this);
}

void Exchange::runExchange() {
    while(!_md_feed_queue.is_finished()){
        const Trade& trade = _md_feed_queue.pop();
    }
}

void Exchange::endExchange() {
    _stream_thread.join();
    _exchange_thread.join();
}

Exchange::~Exchange() {
    endExchange();
}
