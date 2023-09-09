//
// Created by Tony Pham on 04/09/2023.
//

#ifndef TCDL_BT2_LARGENUMBER_H
#define TCDL_BT2_LARGENUMBER_H

#include "iostream"
#include "stdio.h"

using namespace std;

class LargeNumber {
private:
  string _value;
  int _size;
  bool _negative;

public:
  LargeNumber(string newValue) {
    if (newValue.at(0) == '-') {
      _negative = true;
      _value = newValue.erase(0, 1);
    } else {
      _value = newValue;
      _negative = false;
    }
    _size = _value.size();
  }

  void input(string value) {
    clear();
    if (value.at(0) == '-') {
      _negative = true;
      _value = value.erase(0, 1);
    } else {
      _value = value;
      _negative = false;
    }
    _size = _value.size();
  }
  void setNegative(bool negativeSign) { _negative = negativeSign; }

  void setUnsignValue(int intValue) {
    //    Gán giá trị số nguyên cho số lớn
    if (intValue < 0) {
      _negative = true;
      _value = to_string(intValue * (-1));
    } else {
      _value = to_string(intValue);
      _negative = false;
    }
    _size = _value.size();
  }
  string getStringUnSignValue() { return _value; }

  int at(int pos) {
    //    suat ra gia tri tai 1 vi tri
    return to_int(_value.at(pos));
  }

  LargeNumber reverse() {
    //    Đảo giá trị của số lớn
    LargeNumber newLarge(_value);
    std::reverse(newLarge._value.begin(), newLarge._value.end());
    newLarge._negative = this->isNegative();
    return newLarge;
  }

  void clear() {
    //    reset mặc định
    _value = "";
    _size = 0;
    _negative = false;
  }

  LargeNumber() {
    //    default constructor
    _value = "";
    _size = 0;
    _negative = false;
  }

  bool isEmpty() {
    //    Kiểm tra có giá trị không
    if (_value.size() == 0) {
      return true;
    };
    return false;
  }

  string stringValue() {
    //    Suat gia tri cua so sieu lon theo type string
    string Value;
    if (_negative) {
      Value.push_back('-');
    }
    Value = Value + _value;
    return Value;
  }

  int intValue() {
    //     suat so nguyen kèm dấu âm nếu có
    int value = stoi(_value);
    if (_negative) {
      return value * (-1);
    }
    return value;
  }

  int UnsignIntValue() {
    //    suat so nguyen khong kem dau
    return stoi(_value);
  }

  bool isNegative() {
    //    Kiem tra so am
    return _negative;
  }

  int size() {
    //    số ký số không kèm dấu
    _size = _value.size();
    return _size;
  }
  string printFormatValue() {
    //    in theo format 112,312,634
    string formatText, ReverseNumber;
    ReverseNumber = _value;
    std::reverse(ReverseNumber.begin(), ReverseNumber.end());
    for (int i = 0; i < _size; ++i) {
      formatText.push_back(ReverseNumber.at(i));
      if ((i + 1) % 3 == 0 && i + 1 < _size) {
        formatText.push_back(',');
      }
    }
    if (isNegative()) {
      formatText.push_back('-');
    }
    std::reverse(formatText.begin(), formatText.end());
    return formatText;
  }

  int sumElement() {
    //    Tính tổng các số trong chuỗi
    int sum = 0;
    for (char element : _value) {
      sum += to_int(element);
    }
    return sum;
  }

  //  Các function phục vụ phép chia

  void pushBackstring(string Number) {
    for (int i = 0; i < Number.size(); ++i) {
      _value.push_back(Number.at(i));
    }
    _size = _value.size();
  }
  void pushBackLagNum(LargeNumber Number) {
    for (int i = 0; i < Number._value.size(); ++i) {
      _value.push_back(Number._value.at(i));
    }
  }

  LargeNumber findAvalableNumber(LargeNumber biChia) {
    //    Tìm số khả thi
    LargeNumber Number;
    for (int i = 0; i < _value.size(); ++i) {
      Number._value.push_back(_value.at(i));
      int first = Number.intValue();
      int second = biChia.intValue();
      if (first > second) {
        break;
      }
    }
    return Number;
  }
};

#endif // TCDL_BT2_LARGENUMBER_H
