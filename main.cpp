#include <Windows.h>
#include <Task.h>

// Global variables
HWND hListView;
HINSTANCE hInst;

// Function to populate the list view control with tasks
void PopulateListView() {
    // Replace this with your task data retrieval logic
    // For this example, we add dummy data
    LVITEM lvItem;
    lvItem.mask = LVIF_TEXT;
    lvItem.iItem = 0;
    lvItem.iSubItem = 0;
    lvItem.pszText = L"Task 1";
    ListView_InsertItem(hListView, &lvItem);
}

// Windows procedure function
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_CREATE:
        // Create the list view control
        hListView = CreateWindow(WC_LISTVIEW, L"",
            WS_VISIBLE | WS_CHILD | LVS_REPORT, 10, 10, 400, 200,
            hWnd, (HMENU)IDC_TASK_LIST, hInst, NULL);

        // Initialize the list view
        ListView_SetExtendedListViewStyle(hListView, LVS_EX_FULLROWSELECT);

        // Add columns to the list view
        LVCOLUMN lvColumn;
        lvColumn.mask = LVCF_TEXT | LVCF_WIDTH;
        lvColumn.cx = 200;
        lvColumn.pszText = L"Tasks";
        ListView_InsertColumn(hListView, 0, &lvColumn);

        // Populate the list view
        PopulateListView();
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    hInst = hInstance; // Store the instance handle in a global variable

    // Register the window class
    WNDCLASSEX wcex = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0, hInst, NULL, NULL, NULL, NULL, L"YourWindowClass", NULL };
    RegisterClassEx(&wcex);

    // Create the window
    HWND hWnd = CreateWindow(L"YourWindowClass", L"Task List", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInst, NULL);
    if (!hWnd) {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
