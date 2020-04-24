// Королев ДА группа 417


// Дана целочисленная прямоугольная матрица. Определить количество столбцов, не содержащих ни одного нулевого элемента


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <limits.h>

void resetInput() {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "\n Введите корректные данные \n \n";
}

void inputInvitation() {
    std::cout << "\n Выберите отрезок, по которому будут вычисляться случайные значения: \n \n";
    std::cout << "1: от 0 до 9 \n";
    std::cout << "2: задать отрезок вручную \n \n";
}

void randomRange(int** array, int row, int column, int minElement, int maxElement) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            array[i][j] = minElement + rand() % (maxElement - minElement + 1);
        }
    }
}

void inputRandomRange(int** array, int row, int column, int minElement, int maxElement) {
    std::cout << '\n';
    randomRange(array, row, column, minElement, maxElement);
}

void inputRange(int** array, int minElement, int maxElement, int row, int column) {
    std::cout << '\n';
    bool flag;
    flag = true;
    while (flag) {
        std::cout << "Введите минимальное значение \n \n";
        std::cin >> minElement;
        if (std::cin.fail()) {
            resetInput();
        }
        else {
            std::cin.ignore(INT_MAX, '\n');
            while (flag) {
                std::cout << "\n Введите максимальное значение \n \n";
                std::cin >> maxElement;
                if (std::cin.fail())
                    resetInput();
                else {
                    std::cin.ignore(INT_MAX, '\n');
                    std::cout << '\n';
                    randomRange(array, row, column, minElement, maxElement);
                    flag = false;
                }
            }
        }
    }
}

// Заполнение матрицы случайными элементами
void arrayRandomFill(int** array, int row, int column) { 
    int  minElement = 0, maxElement = 9;
    bool flag;
    short choice;
    flag = true;
    while (flag) {
        inputInvitation();
        std::cin >> choice;
        if (std::cin.fail() || (choice != 1 && choice != 2)) {
            resetInput();
        }
        else {
            std::cin.ignore(SHRT_MAX, '\n');
            switch (choice) {
            case 1: 
                inputRandomRange(array, row, column, minElement, maxElement);
                flag = false;
                break;
            case 2: 
                inputRange(array, minElement, maxElement, row, column);
                flag = false;
                break;
            }
        }
    }
}

// Заполнение матрицы вручную
void arrayInput(int** array, int row, int column) { 
    bool flag;
    flag = true;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            while (flag) {
                std::cout << "\n Введите " << "[" << i << "] [" << j << "] -ый элемент массива ";
                std::cin >> array[i][j];
                if (std::cin.fail() || column <= 0) {
                    resetInput();
                }
                else {
                    std::cin.ignore(INT_MAX, '\n');
                    break;
                }
            }
        }
    }
}

// Вывод элементов матрицы
void arrayOutput(int** array, int row, int column) { 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << '\n';
    }
}

// Ввод количества строк в матрице
int rowInput(int row) { 
    while (true) {
        std::cout << "Введите количество строк в массиве: ";
        std::cin >> row;
        if(std::cin.fail() || row <= 0) {
            resetInput();
        }
        else {
            std::cin.ignore(INT_MAX, '\n');
            return row;
        }
    }
}

// Ввод количества столбцов в матрице
int columnInput(int column) { 
    while (true) {
        std::cout << "Введите количество столбцов в массиве: ";
        std::cin >> column;
        if(std::cin.fail() || column <= 0) {
            resetInput();
        }
        else {
            std::cin.ignore(INT_MAX, '\n');
            return column;
        }
    }
}

short zeroCounter(bool flag, short counter) {
    if (flag == true)
        counter++;
    return counter;
}

short checkZeroes(int** array, int row, int column, bool flag, short counter) {
    for (int i = 0; i < column; i++) {
        flag = true;
        for (int j = 0; j < row; j++) {
            if(array[j][i] == 0)
                flag = false;
        }
        counter = zeroCounter(flag, counter);
    }
    return counter;
}

// Подсчет столбцов, в которых нет нулей
void countColumnsWithoutZeroes(int** array, int row, int column) { 
    bool flag;
    flag = true;
    short counter = 0;
    counter = checkZeroes(array, row, column, flag, counter);
    std::cout << "\n Столбцов, не содержащих ни одного нулевого элемента: " << counter << '\n';
}

// Выбор способа ввода элементов матрицы
void inputChoice(int** array, int row, int column) { 
    short choice = 0;
    bool flag;
    flag = true;
    while (flag) {
        std::cout << "\n Выберите способ ввода массива: \n \n";
        std::cout << "1: Ввод случайными числами \n";
        std::cout << "2: Ввод вручную \n \n";
        std::cin >> choice;
        if (std::cin.fail() || ((choice != 1) && (choice != 2))) {
            resetInput();
        }
        else {
            std::cin.ignore(SHRT_MAX, '\n');
            switch (choice) {
            case 1: {
                arrayRandomFill(array, row, column);
                flag = false;                                   
            }
            break;
            case 2: {
                arrayInput(array, row, column);
                flag = false;
            }
            break;
            }
        }
    }
}

int main()
{
    SetConsoleCP(1251); // Смена локали для корректного отображения русских символов в Visual Studio
    SetConsoleOutputCP(1251); // Смена локали для корректного отображения русских символов в Visual Studio
    srand(time(NULL));
    int row = 0, column = 0;
    int** array;
    row = rowInput(row);
    column = columnInput(column);
    array = new int* [row]; // Инициализация двумерного динамического массива
    for (int i = 0; i < row; i++) {
        array[i] = new int[column];
    }
    inputChoice(array, row, column);
    arrayOutput(array, row, column);
    countColumnsWithoutZeroes(array, row, column);
}
