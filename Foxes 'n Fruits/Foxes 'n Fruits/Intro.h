#pragma comment(lib,"msimg32.lib") 

HWND img;
HANDLE q = GetStdHandle(STD_OUTPUT_HANDLE);
//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void logo1(string path, int left, int top, int width, int height)
{
	int style = WS_CLIPSIBLINGS | WS_CHILD | WS_VISIBLE | SS_BITMAP;

	img = CreateWindowExA(0, "static", 0, style, left, top, 0, 0, GetConsoleWindow(),
		(HMENU)0, GetModuleHandle(0), 0);
	HBITMAP bitmap = (HBITMAP)LoadImageA(0, path.c_str(),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	bitmap = (HBITMAP)CopyImage(bitmap, IMAGE_BITMAP, width, height, LR_COPYRETURNORG);
	SendMessage(img, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)bitmap);
	SetWindowPos(img, HWND_TOP, left, top, width, height, SWP_DRAWFRAME);
	Sleep(500);

	DestroyWindow(img);
}

void options()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = false;
	cursor.dwSize = 100;
	SetConsoleCursorInfo(h, &cursor);

	system("mode con cols=180 lines=60");
}

void animation()
{
	options();
	//logo1("C:\\1\\logo1.bmp", 50, 0, 1800, 1000);
	for (int i = 0; i < 6; i++)
	{
		logo1("Media\\logo3.bmp", 0, 0, 1300, 1300);
	}
	for (int i = 0; i < 6; i++)
	{
		logo1("Media\\logo1.bmp", 0, 0, 1800, 1000);
		logo1("Media\\logo2.bmp", 0, 0, 1800, 1000);
	}
}