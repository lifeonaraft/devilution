//HEADER_GOES_HERE

#include "../types.h"

char L5dungeon[80][80];
char mydflags[40][40];
int setloadflag; // weak
int HR1;
int HR2;
int HR3;
int VR1;
int VR2;
int VR3;
void *pSetPiece; // idb

const ShadowStruct SPATS[37] =
{
  { 7, 13, 0, 13, 144, 0, 142 },
  { 16, 13, 0, 13, 144, 0, 142 },
  { 15, 13, 0, 13, 145, 0, 142 },
  { 5, 13, 13, 13, 152, 140, 139 },
  { 5, 13, 1, 13, 143, 146, 139 },
  { 5, 13, 13, 2, 143, 140, 148 },
  { 5, 0, 1, 2, 0, 146, 148 },
  { 5, 13, 11, 13, 143, 147, 139 },
  { 5, 13, 13, 12, 143, 140, 149 },
  { 5, 13, 11, 12, 150, 147, 149 },
  { 5, 13, 1, 12, 143, 146, 149 },
  { 5, 13, 11, 2, 143, 147, 148 },
  { 9, 13, 13, 13, 144, 140, 142 },
  { 9, 13, 1, 13, 144, 146, 142 },
  { 9, 13, 11, 13, 151, 147, 142 },
  { 8, 13, 0, 13, 144, 0, 139 },
  { 8, 13, 0, 12, 143, 0, 149 },
  { 8, 0, 0, 2, 0, 0, 148 },
  { 11, 0, 0, 13, 0, 0, 139 },
  { 11, 13, 0, 13, 139, 0, 139 },
  { 11, 2, 0, 13, 148, 0, 139 },
  { 11, 12, 0, 13, 149, 0, 139 },
  { 11, 13, 11, 12, 139, 0, 149 },
  { 14, 0, 0, 13, 0, 0, 139 },
  { 14, 13, 0, 13, 139, 0, 139 },
  { 14, 2, 0, 13, 148, 0, 139 },
  { 14, 12, 0, 13, 149, 0, 139 },
  { 14, 13, 11, 12, 139, 0, 149 },
  { 10, 0, 13, 0, 0, 140, 0 },
  { 10, 13, 13, 0, 140, 140, 0 },
  { 10, 0, 1, 0, 0, 146, 0 },
  { 10, 13, 11, 0, 140, 147, 0 },
  { 12, 0, 13, 0, 0, 140, 0 },
  { 12, 13, 13, 0, 140, 140, 0 },
  { 12, 0, 1, 0, 0, 146, 0 },
  { 12, 13, 11, 0, 140, 147, 0 },
  { 3, 13, 11, 12, 150, 0, 0 }
};
const unsigned char BSTYPES[206] =
{
	0,   1,   2,   3,   4,   5,   6,   7,   8,   9,
   10,  11,  12,  13,  14,  15,  16,  17,   0,   0,
	0,   0,   0,   0,   0,   1,   2,  10,   4,   5,
	6,   7,   8,   9,  10,  11,  12,  14,   5,  14,
   10,   4,  14,   4,   5,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   1,
	2,   3,   4,   1,   6,   7,  16,  17,   2,   1,
	1,   2,   2,   1,   1,   2,   2,   2,   2,   2,
	1,   1,  11,   1,  13,  13,  13,   1,   2,   1,
	2,   1,   2,   1,   2,   2,   2,   2,  12,   0,
	0,  11,   1,  11,   1,  13,   0,   0,   0,   0,
	0,   0,   0,  13,  13,  13,  13,  13,  13,  13,
   13,  13,  13,  13,  13,  13,   1,  11,   2,  12,
   13,  13,  13,  12,   2,   1,   2,   2,   4,  14,
	4,  10,  13,  13,   4,   4,   1,   1,   4,   2,
	2,  13,  13,  13,  13,  25,  26,  28,  30,  31,
   41,  43,  40,  41,  42,  43,  25,  41,  43,  28,
   28,   1,   2,  25,  26,  22,  22,  25,  26,   0,
	0,   0,   0,   0,   0,   0
};
const unsigned char L5BTYPES[206] =
{
	0,   1,   2,   3,   4,   5,   6,   7,   8,   9,
   10,  11,  12,  13,  14,  15,  16,  17,   0,   0,
	0,   0,   0,   0,   0,  25,  26,   0,  28,   0,
   30,  31,   0,   0,   0,   0,   0,   0,   0,   0,
   40,  41,  42,  43,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,  79,
   80,   0,  82,   0,   0,   0,   0,   0,   0,  79,
	0,  80,   0,   0,  79,  80,   0,   2,   2,   2,
	1,   1,  11,  25,  13,  13,  13,   1,   2,   1,
	2,   1,   2,   1,   2,   2,   2,   2,  12,   0,
	0,  11,   1,  11,   1,  13,   0,   0,   0,   0,
	0,   0,   0,  13,  13,  13,  13,  13,  13,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0
};
const unsigned char STAIRSUP[] = { 4, 4, 13, 13, 13, 13, 2, 2, 2, 2, 13, 13, 13, 13, 13, 13, 13, 13, 0, 66, 6, 0, 63, 64, 65, 0, 0, 67, 68, 0, 0, 0, 0, 0 };
const unsigned char L5STAIRSUP[] = { 4, 4, 22, 22, 22, 22, 2, 2, 2, 2, 13, 13, 13, 13, 13, 13, 13, 13, 0, 66, 23, 0, 63, 64, 65, 0, 0, 67, 68, 0, 0, 0, 0, 0 };
const unsigned char STAIRSDOWN[] = { 4, 3, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 62, 57, 58, 0, 61, 59, 60, 0, 0, 0, 0, 0 };
const unsigned char LAMPS[] = { 2, 2, 13, 0, 13, 13, 129, 0, 130, 128 };
const unsigned char PWATERIN[] = { 6, 6, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 202, 200, 200, 84, 0, 0, 199, 203, 203, 83, 0, 0, 85, 206, 80, 81, 0, 0, 0, 134, 135, 0, 0, 0, 0, 0, 0, 0, 0 };

/* data */
unsigned char L5ConvTbl[16] = { 22u, 13u, 1u, 13u, 2u, 13u, 13u, 13u, 4u, 13u, 1u, 13u, 2u, 13u, 16u, 13u };

void __cdecl DRLG_Init_Globals()
{
	char c;

	memset(dFlags, 0, sizeof(dFlags));
	memset(dPlayer, 0, sizeof(dPlayer));
	memset(dMonster, 0, sizeof(dMonster));
	memset(dDead, 0, sizeof(dDead));
	memset(dObject, 0, sizeof(dObject));
	memset(dItem, 0, sizeof(dItem));
	memset(dMissile, 0, sizeof(dMissile));
	memset(dArch, 0, sizeof(dArch));
	if ( !lightflag )
		c = ( light4flag ) ? 3 : 15;
	else
		c = 0;
	memset(dTransVal, c, sizeof(dTransVal));
}
// 525728: using guessed type int light4flag;
// 646A28: using guessed type int lightflag;

void __fastcall LoadL1Dungeon(char *sFileName, int vx, int vy)
{
	char *v3; // esi
	unsigned char *v4; // esi
	signed int v5; // ecx
	signed int v6; // eax
	signed int v7; // edx
	int v8; // edi
	int v9; // ebx
	char *v10; // eax
	int v11; // ecx
	char v12; // dl
	int v13; // [esp+Ch] [ebp-Ch]
	int v14; // [esp+10h] [ebp-8h]
	int v15; // [esp+14h] [ebp-4h]

	v13 = vx;
	dminx = 16;
	dminy = 16;
	v3 = sFileName;
	dmaxx = 96;
	dmaxy = 96;
	DRLG_InitTrans();
	v4 = LoadFileInMem(v3, 0);
	v5 = 0;
	do
	{
		v6 = v5;
		v7 = 40;
		do
		{
			mydflags[0][v6] = 0;
			dungeon[0][v6] = 22;
			v6 += 40;
			--v7;
		}
		while ( v7 );
		++v5;
	}
	while ( v5 < 40 );
	v15 = 0;
	v8 = *v4;
	v9 = v4[2];
	v10 = (char *)(v4 + 4);
	if ( v9 > 0 )
	{
		do
		{
			if ( v8 > 0 )
			{
				v11 = v15;
				v14 = v8;
				do
				{
					v12 = *v10;
					if ( *v10 )
					{
						mydflags[0][v11] |= 0x80u;
						dungeon[0][v11] = v12;
					}
					else
					{
						dungeon[0][v11] = 13;
					}
					v11 += 40;
					v10 += 2;
					--v14;
				}
				while ( v14 );
			}
			++v15;
		}
		while ( v15 < v9 );
	}
	DRLG_L1Floor();
	ViewX = v13;
	ViewY = vy;
	DRLG_L1Pass3();
	DRLG_Init_Globals();
	DRLG_InitL1Vals();
	SetMapMonsters(v4, 0, 0);
	SetMapObjects(v4, 0, 0);
	mem_free_dbg(v4);
}
// 5CF328: using guessed type int dmaxx;
// 5CF32C: using guessed type int dmaxy;
// 5D2458: using guessed type int dminx;
// 5D245C: using guessed type int dminy;

