#include <iostream>
#include <chrono>

using namespace std;

extern "C" char* combine_half_asm(const char* str1, const char* str2);
char* combine_half_cpp(const char* str1, const char* str2);

int main() {
    const char* str1 = "HelloWorld";
    const char* str2 = "GoodbyeEveryone";

    auto start = chrono::high_resolution_clock::now();
    char* result_asm = combine_half_asm(str1, str2);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_asm = end - start;

    cout << "Результат (ASM): " << result_asm << std::endl;
    cout << "Время выполнения ASM: " << duration_asm.count() << " секунд" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    char* result_cpp = combine_half_cpp(str1, str2);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_cpp = end - start;

    std::cout << "Результат (C++): " << result_cpp << std::endl;
    std::cout << "Время выполнения C++: " << duration_cpp.count() << " секунд" << std::endl;

    delete[] result_asm; // Освобождаем память
    delete[] result_cpp; // Освобождаем память

    return 0;
}