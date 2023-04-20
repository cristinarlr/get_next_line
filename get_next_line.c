/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:57:14 by Cristina          #+#    #+#             */
/*   Updated: 2023/04/20 13:02:54 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char *ft_read_and_stock_in_stash(int fd)
{
    char    *buff;
    char    *temp;
    static char *stash;
    ssize_t nbytes;
  //  int i;
    
    //creo BUFF y relleno con función READ
    buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (0);
        //READ
    nbytes = read(fd, buff, BUFFER_SIZE);
    if (nbytes == -1)
    {
        printf("Error reading file");
        return(0);
    }
    buff[nbytes] = '\0';
    //creo STASH y copio contenido de BUFF
    stash = (char *)malloc((BUFFER_SIZE) * sizeof(char));
    if (!stash)
        return (0);
    ft_strlcpy(stash, buff, BUFFER_SIZE + 1);
    //detectar si hay '\0' o si estamos al final de la cadena, si no es ninguno de los dos casos, seguir leyendo + concatenando
//     i = 0;

    while(nbytes > 0)
    {
        nbytes = read(fd, buff, BUFFER_SIZE);
        temp = ft_strjoin(stash, buff);
        free(stash);
        stash = temp;
        if (ft_strchr(stash, '\n'))
            break ;
    }
    printf("stash después de WHILE = %s", stash);
    return(stash);


    
    if (ft_strchr(stash, '\n') == 0 && nbytes > 0 )
    {   
        printf ("dentro del IF \n");
      /*   while (stash[i] != '\0')
        {
            stash = ft_strjoin(stash, buff);
            printf("después de ft_strjoin, como queda stash = %s", stash);
            nbytes = read(fd, buff, BUFFER_SIZE);
        }
        i++; */
    } 
    // que hacer si hay '\0' o si estamos al final de cadena
    return (stash);
}



/* static char *ft_pass_buff_content_to_stash(char *buff)
{
    static char *stash;

    stash = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    ft_strlcpy(stash, buff, BUFFER_SIZE + 1);
    printf("salió de ft_strlcpy, buff = %s\n", buff);
    printf("salió de ft_strlcpy, stash = %s\n", stash);
    return (stash);
} */

/* static  char *ft_stash_extract_for_next_GNL()

static char *ft_clean_stash_to_line(char *stash)
 */



char *get_next_line(int fd)
{
   char *line;

    printf("BUFFER_SIZE es = %d\n", BUFFER_SIZE);
    line = ft_read_and_stock_in_stash(fd);
    return (line);
}



int main()
{
    int fd;
    char *result;

    fd = open("15char", O_RDONLY);
    if (fd == -1)
    {
     printf("Error opening file");
     exit(1);
    }
    printf("fd = %d\n", fd);
    result = get_next_line(fd);
    close(fd);
}


   /*  
   TESTS PARA PRINTEAR CADA CARACTER
   printf("Result = %s\n", result);
    printf("Result = %c\n", result[0]);
    printf("Result = %c\n", result[1]);
    printf("Result = %c\n", result[2]);
        result[2] = 0;
    printf("Result = %c\n", result[2]);
    printf("Result = %c\n", result[3]);
    printf("Result = %c\n", result[4]);
    printf("Result = %c\n\n", result[5]);
    printf("Result = %c\n", result[BUFFER_SIZE - 5]);
    printf("Result = %c\n", result[BUFFER_SIZE - 4]);
    printf("Result = %c\n", result[BUFFER_SIZE - 3]);
    printf("Result = %c\n", result[BUFFER_SIZE - 2]);
    printf("Result = %c\n", result[BUFFER_SIZE - 1]);
    printf("Result = %c\n", result[BUFFER_SIZE]);
    printf("Result = %c\n", result[BUFFER_SIZE + 1]);
    printf("Result = %c\n", result[BUFFER_SIZE + 2]);
    if(result[BUFFER_SIZE] == 0)
        {
        printf("El valor result[BUFFER_SIZE] es nulo.\n");
        } 
    else if (result[BUFFER_SIZE] == ' ')
        {
        printf("El valor result[BUFFER_SIZE] es un espacio.\n");
        }
    else 
    {
        printf("El valor result[BUFFER_SIZE] es %c.\n", result[BUFFER_SIZE]);
    }
    if(result[5] == 0)
        {
        printf("El valor result[5] es nulo.\n");
        } 
    else if (result[5] == ' ')
        {
        printf("El valor result[5] es un espacio.\n");
        }
    else 
    {
        printf("El valor result[5] es %c.\n", result[5]);
    } */