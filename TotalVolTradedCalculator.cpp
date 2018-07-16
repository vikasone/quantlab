#include "TotalVolTradedCalculator.h"

TotalVolTradedCalculator::TotalVolTradedCalculator(TradeDataStore& tds) : m_tds(tds) {}

void TotalVolTradedCalculator::calculate(Trade& t) {
  TradeData& td = m_tds.getTradeData(t);
  td.setTotalVolTraded(td.getTotalVolTraded()+t.getQty());
}
