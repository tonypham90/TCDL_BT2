//
// Created by Tony Pham on 29/08/2023.
// Bài tập 4.1.1
#include "stdio.h"
#include <iostream>
using namespace std;

class DaThuc {
private:
  vector<float> list_parameters; // Bac moi tham so tuong ung index
  float Bac_cao_nhat;

public:
  DaThuc() {
    this->list_parameters = *new vector<float>;
    this->Bac_cao_nhat = 0;
    inputDaThuc();
    printDaThuc();
    SolveDatThuc();
  };

  void inputDaThuc() {
    string Bac;
    std::cout << "Nhập bậc lớn nhất của đa thức:";
    std::cin >> Bac;
    //        scanf("%d", Bac);
    this->Bac_cao_nhat = stoi(Bac);
    std::cout << "Nhập tham số:" << endl;
    for (int i = this->Bac_cao_nhat; i >= 0; --i) {
      float input;
      string text;
      std::cout << "Tham số bậc " << i << ": ";
      std::cout << "Giá trị: ";
      cin >> text;
      input = std::stof(text);
      this->list_parameters.push_back(input);
    }
    std::reverse(this->list_parameters.begin(), this->list_parameters.end());
  };
  void printDaThuc() {
    std::cout << "Đa Thức:" << endl;
    string basicString = "";
    for (int i = this->list_parameters.size() - 1; i >= 0; --i) {
      if (i == list_parameters.size() - 1) {
        basicString = basicString + to_string(list_parameters.at(i)) + "x^" +
                      to_string(i);
        continue;
      }
      if (list_parameters.at(i) == 0) {
        continue;
      } else if (list_parameters.at(i) < 0) {
        basicString = basicString + " + (" + to_string(list_parameters.at(i)) +
                      ")" + "x^" + to_string(i);
      } else {
        basicString = basicString + " + " + to_string(list_parameters.at(i)) +
                      "x^" + to_string(i);
      }
    }
    cout << basicString << endl;
  };

  void CalDaThuc(const float &x) {
    float result = this->list_parameters.at(this->Bac_cao_nhat);
    float i = this->Bac_cao_nhat;
    while (i > 0) {
      result = this->list_parameters.at(i - 1) + x * result;
      --i;
    }
    cout << "kết quả phương trình: " << to_string(result) << endl;
  }

  void SolveDatThuc() {
    float x;
    bool Continuos = true;
    while (Continuos) {
      cout << "x = ";
      cin >> x;
      CalDaThuc(x);
      string answer;
      cout << "Bạn có muốn gán giá trị khác?(y/n): ";
      cin >> answer;
      if (answer != "y") {
        Continuos = false;
      };
    }
  }
};

int main() {
  DaThuc();
  return 0;
};