// HelloWorld.c : Определяет точку входа для приложения.
//
#include "framework.h"
#include "DrawEllipse.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;// текущий экземпляр

// Отправить объявления функций, включенных в этот модуль кода:
BOOL                InitInstance(HINSTANCE, int);
INT_PTR CALLBACK    DrawEllipseDlg(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.
    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    return 0;
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной
    INT_PTR nResponse = DialogBox(hInst, MAKEINTRESOURCE(IDD_DRAWELLIPSE_DIALOG), NULL, DrawEllipseDlg);
    if (nResponse == IDOK)
    {
        // TODO: Введите код для обработки закрытия диалогового окна
        //  с помощью кнопки "ОК"
    }
    else if (nResponse == IDCANCEL)
    {
        // TODO: Введите код для обработки закрытия диалогового окна
        //  с помощью кнопки "Отмена"
    }
    else if (nResponse == -1)
        return FALSE;
   return TRUE;
}

// Обработчик сообщений для окна "DrawEllipse".
INT_PTR CALLBACK DrawEllipseDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hDlg, &ps);
            RECT rcPaint = ps.rcPaint;
            int nWidth = rcPaint.right - rcPaint.left;
            int nHeight = rcPaint.bottom - rcPaint.top;
            HPEN oRedPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0)), oDefaultPen;
            HBRUSH oYellowBrush = CreateSolidBrush(RGB(255, 255, 0)), oDefaultBrush;
            HBRUSH oBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
            FillRect(hdc, &rcPaint, oBlackBrush);
            oDefaultPen = SelectObject(hdc, oRedPen);
            oDefaultBrush = SelectObject(hdc, oYellowBrush);
            Ellipse(hdc, 0, 0, nWidth, nHeight);
            oRedPen = SelectObject(hdc, oDefaultPen);
            oYellowBrush = SelectObject(hdc, oDefaultBrush);
            DeleteObject(oBlackBrush);
            DeleteObject(oRedPen);
            DeleteObject(oYellowBrush);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hDlg, &ps);
        }
        break;
    case WM_SIZE:
        {
            InvalidateRect(hDlg, NULL, TRUE);
        }
        break;
    }
    return (INT_PTR)FALSE;
}