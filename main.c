#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddControls(HWND);
void resetGame(HWND);
void updatePointsDisplay(HWND);

char numberStr[4];
int number, tries = 0, maxTries = 5;
int points = 0, totalPoints = 0;

typedef struct {
    int num;
    const char* message;
} Hint;

Hint hints[] = {
    {1, "The Topper"},
    {2, "An Even Number"},
    {3, "Unlucky Number"},
    {4, "An Even Number"},
    {5, "Odd Number"},
    {6, "Hardly Comes in Dice"},
    {7, "Related to MSD"},
    {8, "Big Bro of 4"},
    {9, "The Larger"},
    {10, "I have no Hint"}
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR args, int nCmdShow) {
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInstance;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc)) return -1;

    HWND hwnd = CreateWindowW(L"myWindowClass", L"Guess the Number Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                              100, 100, 500, 400, NULL, NULL, hInstance, NULL);

    srand(time(0));
    resetGame(hwnd);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

void resetGame(HWND hwnd) {
    number = rand() % 10 + 1;
    tries = 0;

    if (hwnd) {
        ShowWindow(GetDlgItem(hwnd, 4), SW_HIDE);
        ShowWindow(GetDlgItem(hwnd, 5), SW_HIDE);
        SetWindowText(GetDlgItem(hwnd, 1), L"");
        EnableWindow(GetDlgItem(hwnd, 2), TRUE);
        SetWindowText(GetDlgItem(hwnd, 3), L"");
        updatePointsDisplay(hwnd);
    }
}

void updatePointsDisplay(HWND hwnd) {
    char buffer[256];
    sprintf(buffer, "Total Points: %d", totalPoints);
    SetWindowText(GetDlgItem(hwnd, 6), buffer);
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_COMMAND:
        if (LOWORD(wp) == 2) { // Guess button
            GetWindowText(GetDlgItem(hwnd, 1), numberStr, sizeof(numberStr));
            int guess = atoi(numberStr);
            tries++;

            char buffer[512]; // Increased buffer size to accommodate larger messages
            if (guess > number) {
                sprintf(buffer, "Too high! Try again.");
            } else if (guess < number) {
                sprintf(buffer, "Too low! Try again.");
            } else {
                points = (maxTries - tries + 1) * 2;
                totalPoints += points;
                sprintf(buffer, "Congratulations! You guessed it in %d tries.\nYou earned %d points.", tries, points);
                EnableWindow(GetDlgItem(hwnd, 2), FALSE);
                ShowWindow(GetDlgItem(hwnd, 5), SW_SHOW);
            }
            if (tries >= maxTries && guess != number) {
                points = -2;
                totalPoints += points;
                sprintf(buffer, "Game Over! The number was %d.\nYou lost 2 points.", number);
                EnableWindow(GetDlgItem(hwnd, 2), FALSE);
                ShowWindow(GetDlgItem(hwnd, 5), SW_SHOW);
            }
            SetWindowText(GetDlgItem(hwnd, 3), buffer);
            updatePointsDisplay(hwnd);

            if (tries >= 2) {
                ShowWindow(GetDlgItem(hwnd, 4), SW_SHOW);
            }
        } else if (LOWORD(wp) == 4) { // Hint button
            char hint[256] = "";
            for (int i = 0; i < 10; i++) {
                if (hints[i].num == number) {
                    sprintf(hint, "Hint: %s", hints[i].message);
                    break;
                }
            }
            SetWindowText(GetDlgItem(hwnd, 3), hint);
        } else if (LOWORD(wp) == 5) { // Restart button
            resetGame(hwnd);
        }
        break;

    case WM_CREATE:
        AddControls(hwnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}

void AddControls(HWND hwnd) {
    CreateWindowW(L"Static", L"I have chosen a number between 1 and 10. Can you guess it?",
                  WS_VISIBLE | WS_CHILD | SS_CENTER, 50, 20, 400, 25, hwnd, NULL, NULL, NULL);

    CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER,
                  150, 60, 200, 25, hwnd, (HMENU)1, NULL, NULL);

    CreateWindowW(L"Button", L"Guess", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                  200, 100, 100, 30, hwnd, (HMENU)2, NULL, NULL);

    CreateWindowW(L"Button", L"Hint", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
                  200, 140, 100, 30, hwnd, (HMENU)4, NULL, NULL);
    ShowWindow(GetDlgItem(hwnd, 4), SW_HIDE);

    CreateWindowW(L"Button", L"Restart", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
                  200, 180, 100, 30, hwnd, (HMENU)5, NULL, NULL);
    ShowWindow(GetDlgItem(hwnd, 5), SW_HIDE);

    CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | SS_CENTER,
                  50, 220, 400, 50, hwnd, (HMENU)3, NULL, NULL);

    CreateWindowW(L"Static", L"Total Points: 0", WS_VISIBLE | WS_CHILD | SS_CENTER,
                  150, 300, 200, 25, hwnd, (HMENU)6, NULL, NULL); // Centered at the bottom of the window
}