void __cdecl DRLG_L1Floor()
{
	signed int i; // edi
	signed int v1; // esi
	signed int j; // ebx
	int rv; // eax

	i = 0;
	do
	{
		v1 = i;
		j = 40;
		do
		{
			if ( !mydflags[0][v1] && dungeon[0][v1] == 13 )
			{
				rv = random(0, 3);
				if ( rv == 1 )
					dungeon[0][v1] = -94;
				if ( rv == 2 )
					dungeon[0][v1] = -93;
			}
			v1 += 40;
			--j;
		}
		while ( j );
		++i;
	}
	while ( i < 40 );
}

void __cdecl DRLG_L1Pass3()
{
	int v0; // eax
	int *v1; // edx
	int *v2; // eax
	signed int v3; // ecx
	signed int v4; // ebx
	int *v5; // ecx
	unsigned char *v6; // edx
	unsigned short *v7; // esi
	unsigned short v8; // ax
	int v9; // eax
	int v10; // ST24_4
	int v11; // ST20_4
	int v12; // ST1C_4
	signed int v13; // [esp+Ch] [ebp-1Ch]
	int *v14; // [esp+10h] [ebp-18h]
	int v15; // [esp+14h] [ebp-14h]
	int v16; // [esp+18h] [ebp-10h]
	int v17; // [esp+1Ch] [ebp-Ch]
	int v18; // [esp+20h] [ebp-8h]

	v0 = *((unsigned short *)pMegaTiles + 84) + 1;
	v18 = *((unsigned short *)pMegaTiles + 84) + 1;
	_LOWORD(v0) = *((_WORD *)pMegaTiles + 85);
	v17 = ++v0;
	_LOWORD(v0) = *((_WORD *)pMegaTiles + 86);
	v16 = ++v0;
	_LOWORD(v0) = *((_WORD *)pMegaTiles + 87);
	v15 = v0 + 1;
	v1 = dPiece[1];
	do
	{
		v2 = v1;
		v3 = 56;
		do
		{
			*(v2 - 112) = v18;
			*v2 = v17;
			*(v2 - 111) = v16;
			v2[1] = v15;
			v2 += 224;
			--v3;
		}
		while ( v3 );
		v1 += 2;
	}
	while ( (signed int)v1 < (signed int)dPiece[2] );
	v4 = 0;
	v14 = &dPiece[17][16]; /* check */
	do
	{
		v5 = v14;
		v6 = (unsigned char *)dungeon + v4;
		v13 = 40;
		do
		{
			v7 = (unsigned short *)((char *)pMegaTiles + 8 * (*v6 - 1));
			v8 = *v7;
			++v7;
			v9 = v8 + 1;
			v10 = v9;
			_LOWORD(v9) = *v7;
			++v7;
			v11 = ++v9;
			_LOWORD(v9) = *v7;
			v12 = ++v9;
			_LOWORD(v9) = v7[1];
			v6 += 40;
			*(v5 - 112) = v10;
			*v5 = v11;
			*(v5 - 111) = v12;
			v5[1] = v9 + 1;
			v5 += 224;
			--v13;
		}
		while ( v13 );
		v14 += 2;
		++v4;
	}
	while ( v4 < 40 );
}

void __cdecl DRLG_InitL1Vals()
{
	int v0; // esi
	int (*v1)[112]; // edx
	char *v2; // ecx
	int v3; // eax
	char v4; // al
	char v5; // [esp-4h] [ebp-18h]
	signed int v6; // [esp+Ch] [ebp-8h]
	int (*v7)[112]; // [esp+10h] [ebp-4h]

	v0 = 0;
	v7 = dPiece;
	do
	{
		v1 = v7;
		v2 = (char *)dArch + v0;
		v6 = 112;
		do
		{
			v3 = (*v1)[0];
			if ( (*v1)[0] != 12 )
			{
				if ( v3 == 11 )
					goto LABEL_21;
				if ( v3 != 71 )
				{
					if ( v3 == 259 )
					{
						v5 = 5;
LABEL_9:
						v4 = v5;
						goto LABEL_22;
					}
					if ( v3 == 249 || v3 == 325 )
						goto LABEL_21;
					if ( v3 != 321 )
					{
						if ( v3 == 255 )
						{
							v5 = 4;
							goto LABEL_9;
						}
						if ( v3 != 211 )
						{
							if ( v3 == 344 )
								goto LABEL_21;
							if ( v3 != 341 )
							{
								if ( v3 == 331 )
									goto LABEL_21;
								if ( v3 != 418 )
								{
									if ( v3 != 421 )
										goto LABEL_23;
LABEL_21:
									v4 = 2;
									goto LABEL_22;
								}
							}
						}
					}
				}
			}
			v4 = 1;
LABEL_22:
			*v2 = v4;
LABEL_23:
			++v1;
			v2 += 112;
			--v6;
		}
		while ( v6 );
		v7 = (int (*)[112])((char *)v7 + 4);
		++v0;
	}
	while ( (signed int)v7 < (signed int)dPiece[1] );
}

void __fastcall LoadPreL1Dungeon(char *sFileName, int vx, int vy)
{
	unsigned char *v3; // ebx
	signed int v4; // ecx
	signed int v5; // eax
	signed int v6; // edx
	int v7; // esi
	int v8; // edi
	char *v9; // eax
	int v10; // ecx
	char v11; // dl
	signed int v12; // esi
	signed int v13; // eax
	signed int v14; // edi
	int v15; // [esp+Ch] [ebp-8h]
	int v16; // [esp+10h] [ebp-4h]

	dminx = 16;
	dminy = 16;
	dmaxx = 96;
	dmaxy = 96;
	v3 = LoadFileInMem(sFileName, 0);
	v4 = 0;
	do
	{
		v5 = v4;
		v6 = 40;
		do
		{
			mydflags[0][v5] = 0;
			dungeon[0][v5] = 22;
			v5 += 40;
			--v6;
		}
		while ( v6 );
		++v4;
	}
	while ( v4 < 40 );
	v16 = 0;
	v7 = *v3;
	v8 = v3[2];
	v9 = (char *)(v3 + 4);
	if ( v8 > 0 )
	{
		do
		{
			if ( v7 > 0 )
			{
				v10 = v16;
				v15 = v7;
				do
				{
					v11 = *v9;
					if ( *v9 )
					{
						mydflags[0][v10] |= 0x80u;
						dungeon[0][v10] = v11;
					}
					else
					{
						dungeon[0][v10] = 13;
					}
					v10 += 40;
					v9 += 2;
					--v15;
				}
				while ( v15 );
			}
			++v16;
		}
		while ( v16 < v8 );
	}
	DRLG_L1Floor();
	v12 = 0;
	do
	{
		v13 = v12;
		v14 = 40;
		do
		{
			pdungeon[0][v13] = dungeon[0][v13];
			v13 += 40;
			--v14;
		}
		while ( v14 );
		++v12;
	}
	while ( v12 < 40 );
	mem_free_dbg(v3);
}
// 5CF328: using guessed type int dmaxx;
// 5CF32C: using guessed type int dmaxy;
// 5D2458: using guessed type int dminx;
// 5D245C: using guessed type int dminy;

void __fastcall CreateL5Dungeon(int rseed, int entry)
{
	SetRndSeed(rseed);

	dminx = 16;
	dminy = 16;
	dmaxx = 96;
	dmaxy = 96;

	DRLG_InitTrans();
	DRLG_InitSetPC();
	DRLG_LoadL1SP();
	DRLG_L5(entry);
	DRLG_L1Pass3();
	DRLG_FreeL1SP();
	DRLG_InitL1Vals();
	DRLG_SetPC();
}
// 5CF328: using guessed type int dmaxx;
// 5CF32C: using guessed type int dmaxy;
// 5D2458: using guessed type int dminx;
// 5D245C: using guessed type int dminy;

