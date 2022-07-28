/*
		MEANT FOR PSX
		
		SCEA & HDFSYU
		ok i was trying to look cool by doing all this complex wording and my C is RUSTy because i havent coded in a long time
*/
// libs
#include <sys/types.h>
#include <stdio.h>
#include <libetc.h>
#include <libgte.h>
#include <libgpu.h>
#define OTLEN 8
DISPENV disp[2];
DRAWENV draw[2];
int db = 0;
u_long ot[2][OTLEN];
char pribuff[2][32768];
char *nextpri;
void display(){
    DrawSync(0);
    VSync(0);
    PutDispEnv(&disp[db]);
    PutDrawEnv(&draw[db]);
    SetDispMask(1);
    DrawOTag(ot[db]+OTLEN-1);
    db = !db;
    nextpri = pribuff[db];
}
int main() { // main function
    TILE *tile;
    ResetGraph(0);
    SetDefDispEnv(&disp[0], 0, 0, 320, 240);
    SetDefDrawEnv(&draw[0], 0, 240, 320, 240);
    SetDefDispEnv(&disp[1], 0, 240, 320, 240);
    SetDefDrawEnv(&draw[1], 0, 0, 320, 240);
    draw[0].isbg = 1;
    setRGB0(&draw[0], 14, 29, 161);
    draw[1].isbg = 1;
    setRGB0(&draw[1], 14, 29, 161);
    nextpri = pribuff[0];
    while(1) { // loop
        ClearOTagR(ot[db], OTLEN);
        tile = (TILE*)nextpri;
        setTile(tile);
        setXY0(tile, 32, 32);
        setWH(tile, 64, 64);
        setRGB0(tile, 138, 42, 28);
        addPrim(ot[db], tile);
        nextpri += sizeof(TILE);
        display();
    }
    return 0;
}
// end