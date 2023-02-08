#include "Fatfs.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define FILES 25
#define MAXSIZE 11
#define PHOTONUMBER 5

extern void getBmpFile(void);
extern void showPhoto(void);

char *nameOfFiles[FILES];

void allocSize(unsigned int *index , FILINFO *files) {
		nameOfFiles[*index] = malloc(MAXSIZE);
		sprintf(nameOfFiles[(*index)++], "%-11.11s", files->fname);
}

void getBmpFile(void) {
	static FATFS fs;
	static FILINFO files;
	static DIR dir;
	uint32_t index = 0;
	
	for(int i = 0; i < FILES; i++) nameOfFiles[i] = NULL;
  	if(f_mount(&fs, (TCHAR const*)"",0)) while(1);
	if(f_findfirst(&dir, &files, "0:/", "*.bmp")) while(1);

  while (files.fname[0]) {
      if(index < FILES) allocSize(&index, &files);
      f_findnext(&dir, &files);
  }

  f_closedir(&dir);
}

void openFile(FIL *fil, const char *name) {
	if(f_open(fil, name, FA_READ)) while(1);
}

void showPhoto(void) {
	static UINT currentPhoto = 0;
	static FIL fil;
	static char *pBmp = NULL;
	UINT ptr, index, Xaxis, Yaxis;
	char name[30];
	int temp;
	
	GUI_Clear();
	ptr = NULL;
	ptr = GUI_ALLOC_AllocZero(f_size(&fil));
	if(currentPhoto >= PHOTONUMBER) currentPhoto = 0;
	sprintf (name, "0:/%-11.11s", nameOfFiles[currentPhoto]);
	currentPhoto = currentPhoto + 1;
	openFile(&fil, name);
	pBmp = GUI_ALLOC_h2p(ptr);
	if(f_read(&fil, pBmp, f_size(&fil), &index)) while(1);
	Xaxis = GUI_BMP_GetXSize(pBmp);		
	Yaxis = GUI_BMP_GetYSize(pBmp);
	temp = ((Xaxis - 480) > (Yaxis - 272)) ? 0 : 1;
	
	switch(temp) {
		case 0 : GUI_BMP_DrawScaled(pBmp, 0, 0, 480, Xaxis); break;
		case 1 : GUI_BMP_DrawScaled(pBmp, 0, 0, 272, Yaxis); break;
		default : break;
	}
	
	f_close(&fil);
	GUI_ALLOC_Free(ptr);
}
