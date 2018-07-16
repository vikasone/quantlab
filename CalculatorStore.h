#ifndef CALCULATORSTORE_H
#define CALCULATORSTORE_H

#include "Trade.h"
#include "TradeDataStore.h"
#include "TradeCalculator.h"
#include <string>
#include <vector>
using namespace std;

//CalculatorStore is a repository for all trade calculators
//Just create and add calculators for any additional trade operations 

class CalculatorStore {
  public:
    CalculatorStore();
    ~CalculatorStore() = default;
    void add(TradeCalculator* c);
    void calculate(Trade& t);

    CalculatorStore (const CalculatorStore&) = default;
    CalculatorStore (CalculatorStore&&) = default;
    CalculatorStore& operator=(const CalculatorStore&) = default;
    CalculatorStore& operator=(CalculatorStore&&) = default;

  private:
    vector<TradeCalculator*> m_calculators;
};

#endif