void __cdecl DRLG_LoadL1SP()
{
	setloadflag = 0;
	if ( QuestStatus(6) )
	{
		pSetPiece = LoadFileInMem("Levels\\L1Data\\rnd6.DUN", 0);
		setloadflag = 1;
	}
	if ( QuestStatus(12) && gbMaxPlayers == 1 )
	{
		pSetPiece = LoadFileInMem("Levels\\L1Data\\SKngDO.DUN", 0);
		setloadflag = 1;
	}
	if ( QuestStatus(7) )
	{
		pSetPiece = LoadFileInMem("Levels\\L1Data\\Banner2.DUN", 0);
		setloadflag = 1;
	}
}
// 5276A4: using guessed type int setloadflag;
// 679660: using guessed type char gbMaxPlayers;

void __cdecl DRLG_FreeL1SP()
{
	void *v0; // ecx

	v0 = pSetPiece;
	pSetPiece = 0;
	mem_free_dbg(v0);
}

void __fastcall DRLG_L5(int entry)
{
	signed int v1; // esi
	signed int v2; // edi
	int v5; // eax
	int v6; // ebx
	int v7; // edi
	int v8; // edi
	int v9; // ebp
	_BYTE *v10; // ebx
	signed int v11; // eax
	signed int v12; // ecx
	int v13; // [esp+10h] [ebp-8h]
	int v14; // [esp+10h] [ebp-8h]
	int v15; // [esp+14h] [ebp-4h]
	_BYTE *v16; // [esp+14h] [ebp-4h]

	v13 = entry;
	if ( currlevel == 1 )
	{
		v15 = 533;
	}
	else if ( currlevel == 2 )
	{
		v15 = 693;
	}
	else if ( currlevel > 2u && currlevel <= 4u )
	{
		v15 = 761;
	}
	v1 = 0;
	while ( 1 )
	{
		DRLG_InitTrans();
		do
		{
			InitL5Dungeon();
			L5firstRoom();
		}
		while ( L5GetArea() < v15 );
		L5makeDungeon();
		L5makeDmt();
		L5FillChambers();
		L5tileFix();
		L5AddWall();
		L5ClearFlags();
		DRLG_L5FloodTVal();
		v2 = 1;
		if ( QuestStatus(13) )
		{
			if ( v13 )
			{
				if ( DRLG_PlaceMiniSet(PWATERIN, 1, 1, 0, 0, 0, -1, 0) < 0 )
					v2 = 0;
				--ViewY;
			}
			else if ( DRLG_PlaceMiniSet(PWATERIN, 1, 1, 0, 0, 1, -1, 0) < 0 )
			{
				v2 = 0;
			}
		}
		if ( QuestStatus(7) )
		{
			if ( !v13 )
			{
				v5 = DRLG_PlaceMiniSet(STAIRSUP, 1, 1, 0, 0, 1, -1, 0);
				goto LABEL_21;
			}
			if ( DRLG_PlaceMiniSet(STAIRSUP, 1, 1, 0, 0, 0, -1, 0) < 0 )
				v2 = 0;
			if ( v13 == 1 )
			{
				ViewX = 2 * setpc_x + 20;
				ViewY = 2 * setpc_y + 28;
				goto LABEL_34;
			}
LABEL_33:
			--ViewY;
			goto LABEL_34;
		}
		if ( v13 )
		{
			if ( DRLG_PlaceMiniSet(L5STAIRSUP, 1, 1, 0, 0, 0, -1, 0) < 0
			  || DRLG_PlaceMiniSet(STAIRSDOWN, 1, 1, 0, 0, 1, -1, 1) < 0 )
			{
				v2 = 0;
			}
			goto LABEL_33;
		}
		if ( DRLG_PlaceMiniSet(L5STAIRSUP, 1, 1, 0, 0, 1, -1, 0) >= 0 )
		{
			v5 = DRLG_PlaceMiniSet(STAIRSDOWN, 1, 1, 0, 0, 0, -1, 1);
LABEL_21:
			if ( v5 < 0 )
				v2 = 0;
LABEL_34:
			if ( v2 )
				break;
		}
	}
	v14 = 0;
	v6 = 16;
	do
	{
		v7 = 16;
		v16 = (unsigned char *)dungeon + v14;
		do
		{
			if ( *v16 == 64 )
			{
				DRLG_CopyTrans(v7, v6 + 1, v7, v6);
				DRLG_CopyTrans(v7 + 1, v6 + 1, v7 + 1, v6);
			}
			v16 += 40;
			v7 += 2;
		}
		while ( v7 < 96 );
		++v14;
		v6 += 2;
	}
	while ( v6 < 96 );
	DRLG_L5TransFix();
	DRLG_L5DirtFix();
	DRLG_L5CornerFix();
	v8 = 0;
	do
	{
		v9 = 0;
		v10 = (unsigned char *)mydflags + v8;
		do
		{
			if ( *v10 & 0x7F )
				DRLG_PlaceDoor(v9, v8);
			++v9;
			v10 += 40;
		}
		while ( v9 < 40 );
		++v8;
	}
	while ( v8 < 40 );
	DRLG_L5Subs();
	DRLG_L1Shadows();
	DRLG_PlaceMiniSet(LAMPS, 5, 10, 0, 0, 0, -1, 4);
	DRLG_L1Floor();
	do
	{
		v11 = v1;
		v12 = 40;
		do
		{
			pdungeon[0][v11] = dungeon[0][v11];
			v11 += 40;
			--v12;
		}
		while ( v12 );
		++v1;
	}
	while ( v1 < 40 );
	DRLG_Init_Globals();
	DRLG_CheckQuests(setpc_x, setpc_y);
}

void __fastcall DRLG_PlaceDoor(int x, int y)
{
	if((mydflags[x][y] & 0x80) == 0) { /* todo: unsigned */
		unsigned char df = mydflags[x][y] & 0x7F;
		unsigned char c = dungeon[x][y];

		if(df == 1) {
			if(y != 1 && c == 2)
				dungeon[x][y] = 26;
			if(y != 1 && c == 7)
				dungeon[x][y] = 31;
			if(y != 1 && c == 14)
				dungeon[x][y] = 42;
			if(y != 1 && c == 4)
				dungeon[x][y] = 43;
			if(x != 1 && c == 1)
				dungeon[x][y] = 25;
			if(x != 1 && c == 10)
				dungeon[x][y] = 40;
			if(x != 1 && c == 6)
				dungeon[x][y] = 30;
		}
		if(df == 2) {
			if(x != 1 && c == 1)
				dungeon[x][y] = 25;
			if(x != 1 && c == 6)
				dungeon[x][y] = 30;
			if(x != 1 && c == 10)
				dungeon[x][y] = 40;
			if(x != 1 && c == 4)
				dungeon[x][y] = 41;
			if(y != 1 && c == 2)
				dungeon[x][y] = 26;
			if(y != 1 && c == 14)
				dungeon[x][y] = 42;
			if(y != 1 && c == 7)
				dungeon[x][y] = 31;
		}
		if(df == 3) {
			if(x != 1 && y != 1 && c == 4)
				dungeon[x][y] = 28;
			if(x != 1 && c == 10)
				dungeon[x][y] = 40;
			if(y != 1 && c == 14)
				dungeon[x][y] = 42;
			if(y != 1 && c == 2)
				dungeon[x][y] = 26;
			if(x != 1 && c == 1)
				dungeon[x][y] = 25;
			if(y != 1 && c == 7)
				dungeon[x][y] = 31;
			if(x != 1 && c == 6)
				dungeon[x][y] = 30;
		}
	}

	mydflags[x][y] = 0x80;
}

