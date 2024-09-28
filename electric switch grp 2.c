#include <stdio.h>

#define NUM_DEVICES 5

void displayStatus(int switchStates[]) {
    for (int i = 0; i < NUM_DEVICES; i++) {
        printf("Device %d is %s.\n", i + 1, switchStates[i] ? "ON" : "OFF");
    }
}

int main() {
    int switchStates[NUM_DEVICES] = {0}; // Initialize all devices to OFF
    int deviceNumber;
    char command;

    printf("Home Automation System\n");
    printf("Commands:\n");
    printf("  1: Turn ON a device (followed by device number)\n");
    printf("  0: Turn OFF a device (followed by device number)\n");
    printf("  s: Show status of all devices\n");
    printf("  q: Quit\n");

    while (1) {
        printf("\nEnter command: ");
        scanf(" %c", &command);

        if (command == 'q') {
            break; // Exit the loop
        } else if (command == 's') {
            displayStatus(switchStates); // Display status of all devices
        } else if (command == '1' || command == '0') {
            printf("Enter device number (1 to %d): ", NUM_DEVICES);
            scanf("%d", &deviceNumber);

            // Validate device number
            if (deviceNumber < 1 || deviceNumber > NUM_DEVICES) {
                printf("Invalid device number! Please enter a number between 1 and %d.\n", NUM_DEVICES);
                continue;
            }

            // Control the device based on the command
            int deviceIndex = deviceNumber - 1; // Adjust for array indexing
            if (command == '1') {
                if (switchStates[deviceIndex] == 1) {
                    printf("Device %d is already ON.\n", deviceNumber);
                } else {
                    switchStates[deviceIndex] = 1; // Turn ON the device
                    printf("Device %d is now ON.\n", deviceNumber);
                }
            } else if (command == '0') {
                if (switchStates[deviceIndex] == 0) {
                    printf("Device %d is already OFF.\n", deviceNumber);
                } else {
                    switchStates[deviceIndex] = 0; // Turn OFF the device
                    printf("Device %d is now OFF.\n", deviceNumber);
                }
            }
        } else {
            printf("Invalid command! Please enter 1, 0, s, or q.\n");
        }
    }

    printf("Exiting the Home Automation System.\n");
    return 0;
}
