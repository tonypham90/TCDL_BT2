//
// Created by Tony Pham on 03/09/2023.
//
#include "CalculatorString.h"
#include "LargeNumber.h"
#include "iostream"
#include "stdio.h"

using namespace std;

class methodCal {
protected:
  LargeNumber First;
  LargeNumber Second;
  stringCalculator strCalculator;
  LargeNumber Result;

public:
  void input(LargeNumber &a, LargeNumber &b) {
    First = a;
    Second = b;
    strCalculator.setSoThuNhat(a.getStringUnSignValue());
    strCalculator.setSoThuHai(b.getStringUnSignValue());
    Result.clear();
  }
  void setFirstValue(LargeNumber &value) { First = value; };
  void setSecondValue(LargeNumber &value) { Second = value; };
  void setResult(LargeNumber &result) { Result = result; };
  LargeNumber getFirstValue() { return First; }
  LargeNumber getSecondValue() { return Second; }
  virtual LargeNumber getResult() { return Result; };
  virtual void calculate(){};
  virtual void printResult(){};
  void run() {
    calculate();
    printResult();
  }
};

class PrintResult : methodCal {
  string stra;
  string strb;
  string strResult;

public:
  int maxsize(vector<string> number) {
    vector<string> strNumber;
    strNumber.push_back(stra);
    strNumber.push_back(strb);
    strNumber.push_back(strResult);
    if (number.size() != 0) {
      for (string x : number) {
        strNumber.push_back(x);
      }
    }
    int maxsize = 0;
    for (string value : strNumber) {
      if (value.size() > maxsize)
        maxsize = value.size();
    }
    return maxsize;
  }
  void Plus(char dau) {
    vector<string> listNumber = *new vector<string>;
    int size = maxsize(listNumber);
    size += 1; // thêm 1 dấu cho dấu phép tính
    stra = addSpace(stra, size);
    strb = addSpace(strb, size);
    strResult = addSpace(strResult, size);
    string line = drawLine(size);
    cout << stra << endl
         << dau << endl
         << strb << endl
         << line << endl
         << strResult;
  }
  void Multiple(vector<string> number) {
    int size = maxsize(number);
    size += 1;
    stra = addSpace(stra, size);
    strb = addSpace(strb, size);
    strResult = addSpace(strResult, size);
    string line = drawLine(size);
    cout << stra << endl << "x" << endl << strb << endl << line << endl;
    for (int i = 0; i < number.size(); ++i) {
      string strNumber = addSpace(number.at(i), size);
      if (i == 0) {
        cout << strNumber << endl;
      } else {
        cout << "+" << endl << strNumber << endl;
      }
    }
    cout << line << endl << strResult;
    //    TODO check lai in phep nhan
  }
  void Devide(vector<LargeNumber> SoChia, vector<LargeNumber> SoTru) {
    int row = max(SoChia.size(), SoTru.size());
    int maxsize = First.stringValue().size();
    string textrow;
    for (int i = 0; i < row; ++i) {
      string strbiChia = "";
      string strSochia = addSpace(SoChia.at(i).stringValue(), maxsize);
      if (i < SoTru.size()) {
        strbiChia = addSpace(SoTru.at(i).stringValue(), maxsize);
      }
      if (i == 0) {
        string space = "";
        space = addSpace(space, maxsize);
        string line = drawLine(
            max(Second.stringValue().size(), Result.stringValue().size()));
        cout << First.stringValue() << "|" << Second.stringValue() << endl
             << strbiChia << "|" << line << endl;
        //             << strbiChia << "|" << Result.stringValue() << endl;
      } else if (i == 1 && i < SoTru.size()) {
        string line = drawLine(maxsize);
        cout << line << "|" << Result.stringValue() << endl
             << strSochia << "|" << endl
             << strbiChia << "|" << endl;
        ;
      } else if (i < SoTru.size()) {
        string line = drawLine(maxsize);
        cout << line << "|" << endl
             << strSochia << "|" << endl
             << strbiChia << "|" << endl;
      } else {
        string line = drawLine(maxsize);
        cout << line << "|" << endl << strSochia << "|";
      }
    }
  }

  PrintResult(LargeNumber a, LargeNumber b, LargeNumber Result) {
    input(a, b);
    setResult(Result);
    this->stra = First.stringValue();
    this->strb = Second.stringValue();
    strResult = Result.stringValue();
  }
};
class Sum : methodCal {
public:
  Sum(LargeNumber &a, LargeNumber &b) {
    input(a, b);
    calculate();
  };
  void calculate() override {
    if (First.isNegative() == Second.isNegative()) {
      strCalculator = *new stringCalculator(First.getStringUnSignValue(),
                                            Second.getStringUnSignValue());
      strCalculator.Tong();
      Result = *new LargeNumber(strCalculator.exportResult());
      Result.setNegative(First.isNegative());
    } else {
      if (First.isNegative()) {
        strCalculator = *new stringCalculator(Second.getStringUnSignValue(),
                                              First.getStringUnSignValue());
        strCalculator.Hieu();
      } else {
        strCalculator = *new stringCalculator(First.getStringUnSignValue(),
                                              Second.getStringUnSignValue());
        strCalculator.Hieu();
      }
      Result = *new LargeNumber(strCalculator.exportResult());
    }
  };
  void printResult() override {
    PrintResult printer = *new PrintResult(this->First, this->Second, Result);
    printer.Plus('+');
  };
  LargeNumber getResult() override { return Result; }
};
class Minus : methodCal {
public:
  void calculate() override {
    bool subsign = false; // kiem tra đảo dấu
    if (First.isNegative() != Second.isNegative()) {
      strCalculator = *new stringCalculator(First.getStringUnSignValue(),
                                            Second.getStringUnSignValue());
      strCalculator.Tong();
      Result = *new LargeNumber(strCalculator.exportResult());
      Result.setNegative(First.isNegative());
    } else {
      if (First.UnsignIntValue() < Second.UnsignIntValue()) {
        strCalculator = *new stringCalculator(Second.getStringUnSignValue(),
                                              First.getStringUnSignValue());
        strCalculator.Hieu();
        subsign = true;
      } else {
        strCalculator = *new stringCalculator(First.getStringUnSignValue(),
                                              Second.getStringUnSignValue());
        strCalculator.Hieu();
      }
      Result = *new LargeNumber(strCalculator.exportResult());
      Result.setNegative(First.isNegative());
      if (subsign) {
        if (Result.isNegative()) {
          Result.setNegative(false);
        } else {
          Result.setNegative(true);
        }
      }
    }
  }
  void printResult() override {
    PrintResult printer = *new PrintResult(this->First, this->Second, Result);
    printer.Plus('-');
  }
  LargeNumber getResult() override { return Result; }
  Minus(LargeNumber a, LargeNumber b) {
    input(a, b);
    calculate();
  }
};
class Multiple : methodCal {
  vector<string> listElePlus;
  //
public:
  Multiple(LargeNumber &a, LargeNumber &b) {
    input(a, b);
    calculate();
  }

