#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int size, choice;
int* arr = 0;
char n_file[49];
FILE* file;


void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void writeArrayToFile(int arr[], int size) {
    printf("Введите имя файла для сохранения массива в файл: ");
    scanf("%s", n_file);
    if (sizeof(n_file) > 49) {
        printf("Имя файла превышает максимально допустимую длину (49)!\n");
        return;
    }
    if ((file = fopen(n_file, "w")) == NULL)
    {
        printf("\nНевозможно открыть файл для записи: %s\n", n_file);
        _getch();
        return;
    }
    fprintf(file, "%d\n", size);
    for (int i = 0; i < size; i++)
        fprintf(file, "%d ", arr[i]);

    fclose(file);
    printf("Запись массива завершена!\n");
}
void readArrayFromFile() {
    printf("Введите имя файла для чтения массива из файла: ");
    scanf("%s", n_file);
    if (sizeof(n_file) > 49) {
        printf("Имя файла превышает максимально допустимую длину (49)!");
        return;
    }
    if ((file = fopen(n_file, "r+")) == 0)
    {
        printf("Невозможно открыть файл для чтения %s\n", n_file);
        _getch();
        return;
    }
    fscanf(file, "%d", &size);
    arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
    printf("Чтение массива завершено!\n");
}

void helloScreen() {
    printf("Практическая работа\nНа тему: \"Сортировка пузырьком (bubble sort)\"\n\nВыполнили студенты группы 24ВВВ1: Максимов Олег, Белов Павел, Санжаренко Максим.\n\n");
    system("PAUSE");
}

void main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    helloScreen();
    clock_t start, end;
    double time_spent = 0.0;
    system("cls");
    do {
        printf("\tМеню\n");
        printf("1. Показать массив\n");
        printf("2. Отсортировать массив\n");
        printf("3. Записать массив в файл\n");
        printf("4. Считать массив из файла\n");
        printf("5. Показать время сортировки\n");
        printf("6. Создать новый массив\n");
        printf("7. Выход\n");
        printf("Введите выбор: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            system("cls");
            printf("Массив:\n ");
            for (int i = 0; i < size; i++) {
                printf("%d) %d\n ", i+1, arr[i]);
            }
            printf("\n");
            break;
        case 2:
            system("cls");
            start = clock();
            bubbleSort(arr, size);
            end = clock();
            printf("Массив отсортирован!\n");
            time_spent += (double)(end - start) / CLOCKS_PER_SEC;
            printf("\n");
            break;
        case 3:
            system("cls");
            writeArrayToFile(arr, size);
            break;
        case 4:
            system("cls");
            if (arr != NULL) 
            {
                free(arr);
            }
            readArrayFromFile();
            break;
        case 5:
            system("cls");
            if (time_spent == 0) {
                printf("Сначала отсортируйте массив!\n");
                break;
            }
             printf("Общее время сортировки: %f\n", time_spent);
             break;
        case 6:
            system("cls");
            free(arr);
            printf("Введите размер массива: ");
            scanf("%d", &size);
            arr = (int*)malloc(size * sizeof(int));
            if (arr == NULL) {
                printf("Не удалось выделить память!\n");
                return;
            }
            for (int i = 0; i < size; i++) {
                arr[i] = rand();
            }
            break;
        case 7:
             system("cls");
             printf("До свидания!\n");
             break;
        default:
             system("cls");
             printf("Некорректный ввод!\n");
             break;
        }
    } while (choice != 7);

    getchar();
}
