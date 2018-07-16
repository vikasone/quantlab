#ifndef TOTALVOLTRADED_CALCULATOR_H
#define TOTALVOLTRADED_CALCULATOR_H

#include "TradeCalculator.h"
#include "Trade.h"
#include "TradeDataStore.h"

// TotalVolTradedCalculator - A calculator to calculate total volume traded for any symbol

class TotalVolTradedCalculator : public TradeCalculator {

  public:
    TotalVolTradedCalculator(TradeDataStore& tds);
    virtual void calculate(Trade& t);

  private:
    TradeDataStore& m_tds;
};

#endif
