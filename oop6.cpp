#include <iostream>
using namespace std;


template <class T>
void selectionSort(T arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[i]) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


template <typename T>
void displayArray(T arr[], int N) {
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, N;

    cout << "Choose the type of array to sort:\n";
    cout << "1. Integer array\n";
    cout << "2. Float array\n";
    cout << "3. Character array\n";
    cin >> choice;

    cout << "Enter the size of the array : ";
    cin >> N;

    switch (choice) {
        case 1: {
            int arr[N];
            cout << "Enter " << N << " integers: ";
            for (int i = 0; i < N; ++i) {
                cin >> arr[i];
            }

            cout << "Original array: ";
            displayArray(arr, N);

            selectionSort(arr, N);

            cout << "Sorted array: ";
            displayArray(arr, N);
            break;
        }
        case 2: {
            float arr[N];
            cout << "Enter " << N << " float numbers: ";
            for (int i = 0; i < N; ++i) {
                cin >> arr[i];
            }

            cout << "Original array: ";
            displayArray(arr, N);

            selectionSort(arr, N);

            cout << "Sorted array: ";
            displayArray(arr, N);
            break;
        }
        case 3: {
            char arr[N];
            cout << "Enter " << N << " characters: ";
            for (int i = 0; i < N; ++i) {
                cin >> arr[i];
            }

            cout << "Original array: ";
            displayArray(arr, N);

            selectionSort(arr, N);

            cout << "Sorted array: ";
            displayArray(arr, N);
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