void __cdecl DRLG_L1Shadows()
{
	int x, y;
	unsigned char sd[2][2];
	unsigned char tnv3;

	for(y = 1; y < DMAXY; y++) {
		for(x = 1; x < DMAXX; x++) {
			sd[0][0] = BSTYPES[(unsigned char)dungeon[x][y]];
			sd[1][0] = BSTYPES[(unsigned char)dungeon[x-1][y]];
			sd[0][1] = BSTYPES[(unsigned char)dungeon[x][y-1]];
			sd[1][1] = BSTYPES[(unsigned char)dungeon[x-1][y-1]];

			for(int i = 0; i < 37; i++) {
				if(SPATS[i].strig == sd[0][0]) {
					BOOL patflag = TRUE;
					if(SPATS[i].s1 && SPATS[i].s1 != sd[1][1])
						patflag = FALSE;
					if(SPATS[i].s2 && SPATS[i].s2 != sd[0][1])
						patflag = FALSE;
					if(SPATS[i].s3 && SPATS[i].s3 != sd[1][0])
						patflag = FALSE;
					if(patflag == TRUE) {
						if(SPATS[i].nv1 && !mydflags[x-1][y-1])
							dungeon[x-1][y-1] = SPATS[i].nv1;
						if(SPATS[i].nv2 && !mydflags[x][y-1])
							dungeon[x][y-1] = SPATS[i].nv2;
						if(SPATS[i].nv3) {
							if(!mydflags[x-1][y])
								dungeon[x-1][y] = SPATS[i].nv3;
						}
					}
				}
			}
		}
	}

	for(y = 1; y < DMAXY; y++) {
		for(x = 1; x < DMAXX; x++) {
			if((unsigned char)dungeon[x-1][y] == 139 && !mydflags[x-1][y]) {
				tnv3 = 139;
				if(dungeon[x][y] == 29)
					tnv3 = 141;
				if(dungeon[x][y] == 32)
					tnv3 = 141;
				if(dungeon[x][y] == 35)
					tnv3 = 141;
				if(dungeon[x][y] == 37)
					tnv3 = 141;
				if(dungeon[x][y] == 38)
					tnv3 = 141;
				if(dungeon[x][y] == 39)
					tnv3 = 141;
				dungeon[x-1][y] = tnv3;
			}
			if((unsigned char)dungeon[x-1][y] == 149 && !mydflags[x-1][y]) {
				tnv3 = 149;
				if(dungeon[x][y] == 29)
					tnv3 = 153;
				if(dungeon[x][y] == 32)
					tnv3 = 153;
				if(dungeon[x][y] == 35)
					tnv3 = 153;
				if(dungeon[x][y] == 37)
					tnv3 = 153;
				if(dungeon[x][y] == 38)
					tnv3 = 153;
				if(dungeon[x][y] == 39)
					tnv3 = 153;
				dungeon[x-1][y] = tnv3;
			}
			if((unsigned char)dungeon[x-1][y] == 148 && !mydflags[x-1][y]) {
				tnv3 = 148;
				if(dungeon[x][y] == 29)
					tnv3 = 154;
				if(dungeon[x][y] == 32)
					tnv3 = 154;
				if(dungeon[x][y] == 35)
					tnv3 = 154;
				if(dungeon[x][y] == 37)
					tnv3 = 154;
				if(dungeon[x][y] == 38)
					tnv3 = 154;
				if(dungeon[x][y] == 39)
					tnv3 = 154;
				dungeon[x-1][y] = tnv3;
			}
		}
	}
}

int __fastcall DRLG_PlaceMiniSet(const unsigned char *miniset, int tmin, int tmax, int cx, int cy, bool setview, int noquad, int ldir)
{
	unsigned char *v8; // ebx
	int v9; // edi
	int v10; // esi
	int v11; // edx
	int v12; // esi
	int v13; // edi
	int v14; // ebx
	signed int v15; // edx
	int v16; // eax
	unsigned char v17; // cl
	int v18; // ebx
	int result; // eax
	int v20; // eax
	char *v21; // ecx
	char v22; // dl
	char v23; // bl
	bool v24; // zf
	bool v25; // sf
	unsigned char v26; // of
	int v27; // [esp-4h] [ebp-34h]
	int v28; // [esp+Ch] [ebp-24h]
	const unsigned char *v29; // [esp+10h] [ebp-20h]
	int v30; // [esp+14h] [ebp-1Ch]
	int v31; // [esp+18h] [ebp-18h]
	int v32; // [esp+1Ch] [ebp-14h]
	int v33; // [esp+20h] [ebp-10h]
	int max; // [esp+24h] [ebp-Ch]
	int v35; // [esp+28h] [ebp-8h]
	int v36; // [esp+2Ch] [ebp-4h]
	int tmaxa; // [esp+38h] [ebp+8h]
	int tmaxb; // [esp+38h] [ebp+8h]

	v8 = (unsigned char *)miniset;
	v9 = *miniset;
	v10 = tmin;
	v11 = tmax - tmin;
	v29 = miniset;
	v35 = *miniset;
	v36 = miniset[1];
	if ( v11 )
		v30 = v10 + random(0, v11);
	else
		v30 = 1;
	v31 = 0;
	if ( v30 > 0 )
	{
		max = 40 - v9;
		v28 = 40 - v36;
		while ( 1 )
		{
			v12 = random(0, max);
			v32 = 0;
			v13 = random(0, v28);
			while ( 1 )
			{
				tmaxa = 1;
				if ( cx != -1 && v12 >= cx - v35 && v12 <= cx + 12 )
				{
					++v12;
					tmaxa = 0;
				}
				if ( cy != -1 && v13 >= cy - v36 && v13 <= cy + 12 )
				{
					++v13;
					tmaxa = 0;
				}
				v14 = 0;
				switch ( noquad )
				{
					case 0:
						if ( v12 >= cx )
							goto LABEL_29;
						goto LABEL_27;
					case 1:
						if ( v12 <= cx )
							goto LABEL_29;
LABEL_27:
						if ( v13 >= cy )
							goto LABEL_29;
LABEL_28:
						tmaxa = 0;
						goto LABEL_29;
					case 2:
						if ( v12 >= cx )
							goto LABEL_29;
LABEL_22:
						if ( v13 <= cy )
							goto LABEL_29;
						goto LABEL_28;
				}
				if ( noquad == 3 && v12 > cx )
					goto LABEL_22;
LABEL_29:
				v15 = 2;
				if ( v36 > 0 )
				{
					do
					{
						if ( tmaxa != 1 )
							break;
						v33 = 0;
						if ( v35 > 0 )
						{
							v16 = v13 + v14 + 40 * v12;
							do
							{
								if ( tmaxa != 1 )
									break;
								v17 = v29[v15];
								if ( v17 && dungeon[0][v16] != v17 )
									tmaxa = 0;
								if ( mydflags[0][v16] )
									tmaxa = 0;
								++v15;
								++v33;
								v16 += 40;
							}
							while ( v33 < v35 );
						}
						++v14;
					}
					while ( v14 < v36 );
				}
				v18 = 0;
				if ( tmaxa )
					break;
				if ( ++v12 == max )
				{
					v12 = 0;
					if ( ++v13 == v28 )
						v13 = 0;
				}
				if ( ++v32 > 4000 )
					return -1;
			}
			v20 = v35 * v36 + 2;
			if ( v36 > 0 )
			{
				do
				{
					if ( v35 > 0 )
					{
						tmaxb = v35;
						v21 = &dungeon[v12][v18 + v13];
						do
						{
							v22 = v29[v20];
							if ( v22 )
								*v21 = v22;
							++v20;
							v21 += 40;
							--tmaxb;
						}
						while ( tmaxb );
					}
					++v18;
				}
				while ( v18 < v36 );
			}
			if ( ++v31 >= v30 )
			{
				v8 = (unsigned char *)v29;
				goto LABEL_57;
			}
		}
	}
	v12 = cx;
	v13 = cx;
LABEL_57:
	if ( v8 == PWATERIN )
	{
		v23 = TransVal;
		TransVal = 0;
		DRLG_MRectTrans(v12, v13 + 2, v12 + 5, v13 + 4);
		TransVal = v23;
		quests[13]._qtx = 2 * v12 + 21;
		quests[13]._qty = 2 * v13 + 22;
	}
	result = 1;
	if ( setview == 1 )
	{
		ViewX = 2 * v12 + 19;
		ViewY = 2 * v13 + 20;
	}
	if ( !ldir )
	{
		LvlViewX = 2 * v12 + 19;
		LvlViewY = 2 * v13 + 20;
	}
	v26 = __OFSUB__(v12, cx);
	v24 = v12 == cx;
	v25 = v12 - cx < 0;
	if ( v12 < cx )
	{
		if ( v13 < cy )
			return 0;
		v26 = __OFSUB__(v12, cx);
		v24 = v12 == cx;
		v25 = v12 - cx < 0;
	}
	if ( (unsigned char)(v25 ^ v26) | v24 || v13 >= cy )
	{
		if ( v12 >= cx || v13 <= cy )
			v27 = 3;
		else
			v27 = 2;
		result = v27;
	}
	return result;
}
// 5A5590: using guessed type char TransVal;
// 5CF320: using guessed type int LvlViewY;
// 5CF324: using guessed type int LvlViewX;

void __cdecl InitL5Dungeon()
{
	for(int j = 0; j < DMAXY; j++) {
		for(int i = 0; i < DMAXX; i++) {
			dungeon[i][j] = 0;
			mydflags[i][j] = 0;
		}
	}
}

void __cdecl L5ClearFlags()
{
	for(int j = 0; j < DMAXY; j++) {
		for(int i = 0; i < DMAXX; i++) {
			mydflags[i][j] &= 0xBF;
		}
	}
}

