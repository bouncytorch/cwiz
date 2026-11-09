#include <cwiz.h>
#include <stdio.h>

int main() {
    cw_init();
    int res = cw_open_audio("/home/bouncytorch/Desktop/test2.wav");
    if (res) {
        printf("Error %d", res);
        cw_clean();
        return 1;
    }
}
