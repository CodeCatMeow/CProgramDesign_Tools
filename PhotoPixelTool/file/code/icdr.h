/***************
 * 初始化和关闭图形界面
 * **************/

#ifndef _ICDR_H_
#define _ICDR_H_

#include "SVGAUTIL.H"
#include "svga256.h"
#include "mouse.h"

/* 定义颜色名称和编号 */
#ifndef _WIN_RGB_CODE_
#define _WIN_RGB_CODE_

/* 宏定义色表，调用时只用在RGB后加上RGB编码，方便调用 */
enum RGB
{
	RGB000000,
	RGB800000,
	RGB008000,
	RGB808000,
	RGB000080,
	RGB800080,
	RGB008080,
	RGB808080,
	RGBc0dcc0,
	RGBa6caf0,
	RGB2a3faa,
	RGB2a3fff,
	RGB2a5f00,
	RGB2a5f55,
	RGB2a5faa,
	RGB2a5fff,
	RGB2a7f00,
	RGB2a7f55,
	RGB2a7faa,
	RGB2a7fff,
	RGB2a9f00,
	RGB2a9f55,
	RGB2a9faa,
	RGB2a9fff,
	RGB2abf00,
	RGB2abf55,
	RGB2abfaa,
	RGB2abfff,
	RGB2adf00,
	RGB2adf55,
	RGB2adfaa,
	RGB2adfff,
	RGB2aff00,
	RGB2aff55,
	RGB2affaa,
	RGB2affff,
	RGB550000,
	RGB550055,
	RGB5500aa,
	RGB5500ff,
	RGB551f00,
	RGB551f55,
	RGB551faa,
	RGB551fff,
	RGB553f00,
	RGB553f55,
	RGB553faa,
	RGB553fff,
	RGB555f00,
	RGB555f55,
	RGB555faa,
	RGB555fff,
	RGB557f00,
	RGB557f55,
	RGB557faa,
	RGB557fff,
	RGB559f00,
	RGB559f55,
	RGB559faa,
	RGB559fff,
	RGB55bf00,
	RGB55bf55,
	RGB55bfaa,
	RGB55bfff,
	RGB55df00,
	RGB55df55,
	RGB55dfaa,
	RGB55dfff,
	RGB55ff00,
	RGB55ff55,
	RGB55ffaa,
	RGB55ffff,
	RGB7f0000,
	RGB7f0055,
	RGB7f00aa,
	RGB7f00ff,
	RGB7f1f00,
	RGB7f1f55,
	RGB7f1faa,
	RGB7f1fff,
	RGB7f3f00,
	RGB7f3f55,
	RGB7f3faa,
	RGB7f3fff,
	RGB7f5f00,
	RGB7f5f55,
	RGB7f5faa,
	RGB7f5fff,
	RGB7f7f00,
	RGB7f7f55,
	RGB7f7faa,
	RGB7f7fff,
	RGB7f9f00,
	RGB7f9f55,
	RGB7f9faa,
	RGB7f9fff,
	RGB7fbf00,
	RGB7fbf55,
	RGB7fbfaa,
	RGB7fbfff,
	RGB7fdf00,
	RGB7fdf55,
	RGB7fdfaa,
	RGB7fdfff,
	RGB7fff00,
	RGB7fff55,
	RGB7fffaa,
	RGB7fffff,
	RGBaa0000,
	RGBaa0055,
	RGBaa00aa,
	RGBaa00ff,
	RGBaa1f00,
	RGBaa1f55,
	RGBaa1faa,
	RGBaa1fff,
	RGBaa3f00,
	RGBaa3f55,
	RGBaa3faa,
	RGBaa3fff,
	RGBaa5f00,
	RGBaa5f55,
	RGBaa5faa,
	RGBaa5fff,
	RGBaa7f00,
	RGBaa7f55,
	RGBaa7faa,
	RGBaa7fff,
	RGBaa9f00,
	RGBaa9f55,
	RGBaa9faa,
	RGBaa9fff,
	RGBaabf00,
	RGBaabf55,
	RGBaabfaa,
	RGBaabfff,
	RGBaadf00,
	RGBaadf55,
	RGBaadfaa,
	RGBaadfff,
	RGBaaff00,
	RGBaaff55,
	RGBaaffaa,
	RGBaaffff,
	RGBd40000,
	RGBd40055,
	RGBd400aa,
	RGBd400ff,
	RGBd41f00,
	RGBd41f55,
	RGBd41faa,
	RGBd41fff,
	RGBd43f00,
	RGBd43f55,
	RGBd43faa,
	RGBd43fff,
	RGBd45f00,
	RGBd45f55,
	RGBd45faa,
	RGBd45fff,
	RGBd47f00,
	RGBd47f55,
	RGBd47faa,
	RGBd47fff,
	RGBd49f00,
	RGBd49f55,
	RGBd49faa,
	RGBd49fff,
	RGBd4bf00,
	RGBd4bf55,
	RGBd4bfaa,
	RGBd4bfff,
	RGBd4df00,
	RGBd4df55,
	RGBd4dfaa,
	RGBd4dfff,
	RGBd4ff00,
	RGBd4ff55,
	RGBd4ffaa,
	RGBd4ffff,
	RGBff0055,
	RGBff00aa,
	RGBff1f00,
	RGBff1f55,
	RGBff1faa,
	RGBff1fff,
	RGBff3f00,
	RGBff3f55,
	RGBff3faa,
	RGBff3fff,
	RGBff5f00,
	RGBff5f55,
	RGBff5faa,
	RGBff5fff,
	RGBff7f00,
	RGBff7f55,
	RGBff7faa,
	RGBff7fff,
	RGBff9f00,
	RGBff9f55,
	RGBff9faa,
	RGBff9fff,
	RGBffbf00,
	RGBffbf55,
	RGBffbfaa,
	RGBffbfff,
	RGBffdf00,
	RGBffdf55,
	RGBffdfaa,
	RGBffdfff,
	RGBffff55,
	RGBffffaa,
	RGBccccff,
	RGBffccff,
	RGB33ffff,
	RGB66ffff,
	RGB99ffff,
	RGBccffff,
	RGB007f00,
	RGB007f55,
	RGB007faa,
	RGB007fff,
	RGB009f00,
	RGB009f55,
	RGB009faa,
	RGB009fff,
	RGB00bf00,
	RGB00bf55,
	RGB00bfaa,
	RGB00bfff,
	RGB00df00,
	RGB00df55,
	RGB00dfaa,
	RGB00dfff,
	RGB00ff55,
	RGB00ffaa,
	RGB2a0000,
	RGB2a0055,
	RGB2a00aa,
	RGB2a00ff,
	RGB2a1f00,
	RGB2a1f55,
	RGB2a1faa,
	RGB2a1fff,
	RGB2a3f00,
	RGB2a3f55,
	RGBfffbf0,
	RGBa0a0a4,
	RGBff0000 = 249,
	RGB00ff00,
	RGBffff00,
	RGB0000ff,
	RGBff00ff,
	RGB00ffff,
	RGBffffff,
};

