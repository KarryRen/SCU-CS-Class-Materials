#include "sfs_api.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// 处理最后命令最后的空格
void shell_remove_space(char *buf)
{
    if (buf[strlen(buf) - 1] == ' ' || buf[strlen(buf) - 1] == '\n')
        buf[strlen(buf) - 1] = '\0';
    if (buf[0] == ' ' || buf[0] == '\n')
        memmove(buf, buf + 1, strlen(buf));
}

// 分割输入的命令
void shell_tokenize_buffer(char **param, int *nr, char *buf, const char *c)
{
    char *token;
    token = strtok(buf, c);
    int pc = -1;
    while (token)
    {
        param[++pc] = malloc(sizeof(token) + 1);
        strcpy(param[pc], token);
        shell_remove_space(param[pc]);
        token = strtok(NULL, c);
    }
    param[++pc] = NULL;
    *nr = pc;
}

void shell_print_prefix()
{
    printf("\n>>> ");
}

void shell_clear()
{
    system("clear");
}

void shell_create_file(char *file_name)
{
    int fid = sfs_open(file_name);
    sfs_close(fid);

    printf("%s 创建成功！", file_name);
}

void shell_del_file(char *file_name)
{
    int fid = sfs_open(file_name);
    // sfs_close(fid);
    sfs_del(fid);
    printf("%s 删除成功", file_name);
}

void shell_print_intro()
{

    puts("         ┌─┐       ┌─┐");
    puts("      ┌──┘ ┴───────┘ ┴──┐");
    puts("      │                 │");
    puts("      │       ───       │");
    puts("      │  ─┬┘       └┬─  │");
    puts("      │                 │");
    puts("      │       ─┴─       │");
    puts("      │                 │");
    puts("      └───┐         ┌───┘");
    puts("          │         │");
    puts("          │         │");
    puts("          │         │");
    puts("          │         └──────────────┐");
    puts("          │                        │");
    puts("          │                        ├─┐");
    puts("          │                        ┌─┘");
    puts("          │                        │");
    puts("          └─┐  ┐  ┌───────┬──┐  ┌──┘");
    puts("            │ ─┤ ─┤       │ ─┤ ─┤");
    puts("            └──┴──┘       └──┴──┘");
    puts("                神兽保佑");
    puts("                代码无BUG!");
    sleep(4);
}

void shell_read_file(char *file_name)
{
    int buff_size = 4096 * 2;
    int fid = sfs_open(file_name);
    char buff[buff_size];
    int fsize = sfs_read(fid, buff, buff_size);
    if (buff[fsize - 1] != '\0')
        buff[fsize - 1] = '\0';

    sfs_close(fid);
    printf("\n%s", buff);
}

void shell_write_file(char *file_name, char *content)
{
    int buff_size = 4096 * 2;
    int fid = sfs_open(file_name);
    sfs_write(fid, content, strlen(content) + 1);

    sfs_close(fid);
}

int main(void)
{
    char buf[500], *params1[100];
    int nr = 0;
    shell_print_intro();
    // getc();
    sfs_system_init();
    shell_clear();
    shell_print_prefix();
    while (1)
    {
        fgets(buf, 500, stdin); // buffer overflow cannot happen
        shell_tokenize_buffer(params1, &nr, buf, " ");

        if (strstr(params1[0], "ls"))
        {
            sfs_ls();
        }
        else if (strstr(params1[0], "exit"))
        {
            break;
        }
        else if (strstr(params1[0], "create"))
        {
            shell_create_file(params1[1]);
        }
        else if (strstr(params1[0], "rm"))
        {
            shell_del_file(params1[1]);
        }
        else if (strstr(params1[0], "read"))
        {
            shell_read_file(params1[1]);
        }
        else if (strstr(params1[0], "write"))
        {
            shell_write_file(params1[1], params1[2]);
        }
        else if (strstr(params1[0], "clear"))
        {
            shell_clear();
        }
        else
        {
            printf("Command %s not found!\n", params1[0]);
        }
        shell_print_prefix();
    }
    sfs_system_close();
    return 0;
}