void __cdecl L5firstRoom()
{
	if(random(0, 2) == 0) {
		int ys = 1;
		int ye = 39;

		VR1 = random(0, 2);
		VR2 = random(0, 2);
		VR3 = random(0, 2);

		if(VR1 + VR3 <= 1)
			VR2 = 1;
		if(VR1)
			L5drawRoom(15, 1, 10, 10);
		else
			ys = 18;

		if(VR2)
			L5drawRoom(15, 15, 10, 10);
		if(VR3)
			L5drawRoom(15, 29, 10, 10);
		else
			ye = 22;

		for(int y = ys; y < ye; y++) {
			dungeon[17][y] = 1;
			dungeon[18][y] = 1;
			dungeon[19][y] = 1;
			dungeon[20][y] = 1;
			dungeon[21][y] = 1;
			dungeon[22][y] = 1;
		}

		if(VR1)
			L5roomGen(15, 1, 10, 10, 0);
		if(VR2)
			L5roomGen(15, 15, 10, 10, 0);
		if(VR3)
			L5roomGen(15, 29, 10, 10, 0);

		HR3 = 0;
		HR2 = 0;
		HR1 = 0;
	}
	else {
		int xs = 1;
		int xe = 39;

		HR1 = random(0, 2);
		HR2 = random(0, 2);
		HR3 = random(0, 2);

		if(HR1 + HR3 <= 1)
			HR2 = 1;
		if(HR1)
			L5drawRoom(1, 15, 10, 10);
		else
			xs = 18;

		if(HR2)
			L5drawRoom(15, 15, 10, 10);
		if(HR3)
			L5drawRoom(29, 15, 10, 10);
		else
			xe = 22;

		for(int x = xs; x < xe; x++) {
			dungeon[x][17] = 1;
			dungeon[x][18] = 1;
			dungeon[x][19] = 1;
			dungeon[x][20] = 1;
			dungeon[x][21] = 1;
			dungeon[x][22] = 1;
		}

		if(HR1)
			L5roomGen(1, 15, 10, 10, 1);
		if(HR2)
			L5roomGen(15, 15, 10, 10, 1);
		if(HR3)
			L5roomGen(29, 15, 10, 10, 1);

		VR3 = 0;
		VR2 = 0;
		VR1 = 0;
	}
}

void __fastcall L5drawRoom(int x, int y, int w, int h)
{
	for(int j = 0; j < h; j++) {
		for(int i = 0; i < w; i++) {
			dungeon[x+i][y+j] = 1;
		}
	}
}

void __fastcall L5roomGen(int x, int y, int w, int h, BOOL dir)
{
	int v5; // eax
	BOOL v6; // ecx
	BOOL v7; // eax
	int v8; // ecx
	int v9; // eax
	int v11; // esi
	int v12; // edi
	int v13; // ebx
	int v14; // eax
	int v15; // eax
	int v16; // eax
	int v18; // esi
	int v19; // edi
	int v20; // ebx
	int v21; // eax
	int v22; // eax
	int tya; // [esp+Ch] [ebp-10h]
	int tyb; // [esp+Ch] [ebp-10h]
	int v25; // [esp+10h] [ebp-Ch]
	int v26; // [esp+10h] [ebp-Ch]
	int txa; // [esp+14h] [ebp-8h]
	int txb; // [esp+14h] [ebp-8h]
	int v29; // [esp+18h] [ebp-4h]
	int twa; // [esp+24h] [ebp+8h]
	int tha; // [esp+28h] [ebp+Ch]
	int thb; // [esp+28h] [ebp+Ch]
	int thc; // [esp+28h] [ebp+Ch]
	signed int dir_horiza; // [esp+2Ch] [ebp+10h]
	signed int dir_horizb; // [esp+2Ch] [ebp+10h]

	v29 = y;
	txa = x;
	while ( 1 )
	{
		while ( 1 )
		{
			v5 = random(0, 4);
			v6 = 0;
			v6 = dir == 1 ? v5 != 0 : v5 == 0;
			v7 = v6;
			v8 = 0;
			if ( !v7 )
				break;
			if ( v7 != 1 )
				return;
			dir_horiza = 0;
			twa = w / 2;
			do
			{
				v9 = random(0, 5);
				v11 = (v9 + 2) & 0xFFFFFFFE;
				v12 = (random(0, 5) + 2) & 0xFFFFFFFE;
				v13 = txa + twa - v11 / 2;
				tya = v29 - v12;
				v14 = L5checkRoom(v13 - 1, v29 - v12 - 1, v11 + 2, v12 + 1);
				++dir_horiza;
				v25 = v14;
			}
			while ( !v14 && dir_horiza < 20 );
			if ( v14 == 1 )
				L5drawRoom(v13, tya, v11, v12);
			txb = v29 + h;
			v15 = L5checkRoom(v13 - 1, v29 + h, v11 + 2, v12 + 1);
			tha = v15;
			if ( v15 == 1 )
				L5drawRoom(v13, txb, v11, v12);
			if ( v25 == 1 )
				L5roomGen(v13, tya, v11, v12, 0);
			if ( tha != 1 )
				return;
			dir = 0;
			h = v12;
			w = v11;
			v29 = txb;
			txa = v13;
		}
		dir_horizb = 0;
		thb = h / 2;
		do
		{
			v16 = random(0, 5);
			v18 = (v16 + 2) & 0xFFFFFFFE;
			v19 = (random(0, 5) + 2) & 0xFFFFFFFE;
			v20 = v29 + thb - v19 / 2;
			tyb = txa - v18;
			v21 = L5checkRoom(txa - v18 - 1, v20 - 1, v19 + 2, v18 + 1);
			++dir_horizb;
			v26 = v21;
		}
		while ( !v21 && dir_horizb < 20 );
		if ( v21 == 1 )
			L5drawRoom(tyb, v20, v18, v19);
		txa += w;
		v22 = L5checkRoom(txa, v20 - 1, v18 + 1, v19 + 2);
		thc = v22;
		if ( v22 == 1 )
			L5drawRoom(txa, v20, v18, v19);
		if ( v26 == 1 )
			L5roomGen(tyb, v20, v18, v19, 1);
		if ( thc != 1 )
			break;
		dir = 1;
		h = v19;
		w = v18;
		v29 = v20;
	}
}

BOOL __fastcall L5checkRoom(int x, int y, int width, int height)
{
	for(int j = 0; j < height; j++) {
		for(int i = 0; i < width; i++) {
			if(i+x < 0 || i+x >= DMAXX || j+y < 0 || j+y >= DMAXY)
				return FALSE;
			if(dungeon[i+x][j+y])
				return FALSE;
		}
	}

	return TRUE;
}

int __cdecl L5GetArea()
{
	int rv = 0;

	for(int j = 0; j < DMAXY; j++) {
		for(int i = 0; i < DMAXX; i++) {
			if(dungeon[i][j] == 1)
				rv++;
		}
	}

	return rv;
}

void __cdecl L5makeDungeon()
{
	signed int v0; // edi
	signed int v1; // esi
	char *v2; // edx
	char v3; // cl
	int v4; // eax
	int v5; // eax

	v0 = 0;
	do
	{
		v1 = 0;
		v2 = (char *)dungeon + v0;
		do
		{
			v3 = *v2;
			v2 += 40;
			v4 = 160 * v1++;
			v5 = v4 + 2 * v0;
			L5dungeon[0][v5] = v3;
			L5dungeon[0][v5 + 1] = v3;
			L5dungeon[1][v5] = v3;
			L5dungeon[1][v5 + 1] = v3;
		}
		while ( v1 < 40 );
		++v0;
	}
	while ( v0 < 40 );
}

void __cdecl L5makeDmt()
{
	int i, j, dmtx, dmty;

	for(j = 0; j < DMAXY; j++) {
		for(i = 0; i < DMAXX; i++) {
			dungeon[i][j] = 22;
		}
	}

	for(j = 0, dmty = 1; dmty <= 77; j++, dmty += 2) {
		for(i = 0, dmtx = 1; dmtx <= 77; i++, dmtx += 2) {
			dungeon[i][j] = L5ConvTbl[8 * (unsigned char)L5dungeon[dmtx+1][dmty+1] /* todo: unsigned */
									+ 4 * (unsigned char)L5dungeon[dmtx][dmty+1]
									+ 2 * (unsigned char)L5dungeon[dmtx+1][dmty]
									+ (unsigned char)L5dungeon[dmtx][dmty]];
		}
	}
}

