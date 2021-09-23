#define WINVER 0x0500

#include <stdio.h>
#include <windows.h>

void usage()
{
	printf(
			"notify-send.exe [OPTIONS] <title> <body>\n\n"
			"OPTIONS:\n"
			"\t-t        Notification type, one of: none, info, warning, error\n"
	);
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc < 3) {
		usage();
	}

	DWORD notifType = NIIF_NONE;

	for (int i = 1; i < argc - 2; i++) {
		if (i + 3 >= argc) {
			usage();
		} else if (!strcmp(argv[i], "-t")) {
			const char *type = argv[++i];
			if (!strcmp(type, "none")) {
				notifType = NIIF_NONE;
			} else if (!strcmp(type, "info")) {
				notifType = NIIF_INFO;
			} else if (!strcmp(type, "warning")) {
				notifType = NIIF_WARNING;
			} else if (!strcmp(type, "error")) {
				notifType = NIIF_ERROR;
			} else {
				usage();
			}
		} else {
			usage();
		}
	}

	NOTIFYICONDATAA nid = {
		.cbSize = sizeof(nid),
		.uFlags = NIF_INFO,
		.dwInfoFlags = notifType,
	};

	strncpy(nid.szInfoTitle, argv[argc - 2], sizeof(nid.szInfoTitle) - 1);
	strncpy(nid.szInfo, argv[argc - 1], sizeof(nid.szInfo) - 1);

	Shell_NotifyIconA(NIM_ADD, &nid);
	Shell_NotifyIconA(NIM_DELETE, &nid);

	return 0;
}
