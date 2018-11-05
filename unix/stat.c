#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat a;
    if(stat("./stat.c", &a) != -1) {
        printf("%llu,%d,%u", a.st_ino, a.st_dev, a.st_mode);
    }
    return 0;
}
