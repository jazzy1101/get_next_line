/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:48:59 by dabae             #+#    #+#             */
/*   Updated: 2023/11/10 11:14:26 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main() {
    int fd;
    char *line;

    // Replace "test.txt" with the path to your text file
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) {
        printf("Line: %s\n", line);
        free(line);
    }

    // Check for errors or end-of-file
    if (line == NULL) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    // Result is NULL, meaning end-of-file
    printf("End of file reached.\n");

    close(fd);

    return 0;
}

