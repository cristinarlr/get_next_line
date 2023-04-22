
#include "get_next_line.h"

char *ft_clean_stash(char *stash)
{
    char *rest_stash;
    //char *aux;
    //int i;
    
    if(!ft_strchr(stash, '\n'))
    {
        printf("@@@@@@vete pa casa\n");
        return (0);
    }
    rest_stash = ft_strdup(stash);
    printf(">>> DENTRO DE CLEAN STASH\n");
    rest_stash = ft_strchr(stash, '\n') + 1;
    //i = ft_strlen(aux);
    printf("rest_stash = %s\n", rest_stash);
    return(rest_stash);      
}

char *ft_extract_line(char *stash)
{
    char *line;
    char *aux;
    int len;
    
    printf(">>> DENTRO DE EXTRACT LINE\n");
    printf("stash = %s\n", stash);
    if(!stash)
        return (0);
    if(!ft_strchr(stash, '\n'))
    {
        printf("@@@@@@fin de documento \n");
        return (stash);
    }
    printf(">>> sigue por aquí \n");
    aux = ft_strchr(stash, '\n') + 1;
    len = ft_strlen(stash) - ft_strlen(aux) + 1;
    line = (char *)malloc((len + 1) * sizeof(char));
    if (!line)
        return (0);
    ft_strlcpy(line, stash, len);
    printf("line = %s", line);
    printf(">>> SALIMOS DE EXTRACT LINE\n");
    return(line);  
}

char *ft_get_full_line (int fd, char *stash) 
{
    int     nbytes;
	char    *buff;
	
    printf(">>> DENTRO DE GET FULL LINE\n");
    printf("stash = %s\n", stash);
    nbytes = 1;
	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buff) 
		return(0);
	while(nbytes == BUFFER_SIZE || nbytes == 1)
    //while(nbytes > 0)
	{
        printf("||while||\n");
        nbytes = read(fd, buff, BUFFER_SIZE);
        printf("##READ##\n");
        printf("stash = %s\n", stash);
        printf("len stash = %zu\n", ft_strlen(stash));
         if (nbytes == -1 || ((nbytes == 0) && ft_strlen(stash) == 0))
         {
            printf("##dentro de if##\n");
            return (0);
         }
        buff[nbytes] = '\0';
        printf("buff = %s\n", buff);
        stash = ft_strjoin(stash, buff);
        printf("stash join = %s\n", stash);
        //if (ft_strchr(stash, '\n') || (nbytes < BUFFER_SIZE))
        if (nbytes == -1 || ((nbytes == 0) && ft_strlen(stash) == 0))
            return (stash);
        if (ft_strchr(stash, '\n') || nbytes == 0)
        {
            printf("stash al encontrar salto o final doc = %s\n", stash);
/*             if (nbytes == 0 && ft_strlen(stash) == 0)
            {
                free(buff);
                free(stash);
                return (NULL);
            } */
            return (stash);
        }
	}
    return (0);
} 

char *get_next_line(fd)
{
    char *line;
    static char *stash = NULL;

    printf(">>> DENTRO DE GNL\n");
    if (fd < 0 || BUFFER_SIZE <= 0)
    	return (NULL);
    if(!stash)
    {
        printf("stash null\n");
        stash = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    }
        if (!stash)
            return (0);
    stash = ft_get_full_line(fd, stash);
    if (stash == NULL)
        return (NULL);
    line = ft_extract_line(stash);
    if (line == NULL)
        return (NULL);
    stash = ft_clean_stash(stash);
    if (line == NULL)
        return (NULL);
    return (line);
} 
/* 
int main()
{
    int fd;
    char *line;

    fd = open("num", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file");
        return (1);
    }
    while ((line = get_next_line(fd)) > 0) // mientras haya líneas para leer
    {
       // printf("dentro de while de MAIN\n");
        printf("**************************main line = %s", line); // imprime la línea leída
        free(line); // libera la memoria reservada por la función get_next_line
       // break ;
    }
    close(fd); // cierra el archivo
    return (0);
} */

int main()
{
    int fd;
    char *line;

    fd = open("f_test", O_RDONLY);
    if (fd == -1)
    {
        printf("Error al abrir el archivo\n");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("****************%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}