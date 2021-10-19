#include <stdio.h>
void print(int cnt)
{
    if (cnt == 1)
        printf("Bingo!\n");
    else if (cnt <= 3)
        printf("Lucky You!\n");
    else
        printf("Good Guess!\n");
}
signed main()
{
    int a, n;
    scanf("%d%d", &a, &n);
    int g, cnt = 0;
    while (++cnt, scanf("%d", &g), g >= 0 && cnt <= n)
    {
        if (g < a)
            printf("Too small\n");
        else if (g > a)
            printf("Too big\n");
        else
        {
            print(cnt);
            return 0;
        }
    }
    printf("Game Over\n");
    return 0;
}