#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    // létező
    system("date");
    // nem létezõ
    system("something");

    return 0;
}
