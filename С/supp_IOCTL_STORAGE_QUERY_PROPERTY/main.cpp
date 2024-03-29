#include <stdio.h>
#include <windows.h>

int main() {
    // Открываем дескриптор устройства (замените "C:" на нужное устройство)
    HANDLE volumeHandle = CreateFileA("\\\\.\\C:", 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);

    if (volumeHandle != INVALID_HANDLE_VALUE) {
        // Подготовка запроса
        STORAGE_PROPERTY_QUERY query;
        query.PropertyId = StorageDeviceProperty;
        query.QueryType = PropertyStandardQuery;

        // Выделение буфера для получения информации
        STORAGE_DEVICE_DESCRIPTOR deviceDescriptor;
        DWORD bytesReturned;

        // Вызываем DeviceIoControl для проверки поддержки запроса
        if (DeviceIoControl(volumeHandle, IOCTL_STORAGE_QUERY_PROPERTY, &query, sizeof(query), &deviceDescriptor, sizeof(deviceDescriptor), &bytesReturned, NULL)) {
            // Устройство поддерживает IOCTL_STORAGE_QUERY_PROPERTY
            wprintf(L"Устройство поддерживает запрос IOCTL_STORAGE_QUERY_PROPERTY.\n");
        } else {
            // Устройство не поддерживает IOCTL_STORAGE_QUERY_PROPERTY
            wprintf(L"Устройство не поддерживает запрос IOCTL_STORAGE_QUERY_PROPERTY.\n");
        }

        CloseHandle(volumeHandle);
    } else {
        wprintf(L"Не удалось открыть дескриптор устройства.\n");
    }

    return 0;
}
