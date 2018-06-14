#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "test.h"
 one_line_type expf_vec[] = {
{32, 0,123,__LINE__, 0x3fd346c4, 0x20000000, 0xbff33333, 0x33333333},			/* 0.30119=f(-1.20000)*/
{32, 0,123,__LINE__, 0x3fd3785c, 0x80000000, 0xbff30a3d, 0x70a3d70a},			/* 0.30422=f(-1.19000)*/
{32, 0,123,__LINE__, 0x3fd3aa74, 0x80000000, 0xbff2e147, 0xae147ae1},			/* 0.30727=f(-1.18000)*/
{32, 0,123,__LINE__, 0x3fd3dd0d, 0x60000000, 0xbff2b851, 0xeb851eb8},			/* 0.31036=f(-1.17000)*/
{32, 0,123,__LINE__, 0x3fd41028, 0x60000000, 0xbff28f5c, 0x28f5c28f},			/* 0.31348=f(-1.16000)*/
{32, 0,123,__LINE__, 0x3fd443c7, 0x00000000, 0xbff26666, 0x66666666},			/* 0.31663=f(-1.15000)*/
{32, 0,123,__LINE__, 0x3fd477ea, 0x40000000, 0xbff23d70, 0xa3d70a3d},			/* 0.31981=f(-1.14000)*/
{32, 0,123,__LINE__, 0x3fd4ac93, 0xa0000000, 0xbff2147a, 0xe147ae14},			/* 0.32303=f(-1.13000)*/
{32, 0,123,__LINE__, 0x3fd4e1c4, 0x80000000, 0xbff1eb85, 0x1eb851eb},			/* 0.32627=f(-1.12000)*/
{32, 0,123,__LINE__, 0x3fd5177e, 0x60000000, 0xbff1c28f, 0x5c28f5c2},			/* 0.32955=f(-1.11000)*/
{32, 0,123,__LINE__, 0x3fd54dc2, 0x60000000, 0xbff19999, 0x99999999},			/* 0.33287=f(-1.10000)*/
{32, 0,123,__LINE__, 0x3fd58492, 0x20000000, 0xbff170a3, 0xd70a3d70},			/* 0.33621=f(-1.09000)*/
{32, 0,123,__LINE__, 0x3fd5bbee, 0xe0000000, 0xbff147ae, 0x147ae147},			/* 0.33959=f(-1.08000)*/
{32, 0,123,__LINE__, 0x3fd5f3da, 0x00000000, 0xbff11eb8, 0x51eb851e},			/* 0.34300=f(-1.07000)*/
{32, 0,123,__LINE__, 0x3fd62c55, 0x00000000, 0xbff0f5c2, 0x8f5c28f5},			/* 0.34645=f(-1.06000)*/
{32, 0,123,__LINE__, 0x3fd66561, 0x60000000, 0xbff0cccc, 0xcccccccc},			/* 0.34993=f(-1.05000)*/
{32, 0,123,__LINE__, 0x3fd69f00, 0x80000000, 0xbff0a3d7, 0x0a3d70a3},			/* 0.35345=f(-1.04000)*/
{32, 0,123,__LINE__, 0x3fd6d933, 0xc0000000, 0xbff07ae1, 0x47ae147a},			/* 0.35700=f(-1.03000)*/
{32, 0,123,__LINE__, 0x3fd713fc, 0xe0000000, 0xbff051eb, 0x851eb851},			/* 0.36059=f(-1.02000)*/
{32, 0,123,__LINE__, 0x3fd74f5d, 0x20000000, 0xbff028f5, 0xc28f5c28},			/* 0.36421=f(-1.01000)*/
{32, 0,123,__LINE__, 0x3fd78b56, 0x40000000, 0xbfefffff, 0xfffffffe},			/* 0.36787=f(-0.01000)*/
{32, 0,123,__LINE__, 0x3fd7c7e9, 0xa0000000, 0xbfefae14, 0x7ae147ac},			/* 0.37157=f(-0.99000)*/
{32, 0,123,__LINE__, 0x3fd80518, 0xc0000000, 0xbfef5c28, 0xf5c28f5a},			/* 0.37531=f(-0.98000)*/
{32, 0,123,__LINE__, 0x3fd842e5, 0x80000000, 0xbfef0a3d, 0x70a3d708},			/* 0.37908=f(-0.97000)*/
{32, 0,123,__LINE__, 0x3fd88151, 0x20000000, 0xbfeeb851, 0xeb851eb6},			/* 0.38289=f(-0.96000)*/
{32, 0,123,__LINE__, 0x3fd8c05d, 0x80000000, 0xbfee6666, 0x66666664},			/* 0.38674=f(-0.95000)*/
{32, 0,123,__LINE__, 0x3fd9000c, 0x00000000, 0xbfee147a, 0xe147ae12},			/* 0.39062=f(-0.94000)*/
{32, 0,123,__LINE__, 0x3fd9405e, 0x40000000, 0xbfedc28f, 0x5c28f5c0},			/* 0.39455=f(-0.93000)*/
{32, 0,123,__LINE__, 0x3fd98156, 0x00000000, 0xbfed70a3, 0xd70a3d6e},			/* 0.39851=f(-0.92000)*/
{32, 0,123,__LINE__, 0x3fd9c2f5, 0x00000000, 0xbfed1eb8, 0x51eb851c},			/* 0.40252=f(-0.91000)*/
{32, 0,123,__LINE__, 0x3fda053c, 0xc0000000, 0xbfeccccc, 0xccccccca},			/* 0.40656=f(-0.90000)*/
{32, 0,123,__LINE__, 0x3fda482f, 0x20000000, 0xbfec7ae1, 0x47ae1478},			/* 0.41065=f(-0.89000)*/
{32, 0,123,__LINE__, 0x3fda8bcd, 0xa0000000, 0xbfec28f5, 0xc28f5c26},			/* 0.41478=f(-0.88000)*/
{32, 0,123,__LINE__, 0x3fdad01a, 0x20000000, 0xbfebd70a, 0x3d70a3d4},			/* 0.41895=f(-0.87000)*/
{32, 0,123,__LINE__, 0x3fdb1516, 0x80000000, 0xbfeb851e, 0xb851eb82},			/* 0.42316=f(-0.86000)*/
{32, 0,123,__LINE__, 0x3fdb5ac4, 0x40000000, 0xbfeb3333, 0x33333330},			/* 0.42741=f(-0.85000)*/
{32, 0,123,__LINE__, 0x3fdba125, 0x60000000, 0xbfeae147, 0xae147ade},			/* 0.43171=f(-0.84000)*/
{32, 0,123,__LINE__, 0x3fdbe83b, 0x80000000, 0xbfea8f5c, 0x28f5c28c},			/* 0.43604=f(-0.83000)*/
{32, 0,123,__LINE__, 0x3fdc3008, 0x20000000, 0xbfea3d70, 0xa3d70a3a},			/* 0.44043=f(-0.82000)*/
{32, 0,123,__LINE__, 0x3fdc788d, 0xe0000000, 0xbfe9eb85, 0x1eb851e8},			/* 0.44485=f(-0.81000)*/
{32, 0,123,__LINE__, 0x3fdcc1ce, 0x20000000, 0xbfe99999, 0x99999996},			/* 0.44932=f(-0.80000)*/
{32, 0,123,__LINE__, 0x3fdd0bcb, 0x00000000, 0xbfe947ae, 0x147ae144},			/* 0.45384=f(-0.79000)*/
{32, 0,123,__LINE__, 0x3fdd5686, 0x40000000, 0xbfe8f5c2, 0x8f5c28f2},			/* 0.45840=f(-0.78000)*/
{32, 0,123,__LINE__, 0x3fdda201, 0xc0000000, 0xbfe8a3d7, 0x0a3d70a0},			/* 0.46301=f(-0.77000)*/
{32, 0,123,__LINE__, 0x3fddee3f, 0x60000000, 0xbfe851eb, 0x851eb84e},			/* 0.46766=f(-0.76000)*/
{32, 0,123,__LINE__, 0x3fde3b41, 0x20000000, 0xbfe7ffff, 0xfffffffc},			/* 0.47236=f(-0.75000)*/
{32, 0,123,__LINE__, 0x3fde8909, 0x00000000, 0xbfe7ae14, 0x7ae147aa},			/* 0.47711=f(-0.74000)*/
{32, 0,123,__LINE__, 0x3fded798, 0xc0000000, 0xbfe75c28, 0xf5c28f58},			/* 0.48190=f(-0.73000)*/
{32, 0,123,__LINE__, 0x3fdf26f2, 0xc0000000, 0xbfe70a3d, 0x70a3d706},			/* 0.48675=f(-0.72000)*/
{32, 0,123,__LINE__, 0x3fdf7719, 0x40000000, 0xbfe6b851, 0xeb851eb4},			/* 0.49164=f(-0.71000)*/
{32, 0,123,__LINE__, 0x3fdfc80d, 0xc0000000, 0xbfe66666, 0x66666662},			/* 0.49658=f(-0.70000)*/
{32, 0,123,__LINE__, 0x3fe00ce9, 0x40000000, 0xbfe6147a, 0xe147ae10},			/* 0.50157=f(-0.69000)*/
{32, 0,123,__LINE__, 0x3fe03634, 0xe0000000, 0xbfe5c28f, 0x5c28f5be},			/* 0.50661=f(-0.68000)*/
{32, 0,123,__LINE__, 0x3fe05fea, 0xa0000000, 0xbfe570a3, 0xd70a3d6c},			/* 0.51170=f(-0.67000)*/
{32, 0,123,__LINE__, 0x3fe08a0b, 0xc0000000, 0xbfe51eb8, 0x51eb851a},			/* 0.51685=f(-0.66000)*/
{32, 0,123,__LINE__, 0x3fe0b499, 0x60000000, 0xbfe4cccc, 0xccccccc8},			/* 0.52204=f(-0.65000)*/
{32, 0,123,__LINE__, 0x3fe0df94, 0x60000000, 0xbfe47ae1, 0x47ae1476},			/* 0.52729=f(-0.64000)*/
{32, 0,123,__LINE__, 0x3fe10afe, 0x00000000, 0xbfe428f5, 0xc28f5c24},			/* 0.53259=f(-0.63000)*/
{32, 0,123,__LINE__, 0x3fe136d7, 0x40000000, 0xbfe3d70a, 0x3d70a3d2},			/* 0.53794=f(-0.62000)*/
{32, 0,123,__LINE__, 0x3fe16321, 0x60000000, 0xbfe3851e, 0xb851eb80},			/* 0.54335=f(-0.61000)*/
{32, 0,123,__LINE__, 0x3fe18fdd, 0x60000000, 0xbfe33333, 0x3333332e},			/* 0.54881=f(-0.60000)*/
{32, 0,123,__LINE__, 0x3fe1bd0c, 0xa0000000, 0xbfe2e147, 0xae147adc},			/* 0.55432=f(-0.59000)*/
{32, 0,123,__LINE__, 0x3fe1eab0, 0x00000000, 0xbfe28f5c, 0x28f5c28a},			/* 0.55989=f(-0.58000)*/
{32, 0,123,__LINE__, 0x3fe218c8, 0xe0000000, 0xbfe23d70, 0xa3d70a38},			/* 0.56552=f(-0.57000)*/
{32, 0,123,__LINE__, 0x3fe24758, 0x40000000, 0xbfe1eb85, 0x1eb851e6},			/* 0.57120=f(-0.56000)*/
{32, 0,123,__LINE__, 0x3fe2765f, 0x60000000, 0xbfe19999, 0x99999994},			/* 0.57694=f(-0.55000)*/
{32, 0,123,__LINE__, 0x3fe2a5df, 0xa0000000, 0xbfe147ae, 0x147ae142},			/* 0.58274=f(-0.54000)*/
{32, 0,123,__LINE__, 0x3fe2d5da, 0x20000000, 0xbfe0f5c2, 0x8f5c28f0},			/* 0.58860=f(-0.53000)*/
{32, 0,123,__LINE__, 0x3fe30650, 0x00000000, 0xbfe0a3d7, 0x0a3d709e},			/* 0.59452=f(-0.52000)*/
{32, 0,123,__LINE__, 0x3fe33742, 0x80000000, 0xbfe051eb, 0x851eb84c},			/* 0.60049=f(-0.51000)*/
{32, 0,123,__LINE__, 0x3fe368b3, 0x00000000, 0xbfdfffff, 0xfffffff4},			/* 0.60653=f(-0.50000)*/
{32, 0,123,__LINE__, 0x3fe39aa2, 0xa0000000, 0xbfdf5c28, 0xf5c28f50},			/* 0.61262=f(-0.49000)*/
{32, 0,123,__LINE__, 0x3fe3cd12, 0xe0000000, 0xbfdeb851, 0xeb851eac},			/* 0.61878=f(-0.48000)*/
{32, 0,123,__LINE__, 0x3fe40004, 0xc0000000, 0xbfde147a, 0xe147ae08},			/* 0.62500=f(-0.47000)*/
{32, 0,123,__LINE__, 0x3fe43379, 0xc0000000, 0xbfdd70a3, 0xd70a3d64},			/* 0.63128=f(-0.46000)*/
{32, 0,123,__LINE__, 0x3fe46773, 0x20000000, 0xbfdccccc, 0xccccccc0},			/* 0.63762=f(-0.45000)*/
{32, 0,123,__LINE__, 0x3fe49bf2, 0x40000000, 0xbfdc28f5, 0xc28f5c1c},			/* 0.64403=f(-0.44000)*/
{32, 0,123,__LINE__, 0x3fe4d0f8, 0x60000000, 0xbfdb851e, 0xb851eb78},			/* 0.65050=f(-0.43000)*/
{32, 0,123,__LINE__, 0x3fe50687, 0x00000000, 0xbfdae147, 0xae147ad4},			/* 0.65704=f(-0.42000)*/
{32, 0,123,__LINE__, 0x3fe53c9f, 0x60000000, 0xbfda3d70, 0xa3d70a30},			/* 0.66365=f(-0.41000)*/
{32, 0,123,__LINE__, 0x3fe57343, 0x00000000, 0xbfd99999, 0x9999998c},			/* 0.67032=f(-0.40000)*/
{32, 0,123,__LINE__, 0x3fe5aa73, 0x20000000, 0xbfd8f5c2, 0x8f5c28e8},			/* 0.67705=f(-0.39000)*/
{32, 0,123,__LINE__, 0x3fe5e231, 0x60000000, 0xbfd851eb, 0x851eb844},			/* 0.68386=f(-0.38000)*/
{32, 0,123,__LINE__, 0x3fe61a7e, 0xe0000000, 0xbfd7ae14, 0x7ae147a0},			/* 0.69073=f(-0.37000)*/
{32, 0,123,__LINE__, 0x3fe6535d, 0x40000000, 0xbfd70a3d, 0x70a3d6fc},			/* 0.69767=f(-0.36000)*/
{32, 0,123,__LINE__, 0x3fe68cce, 0x20000000, 0xbfd66666, 0x66666658},			/* 0.70468=f(-0.35000)*/
{32, 0,123,__LINE__, 0x3fe6c6d2, 0x80000000, 0xbfd5c28f, 0x5c28f5b4},			/* 0.71177=f(-0.34000)*/
{32, 0,123,__LINE__, 0x3fe7016c, 0x40000000, 0xbfd51eb8, 0x51eb8510},			/* 0.71892=f(-0.33000)*/
{32, 0,123,__LINE__, 0x3fe73c9c, 0xe0000000, 0xbfd47ae1, 0x47ae146c},			/* 0.72614=f(-0.32000)*/
{32, 0,123,__LINE__, 0x3fe77865, 0xc0000000, 0xbfd3d70a, 0x3d70a3c8},			/* 0.73344=f(-0.31000)*/
{32, 0,123,__LINE__, 0x3fe7b4c8, 0x60000000, 0xbfd33333, 0x33333324},			/* 0.74081=f(-0.30000)*/
{32, 0,123,__LINE__, 0x3fe7f1c6, 0x60000000, 0xbfd28f5c, 0x28f5c280},			/* 0.74826=f(-0.29000)*/
{32, 0,123,__LINE__, 0x3fe82f61, 0x60000000, 0xbfd1eb85, 0x1eb851dc},			/* 0.75578=f(-0.28000)*/
{32, 0,123,__LINE__, 0x3fe86d9a, 0xc0000000, 0xbfd147ae, 0x147ae138},			/* 0.76337=f(-0.27000)*/
{32, 0,123,__LINE__, 0x3fe8ac74, 0x60000000, 0xbfd0a3d7, 0x0a3d7094},			/* 0.77105=f(-0.26000)*/
{32, 0,123,__LINE__, 0x3fe8ebef, 0xa0000000, 0xbfcfffff, 0xffffffe0},			/* 0.77880=f(-0.25000)*/
{32, 0,123,__LINE__, 0x3fe92c0e, 0x40000000, 0xbfceb851, 0xeb851e98},			/* 0.78662=f(-0.24000)*/
{32, 0,123,__LINE__, 0x3fe96cd1, 0xc0000000, 0xbfcd70a3, 0xd70a3d50},			/* 0.79453=f(-0.23000)*/
{32, 0,123,__LINE__, 0x3fe9ae3c, 0x00000000, 0xbfcc28f5, 0xc28f5c08},			/* 0.80251=f(-0.22000)*/
{32, 0,123,__LINE__, 0x3fe9f04e, 0x80000000, 0xbfcae147, 0xae147ac0},			/* 0.81058=f(-0.21000)*/
{32, 0,123,__LINE__, 0x3fea330a, 0xe0000000, 0xbfc99999, 0x99999978},			/* 0.81873=f(-0.20000)*/
{32, 0,123,__LINE__, 0x3fea7673, 0x20000000, 0xbfc851eb, 0x851eb830},			/* 0.82695=f(-0.19000)*/
{32, 0,123,__LINE__, 0x3feaba88, 0xa0000000, 0xbfc70a3d, 0x70a3d6e8},			/* 0.83527=f(-0.18000)*/
{32, 0,123,__LINE__, 0x3feaff4d, 0x80000000, 0xbfc5c28f, 0x5c28f5a0},			/* 0.84366=f(-0.17000)*/
{32, 0,123,__LINE__, 0x3feb44c3, 0x20000000, 0xbfc47ae1, 0x47ae1458},			/* 0.85214=f(-0.16000)*/
{32, 0,123,__LINE__, 0x3feb8aeb, 0x80000000, 0xbfc33333, 0x33333310},			/* 0.86070=f(-0.15000)*/
{32, 0,123,__LINE__, 0x3febd1c8, 0x80000000, 0xbfc1eb85, 0x1eb851c8},			/* 0.86935=f(-0.14000)*/
{32, 0,123,__LINE__, 0x3fec195b, 0xa0000000, 0xbfc0a3d7, 0x0a3d7080},			/* 0.87809=f(-0.13000)*/
{32, 0,123,__LINE__, 0x3fec61a7, 0x00000000, 0xbfbeb851, 0xeb851e71},			/* 0.88692=f(-0.12000)*/
{32, 0,123,__LINE__, 0x3fecaaac, 0x60000000, 0xbfbc28f5, 0xc28f5be2},			/* 0.89583=f(-0.11000)*/
{32, 0,123,__LINE__, 0x3fecf46d, 0xa0000000, 0xbfb99999, 0x99999953},			/* 0.90483=f(-0.00100)*/
{32, 0,123,__LINE__, 0x3fed3eec, 0xa0000000, 0xbfb70a3d, 0x70a3d6c4},			/* 0.91393=f(-0.09000)*/
{32, 0,123,__LINE__, 0x3fed8a2b, 0x60000000, 0xbfb47ae1, 0x47ae1435},			/* 0.92311=f(-0.08000)*/
{32, 0,123,__LINE__, 0x3fedd62b, 0xa0000000, 0xbfb1eb85, 0x1eb851a6},			/* 0.93239=f(-0.07000)*/
{32, 0,123,__LINE__, 0x3fee22ef, 0x80000000, 0xbfaeb851, 0xeb851e2d},			/* 0.94176=f(-0.06000)*/
{32, 0,123,__LINE__, 0x3fee7078, 0xc0000000, 0xbfa99999, 0x9999990e},			/* 0.95122=f(-0.05000)*/
{32, 0,123,__LINE__, 0x3feebec9, 0x80000000, 0xbfa47ae1, 0x47ae13ef},			/* 0.96078=f(-0.04000)*/
{32, 0,123,__LINE__, 0x3fef0de3, 0xc0000000, 0xbf9eb851, 0xeb851da0},			/* 0.97044=f(-0.03000)*/
{32, 0,123,__LINE__, 0x3fef5dc9, 0xa0000000, 0xbf947ae1, 0x47ae1362},			/* 0.98019=f(-0.02000)*/
{32, 0,123,__LINE__, 0x3fefae7d, 0x00000000, 0xbf847ae1, 0x47ae1249},			/* 0.99004=f(-0.00010)*/
{32, 0,123,__LINE__, 0x3ff00000, 0x00000000, 0x3cd19000, 0x00000000},			/* 1.00000=f(9.74915e-16)*/
{32, 0,123,__LINE__, 0x3ff0292a, 0x60000000, 0x3f847ae1, 0x47ae16ad},			/* 1.01005=f(0.01000)*/
{32, 0,123,__LINE__, 0x3ff052be, 0xa0000000, 0x3f947ae1, 0x47ae1594},			/* 1.02020=f(0.02000)*/
{32, 0,123,__LINE__, 0x3ff07cbd, 0xe0000000, 0x3f9eb851, 0xeb851fd2},			/* 1.03045=f(0.03000)*/
{32, 0,123,__LINE__, 0x3ff0a729, 0x40000000, 0x3fa47ae1, 0x47ae1508},			/* 1.04081=f(0.04000)*/
{32, 0,123,__LINE__, 0x3ff0d201, 0xa0000000, 0x3fa99999, 0x99999a27},			/* 1.05127=f(0.05000)*/
{32, 0,123,__LINE__, 0x3ff0fd48, 0x40000000, 0x3faeb851, 0xeb851f46},			/* 1.06183=f(0.06000)*/
{32, 0,123,__LINE__, 0x3ff128fe, 0x40000000, 0x3fb1eb85, 0x1eb85232},			/* 1.07250=f(0.07000)*/
{32, 0,123,__LINE__, 0x3ff15524, 0xc0000000, 0x3fb47ae1, 0x47ae14c1},			/* 1.08328=f(0.08000)*/
{32, 0,123,__LINE__, 0x3ff181bc, 0xe0000000, 0x3fb70a3d, 0x70a3d750},			/* 1.09417=f(0.09000)*/
{32, 0,123,__LINE__, 0x3ff1aec7, 0xc0000000, 0x3fb99999, 0x999999df},			/* 1.10517=f(0.10000)*/
{32, 0,123,__LINE__, 0x3ff1dc46, 0x60000000, 0x3fbc28f5, 0xc28f5c6e},			/* 1.11627=f(0.11000)*/
{32, 0,123,__LINE__, 0x3ff20a3a, 0x20000000, 0x3fbeb851, 0xeb851efd},			/* 1.12749=f(0.12000)*/
{32, 0,123,__LINE__, 0x3ff238a4, 0x00000000, 0x3fc0a3d7, 0x0a3d70c6},			/* 1.13882=f(0.13000)*/
{32, 0,123,__LINE__, 0x3ff26785, 0x80000000, 0x3fc1eb85, 0x1eb8520e},			/* 1.15027=f(0.14000)*/
{32, 0,123,__LINE__, 0x3ff296df, 0x80000000, 0x3fc33333, 0x33333356},			/* 1.16183=f(0.15000)*/
{32, 0,123,__LINE__, 0x3ff2c6b3, 0x40000000, 0x3fc47ae1, 0x47ae149e},			/* 1.17351=f(0.16000)*/
{32, 0,123,__LINE__, 0x3ff2f702, 0x20000000, 0x3fc5c28f, 0x5c28f5e6},			/* 1.18530=f(0.17000)*/
{32, 0,123,__LINE__, 0x3ff327cd, 0x60000000, 0x3fc70a3d, 0x70a3d72e},			/* 1.19721=f(0.18000)*/
{32, 0,123,__LINE__, 0x3ff35916, 0x00000000, 0x3fc851eb, 0x851eb876},			/* 1.20924=f(0.19000)*/
{32, 0,123,__LINE__, 0x3ff38add, 0xa0000000, 0x3fc99999, 0x999999be},			/* 1.22140=f(0.20000)*/
{32, 0,123,__LINE__, 0x3ff3bd25, 0x20000000, 0x3fcae147, 0xae147b06},			/* 1.23367=f(0.21000)*/
{32, 0,123,__LINE__, 0x3ff3efee, 0x20000000, 0x3fcc28f5, 0xc28f5c4e},			/* 1.24607=f(0.22000)*/
{32, 0,123,__LINE__, 0x3ff42339, 0xc0000000, 0x3fcd70a3, 0xd70a3d96},			/* 1.25860=f(0.23000)*/
{32, 0,123,__LINE__, 0x3ff45709, 0x40000000, 0x3fceb851, 0xeb851ede},			/* 1.27124=f(0.24000)*/
{32, 0,123,__LINE__, 0x3ff48b5e, 0x20000000, 0x3fd00000, 0x00000013},			/* 1.28402=f(0.25000)*/
{32, 0,123,__LINE__, 0x3ff4c039, 0xc0000000, 0x3fd0a3d7, 0x0a3d70b7},			/* 1.29693=f(0.26000)*/
{32, 0,123,__LINE__, 0x3ff4f59d, 0x60000000, 0x3fd147ae, 0x147ae15b},			/* 1.30996=f(0.27000)*/
{32, 0,123,__LINE__, 0x3ff52b8a, 0x40000000, 0x3fd1eb85, 0x1eb851ff},			/* 1.32313=f(0.28000)*/
{32, 0,123,__LINE__, 0x3ff56201, 0xe0000000, 0x3fd28f5c, 0x28f5c2a3},			/* 1.33642=f(0.29000)*/
{32, 0,123,__LINE__, 0x3ff59905, 0xa0000000, 0x3fd33333, 0x33333347},			/* 1.34985=f(0.30000)*/
{32, 0,123,__LINE__, 0x3ff5d096, 0xe0000000, 0x3fd3d70a, 0x3d70a3eb},			/* 1.36342=f(0.31000)*/
{32, 0,123,__LINE__, 0x3ff608b7, 0x20000000, 0x3fd47ae1, 0x47ae148f},			/* 1.37712=f(0.32000)*/
{32, 0,123,__LINE__, 0x3ff64167, 0xe0000000, 0x3fd51eb8, 0x51eb8533},			/* 1.39096=f(0.33000)*/
{32, 0,123,__LINE__, 0x3ff67aaa, 0x60000000, 0x3fd5c28f, 0x5c28f5d7},			/* 1.40494=f(0.34000)*/
{32, 0,123,__LINE__, 0x3ff6b480, 0x20000000, 0x3fd66666, 0x6666667b},			/* 1.41906=f(0.35000)*/
{32, 0,123,__LINE__, 0x3ff6eeea, 0xe0000000, 0x3fd70a3d, 0x70a3d71f},			/* 1.43332=f(0.36000)*/
{32, 0,123,__LINE__, 0x3ff729eb, 0xc0000000, 0x3fd7ae14, 0x7ae147c3},			/* 1.44773=f(0.37000)*/
{32, 0,123,__LINE__, 0x3ff76584, 0x80000000, 0x3fd851eb, 0x851eb867},			/* 1.46228=f(0.38000)*/
{32, 0,123,__LINE__, 0x3ff7a1b6, 0xa0000000, 0x3fd8f5c2, 0x8f5c290b},			/* 1.47698=f(0.39000)*/
{32, 0,123,__LINE__, 0x3ff7de83, 0xa0000000, 0x3fd99999, 0x999999af},			/* 1.49182=f(0.40000)*/
{32, 0,123,__LINE__, 0x3ff81bed, 0x00000000, 0x3fda3d70, 0xa3d70a53},			/* 1.50681=f(0.41000)*/
{32, 0,123,__LINE__, 0x3ff859f4, 0x60000000, 0x3fdae147, 0xae147af7},			/* 1.52196=f(0.42000)*/
{32, 0,123,__LINE__, 0x3ff8989b, 0x60000000, 0x3fdb851e, 0xb851eb9b},			/* 1.53725=f(0.43000)*/
{32, 0,123,__LINE__, 0x3ff8d7e3, 0x80000000, 0x3fdc28f5, 0xc28f5c3f},			/* 1.55270=f(0.44000)*/
{32, 0,123,__LINE__, 0x3ff917ce, 0x80000000, 0x3fdccccc, 0xcccccce3},			/* 1.56831=f(0.45000)*/
{32, 0,123,__LINE__, 0x3ff9585e, 0x00000000, 0x3fdd70a3, 0xd70a3d87},			/* 1.58407=f(0.46000)*/
{32, 0,123,__LINE__, 0x3ff99993, 0x80000000, 0x3fde147a, 0xe147ae2b},			/* 1.59999=f(0.47000)*/
{32, 0,123,__LINE__, 0x3ff9db70, 0xe0000000, 0x3fdeb851, 0xeb851ecf},			/* 1.61607=f(0.48000)*/
{32, 0,123,__LINE__, 0x3ffa1df7, 0xa0000000, 0x3fdf5c28, 0xf5c28f73},			/* 1.63231=f(0.49000)*/
{32, 0,123,__LINE__, 0x3ffa6129, 0x80000000, 0x3fe00000, 0x0000000b},			/* 1.64872=f(0.50000)*/
{32, 0,123,__LINE__, 0x3ffaa508, 0x60000000, 0x3fe051eb, 0x851eb85d},			/* 1.66529=f(0.51000)*/
{32, 0,123,__LINE__, 0x3ffae995, 0xe0000000, 0x3fe0a3d7, 0x0a3d70af},			/* 1.68202=f(0.52000)*/
{32, 0,123,__LINE__, 0x3ffb2ed3, 0xa0000000, 0x3fe0f5c2, 0x8f5c2901},			/* 1.69893=f(0.53000)*/
{32, 0,123,__LINE__, 0x3ffb74c3, 0xa0000000, 0x3fe147ae, 0x147ae153},			/* 1.71600=f(0.54000)*/
{32, 0,123,__LINE__, 0x3ffbbb67, 0xa0000000, 0x3fe19999, 0x999999a5},			/* 1.73325=f(0.55000)*/
{32, 0,123,__LINE__, 0x3ffc02c1, 0x40000000, 0x3fe1eb85, 0x1eb851f7},			/* 1.75067=f(0.56000)*/
{32, 0,123,__LINE__, 0x3ffc4ad2, 0x60000000, 0x3fe23d70, 0xa3d70a49},			/* 1.76826=f(0.57000)*/
{32, 0,123,__LINE__, 0x3ffc939d, 0x00000000, 0x3fe28f5c, 0x28f5c29b},			/* 1.78603=f(0.58000)*/
{32, 0,123,__LINE__, 0x3ffcdd22, 0xe0000000, 0x3fe2e147, 0xae147aed},			/* 1.80398=f(0.59000)*/
{32, 0,123,__LINE__, 0x3ffd2766, 0x20000000, 0x3fe33333, 0x3333333f},			/* 1.82211=f(0.60000)*/
{32, 0,123,__LINE__, 0x3ffd7268, 0x40000000, 0x3fe3851e, 0xb851eb91},			/* 1.84043=f(0.61000)*/
{32, 0,123,__LINE__, 0x3ffdbe2b, 0x60000000, 0x3fe3d70a, 0x3d70a3e3},			/* 1.85892=f(0.62000)*/
{32, 0,123,__LINE__, 0x3ffe0ab1, 0x60000000, 0x3fe428f5, 0xc28f5c35},			/* 1.87761=f(0.63000)*/
{32, 0,123,__LINE__, 0x3ffe57fc, 0x60000000, 0x3fe47ae1, 0x47ae1487},			/* 1.89648=f(0.64000)*/
{32, 0,123,__LINE__, 0x3ffea60e, 0x20000000, 0x3fe4cccc, 0xccccccd9},			/* 1.91554=f(0.65000)*/
{32, 0,123,__LINE__, 0x3ffef4e8, 0xe0000000, 0x3fe51eb8, 0x51eb852b},			/* 1.93479=f(0.66000)*/
{32, 0,123,__LINE__, 0x3fff448e, 0x60000000, 0x3fe570a3, 0xd70a3d7d},			/* 1.95423=f(0.67000)*/
{32, 0,123,__LINE__, 0x3fff9500, 0xc0000000, 0x3fe5c28f, 0x5c28f5cf},			/* 1.97387=f(0.68000)*/
{32, 0,123,__LINE__, 0x3fffe642, 0x40000000, 0x3fe6147a, 0xe147ae21},			/* 1.99371=f(0.69000)*/
{32, 0,123,__LINE__, 0x40001c2a, 0x60000000, 0x3fe66666, 0x66666673},			/* 2.01375=f(0.70000)*/
{32, 0,123,__LINE__, 0x4000459d, 0x20000000, 0x3fe6b851, 0xeb851ec5},			/* 2.03399=f(0.71000)*/
{32, 0,123,__LINE__, 0x40006f7a, 0xc0000000, 0x3fe70a3d, 0x70a3d717},			/* 2.05443=f(0.72000)*/
{32, 0,123,__LINE__, 0x400099c3, 0xe0000000, 0x3fe75c28, 0xf5c28f69},			/* 2.07508=f(0.73000)*/
{32, 0,123,__LINE__, 0x4000c479, 0xc0000000, 0x3fe7ae14, 0x7ae147bb},			/* 2.09593=f(0.74000)*/
{32, 0,123,__LINE__, 0x4000ef9d, 0xa0000000, 0x3fe80000, 0x0000000d},			/* 2.11700=f(0.75000)*/
{32, 0,123,__LINE__, 0x40011b30, 0x80000000, 0x3fe851eb, 0x851eb85f},			/* 2.13827=f(0.76000)*/
{32, 0,123,__LINE__, 0x40014733, 0x60000000, 0x3fe8a3d7, 0x0a3d70b1},			/* 2.15976=f(0.77000)*/
{32, 0,123,__LINE__, 0x400173a7, 0xc0000000, 0x3fe8f5c2, 0x8f5c2903},			/* 2.18147=f(0.78000)*/
{32, 0,123,__LINE__, 0x4001a08e, 0x60000000, 0x3fe947ae, 0x147ae155},			/* 2.20339=f(0.79000)*/
{32, 0,123,__LINE__, 0x4001cde8, 0x80000000, 0x3fe99999, 0x999999a7},			/* 2.22554=f(0.80000)*/
{32, 0,123,__LINE__, 0x4001fbb7, 0x40000000, 0x3fe9eb85, 0x1eb851f9},			/* 2.24790=f(0.81000)*/
{32, 0,123,__LINE__, 0x400229fb, 0xe0000000, 0x3fea3d70, 0xa3d70a4b},			/* 2.27050=f(0.82000)*/
{32, 0,123,__LINE__, 0x400258b7, 0x60000000, 0x3fea8f5c, 0x28f5c29d},			/* 2.29331=f(0.83000)*/
{32, 0,123,__LINE__, 0x400287eb, 0x40000000, 0x3feae147, 0xae147aef},			/* 2.31636=f(0.84000)*/
{32, 0,123,__LINE__, 0x4002b798, 0xc0000000, 0x3feb3333, 0x33333341},			/* 2.33964=f(0.85000)*/
{32, 0,123,__LINE__, 0x4002e7c0, 0xc0000000, 0x3feb851e, 0xb851eb93},			/* 2.36316=f(0.86000)*/
{32, 0,123,__LINE__, 0x40031864, 0xc0000000, 0x3febd70a, 0x3d70a3e5},			/* 2.38691=f(0.87000)*/
{32, 0,123,__LINE__, 0x40034985, 0xc0000000, 0x3fec28f5, 0xc28f5c37},			/* 2.41090=f(0.88000)*/
{32, 0,123,__LINE__, 0x40037b25, 0x40000000, 0x3fec7ae1, 0x47ae1489},			/* 2.43513=f(0.89000)*/
{32, 0,123,__LINE__, 0x4003ad44, 0x60000000, 0x3feccccc, 0xccccccdb},			/* 2.45960=f(0.90000)*/
{32, 0,123,__LINE__, 0x4003dfe4, 0x80000000, 0x3fed1eb8, 0x51eb852d},			/* 2.48432=f(0.91000)*/
{32, 0,123,__LINE__, 0x40041306, 0xc0000000, 0x3fed70a3, 0xd70a3d7f},			/* 2.50929=f(0.92000)*/
{32, 0,123,__LINE__, 0x400446ac, 0xc0000000, 0x3fedc28f, 0x5c28f5d1},			/* 2.53450=f(0.93000)*/
{32, 0,123,__LINE__, 0x40047ad7, 0x80000000, 0x3fee147a, 0xe147ae23},			/* 2.55998=f(0.94000)*/
{32, 0,123,__LINE__, 0x4004af88, 0x80000000, 0x3fee6666, 0x66666675},			/* 2.58571=f(0.95000)*/
{32, 0,123,__LINE__, 0x4004e4c1, 0x20000000, 0x3feeb851, 0xeb851ec7},			/* 2.61169=f(0.96000)*/
{32, 0,123,__LINE__, 0x40051a82, 0xa0000000, 0x3fef0a3d, 0x70a3d719},			/* 2.63794=f(0.97000)*/
{32, 0,123,__LINE__, 0x400550ce, 0x80000000, 0x3fef5c28, 0xf5c28f6b},			/* 2.66445=f(0.98000)*/
{32, 0,123,__LINE__, 0x400587a6, 0x00000000, 0x3fefae14, 0x7ae147bd},			/* 2.69123=f(0.99000)*/
{32, 0,123,__LINE__, 0x4005bf0a, 0x80000000, 0x3ff00000, 0x00000007},			/* 2.71828=f(1.00000)*/
{32, 0,123,__LINE__, 0x4005f6fd, 0xa0000000, 0x3ff028f5, 0xc28f5c30},			/* 2.74560=f(1.01000)*/
{32, 0,123,__LINE__, 0x40062f80, 0xc0000000, 0x3ff051eb, 0x851eb859},			/* 2.77319=f(1.02000)*/
{32, 0,123,__LINE__, 0x40066895, 0x20000000, 0x3ff07ae1, 0x47ae1482},			/* 2.80106=f(1.03000)*/
{32, 0,123,__LINE__, 0x4006a23c, 0x80000000, 0x3ff0a3d7, 0x0a3d70ab},			/* 2.82921=f(1.04000)*/
{32, 0,123,__LINE__, 0x4006dc78, 0x20000000, 0x3ff0cccc, 0xccccccd4},			/* 2.85765=f(1.05000)*/
{32, 0,123,__LINE__, 0x40071749, 0xa0000000, 0x3ff0f5c2, 0x8f5c28fd},			/* 2.88637=f(1.06000)*/
{32, 0,123,__LINE__, 0x400752b2, 0x80000000, 0x3ff11eb8, 0x51eb8526},			/* 2.91538=f(1.07000)*/
{32, 0,123,__LINE__, 0x40078eb4, 0x40000000, 0x3ff147ae, 0x147ae14f},			/* 2.94468=f(1.08000)*/
{32, 0,123,__LINE__, 0x4007cb50, 0x60000000, 0x3ff170a3, 0xd70a3d78},			/* 2.97427=f(1.09000)*/
{32, 0,123,__LINE__, 0x40080888, 0x40000000, 0x3ff19999, 0x999999a1},			/* 3.00416=f(1.10000)*/
{32, 0,123,__LINE__, 0x4008465d, 0xc0000000, 0x3ff1c28f, 0x5c28f5ca},			/* 3.03435=f(1.11000)*/
{32, 0,123,__LINE__, 0x400884d2, 0x60000000, 0x3ff1eb85, 0x1eb851f3},			/* 3.06485=f(1.12000)*/
{32, 0,123,__LINE__, 0x4008c3e7, 0xa0000000, 0x3ff2147a, 0xe147ae1c},			/* 3.09565=f(1.13000)*/
{32, 0,123,__LINE__, 0x4009039f, 0x00000000, 0x3ff23d70, 0xa3d70a45},			/* 3.12676=f(1.14000)*/
{32, 0,123,__LINE__, 0x400943fa, 0x80000000, 0x3ff26666, 0x6666666e},			/* 3.15819=f(1.15000)*/
{32, 0,123,__LINE__, 0x400984fb, 0xa0000000, 0x3ff28f5c, 0x28f5c297},			/* 3.18993=f(1.16000)*/
{32, 0,123,__LINE__, 0x4009c6a4, 0x00000000, 0x3ff2b851, 0xeb851ec0},			/* 3.22199=f(1.17000)*/
{32, 0,123,__LINE__, 0x400a08f5, 0x40000000, 0x3ff2e147, 0xae147ae9},			/* 3.25437=f(1.18000)*/
{32, 0,123,__LINE__, 0x400a4bf1, 0x40000000, 0x3ff30a3d, 0x70a3d712},			/* 3.28708=f(1.19000)*/
{32, 0,123,__LINE__, 0x3f5e989f, 0xa0000000, 0xc01921fb, 0x54442d18},			/* 0.00186=f(-6.28318)*/
{32, 0,123,__LINE__, 0x3f8265d5, 0x00000000, 0xc012d97c, 0x7f3321d2},			/* 0.00898=f(-4.71238)*/
{32, 0,123,__LINE__, 0x3fa62022, 0xa0000000, 0xc00921fb, 0x54442d18},			/* 0.04321=f(-3.14159)*/
{32, 0,123,__LINE__, 0x3fca9bcc, 0x60000000, 0xbff921fb, 0x54442d18},			/* 0.20787=f(-1.57079)*/
{32, 0,123,__LINE__, 0x3ff00000, 0x00000000, 0x00000000, 0x00000000},			/* 1.00000=f(0.00000)*/
{32, 0,123,__LINE__, 0x40133ded, 0xc0000000, 0x3ff921fb, 0x54442d18},			/* 4.81047=f(1.57079)*/
{32, 0,123,__LINE__, 0x40372404, 0x60000000, 0x400921fb, 0x54442d18},			/* 23.1406=f(3.14159)*/
{32, 0,123,__LINE__, 0x405bd456, 0x60000000, 0x4012d97c, 0x7f3321d2},			/* 111.317=f(4.71238)*/
{32, 0,123,__LINE__, 0x3d3a56e2, 0xe0000000, 0xc03e0000, 0x00000000},			/* 9.35763e-14=f(-30.0000)*/
{32, 0,123,__LINE__, 0x3d6205c4, 0xe0000000, 0xc03c4ccc, 0xcccccccd},			/* 5.12231e-13=f(-28.3000)*/
{32, 0,123,__LINE__, 0x3d88a9df, 0x80000000, 0xc03a9999, 0x9999999a},			/* 2.80392e-12=f(-26.6000)*/
{32, 0,123,__LINE__, 0x3db0e03b, 0x40000000, 0xc038e666, 0x66666667},			/* 1.53485e-11=f(-24.9000)*/
{32, 0,123,__LINE__, 0x3dd7182b, 0xe0000000, 0xc0373333, 0x33333334},			/* 8.40170e-11=f(-23.2000)*/
{32, 0,123,__LINE__, 0x3dff9abf, 0xc0000000, 0xc0358000, 0x00000001},			/* 4.59906e-10=f(-21.5000)*/
{32, 0,123,__LINE__, 0x3e25a00a, 0x80000000, 0xc033cccc, 0xccccccce},			/* 2.51750e-09=f(-19.8000)*/
{32, 0,123,__LINE__, 0x3e4d97fd, 0x40000000, 0xc0321999, 0x9999999b},			/* 1.37806e-08=f(-18.1000)*/
{32, 0,123,__LINE__, 0x3e743fd3, 0xa0000000, 0xc0306666, 0x66666668},			/* 7.54346e-08=f(-16.4000)*/
{32, 0,123,__LINE__, 0x3e9bb5ff, 0x80000000, 0xc02d6666, 0x6666666a},			/* 4.12925e-07=f(-14.7000)*/
{32, 0,123,__LINE__, 0x3ec2f605, 0x60000000, 0xc02a0000, 0x00000004},			/* 2.26033e-06=f(-13.0000)*/
{32, 0,123,__LINE__, 0x3ee9f2a9, 0xc0000000, 0xc0269999, 0x9999999e},			/* 1.23729e-05=f(-11.3000)*/
{32, 0,123,__LINE__, 0x3f11c132, 0xa0000000, 0xc0233333, 0x33333338},			/* 6.77287e-05=f(-9.60000)*/
{32, 0,123,__LINE__, 0x3f384c0a, 0xe0000000, 0xc01f9999, 0x999999a3},			/* 0.00037=f(-7.90000)*/
{32, 0,123,__LINE__, 0x3f60a006, 0xa0000000, 0xc018cccc, 0xccccccd6},			/* 0.00202=f(-6.20000)*/
{32, 0,123,__LINE__, 0x3f86c050, 0x00000000, 0xc0120000, 0x00000009},			/* 0.01110=f(-4.50000)*/
{32, 0,123,__LINE__, 0x3faf227f, 0x40000000, 0xc0066666, 0x66666678},			/* 0.06081=f(-2.80000)*/
{32, 0,123,__LINE__, 0x3fd54dc2, 0x60000000, 0xbff19999, 0x999999bd},			/* 0.33287=f(-1.10000)*/
{32, 0,123,__LINE__, 0x3ffd2766, 0x20000000, 0x3fe33333, 0x333332ec},			/* 1.82211=f(0.60000)*/
{32, 0,123,__LINE__, 0x4023f2c7, 0xe0000000, 0x40026666, 0x66666654},			/* 9.97418=f(2.30000)*/
{32, 0,123,__LINE__, 0x404b4c90, 0x20000000, 0x400fffff, 0xffffffee},			/* 54.5981=f(4.00000)*/
{32, 0,123,__LINE__, 0x4072ade0, 0x40000000, 0x4016cccc, 0xccccccc4},			/* 298.867=f(5.70000)*/
{32, 0,123,__LINE__, 0x40998ff0, 0x20000000, 0x401d9999, 0x99999991},			/* 1635.98=f(7.40000)*/
{32, 0,123,__LINE__, 0x40c17da6, 0x20000000, 0x40223333, 0x3333332f},			/* 8955.29=f(9.10000)*/
{32, 0,123,__LINE__, 0x40e7ef9a, 0x80000000, 0x40259999, 0x99999995},			/* 49020=f(10.8000)*/
{32, 0,123,__LINE__, 0x411060c4, 0xe0000000, 0x4028ffff, 0xfffffffb},			/* 268337=f(12.5000)*/
{32, 0,123,__LINE__, 0x413669bf, 0xa0000000, 0x402c6666, 0x66666661},			/* 1.46886e+06=f(14.2000)*/
{32, 0,123,__LINE__, 0x415eac08, 0x40000000, 0x402fcccc, 0xccccccc7},			/* 8.04048e+06=f(15.9000)*/
{32, 0,123,__LINE__, 0x4184fcb5, 0x40000000, 0x40319999, 0x99999997},			/* 4.40132e+07=f(17.6000)*/
{32, 0,123,__LINE__, 0x41acb878, 0x40000000, 0x40334ccc, 0xccccccca},			/* 2.40926e+08=f(19.3000)*/
{32, 0,123,__LINE__, 0x41d3a6e2, 0x80000000, 0x4034ffff, 0xfffffffd},			/* 1.31882e+09=f(21.0000)*/
{32, 0,123,__LINE__, 0x41fae4b5, 0x60000000, 0x4036b333, 0x33333330},			/* 7.21914e+09=f(22.7000)*/
{32, 0,123,__LINE__, 0x422266cf, 0x40000000, 0x40386666, 0x66666663},			/* 3.95171e+10=f(24.4000)*/
{32, 0,123,__LINE__, 0x42492eb0, 0x60000000, 0x403a1999, 0x99999996},			/* 2.16315e+11=f(26.1000)*/
{32, 0,123,__LINE__, 0x42713b19, 0x20000000, 0x403bcccc, 0xccccccc9},			/* 1.18410e+12=f(27.8000)*/
{32, 0,123,__LINE__, 0x42979489, 0x80000000, 0x403d7fff, 0xfffffffc},			/* 6.48168e+12=f(29.5000)*/
0,};
void test_expf(m)   { run_vector_1(m,expf_vec,(char *)(expf),"expf","ff");   }	
