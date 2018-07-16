#ifndef WEIGHTEDAVGPRICE_CALCULATOR_H
#define WEIGHTEDAVGPRICE_CALCULATOR_H

#include "TradeCalculator.h"
#include "Trade.h"
#include "TradeDataStore.h"

// WeightedAvgPriceCalculator - A calculator to calculate Weighted Avg Price for any symbol

class WeightedAvgPriceCalculator : public TradeCalculator {

  public:
    WeightedAvgPriceCalculator(TradeDataStore& tds);
    virtual void calculate(Trade& t);

  private:
    TradeDataStore& m_tds;
};

#endif
