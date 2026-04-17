#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main() {
    struct termios old_tio, new_tio;
    // 保存原设置
    tcgetattr(STDIN_FILENO, &old_tio);
    // ... 设置无缓冲 ...

    new_tio = old_tio;
    // 关闭行缓冲和回显
    new_tio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    printf("按 q 退出...\n");
    
    int c;
    while ((c = getchar()) != 'q') {
        printf("你按了: %c (ASCII: %d)\n", c, c);
    }

    // 恢复终端设置（必须！）
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    printf("\n已退出\n");

    return 0;
}