#endif
//函数声明
/********************************
 * FUNCTION:detectSVGA256, initsvga256, closesvga256
 * DESCRIPTION:初始化函数和关闭画图模式函数
 * INPUT:无
 * RETURN:成功返回1， 不成功返回0
 * OTHERS:初始化svga驱动，以便于使用SVGA绘制图形；关闭图形模式
 ********************************/
int huge detectSVGA256(void); //初始化所必须函数
int initsvga256(void);		  //初始化图像模式
int closesvga256(void);		  //关闭图像模式

/********************************
 * FUNCTION:initcolor256
 * DESCRIPTION:初始化Windows系统256色
 * INPUT:无
 * RETURN:无
 * OTHERS:无
 ********************************/
DacPalette256 *getwinRGB(void);
void initcolor256(void);

/********************************
 * FUNCTION:record_imagedata
 * DESCRIPTION:通过文件操作记录图像数据函数
 * INPUT:矩形坐标，数据文件名
 * RETURN:无
 * OTHERS:无
 ********************************/
void record_imagedata(int x1, int x2, int y1, int y2, char *filename);

/********************************
 * FUNCTION:write_imagedata
 * DESCRIPTION:从数据库读文件并将其写在屏幕上
 * INPUT:矩形坐标，数据库名称
 * RETURN:无
 * OTHERS:无
 ********************************/
void write_imagedata(int x1, int x2, int y1, int y2, char *filename);

/********************************
 * FUNCTION:write_photodata
 * DESCRIPTION:写屏辅助函数，读取生成的图片数据并画图
 * INPUT:文件名（绝对路径），图片左上角坐标
 * RETURN:无
 * OTHERS:无
 ********************************/
void write_photodata(char *filename, int x, int y);

#endif