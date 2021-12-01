//
// Created by HRF on 2021/11/15.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 47
#define FILE_NAME "exercises/ch13/files/wordy"

int main(void) {
    FILE *fp;
    char words[MAX];
    int word_count = 0;

    // 检查文件是否能正常打开，并获取文件句柄
    if ((fp = fopen(FILE_NAME, "a+")) == NULL) {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    // 将文件定位到文件开始
    rewind(fp);
    while (fgets(words, MAX, fp) != NULL)
        // 统计单词总个数
        word_count++;
    // 再次将文件定位到文件开始
    rewind(fp);

    // 提示用户输入单词
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        // 将新的单词和编号按照格式添加到文件最后
        fprintf(fp, "%3d: %s\n", ++word_count, words);

    // 显示文件内容
    puts("File contents:");
    rewind(fp);
    while (fgets(words, MAX, fp) != NULL)
        fputs(words, stdout);

    // 检查文件是否能正常关闭，并关闭文件
    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file\n");
    }
    puts("Done!");

    return 0;
}
