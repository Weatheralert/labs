#include <iostream>
#include <cstring>

char* combine_half_cpp(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int half_len1 = len1 / 2;
    int half_len2 = len2 / 2;

    // Выделяем память для новой строки
    char* result = new char[half_len1 + half_len2 + 1];

    // Копируем первую половину первой строки
    strncpy(result, str1, half_len1);
    // Копируем первую половину второй строки
    strncpy(result + half_len1, str2, half_len2);
    
    // Завершаем строку нулевым байтом
    result[half_len1 + half_len2] = '0'; 

    return result;
}

int main() {
    const char* str1 = "HelloWorld";
    const char* str2 = "Goodbye";

    char* result = combine_half_cpp(str1, str2);
    
    std::cout << "Результат: " << result << std::endl;

    // Освобождаем выделенную память
    delete[] result; 

    return 0;
}
