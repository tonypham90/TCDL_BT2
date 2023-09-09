//
// Created by Tony Pham on 31/08/2023.
//
#include "iostream"
#include "stdio.h"
using namespace std;

static string NhapSo() {
  string result;
  cout << "Giá trị = ";
  cin >> result;
  return result;
}
static int to_int(char CharNumber) { return CharNumber - '0'; }
static char to_char_number(int Number) { return '0' + Number; }

static string addSpace(string value, int noSpace) {
  //  Bo sung space phuc vu in gia tri
  if (value.size() < noSpace) {
    int var = noSpace - value.size();
    std::reverse(value.begin(), value.end());
    for (int i = 0; i < var; ++i) {
      value.push_back(' ');
    }
    std::reverse(value.begin(), value.end());
  }
  return value;
}

class calculator {
private:
  string _a, _b, _result, _symbol;

public:
  calculator() {
    _a = "0";
    _b = "0";
    _result = "0";
    _symbol = "";
  };
  void setSoThuNhat(string SoThuNhat) { _a = SoThuNhat; }
  void setSoThuHai(string SoThuHai) { _b = SoThuHai; }
  string exportResult() { return _result; };

  void Tong() {
    string Soa = _a;
    std::reverse(Soa.begin(), Soa.end());
    string Sob = _b;
    std::reverse(Sob.begin(), Sob.end());
    string result = "";
    int length_Math = max(_a.size(), _b.size());
    int extendPoint = 0;
    for (int i = 0; i < length_Math; ++i) {
      int ele_a = 0;
      int ele_b = 0;
      int sum = 0;
      if (i >= Soa.size()) {
        ele_a = 0;
      } else {
        char c_ele_a = Soa.at(i);
        ele_a = c_ele_a - '0';
      }

      if (i >= Sob.size()) {
        ele_b = 0;
      } else {
        char c_ele_b = Sob.at(i);
        ele_b = c_ele_b - '0';
      }
      sum = ele_a + ele_b + extendPoint;
      if (sum > 9) {
        extendPoint = sum / 10;
        int importValue = sum % 10;
        result.push_back('0' + importValue);
      } else {
        result.push_back('0' + sum);
        extendPoint = 0;
      }
    }
    std::reverse(result.begin(), result.end());
    this->_result = result;
    this->_symbol = "+";
  }

  void Hieu() {
    string Soa = _a;
    std::reverse(Soa.begin(), Soa.end());
    string Sob = _b;
    std::reverse(Sob.begin(), Sob.end());
    string result = "";
    int length_Math = max(_a.size(), _b.size());
    int extendPoint = 0;
    for (int i = 0; i < length_Math; ++i) {
      int ele_a = 0;
      int ele_b = 0;
      int sum = 0;
      if (i >= Soa.size()) {
        ele_a = 0;
      } else {
        char c_ele_a = Soa.at(i);
        ele_a = c_ele_a - '0';
      }

      if (i >= Sob.size()) {
        ele_b = 0;
      } else {
        char c_ele_b = Sob.at(i);
        ele_b = c_ele_b - '0';
      }
      sum = ele_a - ele_b - extendPoint;
      if (sum < 0) {
        extendPoint = 1;
        int importValue = sum * (-1);
        result.push_back('0' + importValue);
      } else {
        result.push_back('0' + sum);
        extendPoint = 0;
      };
    }
    if (extendPoint == 1) {
      result.push_back('-');
    }
    std::reverse(result.begin(), result.end());
    this->_result = result;
    this->_symbol = "-";
  }

  // Visualization
  void print_math() {
    int space = max(_a.size(), _b.size());
    if (space < _result.size()) {
      space = _result.size();
    };
    space += 1;
    string value_a, value_b, value_result;
    value_a = _a;
    value_b = _b;
    value_result = _result;

    value_a = addSpace(value_a, space);
    value_b = addSpace(value_b, space);
    value_result = addSpace(value_result, space);
    string straight;
    for (int i = 0; i < space; ++i) {
      straight.push_back('-');
    }
    cout << value_a << endl
         << _symbol << endl
         << value_b << endl
         << straight << endl
         << value_result;
  }
  void Nhan() {
    calculator pheptinh;
    vector<string> list_number;
    string first_number = _a;
    string second_number = _b;
    std::reverse(first_number.begin(), first_number.end());
    std::reverse(second_number.begin(), second_number.end());
    for (int i = 0; i < second_number.size(); ++i) {
      int number_ele_b = second_number.at(i) - '0';
      string Number;
      int extendPoint;
      for (int j = 0; j < i; ++j) {
        Number.push_back('0');
      };
      for (char j : first_number) {
        int number_ele_a = to_int(j);
        int aMultEleB = number_ele_a * number_ele_b;
        if (aMultEleB > 9) {
          extendPoint = aMultEleB / 10;
          Number.push_back(to_char_number(aMultEleB % 10));
        } else {
          Number.push_back(to_char_number(aMultEleB));
          extendPoint = 0;
        }
      };
      std::reverse(Number.begin(), Number.end());
      list_number.push_back(Number);
    }
    _result = "0";
    for (auto value : list_number) {
      pheptinh.setSoThuNhat(_result);
      pheptinh.setSoThuHai(value);
      pheptinh.Tong();
      _result = pheptinh.exportResult();
    }
    _symbol = '*';
  }
  void Chia() { printf("Coming Soon"); }
};

int main() {
  calculator pheptinh = *new calculator();
  cout << "Nhập Số thứ nhất" << endl;
  string So1 = NhapSo();
  string toan;
  cout << "hàm tính (+ ; - ; * ; / ): ";
  cin >> toan;
  cout << "Nhập Số thứ hai" << endl;
  string So2 = NhapSo();
  pheptinh.setSoThuNhat(So1);
  pheptinh.setSoThuHai(So2);
  if (toan == "+") {
    pheptinh.Tong();
  } else if (toan == "-") {
    pheptinh.Hieu();
  } else if (toan == "*")
    pheptinh.Nhan();
  else
    pheptinh.Chia();
  pheptinh.print_math();
  return 0;
}