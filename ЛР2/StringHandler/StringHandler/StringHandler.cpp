#include <windows.h>
#include <iostream>
#include <string>

// ANSI-функции
int countwords(const char* str) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha((unsigned char)str[i])) {
            if (!inWord) {
                inWord = true;
                count++;
            }
        }
        else {
            inWord = false;
        }
    }

    return count;
}

char* reversestring(const char* str) {
    int len = strlen(str);
    char* reversed = (char*)malloc(len+1);;

    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';

    return reversed;
}

BOOL isstringpalindrome(const char* str) {
    int len = strlen(str);

    char* clean_str = (char*)malloc(len + 1);

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum((unsigned char)str[i])) {
            clean_str[j++] = tolower((unsigned char)str[i]); // Приводим к нижнему регистру
        }
    }
    clean_str[j] = '\0';


    char* reversed = reversestring(clean_str);

    return (strcmp(clean_str, reversed) == 0);
}


// Unicode-функции
int countwords(const wchar_t* str) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha((unsigned char)str[i])) {
            if (!inWord) {
                inWord = true;
                count++;
            }
        }
        else {
            inWord = false;
        }
    }

    return count;
}

wchar_t* reversestring(const wchar_t* str) {
    int len = wcslen(str);
    wchar_t* reversed = (wchar_t*)malloc(len + 1);

    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';

    return reversed;
}

BOOL isstringpalindrome(const wchar_t* str) {
    int len = wcslen(str);
    wchar_t* clean_str = (wchar_t*)malloc(len + 1);

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum((unsigned char)str[i])) {
            clean_str[j++] = tolower((unsigned char)str[i]); // Приводим к нижнему регистру
        }
    }
    clean_str[j] = '\0';

    wchar_t* reversed = reversestring(clean_str);

    return (wcscmp(clean_str, reversed) == 0);
}


int main() {
    // ===== ДЕМОНСТРАЦИЯ ANSI-ФУНКЦИЙ =====
    std::cout << "=== ANSI Functions ===" << std::endl;

    char ansiStr[256] = "   Hello, 'World'!";
    std::cout << "Original ANSI string: \"" << ansiStr << "\"" << std::endl;
    std::cout << "Count ANSI words: \"" << countwords(ansiStr) << "\"" << std::endl;
    std::cout << "Reverse ANSI string: \"" << reversestring(ansiStr) << "\"" << std::endl;
    std::cout << "ANSI string is palindrome: \"" << isstringpalindrome(ansiStr) << "\"" << std::endl;

    // ===== ДЕМОНСТРАЦИЯ UNICODE-ФУНКЦИЙ =====
    std::wcout << L"\n=== Unicode Functions ===" << std::endl;

    wchar_t unicodeStr[256] = L"A man, a plan, a canal: Panama";
    std::wcout << L"Original Unicode string: \"" << unicodeStr << L"\"" << std::endl;
    std::wcout << "Count Unicode words: \"" << countwords(unicodeStr) << "\"" << std::endl;
    std::wcout << "Reverse Unicode string: \"" << reversestring(unicodeStr) << "\"" << std::endl;
    std::wcout << "Unicode string is palindrome: \"" << isstringpalindrome(unicodeStr) << "\"" << std::endl;

    // ===== ДЕМОНСТРАЦИЯ ПРЕОБРАЗОВАНИЯ И ОБРАБОТКИ ОШИБОК =====
    // ... код с использованием WideCharToMultiByte и GetLastError ...*/

    return 0;
}
