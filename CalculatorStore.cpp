#include "Trade.h"
#include "TradeDataStore.h"
#include "CalculatorStore.h"
#include <vector>
#include <iostream>
using namespace std;

CalculatorStore::CalculatorStore(){}

void CalculatorStore::add(TradeCalculator* c) {
  m_calculators.push_back(c);
}

void CalculatorStore::calculate(Trade& t) {
  for (auto c : m_calculators) {
    c->calculate(t);
  }
}

