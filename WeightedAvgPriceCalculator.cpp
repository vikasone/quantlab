#include "WeightedAvgPriceCalculator.h"

WeightedAvgPriceCalculator::WeightedAvgPriceCalculator(TradeDataStore& tds) : m_tds(tds) {}

void WeightedAvgPriceCalculator::calculate(Trade& t) {
  string symbol = t.getSymbol();
  unsigned long price = t.getPrice();
  unsigned long qty = t.getQty();

  TradeData& td = m_tds.getTradeData(t);
  td.setTotalWeightedVol(td.getTotalWeightedVol() + qty * price);
}