void __cdecl L5AddWall()
{
	for(int j = 0; j < DMAXY; j++) {
		for(int i = 0; i < DMAXX; i++) {
			if(!mydflags[i][j]) {
				if(dungeon[i][j] == 3 && random(0, 100) < 100) {
					int x = L5HWallOk(i, j);
					if(x != -1)
						L5HorizWall(i, j, 2, x);
				}
				if(dungeon[i][j] == 3 && random(0, 100) < 100) {
					int y = L5VWallOk(i, j);
					if(y != -1)
						L5VertWall(i, j, 1, y);
				}
				if(dungeon[i][j] == 6 && random(0, 100) < 100) {
					int x = L5HWallOk(i, j);
					if(x != -1)
						L5HorizWall(i, j, 4, x);
				}
				if(dungeon[i][j] == 7 && random(0, 100) < 100) {
					int y = L5VWallOk(i, j);
					if(y != -1)
						L5VertWall(i, j, 4, y);
				}
				if(dungeon[i][j] == 2 && random(0, 100) < 100) {
					int x = L5HWallOk(i, j);
					if(x != -1)
						L5HorizWall(i, j, 2, x);
				}
				if(dungeon[i][j] == 1 && random(0, 100) < 100) {
					int y = L5VWallOk(i, j);
					if(y != -1)
						L5VertWall(i, j, 1, y);
				}
			}
		}
	}
}

int __fastcall L5HWallOk(int i, int j)
{
	for(int x = 1; dungeon[i+x][j] == 13; x++) {
		if(dungeon[i+x][j-1] != 13 || dungeon[i+x][j+1] != 13 || mydflags[i+x][j])
			break;
	}

	BOOL wallok = FALSE;
	if((unsigned char)dungeon[i+x][j] >= 3 && (unsigned char)dungeon[i+x][j] <= 7) /* todo: unsigned */
		wallok = TRUE;
	if((unsigned char)dungeon[i+x][j] >= 16 && (unsigned char)dungeon[i+x][j] <= 24)
		wallok = TRUE;
	if(dungeon[i+x][j] == 22)
		wallok = FALSE;
	if(x == 1)
		wallok = FALSE;

	if(wallok)
		return x;
	else
		return -1;
}

int __fastcall L5VWallOk(int i, int j)
{
	for(int y = 1; dungeon[i][j+y] == 13; y++) {
		if(dungeon[i-1][j+y] != 13 || dungeon[i+1][j+y] != 13 || mydflags[i][j+y])
			break;
	}

	BOOL wallok = FALSE;
	if((unsigned char)dungeon[i][j+y] >= 3 && (unsigned char)dungeon[i][j+y] <= 7) /* todo: unsigned */
		wallok = TRUE;
	if((unsigned char)dungeon[i][j+y] >= 16 && (unsigned char)dungeon[i][j+y] <= 24)
		wallok = TRUE;
	if(dungeon[i][j+y] == 22)
		wallok = FALSE;
	if(y == 1)
		wallok = FALSE;

	if(wallok)
		return y;
	else
		return -1;
}

void __fastcall L5HorizWall(int i, int j, char p, int dx)
{
	int xx;
	char wt, dt;

	switch(random(0, 4)) {
		case 0:
		case 1:
			dt = 2;
			break;
		case 2:
			dt = 12;
			if(p == 2)
				p = 12;
			if(p == 4)
				p = 10;
			break;
		case 3:
			dt = 36;
			if(p == 2)
				p = 36;
			if(p == 4)
				p = 27;
			break;
		default:
			break;
	}

	if(random(0, 6) == 5)
		wt = 12;
	else
		wt = 26;
	if(dt == 12)
		wt = 12;

	dungeon[i][j] = p;

	for(xx = 1; xx < dx; xx++) {
		dungeon[i+xx][j] = dt;
	}

	xx = random(0, dx-1) + 1;

	if(wt == 12) {
		dungeon[i+xx][j] = wt;
	}
	else {
		dungeon[i+xx][j] = 2;
		mydflags[i+xx][j] |= 1;
	}
}

void __fastcall L5VertWall(int i, int j, char p, int dy)
{
	int yy;
	char wt, dt;

	switch(random(0, 4)) {
		case 0:
		case 1:
			dt = 1;
			break;
		case 2:
			dt = 11;
			if(p == 1)
				p = 11;
			if(p == 4)
				p = 14;
			break;
		case 3:
			dt = 35;
			if(p == 1)
				p = 35;
			if(p == 4)
				p = 37;
			break;
		default:
			break;
	}

	if(random(0, 6) == 5)
		wt = 11;
	else
		wt = 25;
	if(dt == 11)
		wt = 11;

	dungeon[i][j] = p;

	for(yy = 1; yy < dy; yy++) {
		dungeon[i][j+yy] = dt;
	}

	yy = random(0, dy-1) + 1;

	if(wt == 11) {
		dungeon[i][j+yy] = wt;
	}
	else {
		dungeon[i][j+yy] = 1;
		mydflags[i][j+yy] |= 2;
	}
}

void __cdecl L5tileFix()
{
	int i, j;

	for(j = 0; j < DMAXY; j++) {
		for(i = 0; i < DMAXX; i++) {
			if(dungeon[i][j] == 2 && dungeon[i+1][j] == 22)
				dungeon[i+1][j] = 23;
			if(dungeon[i][j] == 13 && dungeon[i+1][j] == 22)
				dungeon[i+1][j] = 18;
			if(dungeon[i][j] == 13 && dungeon[i+1][j] == 2)
				dungeon[i+1][j] = 7;
			if(dungeon[i][j] == 6 && dungeon[i+1][j] == 22)
				dungeon[i+1][j] = 24;
			if(dungeon[i][j] == 1 && dungeon[i][j+1] == 22)
				dungeon[i][j+1] = 24;
			if(dungeon[i][j] == 13 && dungeon[i][j+1] == 1)
				dungeon[i][j+1] = 6;
			if(dungeon[i][j] == 13 && dungeon[i][j+1] == 22)
				dungeon[i][j+1] = 19;
		}
	}

	for(j = 0; j < DMAXY; j++) {
		for(i = 0; i < DMAXX; i++) {
			if(dungeon[i][j] == 13 && dungeon[i+1][j] == 19)
				dungeon[i+1][j] = 21;
			if(dungeon[i][j] == 13 && dungeon[i+1][j] == 22)
				dungeon[i+1][j] = 20;
			if(dungeon[i][j] == 7 && dungeon[i+1][j] == 22)
				dungeon[i+1][j] = 23;
			if(dungeon[i][j] == 13 && dungeon[i+1][j] == 24)
				dungeon[i+1][j] = 21;
			if(dungeon[i][j] == 19 && dungeon[i+1][j] == 22)
				dungeon[i+1][j] = 20;
			if(dungeon[i][j] == 2 && dungeon[i+1][j] == 19)
				dungeon[i+1][j] = 21;
			if(dungeon[i][j] == 19 && dungeon[i+1][j] == 1)
				dungeon[i+1][j] = 6;
			if(dungeon[i][j] == 7 && dungeon[i+1][j] == 19)
				dungeon[i+1][j] = 21;
			if(dungeon[i][j] == 2 && dungeon[i+1][j] == 1)
				dungeon[i+1][j] = 6;
			if(dungeon[i][j] == 3 && dungeon[i+1][j] == 22)
				dungeon[i+1][j] = 24;
			if(dungeon[i][j] == 21 && dungeon[i+1][j] == 1)
				dungeon[i+1][j] = 6;
			if(dungeon[i][j] == 7 && dungeon[i+1][j] == 1)
				dungeon[i+1][j] = 6;
			if(dungeon[i][j] == 7 && dungeon[i+1][j] == 24)
				dungeon[i+1][j] = 21;
			if(dungeon[i][j] == 4 && dungeon[i+1][j] == 16)
				dungeon[i+1][j] = 17;
			if(dungeon[i][j] == 7 && dungeon[i+1][j] == 13)
				dungeon[i+1][j] = 17;
			if(dungeon[i][j] == 2 && dungeon[i+1][j] == 24)
				dungeon[i+1][j] = 21;
			if(dungeon[i][j] == 2 && dungeon[i+1][j] == 13)
				dungeon[i+1][j] = 17;
			if(dungeon[i][j] == 23 && dungeon[i-1][j] == 22)
				dungeon[i-1][j] = 19;
			if(dungeon[i][j] == 19 && dungeon[i-1][j] == 23)
				dungeon[i-1][j] = 21;
			if(dungeon[i][j] == 6 && dungeon[i-1][j] == 22)
				dungeon[i-1][j] = 24;
			if(dungeon[i][j] == 6 && dungeon[i-1][j] == 23)
				dungeon[i-1][j] = 21;
			if(dungeon[i][j] == 1 && dungeon[i][j+1] == 2)
				dungeon[i][j+1] = 7;
			if(dungeon[i][j] == 6 && dungeon[i][j+1] == 18)
				dungeon[i][j+1] = 21;
			if(dungeon[i][j] == 18 && dungeon[i][j+1] == 2)
				dungeon[i][j+1] = 7;
			if(dungeon[i][j] == 6 && dungeon[i][j+1] == 2)
				dungeon[i][j+1] = 7;
			if(dungeon[i][j] == 21 && dungeon[i][j+1] == 2)
				dungeon[i][j+1] = 7;
			if(dungeon[i][j] == 6 && dungeon[i][j+1] == 22)
				dungeon[i][j+1] = 24;
			if(dungeon[i][j] == 6 && dungeon[i][j+1] == 13)
				dungeon[i][j+1] = 16;
			if(dungeon[i][j] == 1 && dungeon[i][j+1] == 13)
				dungeon[i][j+1] = 16;
			if(dungeon[i][j] == 13 && dungeon[i][j+1] == 16)
				dungeon[i][j+1] = 17;
			if(dungeon[i][j] == 6 && dungeon[i][j-1] == 22)
				dungeon[i][j-1] = 7;
			if(dungeon[i][j] == 6 && dungeon[i][j-1] == 22)
				dungeon[i][j-1] = 24;
			if(dungeon[i][j] == 7 && dungeon[i][j-1] == 24)
				dungeon[i][j-1] = 21;
			if(dungeon[i][j] == 18 && dungeon[i][j-1] == 24)
				dungeon[i][j-1] = 21;
		}
	}

	for(j = 0; j < DMAXY; j++) {
		for(i = 0; i < DMAXX; i++) {
			if(dungeon[i][j] == 4 && dungeon[i][j+1] == 2)
				dungeon[i][j+1] = 7;
			if(dungeon[i][j] == 2 && dungeon[i+1][j] == 19)
				dungeon[i+1][j] = 21;
			if(dungeon[i][j] == 18 && dungeon[i][j+1] == 22)
				dungeon[i][j+1] = 20;
		}
	}
}

