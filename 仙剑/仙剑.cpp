#include<windows.h>
#include <tchar.h>

#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"Msimg32.lib")

#define WINDOW_W 800
#define WINDOW_H 600
#define WINDOW_TITTLE  L"�ɽ�����"
#define  WINDOW_CLASS   L"�ɽ�"


//����ȫ�ֱ���
//ȫ���豸�������,������ȫ���ڴ���
HDC  g_hdc = NULL, g_mdc = NULL, g_buffdc = NULL;
//����λͼ������飬���4�����﷽��ͼƬ
HBITMAP g_hSprite[4] = { NULL }, g_hBackGroud = NULL;

DWORD t_tPre = 0, g_tNow = 0;//��¼ʱ��
int g_iNum = 0,g_ix=0,g_iy=0;//һ��ͼƬ�ĵڼ��š��������ꡣ
int g_iDirection = 0; //���﷽��

LRESULT CALLBACK WndPro(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL  Game_Init(HWND  hwnd);
void   Game_paint(HWND  hwnd);
BOOL   Game_CleanUp(HWND  hwnd);

int WINAPI  WinMain(HINSTANCE  hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nShowCmd)
{
	//ͨ�������� ��������
	WNDCLASSEX wndClass = {0};
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndPro;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndClass.hIcon = NULL;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = WINDOW_CLASS;

	if (!RegisterClassEx(&wndClass))
	{
		return -1;

	}

	//��������
	HWND  hwnd = CreateWindow(WINDOW_CLASS,WINDOW_TITTLE,WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,WINDOW_W,WINDOW_H,NULL,NULL,hInstance,NULL);


	//��ʾ����
	ShowWindow(hwnd,nShowCmd);

	//���´���
	UpdateWindow(hwnd);

	//��Ϣѭ��
	MSG  msg = {0};
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}
	}

	//ע������
	UnregisterClass(L"xianjian",wndClass.hInstance);
	return 0;
}


//���ڹ��̺���WndProc ������Ϣ����
LRESULT CALLBACK WndPro(HWND  hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
	default:
		return DefWindowProc(hwnd,message,wParam,lParam);
	}
	return 0;
}

BOOL Game_Init(HWND hwnd)
{
	HBITMAP bmp;
	g_hdc = GetDC(hwnd);
	g_mdc = CreateCompatibleDC(g_hdc);
	g_buffdc = CreateCompatibleDC(g_hdc);
	bmp=Crea


	return TRUE;
}

VOID   Game_paint(HWND  hwnd)
{


}

BOOL   Game_CleanUp(HWND  hwnd)
{

	return TRUE;
}









