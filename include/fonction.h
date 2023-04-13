#ifndef STU_H_

#define STU_H_

int stu_dprintf(int fd, const char *pattern, ...);
int stu_cputs(const char c, int fd);
int stu_sputs(const char *str, int fd);
int stu_dputs(int nbr, int fd);
int stu_xputs(char *str, int fd);
int d_bourrage(int src, int fd, const char *pattern, int i);
int c_bourrage(char src, int fd, const char *pattern, int i);
int s_bourrage(char *src, int fd, const char *pattern, int i);
int x_bourrage(char *src, int fd, const char *pattern, int i);
int get_digit(int nb, int index);
int nb_len(int nb);
unsigned int stu_strlen(const char *str);
char *stu_strdup(const char *src);
char *stu_strcpy(char *dest, const char *src);
int counter(int j, const char *pattern);
int hexa(char *src);
int d_bourrage_ne(int src, int fd, const char *pattern, int);
int bour(int src, int fd, const char *pattern, int);

#endif