void __cdecl DRLG_L5Subs()
{
	for(int y = 0; y < DMAXY; y++) {
		for(int x = 0; x < DMAXX; x++) {
			if(!random(0, 4))
			{
				unsigned char c = L5BTYPES[(unsigned char)dungeon[x][y]]; /* todo: changed to unsigned */

				if(c && !mydflags[x][y])
				{
					int rv = random(0, 16);
					int i = -1;

					while(rv >= 0) {
						if(++i == sizeof(L5BTYPES))
							i = 0;
						if(c == L5BTYPES[i])
							rv--;
					}

					if(i == 89) {
						if(L5BTYPES[(unsigned char)dungeon[x][y-1]] != 79 || mydflags[x][y-1])
							i = 79;
						else
							dungeon[x][y-1] = 90;
					}
					if(i == 91) {
						if(L5BTYPES[(unsigned char)dungeon[x+1][y]] != 80 || mydflags[x+1][y])
							i = 80;
						else
							dungeon[x+1][y] = 92;
					}
					dungeon[x][y] = i;
				}
			}
		}
	}
}

void __cdecl L5FillChambers()
{
	int v0; // edi
	int v1; // edi
	int v2; // edx
	int v3; // ecx
	int v4; // edi
	signed int v5; // [esp-4h] [ebp-10h]

	v0 = 1;
	if ( HR1 )
		DRLG_L5GChamber(0, 14, 0, 0, 0, 1);
	if ( !HR2 )
		goto LABEL_16;
	if ( HR1 )
	{
		if ( !HR3 )
			DRLG_L5GChamber(14, 14, 0, 0, 1, 0);
		if ( HR1 )
			goto LABEL_111;
	}
	if ( HR3 )
		DRLG_L5GChamber(14, 14, 0, 0, 0, 1);
	if ( HR1 )
	{
LABEL_111:
		if ( HR3 )
			DRLG_L5GChamber(14, 14, 0, 0, 1, 1);
		if ( HR1 )
		{
LABEL_16:
			if ( !HR3 )
				goto LABEL_18;
			goto LABEL_17;
		}
	}
	if ( !HR3 )
	{
		DRLG_L5GChamber(14, 14, 0, 0, 0, 0);
		goto LABEL_16;
	}
LABEL_17:
	DRLG_L5GChamber(28, 14, 0, 0, 1, 0);
LABEL_18:
	if ( HR1 )
	{
		if ( !HR2 )
			goto LABEL_24;
		DRLG_L5GHall(12, 18, 14, 18);
	}
	if ( HR2 && HR3 )
		DRLG_L5GHall(26, 18, 28, 18);
LABEL_24:
	if ( HR1 && !HR2 && HR3 )
		DRLG_L5GHall(12, 18, 28, 18);
	if ( VR1 )
		DRLG_L5GChamber(14, 0, 0, 1, 0, 0);
	if ( !VR2 )
		goto LABEL_43;
	if ( VR1 )
	{
		if ( !VR3 )
			DRLG_L5GChamber(14, 14, 1, 0, 0, 0);
		if ( VR1 )
			goto LABEL_112;
	}
	if ( VR3 )
		DRLG_L5GChamber(14, 14, 0, 1, 0, 0);
	if ( VR1 )
	{
LABEL_112:
		if ( VR3 )
			DRLG_L5GChamber(14, 14, 1, 1, 0, 0);
		if ( VR1 )
		{
LABEL_43:
			if ( !VR3 )
				goto LABEL_45;
			goto LABEL_44;
		}
	}
	if ( !VR3 )
	{
		DRLG_L5GChamber(14, 14, 0, 0, 0, 0);
		goto LABEL_43;
	}
LABEL_44:
	DRLG_L5GChamber(14, 28, 1, 0, 0, 0);
LABEL_45:
	if ( VR1 )
	{
		if ( !VR2 )
			goto LABEL_51;
		DRLG_L5GHall(18, 12, 18, 14);
	}
	if ( VR2 && VR3 )
		DRLG_L5GHall(18, 26, 18, 28);
LABEL_51:
	if ( VR1 && !VR2 && VR3 )
		DRLG_L5GHall(18, 12, 18, 28);
	if ( setloadflag )
	{
		if ( !VR1 && !VR2 && !VR3 )
		{
			if ( HR1 )
				goto LABEL_113;
			if ( HR2 && HR3 )
			{
				if ( random(0, 2) )
					v0 = 2;
				if ( HR1 )
				{
LABEL_113:
					if ( HR2 && !HR3 && random(0, 2) )
						v0 = 0;
					if ( HR1 )
					{
						if ( !HR2 && HR3 )
							v0 = random(0, 2) != 0 ? 0 : 2;
						if ( HR1 && HR2 )
						{
							if ( HR3 )
								v0 = random(0, 3);
						}
					}
				}
			}
			if ( !v0 )
			{
				v3 = 2;
				v2 = 16;
				goto LABEL_108;
			}
			v1 = v0 - 1;
			if ( v1 )
			{
				if ( v1 != 1 )
					return;
				v2 = 16;
				v5 = 30;
				goto LABEL_107;
			}
LABEL_81:
			v3 = 16;
			v2 = 16;
LABEL_108:
			DRLG_L5SetRoom(v3, v2);
			return;
		}
		if ( VR1 )
			goto LABEL_114;
		if ( VR2 && VR3 )
		{
			if ( random(0, 2) )
				v0 = 2;
			if ( VR1 )
			{
LABEL_114:
				if ( VR2 && !VR3 && random(0, 2) )
					v0 = 0;
				if ( VR1 )
				{
					if ( !VR2 && VR3 )
						v0 = random(0, 2) != 0 ? 0 : 2;
					if ( VR1 && VR2 && VR3 )
						v0 = random(0, 3);
				}
			}
		}
		if ( v0 )
		{
			v4 = v0 - 1;
			if ( !v4 )
				goto LABEL_81;
			if ( v4 != 1 )
				return;
			v2 = 30;
		}
		else
		{
			v2 = 2;
		}
		v5 = 16;
LABEL_107:
		v3 = v5;
		goto LABEL_108;
	}
}
// 5276A4: using guessed type int setloadflag;

