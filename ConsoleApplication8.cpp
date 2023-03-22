//1) Напишите функцию swap, которая меняет значения переданных аргументов
//Например, после вызова swap(a, b) в переменной a должно оказаться значение b, а в переменной b значение a

#include <iostream>
void swap(int& nu1, int& nu2);
int main()
{
    int num1, num2;
    std::cout << "Enter first number:";
    std::cin >> num1;
    std::cout << "Enter second number:";
    std::cin >> num2;
    swap(num1, num2);
    std::cout << "First: " << num1 << " " << "Second: " << num2;
    return 0;
}

void swap(int& nu1, int& nu2)
{
    int temp;
    temp = nu1;
    nu1 = nu2;
    nu2 = temp;
}

//2) Дано число n. Требуется создать массив a из n целых чисел и указатели на первый pa и последний pla элементы этого массива.
//Нужно поменять с их помощью первый и последний элементы массива местами и вывести получившийся массив.
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int* a = new int[n];
    int* pa = &a[0];
    int* pla = &a[n - 1];

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }


    int temp = *pa;
    *pa = *pla;
    *pla = temp;

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }

    delete[] a;
    return 0;
}

//3) Дан указатель: double **p = 0; Выполните следующие задания (решения можно оформлять внутри функции main): 
//*создайте конструкцию, изображенную на рисунке;
//*выведите число, указанное в квадратике, на экран;
//*после этого удалите все динамические объекты.
#include <iostream>

int main(void) {

    double** p = 0;
    *(*(p = new double*) = new double) = 2;

    std::cout << **p << std::endl;

    delete* p;

    delete p;

}

//4) Ввести массив, состоящий из 12 элементов действительного типа. Расположить элементы в порядке убывания.
//Определить количество проиcшедших при этом перестановок.
#include <iostream>

int main()
{
    int A[12];
    int n = 12, i;

    for (i = 1; i < n; i++)
    {
        A[i] = rand() % 101 - 50;
        std::cout << A[i] << " ";
    }

    int count = 0;
    for (int j = 1; j < 12; j++)
    {
        for (int j = 1; j < 12; j++)
        {
            if (A[j] > A[j - 1])
            {
                double d = A[j - 1];
                A[j - 1] = A[j];
                A[j] = d;

                ++count;
            }
        }
    }

    std::cout << "\n";

    for (int k = 0; k < 12; k++)
    {
        std::cout << A[k] << " ";
    }

    std::cout << "\n" << count;

    return 0;
}
//5) Переписать элементы одномерного массива в другой массив такого же размера следующим образом: 
// сначала должны идти все отрицательные элементы исходного массива, а затем все остальные. 
// Использовать только один проход по исходному массиву. Сохранить тот порядок среди положительных
//  и среди отрицательных элементов в результирующем массиве, который был в исходном массиве.
//Применить данный алгоритм к трем заданным массивам.
#include <iostream>

int main() {
    int arr[] = { -10, 3, 0, -2, 22 };

    const int size = sizeof(arr) / sizeof(int);

    int* res = new int[size];

    int posNeg = 0;
    int posPos = size - 1;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            res[posNeg] = arr[i];
            posNeg++;
        }
        else {
            res[posPos] = arr[i];
            posPos--;
        }
    }

    for (int i = 0; i < size; i++) {
        std::cout << res[i] << " ";
    }

    delete[] res;

    return 0;
}


//6) Ввести массив, состоящий из 14 элементов действительного типа. Поменять местами
//первую половину со второй.Определить количество произведенных при этом перестановок.

#include <iostream>

int main()
{
    const int d = 14, half = d / 2;
    int s[d];
    int moves = 0;
    std::cout << "Enter elements:\n";
    for (int* i = s; i != s + d; i++)
    {
        std::cin >> *i;
    }
    for (int* i = s; i != s + half; i++)
    {
        int tmp = *i;
        *i = *(i + half);
        *(i + half) = tmp;
        moves += 3;
    }
    std::cout << std::endl;
    for (int* i = s; i != s + d; i++)
    {
        std::cout << *i << "  ";
    }
    std::cout << std::endl << moves << std::endl;
}
//7) Определить количество локальных минимумов в заданном числовом массиве. 
//(Локальный минимум в числовом массиве – это последовательность
//трех рядом стоящих чисел, в которой среднее число меньше стоящих слева и справа от него).
#include <iostream>

int main()
{
    const int size = 10;
    int n[size], count = 0;
    for (int i = 0; i < size; i++)
    {
        n[i] = rand() % 99 + 1;
        std::cout << n[i] << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
    {
        if (i == 0 && n[i] < n[i + 1]) count++;
        else if (i > 0 && i < size - 1 && n[i] < n[i - 1] && n[i] < n[i + 1]) count++;
        else if (i == size - 1 && n[i] < n[i - 1]) count++;
    }
    std::cout << "Количество локальных минимумов: " << count << std::endl;

    return 0;
}
//8) Дана матрица. Известно, что в каждой строке этой матрицы присутствуют два и только два нулевых элемента. 
//Для каждой строки матрицы подсчитать сумму элементов,
//заключенных между этими двумя нулями. Применить функцию, рассматривающую строки матрицы как одномерные массивы.
#include <iostream>

void sumBetweenZeros(int* arr, int size) {
    int firstZeroIndex = -1;
    int secondZeroIndex = -1;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == 0) {
            if (firstZeroIndex == -1) {
                firstZeroIndex = i;
            }
            else {
                secondZeroIndex = i;
                break;
            }
        }
    }
    int sum = 0;
    for (int i = firstZeroIndex + 1; i < secondZeroIndex; i++) {
        sum += *(arr + i);
    }
    std::cout << "Sum between zeros: " << sum << std::endl;
}

