#include "monty.h"

/**
 * fileman - open and read file
 * @fl_nm: File Name
 * @argmnts: Tokenized arguments
 * Return: void
 */

void fileman(char *fl_nm, char **argmnts)
{
        int x;
        int y = 1;
        char *cmd;

        x = open(fl_nm, O_RDONLY);

        if (x == -1)
        {
                fprintf(stderr, "%s won't open", fl_nm);
                exit(EXIT_FAILURE);
        }
        cmd = malloc(ARG_MAX * 1000);
        if (cmd == NULL)
        {
                fprintf(stderr, "Malloc Failure");
                exit(EXIT_FAILURE);
        }
        y = read(x, cmd, ARG_MAX * 1000);
        if (y == -1)
                exit(EXIT_FAILURE);

        tokenize(cmd, "\n", argmnts);
        free(cmd);
}
