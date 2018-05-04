#define _WIN32_IE 0x0500

#include <stdio.h>
#include <Windows.h>

int main(int argc, char** argv) {
    if (argc != 3) {
        puts("notify-send.exe <title> <body>");
        return 1;
    }

    NOTIFYICONDATA nid;
    memset(&nid, 0, sizeof(nid));
    nid.cbSize = sizeof(nid);

    nid.uFlags = NIF_INFO;

    strcpy(nid.szInfoTitle, argv[1]);
    strcpy(nid.szInfo, argv[2]);

    Shell_NotifyIconA(NIM_ADD, &nid);
    Shell_NotifyIconA(NIM_DELETE, &nid);

    return 0;
}