int main() {
    const int rows = 3;
    const int cols = 4;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        sumBetweenZeros(matrix[i], cols);
        delete[] matrix[i];
    }
        
    delete[] matrix;
    return 0;
}
//9) Ввести массив, состоящий из 15 элементов целого типа. Упорядочить
//массив так, чтобы все отрицательные числа были расположены вначале
//по возрастанию, а все положительные – в конце по убыванию.
#include <iostream>

void sortArray(int* arr, int size) {
    int negIndex = 0;
    int posIndex = size - 1;
    while (negIndex < posIndex) {
        while (*(arr + negIndex) < 0 && negIndex < size) {
            negIndex++;
        }
        while (*(arr + posIndex) >= 0 && posIndex >= 0) {
            posIndex--;
        }
        if (negIndex < posIndex) {
            int temp = *(arr + negIndex);
            *(arr + negIndex) = *(arr + posIndex);
            *(arr + posIndex) = temp;
        }
    }
    int negEnd = negIndex;
    int posStart = negEnd;
    for (int i = 0; i < negEnd - 1; i++) {
        for (int j = i + 1; j < negEnd; j++) {
            if (*(arr + i) > *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
    for (int i = posStart; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i) < *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

int main() {
    const int size = 15;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        std::cin >> *(arr + i);
    }
    sortArray(arr, size);
    for (int i = 0; i < size; i++) {
        std::cout << *(arr + i) << " ";
    }
    delete[] arr;
    return 0;
}
//10) Ввести два массива действительных чисел. Определить максимальные элементы в каждом массиве и поменять их местами.
#include <iostream>
#include <ctime>

int main()
{
    srand((int)time(0));
    size_t n, m;
    std::cout << "Size matrix1: "; std::cin >> n;
    std::cout << "Size matrix2: "; std::cin >> m;

    double* a = new double[n], maxa = 0;
    double* b = new double[m], maxb = 0;

    for (size_t i = 0; i < n; i++)
    {
        a[i] = rand() % 11 + 1;
        if (i == 0 || a[i] > maxa) maxa = a[i];
    }
    std::cout << " " << "maxa=" << maxa << "\n";

    for (size_t i = 0; i < m; i++)
    {
        b[i] = rand() % 21 + 1;
        if (i == 0 || b[i] > maxb) maxb = b[i];
    }
    std::cout << " " << "maxb=" << maxb << "\n";
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] == maxa) a[i] = maxb;
        std::cout << a[i] << " ";
    }
    std::cout << "\n";

    for (size_t i = 0; i < m; i++)
    {
        if (b[i] == maxb) b[i] = maxa;
        std::cout << b[i] << " ";
    }


    delete[]b;
    delete[]a;
    return 0;
}
//11) Сдвинуть циклически столбцы матрицы на один столбец вправо. 
#include <iostream>

void shiftColumns(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int temp = matrix[i][cols - 1];
        for (int j = cols - 1; j > 0; j--) {
            matrix[i][j] = matrix[i][j - 1];
        }
        matrix[i][0] = temp;
    }
}

int main() {
    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    shiftColumns(matrix, rows, cols);
    std::cout << "Shifted matrix:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
//12) В матрице найти строки с максимальной и минимальной суммами элементов.

#include <iostream>

int main() {
    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int maxSum = -1000000, minSum = 1000000;
    int maxRow, minRow;

    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
        if (sum < minSum) {
            minSum = sum;
            minRow = i;
        }
    }

    std::cout << "Row with maximum sum: ";
    for (int j = 0; j < cols; j++) {
        std::cout << matrix[maxRow][j] << " ";
    }
    std::cout << std::endl;

    std::cout << "Row with minimum sum: ";
    for (int j = 0; j < cols; j++) {
        std::cout << matrix[minRow][j] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}

//13. Merge sorted array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int* temp = new int[m + n];

        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                temp[k++] = nums1[i++];
            }
            else {
                temp[k++] = nums2[j++];
            }
        }


        while (i < m) {
            temp[k++] = nums1[i++];
        }
        while (j < n) {
            temp[k++] = nums2[j++];
        }


        for (int i = 0; i < m + n; i++) {
            nums1[i] = temp[i];
        }

        delete[] temp;
    }
};

//14 Best time to buy and sell stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minP = 1000000;

        for (int i = 0; i < prices.size(); i++) {
            minP = min(minP, prices[i]);
            if (prices[i] > minP) {
                maxP = max(maxP, prices[i] - minP);
            }
        }

        return maxP;

    }
};
//15 Pascals triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for (int i = 0; i < numRows; i++)
        {
            result[i].resize(i + 1);
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 or j == i)
                    result[i][j] = 1;
                else
                    result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
        return result;
    }
};

