// Королев ДА 417 группа

/*
* «Ханойская башня». Доска имеет три колышка. На первом нанизано M дисков убывающего вверх диаметра.
* Расположить диски в том же порядке на другом колышке. Диски можно перекладывать с колышка на колышек по одному. 
* Класть больший диск на меньший не разрешается. По запросу пользователя программа должна продемонстрировать правильную раскладку дисков.
*/

#include <iostream>
#include <limits.h>

// input reset
void resetInput() {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "\nВведите корректные данные \n \n";
}

// tabulation of blank space in amount of tab
void tabulation(int** array, int row, int column, int tab) {
    for(; tab > 0; tab--) 
        std::cout << ' ';
}

// output of array
void arrayOutput(int** array, int row, int column, int maxCircle) {
    int tab;    // the length of the indentation 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            tab = ((maxCircle - array[i][j]) / 2);    // calculation of indentation for element 
            tabulation(array, row, column, tab);
            if(array[i][j] == 0)
                std::cout << '|';
            else {
                for(int temp = array[i][j]; temp > 0; temp--)
                    std::cout << '-';
            }
            tabulation(array, row, column, tab);
        }
        std::cout << '\n';
    }
    std::cout << "\n \n";
}

//moving disk from a to b
void moveDisk(int** array, int tempHeight, int height, int a, int b, int row, int column, int maxCircle) {
    int height1 = tempHeight - 1;    // the vertical location of the disk from which it will move
    int height2 = 0;    // the vertical location of the disk where it will move
    bool flag = true;    // boolean flag for loop
    while(flag) {
        if(array[height1][b] > array[height2][a] && array[height1][b] != 0)    // movement of disk upwards if there is a disk where the original disk is moved 
            height1--;
        else {
            while(flag) {
                if(array[height2][a] == 0) 
                    height2++;
                else {
                    array[height1][b] = array[height2][a];    // replacing of disks
                    std::cout << "Переставляю диск длиной " << array[height2][a] << " в " << height1 << " " << b << "\n \n";
                    array[height2][a] = 0;    // zeroing of element where there is no more disk
                    arrayOutput(array, row, column, maxCircle);
                    flag = false;
                }
            }
        }
    }
}

// moving tower from a to c
void moveTower(int** array, int tempHeight, int height, int a, int b, int c, int row, int column, int maxCircle) {
    if (height > 0) {
        moveTower(array, tempHeight, height - 1, a, c, b, row, column, maxCircle);
        moveDisk(array, tempHeight, height, a, c, row, column, maxCircle);
        moveTower(array, tempHeight, height - 1, b, a, c, row, column, maxCircle);
    }
}

// filling of array
void arrayFill(int** array, int row, int column) {
    int ring = 1;    // the length of the disk 
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            if(j == 0) {
                array[i][j] = ring;
                ring = ring + 2;
            }
            else 
                array[i][j] = 0;
        }
    }
}

// input of amount of disks
int rowInput(int row) {
    bool flag = true;    //bool flag for loop
    std::cout << "Введите число дисков \n \n";
    while(flag) {
        std::cin >> row;
        if(std::cin.fail() || row <= 0 || row > INT_MAX)    // checking incorrectly entered data
          resetInput();
        else if(row > 16) {
          std::cout << "\nКоличество дисков не должно быть больше 16\n\n";
          resetInput();
        }
        else {
            std::cin.ignore(INT_MAX, '\n');    // clearing the buffer of garbage
            std::cout <<'\n';
            flag = false;
        }
    }
    return row;
}

int main() {
    int a;    // rod #1
    int b;    // rod #2
    int c;    // rod #3
    int row;  // number of disks
    int column = 3;   // total number of rods
    int maxCircle;
    row = rowInput(row);
    int** array;
    array = new int* [row];
    for (int i = 0; i < row; i++) {
        array[i] = new int[column];
    }
    arrayFill(array, row, column);
    maxCircle = array[row - 1][0];
    arrayOutput(array, row, column, maxCircle);
    a = 0;
    b = 1;
    c = 2;
    moveTower(array, row, row, a, b, c, row, column, maxCircle);
}