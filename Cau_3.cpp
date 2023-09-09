//
// Created by Tony Pham on 31/08/2023.
//
#include "CalculatorString.h"
#include "iostream"
#include "stdio.h"
using namespace std;

int main() {
  stringCalculator pheptinh = *new stringCalculator();
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