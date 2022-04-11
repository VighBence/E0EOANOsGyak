#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int pid;
    int status;

    if ((pid = fork()) < 0)
        perror("fork hiba");
    else if (pid == 0) /* gyerek */
        exit(7);       /* befejezõdött   */
    if (wait(&status) != pid)
        perror("wait hiba"); /*szülõ */
    if (WIFEXITED(status))
        printf("Normális befejezõdés, a visszaadott érték =%d\n", WEXITSTATUS(status));

    return 0;
}
