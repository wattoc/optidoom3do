// ========= My externs ========

#include <Burger.h>
#include <celutils.h>

#include "doomopts.h"


#define LIGHTSCALESHIFT 3


typedef struct MyCCB {		/* Clone of the CCB Block from the 3DO includes */
	uint32 ccb_Flags;
	struct MyCCB *ccb_NextPtr;
	CelData    *ccb_SourcePtr;
	void       *ccb_PLUTPtr;
	Coord ccb_XPos;
	Coord ccb_YPos;
	int32  ccb_HDX;
	int32  ccb_HDY;
	int32  ccb_VDX;
	int32  ccb_VDY;
	int32  ccb_HDDX;
	int32  ccb_HDDY;
	uint32 ccb_PIXC;
	uint32 ccb_PRE0;
	uint32 ccb_PRE1;
} MyCCB;			/* I DON'T include width and height */

typedef struct {
    Word xStart;
    Word xEnd;
	Byte *data;			/* Pointer to raw texture data */
	Word width;			/* Width of texture in pixels */
	Word height;		/* Height of texture in pixels */
	int topheight;		/* Top texture height in global pixels */
	int bottomheight;	/* Bottom texture height in global pixels */
	Word texturemid;	/* Anchor point for texture */
} drawtex_t;

typedef struct {
    int scale;
    Word column;
    Word light;
} viscol_t;


// In phase6.c
extern int *scaleArrayData;
extern bool background_clear;


// In phase6_1.c
void SegLoop(viswall_t *segl);
void PrepareSegLoop(void);
void initCCBarraySky(void);

extern bool skyOnView;


// In phase6_2.c

void initCCBarrayWall(void);
void initCCBarrayWallFlat(void);

void DrawSegFull(viswall_t *segl, int *scaleData);
void DrawSegFullUnshaded(viswall_t *segl, int *scaleData);
void DrawSegFullFlat(viswall_t *segl, int *scaleData);
void DrawSegFullFlatUnshaded(viswall_t *segl, int *scaleData);
void DrawSegHalf(viswall_t *segl, int *scaleData);
void DrawSegHalfUnshaded(viswall_t *segl, int *scaleData);
void drawCCBarray(MyCCB* lastCCB, MyCCB *CCBArrayPtr);


// In phase6PL.c
void DrawSegUnshadedPL(viswall_t *segl, int *scaleData);
void DrawSegWireframePL(viswall_t *segl, int *scaleData);
void initCCBQuadWallFlat(void);
void initCCBQuadWallTextured(void);


// In phase7.c
void initCCBarrayFloor(void);
void initCCBarrayFloorFlat(void);
void initCCBarrayFloorFlatVertical(void);
void initSpanDrawFunc(void);


// In phase8.c
extern Word spriteLight;


// In threedo.c
extern int frameTime;
void printDbg(int value);
void updateScreenAndWait(void);
void DisableHardwareClippingWithoutFlush(void);

// In threedor.c
extern Byte *SpanPtr;
extern Byte *CelLine190;            // strange pointer to something having to do with one of the sprite routines
extern Word LightTable[32];

void initAllCCBelements(void);
void FlushCCBs(void);
void resetSpanPointer(void);
void AddCelToCurrentCCB(CCB* cel);
void setColorGradient16(int c0, int c1, int r0, int g0, int b0, int r1, int g1, int b1, uint16* bmp);
void DrawASpan(Word Count,LongWord xfrac,LongWord yfrac,Fixed ds_xstep,Fixed ds_ystep,Byte *Dest);
void DrawASpanLo(Word Count,LongWord xfrac,LongWord yfrac,Fixed ds_xstep,Fixed ds_ystep,Byte *Dest);
void DrawThickLine(Word x1,Word y1,Word x2,Word y2,Word color);
void clearSpanArray(void);
int getSkyScale(unsigned int i);

// In xskies.c
void initNewSkies(void);
int getSkyHeight(unsigned int i);
void drawNewSky(int which);
void updateFireSkyHeightPal(void);

// In ammain.c
extern Boolean ShowAllLines;
extern Boolean ShowAllThings;

void setAutomapLines(bool enabled);
void setAutomapItems(bool enabled);
void toggleNoclip(player_t *player);
void toggleIDDQD(player_t *player);
void applyIDKFA(player_t *player);
void toggleFlyMode(player_t *player);

// In mobj.c
void P_SpawnBloodParticle(Fixed x,Fixed y,Fixed z,Word damage);
void P_SpawnPuffParticle(Fixed x,Fixed y,Fixed z);

// In omain.c
void resetMenuOptions(void);
void setPrimaryMenuOptions(void);


// In modmenu.c
extern bool loadPsxSamples;
void startModMenu(void);
