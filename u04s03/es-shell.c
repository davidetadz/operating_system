//
// Created by Davide on 15-Dec-17.
//

int main() {

    /* Scheletro della shell UNIX */

    while (TRUE) {
        write_prompt;
        read_command(command, parameters);
        if (fork() == 0)
            /* Child: Execute Command */
            execve(command, parameters);

        /* else NON eseguito se il comando
         * viene eseguito in background */
        else
            /* Father: Wait Child */
            wait(&status);
    }

    return 0;
}