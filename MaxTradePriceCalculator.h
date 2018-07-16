#ifndef MAXTRADEPRICE_CALCULATOR_H
#define MAXTRADEPRICE_CALCULATOR_H

#include "TradeCalculator.h"
#include "Trade.h"
#include "TradeDataStore.h"

// MaxTradePriceCalculator - A calculator to calculate maximum trade price for any symbol

class MaxTradePriceCalculator : public TradeCalculator {

  public:
    MaxTradePriceCalculator(TradeDataStore& tds);
    virtual void calculate(Trade& t);

  private:
    TradeDataStore& m_tds;
};

#endif
