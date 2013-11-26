compile: OpenWindow.c
	x86_64-w64-mingw32-gcc OpenWindow.c -o OpenWindow -L C:\Windows\System32 -l user32