void __fastcall DRLG_L5GChamber(int sx, int sy, bool topflag, bool bottomflag, bool leftflag, bool rightflag)
{
	int v6; // eax
	int v7; // edx
	int v8; // eax
	char *v9; // eax
	int v10; // eax
	int v11; // ecx
	int v12; // eax
	char *v13; // eax
	signed int v14; // edi
	int v15; // eax
	int v16; // edx
	int v17; // ecx
	signed int v18; // esi

	if ( topflag == 1 )
	{
		v6 = sy + 40 * sx;
		dungeon[2][v6] = 12;
		dungeon[3][v6] = 12;
		dungeon[4][v6] = 3;
		dungeon[7][v6] = 9;
		dungeon[8][v6] = 12;
		dungeon[9][v6] = 2;
	}
	if ( bottomflag == 1 )
	{
		v7 = sy + 11;
		v8 = v7 + 40 * sx;
		dungeon[2][v8] = 10;
		dungeon[3][v8] = 12;
		dungeon[4][v8] = 8;
		dungeon[7][v8] = 5;
		dungeon[8][v8] = 12;
		v9 = &dungeon[9][v8];
		if ( *v9 != 4 )
			*v9 = 21;
		sy = v7 - 11;
	}
	if ( leftflag == 1 )
	{
		v10 = sy + 40 * sx;
		dungeon[0][v10 + 2] = 11;
		dungeon[0][v10 + 3] = 11;
		dungeon[0][v10 + 4] = 3;
		dungeon[0][v10 + 7] = 8;
		dungeon[0][v10 + 8] = 11;
		dungeon[0][v10 + 9] = 1;
	}
	if ( rightflag == 1 )
	{
		v11 = sx + 11;
		v12 = sy + 40 * v11;
		dungeon[0][v12 + 2] = 14;
		dungeon[0][v12 + 3] = 11;
		dungeon[0][v12 + 4] = 9;
		dungeon[0][v12 + 7] = 5;
		dungeon[0][v12 + 8] = 11;
		v13 = &dungeon[0][v12 + 9];
		if ( *v13 != 4 )
			*v13 = 21;
		sx = v11 - 11;
	}
	v14 = 10;
	v15 = sy + 40 * sx;
	v16 = v15 + 1;
	do
	{
		v17 = v16;
		v18 = 10;
		do
		{
			mydflags[1][v17] |= 0x40u;
			dungeon[1][v17] = 13;
			v17 += 40;
			--v18;
		}
		while ( v18 );
		++v16;
		--v14;
	}
	while ( v14 );
	dungeon[4][v15 + 4] = 15;
	dungeon[7][v15 + 4] = 15;
	dungeon[4][v15 + 7] = 15;
	dungeon[7][v15 + 7] = 15;
}

void __fastcall DRLG_L5GHall(int x1, int y1, int x2, int y2)
{
	int i;

	if(y1 == y2)
	{
		for(i = x1; i < x2; i++) {
			dungeon[i][y1] = 12;
			dungeon[i][y1+3] = 12;
		}
	}
	else
	{
		for(i = y1; i < y2; i++) {
			dungeon[x1][i] = 11;
			dungeon[x1+3][i] = 11;
		}
	}
}

void __fastcall DRLG_L5SetRoom(int rx1, int ry1)
{
	int rw = *(unsigned char *)pSetPiece; /* todo: BYTE */
	int rh = *((unsigned char *)pSetPiece+2);

	setpc_x = rx1;
	setpc_y = ry1;
	setpc_w = rw;
	setpc_h = rh;

	unsigned char *sp = (unsigned char *)pSetPiece+4;

	for(int j = 0; j < rh; j++) {
		for(int i = 0; i < rw; i++) {
			if(*sp) {
				dungeon[rx1+i][ry1+j] = *sp;
				mydflags[rx1+i][ry1+j] |= 0x80;
			}
			else {
				dungeon[rx1+i][ry1+j] = 13;
			}
			sp += 2;
		}
	}
}
// 5CF330: using guessed type int setpc_h;
// 5CF334: using guessed type int setpc_w;

void __cdecl DRLG_L5FloodTVal()
{
	int yy = 16;

	for(int j = 0; j < DMAXY; j++)
	{
		int xx = 16;

		for(int i = 0; i < DMAXX; i++)
		{
			if(dungeon[i][j] == 13 && !dung_map[xx][yy]) {
				DRLG_L5FTVR(i, j, xx, yy, 0);
				TransVal++;
			}
			xx += 2;
		}
		yy += 2;
	}
}
// 5A5590: using guessed type char TransVal;

void __fastcall DRLG_L5FTVR(int i, int j, int x, int y, int d)
{
	if(dung_map[x][y] || dungeon[i][j] != 13) {
		if(d == 1) {
			dung_map[x][y] = TransVal;
			dung_map[x][y+1] = TransVal;
		}
		if(d == 2) {
			dung_map[x+1][y] = TransVal;
			dung_map[x+1][y+1] = TransVal;
		}
		if(d == 3) {
			dung_map[x][y] = TransVal;
			dung_map[x+1][y] = TransVal;
		}
		if(d == 4) {
			dung_map[x][y+1] = TransVal;
			dung_map[x+1][y+1] = TransVal;
		}
		if(d == 5)
			dung_map[x+1][y+1] = TransVal;
		if(d == 6)
			dung_map[x][y+1] = TransVal;
		if(d == 7)
			dung_map[x+1][y] = TransVal;
		if(d == 8)
			dung_map[x][y] = TransVal;
	}
	else {
		dung_map[x][y] = TransVal;
		dung_map[x+1][y] = TransVal;
		dung_map[x][y+1] = TransVal;
		dung_map[x+1][y+1] = TransVal;
		DRLG_L5FTVR(i+1, j, x+2, y, 1);
		DRLG_L5FTVR(i-1, j, x-2, y, 2);
		DRLG_L5FTVR(i, j+1, x, y+2, 3);
		DRLG_L5FTVR(i, j-1, x, y-2, 4);
		DRLG_L5FTVR(i-1, j-1, x-2, y-2, 5);
		DRLG_L5FTVR(i+1, j-1, x+2, y-2, 6);
		DRLG_L5FTVR(i-1, j+1, x-2, y+2, 7);
		DRLG_L5FTVR(i+1, j+1, x+2, y+2, 8);
	}
}
// 5A5590: using guessed type char TransVal;

void __cdecl DRLG_L5TransFix()
{
	int yy = 16;

	for(int j = 0; j < DMAXY; j++)
	{
		int xx = 16;

		for(int i = 0; i < DMAXX; i++)
		{
			if(dungeon[i][j] == 23 && dungeon[i][j-1] == 18) {
				dung_map[xx+1][yy] = dung_map[xx][yy];
				dung_map[xx+1][yy+1] = dung_map[xx][yy];
			}
			if(dungeon[i][j] == 24 && dungeon[i+1][j] == 19) {
				dung_map[xx][yy+1] = dung_map[xx][yy];
				dung_map[xx+1][yy+1] = dung_map[xx][yy];
			}
			if(dungeon[i][j] == 18) {
				dung_map[xx+1][yy] = dung_map[xx][yy];
				dung_map[xx+1][yy+1] = dung_map[xx][yy];
			}
			if(dungeon[i][j] == 19) {
				dung_map[xx][yy+1] = dung_map[xx][yy];
				dung_map[xx+1][yy+1] = dung_map[xx][yy];
			}
			if(dungeon[i][j] == 20) {
				dung_map[xx+1][yy] = dung_map[xx][yy];
				dung_map[xx][yy+1] = dung_map[xx][yy];
				dung_map[xx+1][yy+1] = dung_map[xx][yy];
			}
			xx += 2;
		}
		yy += 2;
	}
}

void __cdecl DRLG_L5DirtFix()
{
	for(int j = 0; j < DMAXY; j++) {
		for(int i = 0; i < DMAXX; i++) {
			if(dungeon[i][j] == 21 && dungeon[i+1][j] != 19)
				dungeon[i][j] = 202;
			if(dungeon[i][j] == 19 && dungeon[i+1][j] != 19)
				dungeon[i][j] = 200;
			if(dungeon[i][j] == 24 && dungeon[i+1][j] != 19)
				dungeon[i][j] = 205;
			if(dungeon[i][j] == 18 && dungeon[i][j+1] != 18)
				dungeon[i][j] = 199;
			if(dungeon[i][j] == 21 && dungeon[i][j+1] != 18)
				dungeon[i][j] = 202;
			if(dungeon[i][j] == 23 && dungeon[i][j+1] != 18)
				dungeon[i][j] = 204;
		}
	}
}

void __cdecl DRLG_L5CornerFix()
{
	signed int v0; // esi
	signed int v1; // eax
	signed int v2; // edi

	v0 = 1;
	do
	{
		v1 = v0;
		v2 = 38;
		do
		{
			if ( mydflags[1][v1] >= 0 && dungeon[1][v1] == 17 && dungeon[0][v1] == 13 && dungeon[0][v1 + 39] == 1 )
			{
				mydflags[0][v1 + 39] &= 0x80u;
				dungeon[1][v1] = 16;
			}
			if ( dungeon[1][v1] == -54 && dungeon[2][v1] == 13 && dungeon[1][v1 + 1] == 1 )
				dungeon[1][v1] = 8;
			v1 += 40;
			--v2;
		}
		while ( v2 );
		++v0;
	}
	while ( v0 < 39 );
}
