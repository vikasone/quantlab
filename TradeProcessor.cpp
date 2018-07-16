#include<iostream>
#include "TradeFileReader.h"
#include "Trade.h"
#include "TradeDataStore.h"
#include "MaxTimeGapCalculator.h"
#include "MaxTradePriceCalculator.h"
#include "TotalVolTradedCalculator.h"
#include "WeightedAvgPriceCalculator.h"
#include "CalculatorStore.h"

string INPUTFILE = "input.csv";
string OUTPUTFILE = "output.csv";
string TESTINPUTFILE = "testinput.csv";
string TESTOUTPUTFILE = "testoutput.csv";

void runProcessor();
void runUnitTests();

int main(int argc, char* argv[]) {
  if (argc > 1 && strcmp(argv[1], "test") == 0){
    cout << "UNIT TEST MODE" << endl;
    runUnitTests();
    exit(0);
  } else {
    runProcessor();
  }

}

void runUnitTests() {

  // Sample Unit Test
  /*
   * Sample Input:
   * 52924702,aaa,13,1136
   * 52924702,aac,20,477
   * 52925641,aab,31,907
   * 52927350,aab,29,724
   * 52927783,aac,21,638
   * 52930489,aaa,18,1222
   * 52931654,aaa,9,1077
   * 52933453,aab,9,756

   * <symbol>,<MaxTimeGap>,<Volume>,<WeightedAveragePrice>,<MaxPrice>
   * Sample Output:
   * aaa,5787,40,1161,1222
   * aab,6103,69,810,907
   * aac,3081,41,559,638
   *
  */

   vector<string> testinput;
   testinput.push_back("52924702,aaa,13,1136");
   testinput.push_back("52924702,aac,20,477");
   testinput.push_back("52925641,aab,31,907");
   testinput.push_back("52927350,aab,29,724");
   testinput.push_back("52927783,aac,21,638");
   testinput.push_back("52930489,aaa,18,1222");
   testinput.push_back("52931654,aaa,9,1077");
   testinput.push_back("52933453,aab,9,756");

   vector<string> testoutput;
   testoutput.push_back("aaa,5787,40,1161,1222");
   testoutput.push_back("aab,6103,69,810,907");
   testoutput.push_back("aac,3081,41,559,638");

   //create test input file
   ofstream os(TESTINPUTFILE, std::ofstream::out);
   for (auto ti : testinput)
    os << ti << endl;
   os.flush();
   os.close();

   INPUTFILE = TESTINPUTFILE;
   OUTPUTFILE = TESTOUTPUTFILE;
   
   runProcessor();

   //verify output
   ifstream ofile;
   ofile.open(TESTOUTPUTFILE, ifstream::in);
   string line;
   bool verified = true;
   int i = 0;
   while (ofile.peek() != EOF){
     getline(ofile, line);
     if (line.compare(testoutput[i++]) != 0) {
       verified = false;
       break;
     }
   }

   if (verified)
     cout << "Trade processor verification SUCCESS" << endl;
   else
     cout << "Trade processor verification FAILURE" << endl;
}

void runProcessor() {
  TradeFileReader tradeFileReader(INPUTFILE);
  TradeDataStore tds;
  MaxTimeGapCalculator maxTimeGapCalculator(tds);
  MaxTradePriceCalculator maxTradePriceCalculator(tds);
  TotalVolTradedCalculator totalVolTradedCalculator(tds);
  WeightedAvgPriceCalculator weightedAvgPriceCalculator(tds);

  CalculatorStore calculatorStore;
  calculatorStore.add(&maxTimeGapCalculator);
  calculatorStore.add(&maxTradePriceCalculator);
  calculatorStore.add(&totalVolTradedCalculator);
  calculatorStore.add(&weightedAvgPriceCalculator);
  
  while (tradeFileReader.hasNextTrade()) {
    Trade t = tradeFileReader.nextTrade();
    calculatorStore.calculate(t);
  }

  tds.createOutputFile(OUTPUTFILE);
}
