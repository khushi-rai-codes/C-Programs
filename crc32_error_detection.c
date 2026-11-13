#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define POLYNOMIAL 0xEDB88320U

uint32_t crc32(const unsigned char *data, size_t length) {
    uint32_t crc = 0xFFFFFFFFU;

    for (size_t i = 0; i < length; i++) {
        crc ^= data[i];

        for (int bit = 0; bit < 8; bit++) {
            if (crc & 1)
                crc = (crc >> 1) ^ POLYNOMIAL;
            else
                crc >>= 1;
        }
    }

    return crc ^ 0xFFFFFFFFU;
}

int main(void) {
    char message[4096];
    char received[4096];
    uint32_t transmittedCRC, receivedCRC;

    printf("Enter original message: ");

    if (!fgets(message, sizeof(message), stdin)) {
        printf("Input error.\n");
        return 1;
    }

    message[strcspn(message, "\n")] = '\0';

    transmittedCRC = crc32(
        (unsigned char *)message,
        strlen(message)
    );

    printf("\nGenerated CRC-32: %08X\n", transmittedCRC);

    printf("\nEnter received message: ");

    if (!fgets(received, sizeof(received), stdin)) {
        printf("Input error.\n");
        return 1;
    }

    received[strcspn(received, "\n")] = '\0';

    printf("Enter received CRC-32 (hexadecimal): ");

    if (scanf("%x", &receivedCRC) != 1) {
        printf("Invalid checksum.\n");
        return 1;
    }

    uint32_t calculatedCRC = crc32(
        (unsigned char *)received,
        strlen(received)
    );

    printf("\nCalculated CRC-32: %08X\n", calculatedCRC);

    if (calculatedCRC == receivedCRC) {
        printf("Verification successful: checksum matches.\n");
    } else {
        printf("Error detected: checksum mismatch.\n");
    }

    return 0;
}
