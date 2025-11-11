#include <iostream>

int main() {
  std::string input;
  bool is_number;
  
  do {
    is_number = true;
    std::cout << "Enter number" << std::endl;
    std::cin >> input;
    for (int curr = 0; curr < input.length(); ++curr) {
      char curr_s = input[curr];
      if ( curr_s > '9' || curr_s < '0' && curr_s != '.') {
        std::cout << "Your answer incorrect, please try again" << std::endl;
        is_number = false;
        break;
      }
    }
  } while (!is_number);

  double i = stod(input);

  std::cout << i;
}