#include <windows.h>

#define ARGNUM 3

// argv[1] : Window Class Name
// argv[2] : Program Path
// argv[3~] : Program Arguments
int main(int argc, char* argv[])
{
    HWND hWin = FindWindow(argv[1], NULL);
    if (hWin) {
        SetForegroundWindow(hWin);
    } else {
        // 引数の数をチェック
        if (argc < ARGNUM)
            return 1;
        // 実行環境
        char path[255];
        GetCurrentDirectory(255, path);
        // 実行するプログラムの引数をまとめる
        char args[1000] = {0};
        int i;
        for (i = ARGNUM; i < argc; ++i) {
            strcat(args, "\"");
            strcat(args, argv[i]);
            strcat(args, "\" ");
        }

        ShellExecute(NULL, "open", argv[2], args, path, SW_SHOWDEFAULT);
    }
    return 0;
}
