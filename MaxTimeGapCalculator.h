#ifndef MAXTIMEGAP_CALCULATOR_H
#define MAXTIMEGAP_CALCULATOR_H

#include "TradeCalculator.h"
#include "Trade.h"
#include "TradeDataStore.h"

// MaxTimeGapCalculator - A calculator to calculate maximum time gap for any symbol

class MaxTimeGapCalculator : public TradeCalculator {

  public:
    MaxTimeGapCalculator(TradeDataStore& tds);
    virtual void calculate(Trade& t);

  private:
    TradeDataStore& m_tds;
};

#endif