  void calculate() override {
    strCalculator = *new stringCalculator(First.getStringUnSignValue(),
                                          Second.getStringUnSignValue());
    strCalculator.Nhan();
    Result = *new LargeNumber(strCalculator.exportResult());
    listElePlus = strCalculator.getlistNumber();
    if (First.isNegative() == Second.isNegative()) {
      Result.setNegative(false);
    } else {
      Result.setNegative(true);
    }
  }
  void printResult() override {
    PrintResult printer = *new PrintResult(First, Second, Result);
    printer.Multiple(listElePlus);
  }
  LargeNumber getResult() override { return Result; }
};

class Division : methodCal {
  vector<LargeNumber> listResult;
  vector<LargeNumber> listMinusValue;

public:
  void calculate() override {
    //    TODO napso
    LargeNumber chia, biChia;
    chia = First;
    chia.setNegative(false);
    biChia = Second;
    biChia.setNegative(false);
    //    TODO
    //    khi số Chia còn lớn hơn số bị chia:
    while (chia.UnsignIntValue() > biChia.UnsignIntValue()) {
      //      chon so trong chuoi so de chia (so phai lon hon so bi chia)
      LargeNumber MinusValue; // So duoc tinh tu so duoc nhan tu gia tri duoc
                              // chon va so bi chia
      LargeNumber chosenNum = chia.findAvalableNumber(biChia);

      //      duoc dung chia nhom so cho so bi chia chon so de nhan cho so bi
      //      chia nhan so duoc chon cho so bi chia -> ket qua duoc nap vao
      int eleResult = chosenNum.UnsignIntValue() / biChia.UnsignIntValue();
      eleResult = max(1, eleResult);
      MinusValue.setUnsignValue(biChia.UnsignIntValue() * eleResult);
      MinusValue.setNegative(true);
      int var = chia.getStringUnSignValue().size() -
                chosenNum.getStringUnSignValue().size();
      string space = "";
      for (int i = 0; i < var; ++i) {
        space.push_back(' ');
      }
      // Bo sung space dua so den vi tru dung don vi tinh

      MinusValue.pushBackstring(space);
      Result.pushBackstring(to_string(eleResult));
      //      listMinusValue lay nhom so tru cho so vua duoc nhan phia tren
      listMinusValue.push_back(MinusValue);
      listResult.push_back(chia);
      Sum Tinh = *new Sum(chia, MinusValue);
      chia = Tinh.getResult();
      if (chia.UnsignIntValue() < biChia.UnsignIntValue()) {
        listResult.push_back(chia);
      }
      //      convert ket qua va ket hop vao chuoi con lai}
    };
    if (First.isNegative() != Second.isNegative()) {
      Result.setNegative(true);
    }
  }
  void printResult() override {
    PrintResult printer = *new PrintResult(First, Second, Result);
    printer.Devide(listResult, listMinusValue);
  }
  LargeNumber getResult() override { return Result; }
  Division(LargeNumber a, LargeNumber b) {
    input(a, b);
    calculate();
  }
};

class Calculator {
private:
  LargeNumber First;
  LargeNumber Second;
  string Symbol;

public:
  Calculator(string Formula) {
    //    ham dua vao "1234 + 4256"
    vector<string> text = splitString(Formula, " ");
    First = *new LargeNumber(text.at(0));
    Symbol.push_back(text.at(1).at(0));
    Second = *new LargeNumber(text.at(2));
    calculating();
  }
  void calculating() {

    if (Symbol.at(0) == '+') {
      Sum Cong = *new Sum(First, Second);
      Cong.calculate();
      Cong.printResult();
    } else if (Symbol.at(0) == '-') {
      Minus Tru = *new Minus(First, Second);
      Tru.calculate();
      Tru.printResult();
    } else if (Symbol.at(0) == '*') {
      Multiple Nhan = *new Multiple(First, Second);
      Nhan.printResult();
    } else if (Symbol.at(0) == ':') {
      Division Chia = *new Division(First, Second);
      Chia.printResult();
    } else {
      printf("Kiem tra lai bai toan");
    }
  }
};

int main() {
  string basicString;
  cout << "phép tính ( '+' ; '-' ; '*' ; ':' ): ";
  getline(cin, basicString);
  //  basicString = "-109349 : 43"; //test sample
  Calculator Cal = *new Calculator(basicString);

  return 0;
}