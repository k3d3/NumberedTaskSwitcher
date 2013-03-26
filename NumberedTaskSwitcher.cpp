/*
    Simple window switcher
    ---

    Released to the public domain by Keith Morrow.
    If that is not possible, I hereby release this code under Creative Commons CC0 Public Domain Dedication,
    found at http://creativecommons.org/publicdomain/zero/1.0/deed.en

    How to use:
      First, register the focused window to a hotkey by using Alt+Shift+Number, where the number is 0-9.
      Then, to bring that window back to the foreground, press Alt+Number, using the same number used to register.
*/

#include <stdio.h>
#include <Windows.h>

int main() {
    int i, slot;
    MSG msg = {0};
    HWND window_handles[10];

    // Register hotkeys 0-9
    for (i = 0; i < 10; i++) {
        if (RegisterHotKey(NULL, i, MOD_ALT | MOD_NOREPEAT, 0x30 + i) == TRUE) {
            printf("Registering Alt+%d as hotkey\n", i);
        } else {
            printf("Failed to register Alt+%d as hotkey\n", i);
            return 1;
        }
        if (RegisterHotKey(NULL, 10 + i, MOD_SHIFT | MOD_ALT | MOD_NOREPEAT, 0x30 + i) == TRUE) {
            printf("Registering Alt+Shift+%d as hotkey\n", i);
        } else {
            printf("Failed to register Alt+Shift+%d as hotkey\n", i);
            return 1;
        }
        window_handles[i] = 0;
    }

    while (GetMessage(&msg, NULL, 0, 0) != 0) {
        if (msg.message == WM_HOTKEY) {
            slot = (msg.lParam >> 16) - 0x30;
            if (msg.lParam & MOD_SHIFT) { /* Shift is pressed, register this window */
                window_handles[slot] = GetForegroundWindow();
                printf("Slot %d: Registering window %d\n", slot, window_handles[slot]);
            } else { /* Shift is not pressed, show this window */
                if (window_handles[slot] == 0) {
                    printf("Slot %d: Cannot show - no window registered\n", slot);
                } else {
                    SetForegroundWindow(window_handles[slot]);
                    printf("Slot %d: Showing window %d\n", slot, window_handles[slot]);
                }
            }
        }
    }
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    main();
}