#include <windows.h>
#include <iostream>

void convertMillisecondsToHMS(long long milliseconds) {
    long long totalSeconds = milliseconds / 1000; // Общее количество секунд
    long long hours = totalSeconds / 3600;       // Часы
    long long minutes = (totalSeconds % 3600) / 60; // Минуты
    long long seconds = totalSeconds % 60;         // Оставшиеся секунды

    std::cout << "Программа работает: " << hours << ":" << minutes << ":" << seconds<< std::endl;
}

void closeProgramm(long long milliseconds) {
    ULONGLONG ticks = GetTickCount64() - milliseconds;
    convertMillisecondsToHMS(ticks);
    exit(0);
}

int main() {
    setlocale(LC_ALL, "Russian");
    ULONGLONG ticks = GetTickCount64(); // Возвращает количество миллисекунд

    while (true) {
        int res = MessageBox(NULL, L"Остановить?", L"Программа запущена.", MB_OKCANCEL | MB_ICONINFORMATION);
        if (res == IDOK) break;
        else if (res == IDCANCEL) {
            int confirm = MessageBox(NULL, L"Вы уверены?", L"", MB_YESNO | MB_ICONWARNING);
            if (confirm == IDYES) break;
        }
    }

    closeProgramm(ticks);
}                                                        