#include <Windows.h>
#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");

    DWORD drives = GetLogicalDrives();
    char driveLetter = 'A';

    while (drives) {
        if (drives & 1) {
            char drivePath[4];
            sprintf_s(drivePath, "%c:\\", driveLetter);

            // Преобразование строки char в LPCWSTR
            wchar_t wDrivePath[4];
            MultiByteToWideChar(CP_ACP, 0, drivePath, -1, wDrivePath, 4);

            DWORD fsFlags;
            wchar_t fileSysName[MAX_PATH];
            DWORD serialNumber;
            DWORD maxComponentLength;

            if (GetVolumeInformation(wDrivePath, NULL, 0, &serialNumber, &maxComponentLength, &fsFlags, fileSysName, MAX_PATH)) {
                std::wcout << L"Диск: " << driveLetter << std::endl;
                std::wcout << L"Файловая система: " << fileSysName << std::endl;
                std::wcout << L"Серийный номер: " << serialNumber << std::endl;
                std::wcout << L"Максимальная длина компонента: " << maxComponentLength << std::endl;

                if (fsFlags & FILE_VOLUME_QUOTAS) {
                    std::wcout << L"Квоты включены." << std::endl;
                }

                ULARGE_INTEGER totalSpace, freeSpace;
                if (GetDiskFreeSpaceEx(wDrivePath, &freeSpace, &totalSpace, NULL)) {
                    std::wcout << L"Общий объем: " << totalSpace.QuadPart << L" байт" << std::endl;
                    std::wcout << L"Свободное пространство: " << freeSpace.QuadPart << L" байт" << std::endl;
                }
                else {
                    std::wcout << L"Не удалось получить информацию о свободном месте на диске." << std::endl;
                }

                std::wcout << std::endl;
            }
        }

        drives >>= 1;
        driveLetter++;
    }

    return 0;
}
