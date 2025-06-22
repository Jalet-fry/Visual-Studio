
#include <windows.h>
#include <stdio.h>
#include <iostream>

int main() {

    LPCWSTR comPortTx = L"COM1";  // Port for transmission
    LPCWSTR comPortRx = L"COM2";  // Port for receiving

    // Open COM port for transmission`
    HANDLE hComTx = CreateFile(comPortTx, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hComTx == INVALID_HANDLE_VALUE) {
        printf("Error opening COM port for transmission!\n");
        return 1;
    }

    // Open COM port for receiving
    HANDLE hComRx = CreateFile(comPortRx, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hComRx == INVALID_HANDLE_VALUE) {
        printf("Error opening COM port for receiving!\n");
        CloseHandle(hComTx);
        return 1;
    }

    // Configure COM port settings
    DCB dcb;
    GetCommState(hComTx, &dcb);  // Get current settings
    dcb.BaudRate = CBR_9600;     // Speed 9600 baud
    dcb.ByteSize = 8;            // 8 data bits
    dcb.Parity = NOPARITY;       // No parity check
    dcb.StopBits = ONESTOPBIT;   // 1 stop bit
    SetCommState(hComTx, &dcb);  // Apply settings
    SetCommState(hComRx, &dcb);

    // Data transmission
    char byteToSend;
    printf("Enter a character to send: ");
    std::cin >> byteToSend;
    DWORD bytesWritten;
    if (!WriteFile(hComTx, &byteToSend, 1, &bytesWritten, NULL)) {
        printf("Error sending data!\n");
    }
    else {
        printf("Sent: %c\n", byteToSend);
    }

    // Data reception
    char receivedByte;
    DWORD bytesRead;
    if (!ReadFile(hComRx, &receivedByte, 1, &bytesRead, NULL)) {
        printf("Error reading data!\n");
    }
    else {
        printf("Received: %c\n", receivedByte);
    }

    // Close COM ports
    CloseHandle(hComTx);
    CloseHandle(hComRx);

    return 0;
}

