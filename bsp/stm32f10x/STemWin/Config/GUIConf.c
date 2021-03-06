#include "GUI.h"
#include <rtthread.h>


#define USE_EXRAM  0//使用内部RAM
//设置EMWIN内存大小
#define GUI_NUMBYTES  (150*1024)
#define GUI_BLOCKSIZE 256  //块大小


//GUI_X_Config
//初始化的时候调用,用来设置emwin所使用的内存
void GUI_X_Config(void) 
{
	U32 *aMemory = rt_malloc(GUI_NUMBYTES); //从内部RAM中分配GUI_NUMBYTES字节的内存
//	rt_memset(aMemory, 0, GUI_NUMBYTES);
	GUI_ALLOC_AssignMemory((U32 *)aMemory, GUI_NUMBYTES); //为存储管理系统分配一个存储块
	GUI_ALLOC_SetAvBlockSize(GUI_BLOCKSIZE); //设置存储快的平均尺寸,该区越大,可用的存储快数量越少
	GUI_SetDefaultFont(GUI_FONT_6X8); //设置默认字体
}
