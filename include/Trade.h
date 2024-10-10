
struct Trade{
    int timestamp;
    // best ask price.
    int best_ap;
    // ask volume.
    int ask_volume;
    // best bid price.
    int best_bp;
    // bid volume.
    int bid_volume;
    Trade() = default;

    Trade(int best_ap, int ask_volume, int best_bp, int bid_volume):
     best_ap(best_ap), ask_volume(ask_volume), best_bp(best_bp), bid_volume(bid_volume){}
};


