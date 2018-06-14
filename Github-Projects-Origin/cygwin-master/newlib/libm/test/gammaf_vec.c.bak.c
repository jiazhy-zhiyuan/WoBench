#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "test.h"
 one_line_type gammaf_vec[] = {
{ 0, 0,123,__LINE__, 0xbfb5db13, 0xc0000000, 0xbff33333, 0x33333333},			/* -0.08537=f(-1.20000)*/
{ 0, 0,123,__LINE__, 0xbfb5197b, 0xc0000000, 0xbff30a3d, 0x70a3d70a},			/* -0.08242=f(-1.19000)*/
{ 0, 0,123,__LINE__, 0xbfb44f7b, 0x80000000, 0xbff2e147, 0xae147ae1},			/* -0.07933=f(-1.18000)*/
{ 0, 0,123,__LINE__, 0xbfb37cfb, 0x00000000, 0xbff2b851, 0xeb851eb8},			/* -0.07612=f(-1.17000)*/
{ 0, 0,123,__LINE__, 0xbfb2a1df, 0x00000000, 0xbff28f5c, 0x28f5c28f},			/* -0.07278=f(-1.16000)*/
{ 0, 0,123,__LINE__, 0xbfb1be0d, 0x20000000, 0xbff26666, 0x66666666},			/* -0.06930=f(-1.15000)*/
{ 0, 0,123,__LINE__, 0xbfb0d169, 0xa0000000, 0xbff23d70, 0xa3d70a3d},			/* -0.06569=f(-1.14000)*/
{ 0, 0,123,__LINE__, 0xbfafb7b1, 0x00000000, 0xbff2147a, 0xe147ae14},			/* -0.06194=f(-1.13000)*/
{ 0, 0,123,__LINE__, 0xbfadba7a, 0x40000000, 0xbff1eb85, 0x1eb851eb},			/* -0.05806=f(-1.12000)*/
{ 0, 0,123,__LINE__, 0xbfabaaf3, 0xe0000000, 0xbff1c28f, 0x5c28f5c2},			/* -0.05403=f(-1.11000)*/
{ 0, 0,123,__LINE__, 0xbfa988e1, 0xc0000000, 0xbff19999, 0x99999999},			/* -0.04987=f(-1.10000)*/
{ 0, 0,123,__LINE__, 0xbfa75406, 0x40000000, 0xbff170a3, 0xd70a3d70},			/* -0.04556=f(-1.09000)*/
{ 0, 0,123,__LINE__, 0xbfa50c22, 0x00000000, 0xbff147ae, 0x147ae147},			/* -0.04110=f(-1.08000)*/
{ 0, 0,123,__LINE__, 0xbfa2b0f4, 0x40000000, 0xbff11eb8, 0x51eb851e},			/* -0.03650=f(-1.07000)*/
{ 0, 0,123,__LINE__, 0xbfa04238, 0xa0000000, 0xbff0f5c2, 0x8f5c28f5},			/* -0.03175=f(-1.06000)*/
{ 0, 0,123,__LINE__, 0xbf9b7f5d, 0xa0000000, 0xbff0cccc, 0xcccccccc},			/* -0.02685=f(-1.05000)*/
{ 0, 0,123,__LINE__, 0xbf96521e, 0x40000000, 0xbff0a3d7, 0x0a3d70a3},			/* -0.02179=f(-1.04000)*/
{ 0, 0,123,__LINE__, 0xbf90fc23, 0xe0000000, 0xbff07ae1, 0x47ae147a},			/* -0.01658=f(-1.03000)*/
{ 0, 0,123,__LINE__, 0xbf86f9b6, 0xc0000000, 0xbff051eb, 0x851eb851},			/* -0.01121=f(-1.02000)*/
{ 0, 0,123,__LINE__, 0xbf774eb7, 0x00000000, 0xbff028f5, 0xc28f5c28},			/* -0.00569=f(-1.01000)*/
{ 1, 0,123,__LINE__, 0x00000000, 0x00000000, 0xbfefffff, 0xfffffffe},			/* 0.00000=f(-0.01000)*/
{ 1, 0,123,__LINE__, 0x3f77fb34, 0x40000000, 0xbfefae14, 0x7ae147ac},			/* 0.00585=f(-0.99000)*/
{ 1, 0,123,__LINE__, 0x3f8852ba, 0x00000000, 0xbfef5c28, 0xf5c28f5a},			/* 0.01187=f(-0.98000)*/
{ 1, 0,123,__LINE__, 0x3f928057, 0xe0000000, 0xbfef0a3d, 0x70a3d708},			/* 0.01806=f(-0.97000)*/
{ 1, 0,123,__LINE__, 0x3f99046d, 0x20000000, 0xbfeeb851, 0xeb851eb6},			/* 0.02443=f(-0.96000)*/
{ 1, 0,123,__LINE__, 0x3f9fb649, 0x40000000, 0xbfee6666, 0x66666664},			/* 0.03096=f(-0.95000)*/
{ 1, 0,123,__LINE__, 0x3fa34b52, 0xe0000000, 0xbfee147a, 0xe147ae12},			/* 0.03768=f(-0.94000)*/
{ 1, 0,123,__LINE__, 0x3fa6d31f, 0x40000000, 0xbfedc28f, 0x5c28f5c0},			/* 0.04457=f(-0.93000)*/
{ 1, 0,123,__LINE__, 0x3faa72ea, 0xa0000000, 0xbfed70a3, 0xd70a3d6e},			/* 0.05165=f(-0.92000)*/
{ 1, 0,123,__LINE__, 0x3fae2b18, 0xa0000000, 0xbfed1eb8, 0x51eb851c},			/* 0.05892=f(-0.91000)*/
{ 1, 0,123,__LINE__, 0x3fb0fe08, 0xe0000000, 0xbfeccccc, 0xccccccca},			/* 0.06637=f(-0.90000)*/
{ 1, 0,123,__LINE__, 0x3fb2f31e, 0x40000000, 0xbfec7ae1, 0x47ae1478},			/* 0.07402=f(-0.89000)*/
{ 1, 0,123,__LINE__, 0x3fb4f503, 0xc0000000, 0xbfec28f5, 0xc28f5c26},			/* 0.08186=f(-0.88000)*/
{ 1, 0,123,__LINE__, 0x3fb703f1, 0xc0000000, 0xbfebd70a, 0x3d70a3d4},			/* 0.08990=f(-0.87000)*/
{ 1, 0,123,__LINE__, 0x3fb92022, 0x20000000, 0xbfeb851e, 0xb851eb82},			/* 0.09814=f(-0.86000)*/
{ 1, 0,123,__LINE__, 0x3fbb49d1, 0x00000000, 0xbfeb3333, 0x33333330},			/* 0.10659=f(-0.85000)*/
{ 1, 0,123,__LINE__, 0x3fbd813c, 0xe0000000, 0xbfeae147, 0xae147ade},			/* 0.11525=f(-0.84000)*/
{ 1, 0,123,__LINE__, 0x3fbfc6a4, 0x20000000, 0xbfea8f5c, 0x28f5c28c},			/* 0.12412=f(-0.83000)*/
{ 1, 0,123,__LINE__, 0x3fc10d24, 0xc0000000, 0xbfea3d70, 0xa3d70a3a},			/* 0.13321=f(-0.82000)*/
{ 1, 0,123,__LINE__, 0x3fc23e38, 0xa0000000, 0xbfe9eb85, 0x1eb851e8},			/* 0.14252=f(-0.81000)*/
{ 1, 0,123,__LINE__, 0x3fc376b1, 0x00000000, 0xbfe99999, 0x99999996},			/* 0.15205=f(-0.80000)*/
{ 1, 0,123,__LINE__, 0x3fc4b6b2, 0x60000000, 0xbfe947ae, 0x147ae144},			/* 0.16182=f(-0.79000)*/
{ 1, 0,123,__LINE__, 0x3fc5fe63, 0x40000000, 0xbfe8f5c2, 0x8f5c28f2},			/* 0.17182=f(-0.78000)*/
{ 1, 0,123,__LINE__, 0x3fc74de9, 0xa0000000, 0xbfe8a3d7, 0x0a3d70a0},			/* 0.18206=f(-0.77000)*/
{ 1, 0,123,__LINE__, 0x3fc8a56e, 0x80000000, 0xbfe851eb, 0x851eb84e},			/* 0.19254=f(-0.76000)*/
{ 1, 0,123,__LINE__, 0x3fca051c, 0x40000000, 0xbfe7ffff, 0xfffffffc},			/* 0.20328=f(-0.75000)*/
{ 1, 0,123,__LINE__, 0x3fcb6d1e, 0x60000000, 0xbfe7ae14, 0x7ae147aa},			/* 0.21426=f(-0.74000)*/
{ 1, 0,123,__LINE__, 0x3fccdda2, 0x60000000, 0xbfe75c28, 0xf5c28f58},			/* 0.22551=f(-0.73000)*/
{ 1, 0,123,__LINE__, 0x3fce56d7, 0x00000000, 0xbfe70a3d, 0x70a3d706},			/* 0.23702=f(-0.72000)*/
{ 1, 0,123,__LINE__, 0x3fcfd8ee, 0x40000000, 0xbfe6b851, 0xeb851eb4},			/* 0.24880=f(-0.71000)*/
{ 1, 0,123,__LINE__, 0x3fd0b20c, 0xa0000000, 0xbfe66666, 0x66666662},			/* 0.26086=f(-0.70000)*/
{ 1, 0,123,__LINE__, 0x3fd17c47, 0x00000000, 0xbfe6147a, 0xe147ae10},			/* 0.27321=f(-0.69000)*/
{ 1, 0,123,__LINE__, 0x3fd24b41, 0xc0000000, 0xbfe5c28f, 0x5c28f5be},			/* 0.28584=f(-0.68000)*/
{ 1, 0,123,__LINE__, 0x3fd31f19, 0x60000000, 0xbfe570a3, 0xd70a3d6c},			/* 0.29877=f(-0.67000)*/
{ 1, 0,123,__LINE__, 0x3fd3f7ec, 0x00000000, 0xbfe51eb8, 0x51eb851a},			/* 0.31200=f(-0.66000)*/
{ 1, 0,123,__LINE__, 0x3fd4d5d9, 0x00000000, 0xbfe4cccc, 0xccccccc8},			/* 0.32555=f(-0.65000)*/
{ 1, 0,123,__LINE__, 0x3fd5b900, 0x80000000, 0xbfe47ae1, 0x47ae1476},			/* 0.33941=f(-0.64000)*/
{ 1, 0,123,__LINE__, 0x3fd6a184, 0xc0000000, 0xbfe428f5, 0xc28f5c24},			/* 0.35360=f(-0.63000)*/
{ 1, 0,123,__LINE__, 0x3fd78f89, 0x40000000, 0xbfe3d70a, 0x3d70a3d2},			/* 0.36813=f(-0.62000)*/
{ 1, 0,123,__LINE__, 0x3fd88333, 0x40000000, 0xbfe3851e, 0xb851eb80},			/* 0.38300=f(-0.61000)*/
{ 1, 0,123,__LINE__, 0x3fd97ca9, 0xa0000000, 0xbfe33333, 0x3333332e},			/* 0.39823=f(-0.60000)*/
{ 1, 0,123,__LINE__, 0x3fda7c15, 0xe0000000, 0xbfe2e147, 0xae147adc},			/* 0.41382=f(-0.59000)*/
{ 1, 0,123,__LINE__, 0x3fdb81a1, 0xe0000000, 0xbfe28f5c, 0x28f5c28a},			/* 0.42978=f(-0.58000)*/
{ 1, 0,123,__LINE__, 0x3fdc8d7a, 0xa0000000, 0xbfe23d70, 0xa3d70a38},			/* 0.44613=f(-0.57000)*/
{ 1, 0,123,__LINE__, 0x3fdd9fd0, 0x20000000, 0xbfe1eb85, 0x1eb851e6},			/* 0.46287=f(-0.56000)*/
{ 1, 0,123,__LINE__, 0x3fdeb8d3, 0x40000000, 0xbfe19999, 0x99999994},			/* 0.48003=f(-0.55000)*/
{ 1, 0,123,__LINE__, 0x3fdfd8b8, 0xa0000000, 0xbfe147ae, 0x147ae142},			/* 0.49760=f(-0.54000)*/
{ 1, 0,123,__LINE__, 0x3fe07fdb, 0xe0000000, 0xbfe0f5c2, 0x8f5c28f0},			/* 0.51560=f(-0.53000)*/
{ 1, 0,123,__LINE__, 0x3fe11704, 0xe0000000, 0xbfe0a3d7, 0x0a3d709e},			/* 0.53405=f(-0.52000)*/
{ 1, 0,123,__LINE__, 0x3fe1b1f6, 0x20000000, 0xbfe051eb, 0x851eb84c},			/* 0.55297=f(-0.51000)*/
{ 1, 0,123,__LINE__, 0x3fe250d0, 0x40000000, 0xbfdfffff, 0xfffffff4},			/* 0.57236=f(-0.50000)*/
{ 1, 0,123,__LINE__, 0x3fe2f3b5, 0x80000000, 0xbfdf5c28, 0xf5c28f50},			/* 0.59224=f(-0.49000)*/
{ 1, 0,123,__LINE__, 0x3fe39aca, 0x40000000, 0xbfdeb851, 0xeb851eac},			/* 0.61264=f(-0.48000)*/
{ 1, 0,123,__LINE__, 0x3fe44634, 0xc0000000, 0xbfde147a, 0xe147ae08},			/* 0.63357=f(-0.47000)*/
{ 1, 0,123,__LINE__, 0x3fe4f61e, 0x60000000, 0xbfdd70a3, 0xd70a3d64},			/* 0.65504=f(-0.46000)*/
{ 1, 0,123,__LINE__, 0x3fe5aab2, 0x80000000, 0xbfdccccc, 0xccccccc0},			/* 0.67708=f(-0.45000)*/
{ 1, 0,123,__LINE__, 0x3fe6641f, 0xc0000000, 0xbfdc28f5, 0xc28f5c1c},			/* 0.69972=f(-0.44000)*/
{ 1, 0,123,__LINE__, 0x3fe72297, 0x80000000, 0xbfdb851e, 0xb851eb78},			/* 0.72297=f(-0.43000)*/
{ 1, 0,123,__LINE__, 0x3fe7e64e, 0xe0000000, 0xbfdae147, 0xae147ad4},			/* 0.74686=f(-0.42000)*/
{ 1, 0,123,__LINE__, 0x3fe8af7e, 0x20000000, 0xbfda3d70, 0xa3d70a30},			/* 0.77142=f(-0.41000)*/
{ 1, 0,123,__LINE__, 0x3fe97e62, 0x60000000, 0xbfd99999, 0x9999998c},			/* 0.79667=f(-0.40000)*/
{ 1, 0,123,__LINE__, 0x3fea533d, 0x00000000, 0xbfd8f5c2, 0x8f5c28e8},			/* 0.82266=f(-0.39000)*/
{ 1, 0,123,__LINE__, 0x3feb2e53, 0xc0000000, 0xbfd851eb, 0x851eb844},			/* 0.84940=f(-0.38000)*/
{ 1, 0,123,__LINE__, 0x3fec0ff2, 0xc0000000, 0xbfd7ae14, 0x7ae147a0},			/* 0.87694=f(-0.37000)*/
{ 1, 0,123,__LINE__, 0x3fecf86b, 0x60000000, 0xbfd70a3d, 0x70a3d6fc},			/* 0.90532=f(-0.36000)*/
{ 1, 0,123,__LINE__, 0x3fede816, 0xc0000000, 0xbfd66666, 0x66666658},			/* 0.93458=f(-0.35000)*/
{ 1, 0,123,__LINE__, 0x3feedf54, 0xa0000000, 0xbfd5c28f, 0x5c28f5b4},			/* 0.96476=f(-0.34000)*/
{ 1, 0,123,__LINE__, 0x3fefde8d, 0xa0000000, 0xbfd51eb8, 0x51eb8510},			/* 0.99591=f(-0.33000)*/
{ 1, 0,123,__LINE__, 0x3ff0731a, 0x00000000, 0xbfd47ae1, 0x47ae146c},			/* 1.02810=f(-0.32000)*/
{ 1, 0,123,__LINE__, 0x3ff0fb62, 0x00000000, 0xbfd3d70a, 0x3d70a3c8},			/* 1.06137=f(-0.31000)*/
{ 1, 0,123,__LINE__, 0x3ff18863, 0x80000000, 0xbfd33333, 0x33333324},			/* 1.09579=f(-0.30000)*/
{ 1, 0,123,__LINE__, 0x3ff21a69, 0xa0000000, 0xbfd28f5c, 0x28f5c280},			/* 1.13144=f(-0.29000)*/
{ 1, 0,123,__LINE__, 0x3ff2b1c7, 0x80000000, 0xbfd1eb85, 0x1eb851dc},			/* 1.16840=f(-0.28000)*/
{ 1, 0,123,__LINE__, 0x3ff34ed9, 0x40000000, 0xbfd147ae, 0x147ae138},			/* 1.20675=f(-0.27000)*/
{ 1, 0,123,__LINE__, 0x3ff3f205, 0x20000000, 0xbfd0a3d7, 0x0a3d7094},			/* 1.24658=f(-0.26000)*/
{ 1, 0,123,__LINE__, 0x3ff49bbd, 0x80000000, 0xbfcfffff, 0xffffffe0},			/* 1.28802=f(-0.25000)*/
{ 1, 0,123,__LINE__, 0x3ff54c82, 0x80000000, 0xbfceb851, 0xeb851e98},			/* 1.33117=f(-0.24000)*/
{ 1, 0,123,__LINE__, 0x3ff604e4, 0x60000000, 0xbfcd70a3, 0xd70a3d50},			/* 1.37619=f(-0.23000)*/
{ 1, 0,123,__LINE__, 0x3ff6c586, 0xe0000000, 0xbfcc28f5, 0xc28f5c08},			/* 1.42322=f(-0.22000)*/
{ 1, 0,123,__LINE__, 0x3ff78f23, 0xe0000000, 0xbfcae147, 0xae147ac0},			/* 1.47244=f(-0.21000)*/
{ 1, 0,123,__LINE__, 0x3ff86290, 0xc0000000, 0xbfc99999, 0x99999978},			/* 1.52406=f(-0.20000)*/
{ 1, 0,123,__LINE__, 0x3ff940c3, 0x20000000, 0xbfc851eb, 0x851eb830},			/* 1.57831=f(-0.19000)*/
{ 1, 0,123,__LINE__, 0x3ffa2ad8, 0xa0000000, 0xbfc70a3d, 0x70a3d6e8},			/* 1.63546=f(-0.18000)*/
{ 1, 0,123,__LINE__, 0x3ffb221f, 0xa0000000, 0xbfc5c28f, 0x5c28f5a0},			/* 1.69583=f(-0.17000)*/
{ 1, 0,123,__LINE__, 0x3ffc2823, 0x00000000, 0xbfc47ae1, 0x47ae1458},			/* 1.75979=f(-0.16000)*/
{ 1, 0,123,__LINE__, 0x3ffd3eb9, 0xa0000000, 0xbfc33333, 0x33333310},			/* 1.82781=f(-0.15000)*/
{ 1, 0,123,__LINE__, 0x3ffe681c, 0x20000000, 0xbfc1eb85, 0x1eb851c8},			/* 1.90041=f(-0.14000)*/
{ 1, 0,123,__LINE__, 0x3fffa701, 0x40000000, 0xbfc0a3d7, 0x0a3d7080},			/* 1.97827=f(-0.13000)*/
{13, 0,123,__LINE__, 0x40007f62, 0xe0000000, 0xbfbeb851, 0xeb851e71},			/* 2.06220=f(-0.12000)*/
{13, 0,123,__LINE__, 0x400139d4, 0x00000000, 0xbfbc28f5, 0xc28f5be2},			/* 2.15323=f(-0.11000)*/
{13, 0,123,__LINE__, 0x4002058e, 0x40000000, 0xbfb99999, 0x99999953},			/* 2.25271=f(-0.00100)*/
{13, 0,123,__LINE__, 0x4002e628, 0xe0000000, 0xbfb70a3d, 0x70a3d6c4},			/* 2.36238=f(-0.09000)*/
{13, 0,123,__LINE__, 0x4003e080, 0xc0000000, 0xbfb47ae1, 0x47ae1435},			/* 2.48462=f(-0.08000)*/
{14, 0,123,__LINE__, 0x4004fb66, 0x60000000, 0xbfb1eb85, 0x1eb851a6},			/* 2.62275=f(-0.07000)*/
{15, 0,123,__LINE__, 0x400640d4, 0xa0000000, 0xbfaeb851, 0xeb851e2d},			/* 2.78165=f(-0.06000)*/
{17, 0,123,__LINE__, 0x4007c043, 0xc0000000, 0xbfa99999, 0x9999990e},			/* 2.96887=f(-0.05000)*/
{12, 0,123,__LINE__, 0x4009939d, 0xc0000000, 0xbfa47ae1, 0x47ae13ef},			/* 3.19707=f(-0.04000)*/
{14, 0,123,__LINE__, 0x400beb76, 0x00000000, 0xbf9eb851, 0xeb851da0},			/* 3.48997=f(-0.03000)*/
{13, 0,123,__LINE__, 0x400f34d9, 0x00000000, 0xbf947ae1, 0x47ae1362},			/* 3.90080=f(-0.02000)*/
{11, 0,123,__LINE__, 0x401265de, 0x20000000, 0xbf847ae1, 0x47ae1249},			/* 4.59948=f(-0.00010)*/
{ 0, 0,123,__LINE__, 0x40414837, 0x20000000, 0x3cd19000, 0x00000000},			/* 34.5641=f(9.74915e-16)*/
{11, 0,123,__LINE__, 0x401265de, 0x20000000, 0x3f847ae1, 0x47ae16ad},			/* 4.59948=f(0.01000)*/
{13, 0,123,__LINE__, 0x400f34d9, 0x00000000, 0x3f947ae1, 0x47ae1594},			/* 3.90080=f(0.02000)*/
{14, 0,123,__LINE__, 0x400beb76, 0x00000000, 0x3f9eb851, 0xeb851fd2},			/* 3.48997=f(0.03000)*/
{12, 0,123,__LINE__, 0x4009939d, 0xc0000000, 0x3fa47ae1, 0x47ae1508},			/* 3.19707=f(0.04000)*/
{17, 0,123,__LINE__, 0x4007c043, 0xc0000000, 0x3fa99999, 0x99999a27},			/* 2.96887=f(0.05000)*/
{15, 0,123,__LINE__, 0x400640d4, 0xa0000000, 0x3faeb851, 0xeb851f46},			/* 2.78165=f(0.06000)*/
{14, 0,123,__LINE__, 0x4004fb66, 0x60000000, 0x3fb1eb85, 0x1eb85232},			/* 2.62275=f(0.07000)*/
{13, 0,123,__LINE__, 0x4003e080, 0xc0000000, 0x3fb47ae1, 0x47ae14c1},			/* 2.48462=f(0.08000)*/
{13, 0,123,__LINE__, 0x4002e628, 0xe0000000, 0x3fb70a3d, 0x70a3d750},			/* 2.36238=f(0.09000)*/
{13, 0,123,__LINE__, 0x4002058e, 0x40000000, 0x3fb99999, 0x999999df},			/* 2.25271=f(0.10000)*/
{13, 0,123,__LINE__, 0x400139d4, 0x00000000, 0x3fbc28f5, 0xc28f5c6e},			/* 2.15323=f(0.11000)*/
{13, 0,123,__LINE__, 0x40007f62, 0xe0000000, 0x3fbeb851, 0xeb851efd},			/* 2.06220=f(0.12000)*/
{ 1, 0,123,__LINE__, 0x3fffa701, 0x40000000, 0x3fc0a3d7, 0x0a3d70c6},			/* 1.97827=f(0.13000)*/
{ 1, 0,123,__LINE__, 0x3ffe681c, 0x20000000, 0x3fc1eb85, 0x1eb8520e},			/* 1.90041=f(0.14000)*/
{ 1, 0,123,__LINE__, 0x3ffd3eb9, 0xa0000000, 0x3fc33333, 0x33333356},			/* 1.82781=f(0.15000)*/
{ 1, 0,123,__LINE__, 0x3ffc2823, 0x00000000, 0x3fc47ae1, 0x47ae149e},			/* 1.75979=f(0.16000)*/
{ 1, 0,123,__LINE__, 0x3ffb221f, 0xa0000000, 0x3fc5c28f, 0x5c28f5e6},			/* 1.69583=f(0.17000)*/
{ 1, 0,123,__LINE__, 0x3ffa2ad8, 0xa0000000, 0x3fc70a3d, 0x70a3d72e},			/* 1.63546=f(0.18000)*/
{ 1, 0,123,__LINE__, 0x3ff940c3, 0x20000000, 0x3fc851eb, 0x851eb876},			/* 1.57831=f(0.19000)*/
{ 1, 0,123,__LINE__, 0x3ff86290, 0xc0000000, 0x3fc99999, 0x999999be},			/* 1.52406=f(0.20000)*/
{ 1, 0,123,__LINE__, 0x3ff78f23, 0xe0000000, 0x3fcae147, 0xae147b06},			/* 1.47244=f(0.21000)*/
{ 1, 0,123,__LINE__, 0x3ff6c586, 0xe0000000, 0x3fcc28f5, 0xc28f5c4e},			/* 1.42322=f(0.22000)*/
{ 1, 0,123,__LINE__, 0x3ff604e4, 0x60000000, 0x3fcd70a3, 0xd70a3d96},			/* 1.37619=f(0.23000)*/
{ 1, 0,123,__LINE__, 0x3ff54c82, 0x80000000, 0x3fceb851, 0xeb851ede},			/* 1.33117=f(0.24000)*/
{ 1, 0,123,__LINE__, 0x3ff49bbd, 0x80000000, 0x3fd00000, 0x00000013},			/* 1.28802=f(0.25000)*/
{ 1, 0,123,__LINE__, 0x3ff3f205, 0x20000000, 0x3fd0a3d7, 0x0a3d70b7},			/* 1.24658=f(0.26000)*/
{ 1, 0,123,__LINE__, 0x3ff34ed9, 0x40000000, 0x3fd147ae, 0x147ae15b},			/* 1.20675=f(0.27000)*/
{ 1, 0,123,__LINE__, 0x3ff2b1c7, 0x80000000, 0x3fd1eb85, 0x1eb851ff},			/* 1.16840=f(0.28000)*/
{ 1, 0,123,__LINE__, 0x3ff21a69, 0xa0000000, 0x3fd28f5c, 0x28f5c2a3},			/* 1.13144=f(0.29000)*/
{ 1, 0,123,__LINE__, 0x3ff18863, 0x80000000, 0x3fd33333, 0x33333347},			/* 1.09579=f(0.30000)*/
{ 1, 0,123,__LINE__, 0x3ff0fb62, 0x00000000, 0x3fd3d70a, 0x3d70a3eb},			/* 1.06137=f(0.31000)*/
{ 1, 0,123,__LINE__, 0x3ff0731a, 0x00000000, 0x3fd47ae1, 0x47ae148f},			/* 1.02810=f(0.32000)*/
{ 1, 0,123,__LINE__, 0x3fefde8d, 0xa0000000, 0x3fd51eb8, 0x51eb8533},			/* 0.99591=f(0.33000)*/
{ 1, 0,123,__LINE__, 0x3feedf54, 0xa0000000, 0x3fd5c28f, 0x5c28f5d7},			/* 0.96476=f(0.34000)*/
{ 1, 0,123,__LINE__, 0x3fede816, 0xc0000000, 0x3fd66666, 0x6666667b},			/* 0.93458=f(0.35000)*/
{ 1, 0,123,__LINE__, 0x3fecf86b, 0x60000000, 0x3fd70a3d, 0x70a3d71f},			/* 0.90532=f(0.36000)*/
{ 1, 0,123,__LINE__, 0x3fec0ff2, 0xc0000000, 0x3fd7ae14, 0x7ae147c3},			/* 0.87694=f(0.37000)*/
{ 1, 0,123,__LINE__, 0x3feb2e53, 0xc0000000, 0x3fd851eb, 0x851eb867},			/* 0.84940=f(0.38000)*/
{ 1, 0,123,__LINE__, 0x3fea533d, 0x00000000, 0x3fd8f5c2, 0x8f5c290b},			/* 0.82266=f(0.39000)*/
{ 1, 0,123,__LINE__, 0x3fe97e62, 0x60000000, 0x3fd99999, 0x999999af},			/* 0.79667=f(0.40000)*/
{ 1, 0,123,__LINE__, 0x3fe8af7e, 0x20000000, 0x3fda3d70, 0xa3d70a53},			/* 0.77142=f(0.41000)*/
{ 1, 0,123,__LINE__, 0x3fe7e64e, 0xe0000000, 0x3fdae147, 0xae147af7},			/* 0.74686=f(0.42000)*/
{ 1, 0,123,__LINE__, 0x3fe72297, 0x80000000, 0x3fdb851e, 0xb851eb9b},			/* 0.72297=f(0.43000)*/
{ 1, 0,123,__LINE__, 0x3fe6641f, 0xc0000000, 0x3fdc28f5, 0xc28f5c3f},			/* 0.69972=f(0.44000)*/
{ 1, 0,123,__LINE__, 0x3fe5aab2, 0x80000000, 0x3fdccccc, 0xcccccce3},			/* 0.67708=f(0.45000)*/
{ 1, 0,123,__LINE__, 0x3fe4f61e, 0x60000000, 0x3fdd70a3, 0xd70a3d87},			/* 0.65504=f(0.46000)*/
{ 1, 0,123,__LINE__, 0x3fe44634, 0xc0000000, 0x3fde147a, 0xe147ae2b},			/* 0.63357=f(0.47000)*/
{ 1, 0,123,__LINE__, 0x3fe39aca, 0x40000000, 0x3fdeb851, 0xeb851ecf},			/* 0.61264=f(0.48000)*/
{ 1, 0,123,__LINE__, 0x3fe2f3b5, 0x80000000, 0x3fdf5c28, 0xf5c28f73},			/* 0.59224=f(0.49000)*/
{ 1, 0,123,__LINE__, 0x3fe250d0, 0x40000000, 0x3fe00000, 0x0000000b},			/* 0.57236=f(0.50000)*/
{ 1, 0,123,__LINE__, 0x3fe1b1f6, 0x20000000, 0x3fe051eb, 0x851eb85d},			/* 0.55297=f(0.51000)*/
{ 1, 0,123,__LINE__, 0x3fe11704, 0xe0000000, 0x3fe0a3d7, 0x0a3d70af},			/* 0.53405=f(0.52000)*/
{ 1, 0,123,__LINE__, 0x3fe07fdb, 0xe0000000, 0x3fe0f5c2, 0x8f5c2901},			/* 0.51560=f(0.53000)*/
{ 1, 0,123,__LINE__, 0x3fdfd8b8, 0xa0000000, 0x3fe147ae, 0x147ae153},			/* 0.49760=f(0.54000)*/
{ 1, 0,123,__LINE__, 0x3fdeb8d3, 0x40000000, 0x3fe19999, 0x999999a5},			/* 0.48003=f(0.55000)*/
{ 1, 0,123,__LINE__, 0x3fdd9fd0, 0x20000000, 0x3fe1eb85, 0x1eb851f7},			/* 0.46287=f(0.56000)*/
{ 1, 0,123,__LINE__, 0x3fdc8d7a, 0xa0000000, 0x3fe23d70, 0xa3d70a49},			/* 0.44613=f(0.57000)*/
{ 1, 0,123,__LINE__, 0x3fdb81a1, 0xe0000000, 0x3fe28f5c, 0x28f5c29b},			/* 0.42978=f(0.58000)*/
{ 1, 0,123,__LINE__, 0x3fda7c15, 0xe0000000, 0x3fe2e147, 0xae147aed},			/* 0.41382=f(0.59000)*/
{ 1, 0,123,__LINE__, 0x3fd97ca9, 0xa0000000, 0x3fe33333, 0x3333333f},			/* 0.39823=f(0.60000)*/
{ 1, 0,123,__LINE__, 0x3fd88333, 0x40000000, 0x3fe3851e, 0xb851eb91},			/* 0.38300=f(0.61000)*/
{ 1, 0,123,__LINE__, 0x3fd78f89, 0x40000000, 0x3fe3d70a, 0x3d70a3e3},			/* 0.36813=f(0.62000)*/
{ 1, 0,123,__LINE__, 0x3fd6a184, 0xc0000000, 0x3fe428f5, 0xc28f5c35},			/* 0.35360=f(0.63000)*/
{ 1, 0,123,__LINE__, 0x3fd5b900, 0x80000000, 0x3fe47ae1, 0x47ae1487},			/* 0.33941=f(0.64000)*/
{ 1, 0,123,__LINE__, 0x3fd4d5d9, 0x00000000, 0x3fe4cccc, 0xccccccd9},			/* 0.32555=f(0.65000)*/
{ 1, 0,123,__LINE__, 0x3fd3f7ec, 0x00000000, 0x3fe51eb8, 0x51eb852b},			/* 0.31200=f(0.66000)*/
{ 1, 0,123,__LINE__, 0x3fd31f19, 0x60000000, 0x3fe570a3, 0xd70a3d7d},			/* 0.29877=f(0.67000)*/
{ 1, 0,123,__LINE__, 0x3fd24b41, 0xc0000000, 0x3fe5c28f, 0x5c28f5cf},			/* 0.28584=f(0.68000)*/
{ 1, 0,123,__LINE__, 0x3fd17c47, 0x00000000, 0x3fe6147a, 0xe147ae21},			/* 0.27321=f(0.69000)*/
{ 1, 0,123,__LINE__, 0x3fd0b20c, 0xa0000000, 0x3fe66666, 0x66666673},			/* 0.26086=f(0.70000)*/
{ 1, 0,123,__LINE__, 0x3fcfd8ee, 0x40000000, 0x3fe6b851, 0xeb851ec5},			/* 0.24880=f(0.71000)*/
{ 1, 0,123,__LINE__, 0x3fce56d7, 0x00000000, 0x3fe70a3d, 0x70a3d717},			/* 0.23702=f(0.72000)*/
{ 1, 0,123,__LINE__, 0x3fccdda2, 0x60000000, 0x3fe75c28, 0xf5c28f69},			/* 0.22551=f(0.73000)*/
{ 1, 0,123,__LINE__, 0x3fcb6d1e, 0x60000000, 0x3fe7ae14, 0x7ae147bb},			/* 0.21426=f(0.74000)*/
{ 1, 0,123,__LINE__, 0x3fca051c, 0x40000000, 0x3fe80000, 0x0000000d},			/* 0.20328=f(0.75000)*/
{ 1, 0,123,__LINE__, 0x3fc8a56e, 0x80000000, 0x3fe851eb, 0x851eb85f},			/* 0.19254=f(0.76000)*/
{ 1, 0,123,__LINE__, 0x3fc74de9, 0xa0000000, 0x3fe8a3d7, 0x0a3d70b1},			/* 0.18206=f(0.77000)*/
{ 1, 0,123,__LINE__, 0x3fc5fe63, 0x40000000, 0x3fe8f5c2, 0x8f5c2903},			/* 0.17182=f(0.78000)*/
{ 1, 0,123,__LINE__, 0x3fc4b6b2, 0x60000000, 0x3fe947ae, 0x147ae155},			/* 0.16182=f(0.79000)*/
{ 1, 0,123,__LINE__, 0x3fc376b1, 0x00000000, 0x3fe99999, 0x999999a7},			/* 0.15205=f(0.80000)*/
{ 1, 0,123,__LINE__, 0x3fc23e38, 0xa0000000, 0x3fe9eb85, 0x1eb851f9},			/* 0.14252=f(0.81000)*/
{ 1, 0,123,__LINE__, 0x3fc10d24, 0xc0000000, 0x3fea3d70, 0xa3d70a4b},			/* 0.13321=f(0.82000)*/
{ 1, 0,123,__LINE__, 0x3fbfc6a4, 0x20000000, 0x3fea8f5c, 0x28f5c29d},			/* 0.12412=f(0.83000)*/
{ 1, 0,123,__LINE__, 0x3fbd813c, 0xe0000000, 0x3feae147, 0xae147aef},			/* 0.11525=f(0.84000)*/
{ 1, 0,123,__LINE__, 0x3fbb49d1, 0x00000000, 0x3feb3333, 0x33333341},			/* 0.10659=f(0.85000)*/
{ 1, 0,123,__LINE__, 0x3fb92022, 0x20000000, 0x3feb851e, 0xb851eb93},			/* 0.09814=f(0.86000)*/
{ 1, 0,123,__LINE__, 0x3fb703f1, 0xc0000000, 0x3febd70a, 0x3d70a3e5},			/* 0.08990=f(0.87000)*/
{ 1, 0,123,__LINE__, 0x3fb4f503, 0xc0000000, 0x3fec28f5, 0xc28f5c37},			/* 0.08186=f(0.88000)*/
{ 1, 0,123,__LINE__, 0x3fb2f31e, 0x40000000, 0x3fec7ae1, 0x47ae1489},			/* 0.07402=f(0.89000)*/
{ 1, 0,123,__LINE__, 0x3fb0fe08, 0xe0000000, 0x3feccccc, 0xccccccdb},			/* 0.06637=f(0.90000)*/
{ 1, 0,123,__LINE__, 0x3fae2b18, 0xa0000000, 0x3fed1eb8, 0x51eb852d},			/* 0.05892=f(0.91000)*/
{ 1, 0,123,__LINE__, 0x3faa72ea, 0xa0000000, 0x3fed70a3, 0xd70a3d7f},			/* 0.05165=f(0.92000)*/
{ 1, 0,123,__LINE__, 0x3fa6d31f, 0x40000000, 0x3fedc28f, 0x5c28f5d1},			/* 0.04457=f(0.93000)*/
{ 1, 0,123,__LINE__, 0x3fa34b52, 0xe0000000, 0x3fee147a, 0xe147ae23},			/* 0.03768=f(0.94000)*/
{ 1, 0,123,__LINE__, 0x3f9fb649, 0x40000000, 0x3fee6666, 0x66666675},			/* 0.03096=f(0.95000)*/
{ 1, 0,123,__LINE__, 0x3f99046d, 0x20000000, 0x3feeb851, 0xeb851ec7},			/* 0.02443=f(0.96000)*/
{ 1, 0,123,__LINE__, 0x3f928057, 0xe0000000, 0x3fef0a3d, 0x70a3d719},			/* 0.01806=f(0.97000)*/
{ 1, 0,123,__LINE__, 0x3f8852ba, 0x00000000, 0x3fef5c28, 0xf5c28f6b},			/* 0.01187=f(0.98000)*/
{ 1, 0,123,__LINE__, 0x3f77fb34, 0x40000000, 0x3fefae14, 0x7ae147bd},			/* 0.00585=f(0.99000)*/
{ 1, 0,123,__LINE__, 0x00000000, 0x00000000, 0x3ff00000, 0x00000007},			/* 0.00000=f(1.00000)*/
{ 0, 0,123,__LINE__, 0xbf774eb7, 0x00000000, 0x3ff028f5, 0xc28f5c30},			/* -0.00569=f(1.01000)*/
{ 0, 0,123,__LINE__, 0xbf86f9b6, 0xc0000000, 0x3ff051eb, 0x851eb859},			/* -0.01121=f(1.02000)*/
{ 0, 0,123,__LINE__, 0xbf90fc23, 0xe0000000, 0x3ff07ae1, 0x47ae1482},			/* -0.01658=f(1.03000)*/
{ 0, 0,123,__LINE__, 0xbf96521e, 0x40000000, 0x3ff0a3d7, 0x0a3d70ab},			/* -0.02179=f(1.04000)*/
{ 0, 0,123,__LINE__, 0xbf9b7f5d, 0xa0000000, 0x3ff0cccc, 0xccccccd4},			/* -0.02685=f(1.05000)*/
{ 0, 0,123,__LINE__, 0xbfa04238, 0xa0000000, 0x3ff0f5c2, 0x8f5c28fd},			/* -0.03175=f(1.06000)*/
{ 0, 0,123,__LINE__, 0xbfa2b0f4, 0x40000000, 0x3ff11eb8, 0x51eb8526},			/* -0.03650=f(1.07000)*/
{ 0, 0,123,__LINE__, 0xbfa50c22, 0x00000000, 0x3ff147ae, 0x147ae14f},			/* -0.04110=f(1.08000)*/
{ 0, 0,123,__LINE__, 0xbfa75406, 0x40000000, 0x3ff170a3, 0xd70a3d78},			/* -0.04556=f(1.09000)*/
{ 0, 0,123,__LINE__, 0xbfa988e1, 0xc0000000, 0x3ff19999, 0x999999a1},			/* -0.04987=f(1.10000)*/
{ 0, 0,123,__LINE__, 0xbfabaaf3, 0xe0000000, 0x3ff1c28f, 0x5c28f5ca},			/* -0.05403=f(1.11000)*/
{ 0, 0,123,__LINE__, 0xbfadba7a, 0x40000000, 0x3ff1eb85, 0x1eb851f3},			/* -0.05806=f(1.12000)*/
{ 0, 0,123,__LINE__, 0xbfafb7b1, 0x00000000, 0x3ff2147a, 0xe147ae1c},			/* -0.06194=f(1.13000)*/
{ 0, 0,123,__LINE__, 0xbfb0d169, 0xa0000000, 0x3ff23d70, 0xa3d70a45},			/* -0.06569=f(1.14000)*/
{ 0, 0,123,__LINE__, 0xbfb1be0d, 0x20000000, 0x3ff26666, 0x6666666e},			/* -0.06930=f(1.15000)*/
{ 0, 0,123,__LINE__, 0xbfb2a1df, 0x00000000, 0x3ff28f5c, 0x28f5c297},			/* -0.07278=f(1.16000)*/
{ 0, 0,123,__LINE__, 0xbfb37cfb, 0x00000000, 0x3ff2b851, 0xeb851ec0},			/* -0.07612=f(1.17000)*/
{ 0, 0,123,__LINE__, 0xbfb44f7b, 0x80000000, 0x3ff2e147, 0xae147ae9},			/* -0.07933=f(1.18000)*/
{ 0, 0,123,__LINE__, 0xbfb5197b, 0xc0000000, 0x3ff30a3d, 0x70a3d712},			/* -0.08242=f(1.19000)*/
{12, 0,123,__LINE__, 0x40151c74, 0xc0000000, 0xc01921fb, 0x54442d18},			/* 5.27778=f(-6.28318)*/
{11, 0,123,__LINE__, 0x400608aa, 0x80000000, 0xc012d97c, 0x7f3321d2},			/* 2.75423=f(-4.71238)*/
{ 1, 0,123,__LINE__, 0x3fea7c79, 0x80000000, 0xc00921fb, 0x54442d18},			/* 0.82769=f(-3.14159)*/
{ 0, 0,123,__LINE__, 0xbfbdabdf, 0x00000000, 0xbff921fb, 0x54442d18},			/* -0.11590=f(-1.57079)*/
{ 0,15, 39,__LINE__, 0x40500000, 0x00000000, 0x00000000, 0x00000000},			/* 64.0000=f(0.00000)*/
{ 0, 0,123,__LINE__, 0xbfbdabdf, 0x00000000, 0x3ff921fb, 0x54442d18},			/* -0.11590=f(1.57079)*/
{ 1, 0,123,__LINE__, 0x3fea7c79, 0x80000000, 0x400921fb, 0x54442d18},			/* 0.82769=f(3.14159)*/
{11, 0,123,__LINE__, 0x400608aa, 0x80000000, 0x4012d97c, 0x7f3321d2},			/* 2.75423=f(4.71238)*/
{11, 0,123,__LINE__, 0x4051d073, 0x60000000, 0xc03e0000, 0x00000000},			/* 71.2570=f(-30.0000)*/
{11, 0,123,__LINE__, 0x4050636b, 0xa0000000, 0xc03c4ccc, 0xcccccccd},			/* 65.5534=f(-28.3000)*/
{12, 0,123,__LINE__, 0x404dfa17, 0xe0000000, 0xc03a9999, 0x9999999a},			/* 59.9538=f(-26.6000)*/
{12, 0,123,__LINE__, 0x404b3b87, 0x20000000, 0xc038e666, 0x66666667},			/* 54.4650=f(-24.9000)*/
{ 9, 0,123,__LINE__, 0x40488c22, 0x20000000, 0xc0373333, 0x33333334},			/* 49.0947=f(-23.2000)*/
{ 9, 0,123,__LINE__, 0x4045ed0c, 0x00000000, 0xc0358000, 0x00000001},			/* 43.8519=f(-21.5000)*/
{ 9, 0,123,__LINE__, 0x40435f97, 0x60000000, 0xc033cccc, 0xccccccce},			/* 38.7468=f(-19.8000)*/
{ 9, 0,123,__LINE__, 0x4040e552, 0xe0000000, 0xc0321999, 0x9999999b},			/* 33.7915=f(-18.1000)*/
{13, 0,123,__LINE__, 0x403d0033, 0xe0000000, 0xc0306666, 0x66666668},			/* 29.0007=f(-16.4000)*/
{12, 0,123,__LINE__, 0x4038645c, 0xa0000000, 0xc02d6666, 0x6666666a},			/* 24.3920=f(-14.7000)*/
{14, 0,123,__LINE__, 0x4033fcba, 0x00000000, 0xc02a0000, 0x00000004},			/* 19.9872=f(-13.0000)*/
{15, 0,123,__LINE__, 0x402fa0dc, 0x80000000, 0xc0269999, 0x9999999e},			/* 15.8141=f(-11.3000)*/
{12, 0,123,__LINE__, 0x4027d1bf, 0x20000000, 0xc0233333, 0x33333338},			/* 11.9096=f(-9.60000)*/
{13, 0,123,__LINE__, 0x4020a606, 0x20000000, 0xc01f9999, 0x999999a3},			/* 8.32426=f(-7.90000)*/
{12, 0,123,__LINE__, 0x40148779, 0x40000000, 0xc018cccc, 0xccccccd6},			/* 5.13229=f(-6.20000)*/
{11, 0,123,__LINE__, 0x4003a140, 0xa0000000, 0xc0120000, 0x00000009},			/* 2.45373=f(-4.50000)*/
{ 1, 0,123,__LINE__, 0x3fe088d4, 0x40000000, 0xc0066666, 0x66666678},			/* 0.51670=f(-2.80000)*/
{ 0, 0,123,__LINE__, 0xbfa988e1, 0xc0000000, 0xbff19999, 0x999999bd},			/* -0.04987=f(-1.10000)*/
{ 1, 0,123,__LINE__, 0x3fd97ca9, 0xa0000000, 0x3fe33333, 0x333332ec},			/* 0.39823=f(0.60000)*/
{ 1, 0,123,__LINE__, 0x3fc3bc7a, 0xa0000000, 0x40026666, 0x66666654},			/* 0.15418=f(2.30000)*/
{ 1, 0,123,__LINE__, 0x3ffcab0c, 0x00000000, 0x400fffff, 0xffffffee},			/* 1.79175=f(4.00000)*/
{12, 0,123,__LINE__, 0x401122c8, 0x60000000, 0x4016cccc, 0xccccccc4},			/* 4.28396=f(5.70000)*/
{10, 0,123,__LINE__, 0x401d5c93, 0x20000000, 0x401d9999, 0x99999991},			/* 7.34040=f(7.40000)*/
{12, 0,123,__LINE__, 0x4025a375, 0x20000000, 0x40223333, 0x3333332f},			/* 10.8192=f(9.10000)*/
{15, 0,123,__LINE__, 0x402d459e, 0xe0000000, 0x40259999, 0x99999995},			/* 14.6359=f(10.8000)*/
{14, 0,123,__LINE__, 0x4032bbfe, 0x40000000, 0x4028ffff, 0xfffffffb},			/* 18.7343=f(12.5000)*/
{14, 0,123,__LINE__, 0x40371300, 0x00000000, 0x402c6666, 0x66666661},			/* 23.0742=f(14.2000)*/
{12, 0,123,__LINE__, 0x403ba020, 0x40000000, 0x402fcccc, 0xccccccc7},			/* 27.6254=f(15.9000)*/
{ 9, 0,123,__LINE__, 0x40402eb0, 0x00000000, 0x40319999, 0x99999997},			/* 32.3647=f(17.6000)*/
{ 9, 0,123,__LINE__, 0x4042a2f9, 0x20000000, 0x40334ccc, 0xccccccca},			/* 37.2732=f(19.3000)*/
{ 9, 0,123,__LINE__, 0x40452af5, 0x80000000, 0x4034ffff, 0xfffffffd},			/* 42.3356=f(21.0000)*/
{ 9, 0,123,__LINE__, 0x4047c501, 0xa0000000, 0x4036b333, 0x33333330},			/* 47.5391=f(22.7000)*/
{12, 0,123,__LINE__, 0x404a6fba, 0xe0000000, 0x40386666, 0x66666663},			/* 52.8728=f(24.4000)*/
{12, 0,123,__LINE__, 0x404d29f1, 0x40000000, 0x403a1999, 0x99999996},			/* 58.3276=f(26.1000)*/
{12, 0,123,__LINE__, 0x404ff29d, 0x20000000, 0x403bcccc, 0xccccccc9},			/* 63.8954=f(27.8000)*/
{11, 0,123,__LINE__, 0x4051646b, 0xe0000000, 0x403d7fff, 0xfffffffc},			/* 69.5690=f(29.5000)*/
0,};
test_gammaf(m)   {run_vector_1(m,gammaf_vec,(char *)(gammaf),"gammaf","ff");   }	
