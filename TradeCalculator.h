#ifndef TRADE_CALCULATOR_H
#define TRADE_CALCULATOR_H

#include "Trade.h"
#include "TradeDataStore.h"

// TradeCalculator - ABC for trade calculators

class TradeCalculator {

  public:
    virtual void calculate(Trade& t) = 0;
};

#endif
