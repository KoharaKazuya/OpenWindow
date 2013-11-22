#include <stdlib.h>
#include <windows.h>

#define ARGNUM 3

// argv[1] : Window Class Name
// argv[2] : Program Path
// argv[3~] : Program Arguments
int main(int argc, char* argv[])
{
    if (argc < ARGNUM)
        return 1;

    // 実行ディレクトリを path に格納
    char path[1000] = {0};
    char drive[10];
    char dir[990];
    _splitpath(argv[2], drive, dir, NULL, NULL);
    strcat(path, drive);
    strcat(path, dir);

    // 実行するプログラムの引数をまとめる
    char args[1000] = {0};
    int i;
    for (i = ARGNUM; i < argc; ++i) {
        strcat(args, "\"");
        strcat(args, argv[i]);
        strcat(args, "\" ");
    }

    HWND hWin = FindWindow(argv[1], NULL);
    if (hWin) {
        SetForegroundWindow(hWin);
    } else {
        ShellExecute(NULL, "open", argv[2], args, path, SW_SHOWDEFAULT);
    }

    return 0;
}
