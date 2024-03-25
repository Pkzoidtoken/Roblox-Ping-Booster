#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void clean_cache() {
    int tmp = system("del /q /s /f %TEMP%\\*.*");
    int prefetch = system("cd C:\\Windows\\prefetch && dir && del /q /s /f *.* ");
}

void stop_services() {
    int stop_update = system("sc stop DoSvc");
    int stop_services = system("sc stop wuauserv");
}

void flush_dns() {
    system("ipconfig /release6");
    system("ipconfig /renew6");
    system("ipconfig /release");
    system("ipconfig /flushdns");
    system("ipconfig /renew");
    system("ipconfig /renew all");
    system("netsh interface set interface 'Ethernet' admin=disable");
    system("timeout /t 5 /nobreak > NUL");
    system("netsh interface set interface 'Ethernet' admin=enable");
}

int main(int argc, char* argv[]) {
    clean_cache();
    stop_services();
    flush_dns();
}
