/************************************
 * 写屏代码输出 辅助脚本
 *
 * 调用格式：name.exe dataFileName[数据源文件路径] outFileName[输出数据文件路径]
 * ***********************************/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(int argc, char **argv)
{
    // 参数初始化
    FILE *fp_r, *fp_w;
    char RGB_r[10];
    unsigned char num;
    int i;
    short dx, dy, dx_;
    unsigned long pixel;
    unsigned long int win_rgb[256] = {
        0x000000,
        0x800000,
        0x008000,
        0x808000,
        0x000080,
        0x800080,
        0x008080,
        0x808080,
        0xc0dcc0,
        0xa6caf0,
        0x2a3faa,
        0x2a3fff,
        0x2a5f00,
        0x2a5f55,
        0x2a5faa,
        0x2a5fff,
        0x2a7f00,
        0x2a7f55,
        0x2a7faa,
        0x2a7fff,
        0x2a9f00,
        0x2a9f55,
        0x2a9faa,
        0x2a9fff,
        0x2abf00,
        0x2abf55,
        0x2abfaa,
        0x2abfff,
        0x2adf00,
        0x2adf55,
        0x2adfaa,
        0x2adfff,
        0x2aff00,
        0x2aff55,
        0x2affaa,
        0x2affff,
        0x550000,
        0x550055,
        0x5500aa,
        0x5500ff,
        0x551f00,
        0x551f55,
        0x551faa,
        0x551fff,
        0x553f00,
        0x553f55,
        0x553faa,
        0x553fff,
        0x555f00,
        0x555f55,
        0x555faa,
        0x555fff,
        0x557f00,
        0x557f55,
        0x557faa,
        0x557fff,
        0x559f00,
        0x559f55,
        0x559faa,
        0x559fff,
        0x55bf00,
        0x55bf55,
        0x55bfaa,
        0x55bfff,
        0x55df00,
        0x55df55,
        0x55dfaa,
        0x55dfff,
        0x55ff00,
        0x55ff55,
        0x55ffaa,
        0x55ffff,
        0x7f0000,
        0x7f0055,
        0x7f00aa,
        0x7f00ff,
        0x7f1f00,
        0x7f1f55,
        0x7f1faa,
        0x7f1fff,
        0x7f3f00,
        0x7f3f55,
        0x7f3faa,
        0x7f3fff,
        0x7f5f00,
        0x7f5f55,
        0x7f5faa,
        0x7f5fff,
        0x7f7f00,
        0x7f7f55,
        0x7f7faa,
        0x7f7fff,
        0x7f9f00,
        0x7f9f55,
        0x7f9faa,
        0x7f9fff,
        0x7fbf00,
        0x7fbf55,
        0x7fbfaa,
        0x7fbfff,
        0x7fdf00,
        0x7fdf55,
        0x7fdfaa,
        0x7fdfff,
        0x7fff00,
        0x7fff55,
        0x7fffaa,
        0x7fffff,
        0xaa0000,
        0xaa0055,
        0xaa00aa,
        0xaa00ff,
        0xaa1f00,
        0xaa1f55,
        0xaa1faa,
        0xaa1fff,
        0xaa3f00,
        0xaa3f55,
        0xaa3faa,
        0xaa3fff,
        0xaa5f00,
        0xaa5f55,
        0xaa5faa,
        0xaa5fff,
        0xaa7f00,
        0xaa7f55,
        0xaa7faa,
        0xaa7fff,
        0xaa9f00,
        0xaa9f55,
        0xaa9faa,
        0xaa9fff,
        0xaabf00,
        0xaabf55,
        0xaabfaa,
        0xaabfff,
        0xaadf00,
        0xaadf55,
        0xaadfaa,
        0xaadfff,
        0xaaff00,
        0xaaff55,
        0xaaffaa,
        0xaaffff,
        0xd40000,
        0xd40055,
        0xd400aa,
        0xd400ff,
        0xd41f00,
        0xd41f55,
        0xd41faa,
        0xd41fff,
        0xd43f00,
        0xd43f55,
        0xd43faa,
        0xd43fff,
        0xd45f00,
        0xd45f55,
        0xd45faa,
        0xd45fff,
        0xd47f00,
        0xd47f55,
        0xd47faa,
        0xd47fff,
        0xd49f00,
        0xd49f55,
        0xd49faa,
        0xd49fff,
        0xd4bf00,
        0xd4bf55,
        0xd4bfaa,
        0xd4bfff,
        0xd4df00,
        0xd4df55,
        0xd4dfaa,
        0xd4dfff,
        0xd4ff00,
        0xd4ff55,
        0xd4ffaa,
        0xd4ffff,
        0xff0055,
        0xff00aa,
        0xff1f00,
        0xff1f55,
        0xff1faa,
        0xff1fff,
        0xff3f00,
        0xff3f55,
        0xff3faa,
        0xff3fff,
        0xff5f00,
        0xff5f55,
        0xff5faa,
        0xff5fff,
        0xff7f00,
        0xff7f55,
        0xff7faa,
        0xff7fff,
        0xff9f00,
        0xff9f55,
        0xff9faa,
        0xff9fff,
        0xffbf00,
        0xffbf55,
        0xffbfaa,
        0xffbfff,
        0xffdf00,
        0xffdf55,
        0xffdfaa,
        0xffdfff,
        0xffff55,
        0xffffaa,
        0xccccff,
        0xffccff,
        0x33ffff,
        0x66ffff,
        0x99ffff,
        0xccffff,
        0x007f00,
        0x007f55,
        0x007faa,
        0x007fff,
        0x009f00,
        0x009f55,
        0x009faa,
        0x009fff,
        0x00bf00,
        0x00bf55,
        0x00bfaa,
        0x00bfff,
        0x00df00,
        0x00df55,
        0x00dfaa,
        0x00dfff,
        0x00ff55,
        0x00ffaa,
        0x2a0000,
        0x2a0055,
        0x2a00aa,
        0x2a00ff,
        0x2a1f00,
        0x2a1f55,
        0x2a1faa,
        0x2a1fff,
        0x2a3f00,
        0x2a3f55,
        0xfffbf0,
        0xa0a0a4,
        0x808080,
        0xff0000,
        0x00ff00,
        0xffff00,
        0x0000ff,
        0xff00ff,
        0x00ffff,
        0xffffff,
    }; // windows系统配色

    char *dataFileName;
    char *outFileName;
    // 文件名读取
    if (argc != 3)
    {
        printf("参数值错误！退出程序");
        getch();
        exit(1);
    }
    else
    {
        dataFileName = argv[1];
        outFileName = argv[2];
    }

    if ((fp_r = fopen(dataFileName, "r")) == NULL) // 只读
    {
        printf("不能打开文件 %s，任意键退出！\n", dataFileName);
        getch();
        exit(1);
    }
    if ((fp_w = fopen(outFileName, "wb")) == NULL)
    {
        printf("不能打开文件 %s，任意键退出！\n", outFileName);
        getch();
        exit(1);
    }

    printf("对文件%s进行解析，输出将保存于%s中\n", dataFileName, outFileName);

    rewind(fp_r);
    dx = 0;
    dy = 0;
    dx_ = 0;
    fwrite(&dx, sizeof(dx), 1, fp_w);
    fwrite(&dy, sizeof(dy), 1, fp_w);
    while (fgetc(fp_r) != EOF)
    {
        fseek(fp_r, -1L, SEEK_CUR);
        fscanf(fp_r, "%s", RGB_r); // 读取数字

        pixel = atol(RGB_r);
        for (i = 0; i < 256; i++) // 查找编号
        {
            if (pixel == win_rgb[i])
            {
                num = i;
                break;
            }
        }
        fputc(num, fp_w); // 输入
        dx_++;
        if (fgetc(fp_r) == '\n')
        {
            dx = dx_;
            dx_ = 0;
            dy++;
        }
    }
    rewind(fp_w);
    fwrite(&dx, sizeof(dx), 1, fp_w);
    fwrite(&dy, sizeof(dy), 1, fp_w);
    fclose(fp_r);
    fclose(fp_w);
    printf("完成数据保存\n数据保存在文件 %s 中\n", outFileName);
    // getch();
    return 0;
}