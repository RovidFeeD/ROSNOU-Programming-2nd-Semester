/*Удвоить положительные элементы массива, если минимальный по модулю элемент массива меньше 50*/

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

/*void input(int *mas) {
  for (int i = 0; i < 10; i++) {
    std::cout << "Введите " << i + 1 << " элемент массива ";
    std::cin >> mas[i];
  }
}*/

void input(int* array) {
  for(int i = 0; i <= 10; i++) {
    array[i] = 45 + rand() % 11;
  }
}


void output(int *mas) {
  for (int i = 0; i < 10; i++) {
    std::cout << mas[i];
    std::cout << " ";
  }
  std::cout << "\n";
}

void sort(int *mas) {
  int temp = 0;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9 - i; j++) {
      if (mas[j] > mas[j + 1]) {
        temp = mas[j];
        mas[j] = mas[j + 1];
        mas[j + 1] = temp;
      }
    }
  }
}

void double_el(int *mas, int min_el) {
  if (min_el < 50) {
    for (int i = 0; i <= 9; i++) {
      if (mas[i] > 0)
        mas[i] *= 2;
    }
  }
}

void choice_of_input() {
  int choice = -1;
  

int main() {
  srand(time(NULL));
  int array[10];
  //choice_of_input();
  input(array);
  std::cout << "\n" << "Исходный массив " << "\n" << "\n";
  output(array);
  int min_el;
  sort(array);
  std::cout << "\n" << "Отсортированный массив" << "\n" << "\n";
  output(array);
  min_el = array[0];
  std::cout << "\n" << min_el << " - Минимальный элемент массива" << "\n" << "\n";
  double_el(array, min_el);
  std::cout << "Полученный массив " << "\n";
  output(array);
}