// Королев ДА группа 417


// Дана целочисленная прямоугольная матрица. Определить количество столбцов, не содержащих ни одного нулевого элемента


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

void inputOfArrayByRandom(int** array, int row, int column) { // Заполнение матрицы случайными элементами
    int  minEl = 0, maxEl = 10;
    short choice;
    bool flag = true;
    while (flag) {
        std::cout << "\n Выберите отрезок, по которому будут вычисляться случайные значения: \n \n";
        std::cout << "1: от 0 до 9 \n";
        std::cout << "2: задать отрезок вручную \n \n";
        std::cin >> choice;
        if (std::cin.fail() || (choice != 1 && choice != 2)) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\n Введите корректные данные \n \n";
        }
        else {
            std::cin.ignore(32767, '\n');
            switch (choice) {
            case 1: {
                std::cout << '\n';
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < column; j++) {
                        array[i][j] = minEl + rand() % (maxEl - minEl);
                    }
                }
                flag = false;
                break;
            case 2: {
                std::cout << '\n';
                while (flag) {
                    std::cout << "Введите минимальное значение \n \n";
                    std::cin >> minEl;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        std::cout << "\n Введите корректные данные \n \n";
                    }
                    else {
                        std::cin.ignore(32767, '\n');
                        while (flag) {
                            std::cout << "\n Введите максимальное значение \n \n";
                            std::cin >> maxEl;
                            if (std::cin.fail()) {
                                std::cin.clear();
                                std::cin.ignore(32767, '\n');
                                std::cout << "\n Введите корректные данные \n \n";
                            }
                            else {
                                std::cin.ignore(32767, '\n');
                                std::cout << '\n';
                                for (int i = 0; i < row; i++) {
                                    for (int j = 0; j < column; j++) {
                                        array[i][j] = minEl + rand() % (maxEl - minEl + 1);
                                    }
                                }
                                flag = false;
                            }
                        }
                    }
                }
                break;
            }
            }
            }
        }
    }
}

void inputOfArrayManually(int** array, int row, int column) { // Заполнение матрицы вручную
    bool flag = true;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            while (flag) {
                std::cout << "\n Введите " << "[" << i << "] [" << j << "] -ый элемент массива ";
                std::cin >> array[i][j];
                if (std::cin.fail() || column <= 0) {
                    std::cin.clear();
                    std::cin.ignore(32767, '\n');
                    std::cout << "\n Введите корректные данные \n \n";
                }
                else {
                    std::cin.ignore(32767, '\n');
                    break;
                }
            }
        }
    }
}

void outputOfArray(int** array, int row, int column) { // Вывод элементов матрицы
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << '\n';
    }
}

int inputOfRow(int row) { // Ввод количества строк в матрице
    while (true) {
        std::cout << "Введите количество строк в массиве: ";
        std::cin >> row;
        if(std::cin.fail() || row <= 0) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\n Введите корректные данные \n \n";
        }
        else {
            std::cin.ignore(32767, '\n');
            return row;
        }
    }
}

int inputOfColumn(int column) { // Ввод количества столбцов в матрице
    while (true) {
        std::cout << "Введите количество столбцов в массиве: ";
        std::cin >> column;
        if(std::cin.fail() || column <= 0) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\n Введите корректные данные \n \n";
        }
        else {
            std::cin.ignore(32767, '\n');
            return column;
        }
    }
}

void countColumnsWithoutZeroes(int** array, int row, int column) { // Подсчет столбцов, в которых нет нулей
    bool flag = true;
    unsigned short counter = 0;
    for (int i = 0; i < column; i++) {
        flag = true;
        for (int j = 0; j < row; j++) {
            if (array[j][i] == 0)
                flag = false;
        }
        if (flag == true)
            counter++;
    }
    std::cout << "\n Столбцов, не содержащих ни одного нулевого элемента: " << counter << '\n';
}

void choiceOfInput(int** array, int row, int column) { // Выбор способа ввода элементов матрицы
    short choice = 0;
    bool flag = true;
    while (flag) {
        std::cout << "\n Выберите способ ввода массива: \n \n";
        std::cout << "1: Ввод случайными числами \n";
        std::cout << "2: Ввод вручную \n \n";
        std::cin >> choice;
        if (std::cin.fail() || ((choice != 1) && (choice != 2))) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\n Введите корректные данные \n \n";
        }
        else {
            std::cin.ignore(32767, '\n');
            switch (choice) {
            case 1: {
                inputOfArrayByRandom(array, row, column);
                flag = false;
            }
            break;
            case 2: {
                inputOfArrayManually(array, row, column);
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
    row = inputOfRow(row);
    column = inputOfColumn(column);
    array = new int* [row]; // Инициализация двумерного динамического массива
    for (int i = 0; i < row; i++) {
        array[i] = new int[column];
    }
    choiceOfInput(array, row, column);
    outputOfArray(array, row, column);
    countColumnsWithoutZeroes(array, row, column);
}
