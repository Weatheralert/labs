#include <iostream>
#include <cstring>

extern "C" char* combine_half_asm(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int half_len1 = len1 / 2;
    int half_len2 = len2 / 2;

    // Выделяем память для новой строки
    char* result = new char[half_len1 + half_len2 + 1];
    
    asm (
        "mov %[src1], %%rsi;"   // Указатель на первую строку
        "mov %[src2], %%rdi;"   // Указатель на вторую строку
        "mov %[half_len1], %%ecx;"   // Длина первой половины первой строки
        "mov %[half_len2], %%edx;"   // Длина первой половины второй строки
        "cld;"                  // Устанавливаем направление при копировании
        "mov %[result], %%rax;" // Указатель на результат

        // Копируем первую половину первой строки
        "rep movsb;"           // Копируем первую половину первой строки

        // Копируем первую половину второй строки
        "rep movsb;"           // Копируем первую половину второй строки

        // Завершаем строку нулевым байтом
        "movb $0, (%%rax);"    // Завершаем строку нулевым байтом
        :                       // Нет выходных операндов
        : [src1] "r" (str1), [src2] "r" (str2), [result] "r" (result), 
          [half_len1] "r" (half_len1), [half_len2] "r" (half_len2)
        : "%rsi", "%rdi", "%rax", "%ecx", "%edx"
    );

    return result;
}

int main() {
    const char* str1 = "HelloWorld";
    const char* str2 = "Goodbye";

    char* combined = combine_half_asm(str1, str2);
    
    std::cout << "Combined string: " << combined << std::endl;

    delete[] combined; // Не забываем освобождать выделенную память
    return 0;
}

