#include <iostream>

// 1. Sumar dos números enteros recibidos como punteros.
int suma(int* a, int* b) {
    return *a + *b;
}

// 2. Copiar un array a otro usando punteros.
void copiarArray(int* origen, int* destino, int n) {
    for (int i = 0; i < n; i++) {
        *(destino + i) = *(origen + i);
    }
}

// 3. Sumar dos matrices de tamaño m por n usando punteros.
void sumarMatrices(int m, int n, int **A, int **B, int **C) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(*C + n*i + j) = *(*A + n*i + j) + *(*B + n*i + j);
        }
    }
}

// 4. Invertir un array recibido como parámetro usando punteros.
void invertirArray(int* arr, int n) {
    int* inicio = arr;
    int* fin = arr + n - 1;
    while (inicio < fin) {
        int temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        inicio++;
        fin--;
    }
}

int main() {
    // 1. Comprobar la función suma
    int a = 5, b = 7;
    std::cout << "Suma: " << suma(&a, &b) << std::endl;  // Debería imprimir 12

    // 2. Comprobar la función copiarArray
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[5];
    copiarArray(arr1, arr2, 5);
    std::cout << "Copia de array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr2[i] << " ";  // Debería imprimir 1 2 3 4 5
    }
    std::cout << std::endl;

    // 3. Comprobar sumaMatrices (En este caso se usa matriz 2x2)
    int A_values[2][2] = {{1, 2}, {3, 4}};
    int B_values[2][2] = {{4, 3}, {2, 1}};
    int Result_values[2][2] = {0};

    int *A[2], *B[2], *Result[2];

    for(int i = 0; i < 2; i++) {
        A[i] = A_values[i];
        B[i] = B_values[i];
        Result[i] = Result_values[i];
    }

    sumarMatrices(2, 2, A, B, Result);

    std::cout << "Resultado de la suma:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << Result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // 4. Comprobar invertirArray
    int arr3[] = {1, 2, 3, 4, 5};
    invertirArray(arr3, 5);
    std::cout << "Array invertido: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr3[i] << " ";  // Debería imprimir 5 4 3 2 1
    }
    std::cout << std::endl;

    return 0;
}
