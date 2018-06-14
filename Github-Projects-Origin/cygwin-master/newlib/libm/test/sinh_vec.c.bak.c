#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
#include "test.h"
 one_line_type sinh_vec[] = {
{61, 0,123,__LINE__, 0xbff826c0, 0xf3412349, 0xbff33333, 0x33333333},			/* -1.50946=f(-1.20000)*/
{61, 0,123,__LINE__, 0xbff7dce5, 0xac88bd42, 0xbff30a3d, 0x70a3d70a},			/* -1.49143=f(-1.19000)*/
{60, 0,123,__LINE__, 0xbff793a6, 0xc96a7945, 0xbff2e147, 0xae147ae1},			/* -1.47354=f(-1.18000)*/
{61, 0,123,__LINE__, 0xbff74b02, 0x69df80b2, 0xbff2b851, 0xeb851eb8},			/* -1.45581=f(-1.17000)*/
{64, 0,123,__LINE__, 0xbff702f6, 0xb1d59e8d, 0xbff28f5c, 0x28f5c28f},			/* -1.43822=f(-1.16000)*/
{64, 0,123,__LINE__, 0xbff6bb81, 0xc9230f5e, 0xbff26666, 0x66666666},			/* -1.42077=f(-1.15000)*/
{64, 0,123,__LINE__, 0xbff674a1, 0xdb7a6ae1, 0xbff23d70, 0xa3d70a3d},			/* -1.40347=f(-1.14000)*/
{64, 0,123,__LINE__, 0xbff62e55, 0x185ea6e8, 0xbff2147a, 0xe147ae14},			/* -1.38631=f(-1.13000)*/
{62, 0,123,__LINE__, 0xbff5e899, 0xb3173341, 0xbff1eb85, 0x1eb851eb},			/* -1.36928=f(-1.12000)*/
{63, 0,123,__LINE__, 0xbff5a36d, 0xe2a42e52, 0xbff1c28f, 0x5c28f5c2},			/* -1.35240=f(-1.11000)*/
{63, 0,123,__LINE__, 0xbff55ecf, 0xe1b2b212, 0xbff19999, 0x99999999},			/* -1.33564=f(-1.10000)*/
{61, 0,123,__LINE__, 0xbff51abd, 0xee91391b, 0xbff170a3, 0xd70a3d70},			/* -1.31902=f(-1.09000)*/
{63, 0,123,__LINE__, 0xbff4d736, 0x4b241b87, 0xbff147ae, 0x147ae147},			/* -1.30254=f(-1.08000)*/
{59, 0,123,__LINE__, 0xbff49437, 0x3cda2350, 0xbff11eb8, 0x51eb851e},			/* -1.28618=f(-1.07000)*/
{60, 0,123,__LINE__, 0xbff451bf, 0x0ca137d8, 0xbff0f5c2, 0x8f5c28f5},			/* -1.26995=f(-1.06000)*/
{63, 0,123,__LINE__, 0xbff40fcc, 0x06db2079, 0xbff0cccc, 0xcccccccc},			/* -1.25385=f(-1.05000)*/
{60, 0,123,__LINE__, 0xbff3ce5c, 0x7b525d87, 0xbff0a3d7, 0x0a3d70a3},			/* -1.23788=f(-1.04000)*/
{63, 0,123,__LINE__, 0xbff38d6e, 0xbd2f17d4, 0xbff07ae1, 0x47ae147a},			/* -1.22202=f(-1.03000)*/
{63, 0,123,__LINE__, 0xbff34d01, 0x22ec2632, 0xbff051eb, 0x851eb851},			/* -1.20630=f(-1.02000)*/
{61, 0,123,__LINE__, 0xbff30d12, 0x064c28b2, 0xbff028f5, 0xc28f5c28},			/* -1.19069=f(-1.01000)*/
{64, 0,123,__LINE__, 0xbff2cd9f, 0xc44eb981, 0xbfefffff, 0xfffffffe},			/* -1.17520=f(-0.01000)*/
{64, 0,123,__LINE__, 0xbff28ea8, 0xbd25b2d0, 0xbfefae14, 0x7ae147ac},			/* -1.15982=f(-0.99000)*/
{64, 0,123,__LINE__, 0xbff2502b, 0x542a89e1, 0xbfef5c28, 0xf5c28f5a},			/* -1.14457=f(-0.98000)*/
{64, 0,123,__LINE__, 0xbff21225, 0xefd3be98, 0xbfef0a3d, 0x70a3d708},			/* -1.12943=f(-0.97000)*/
{64, 0,123,__LINE__, 0xbff1d496, 0xf9aa5f8e, 0xbfeeb851, 0xeb851eb6},			/* -1.11440=f(-0.96000)*/
{64, 0,123,__LINE__, 0xbff1977c, 0xde3fa237, 0xbfee6666, 0x66666664},			/* -1.09948=f(-0.95000)*/
{64, 0,123,__LINE__, 0xbff15ad6, 0x0d228eef, 0xbfee147a, 0xe147ae12},			/* -1.08467=f(-0.94000)*/
{64, 0,123,__LINE__, 0xbff11ea0, 0xf8d5c0a0, 0xbfedc28f, 0x5c28f5c0},			/* -1.06997=f(-0.93000)*/
{64, 0,123,__LINE__, 0xbff0e2dc, 0x16c537bc, 0xbfed70a3, 0xd70a3d6e},			/* -1.05538=f(-0.92000)*/
{64, 0,123,__LINE__, 0xbff0a785, 0xdf3c4053, 0xbfed1eb8, 0x51eb851c},			/* -1.04089=f(-0.91000)*/
{64, 0,123,__LINE__, 0xbff06c9c, 0xcd5b6af6, 0xbfeccccc, 0xccccccca},			/* -1.02651=f(-0.90000)*/
{62, 0,123,__LINE__, 0xbff0321f, 0x5f0e982e, 0xbfec7ae1, 0x47ae1478},			/* -1.01223=f(-0.89000)*/
{64, 0,123,__LINE__, 0xbfeff018, 0x2a062c81, 0xbfec28f5, 0xc28f5c26},			/* -0.99805=f(-0.88000)*/
{64, 0,123,__LINE__, 0xbfef7cc2, 0xe53ba212, 0xbfebd70a, 0x3d70a3d4},			/* -0.98397=f(-0.87000)*/
{64, 0,123,__LINE__, 0xbfef0a3b, 0xfbe32730, 0xbfeb851e, 0xb851eb82},			/* -0.96999=f(-0.86000)*/
{64, 0,123,__LINE__, 0xbfee9880, 0x7f6ab6d3, 0xbfeb3333, 0x33333330},			/* -0.95611=f(-0.85000)*/
{64, 0,123,__LINE__, 0xbfee278d, 0x867579cd, 0xbfeae147, 0xae147ade},			/* -0.94232=f(-0.84000)*/
{64, 0,123,__LINE__, 0xbfedb760, 0x2cc8b1f2, 0xbfea8f5c, 0x28f5c28c},			/* -0.92863=f(-0.83000)*/
{64, 0,123,__LINE__, 0xbfed47f5, 0x9338c6e0, 0xbfea3d70, 0xa3d70a3a},			/* -0.91503=f(-0.82000)*/
{63, 0,123,__LINE__, 0xbfecd94a, 0xdf9673f5, 0xbfe9eb85, 0x1eb851e8},			/* -0.90152=f(-0.81000)*/
{64, 0,123,__LINE__, 0xbfec6b5d, 0x3c9c16ea, 0xbfe99999, 0x99999996},			/* -0.88810=f(-0.80000)*/
{64, 0,123,__LINE__, 0xbfebfe29, 0xd9db1ea9, 0xbfe947ae, 0x147ae144},			/* -0.87477=f(-0.79000)*/
{64, 0,123,__LINE__, 0xbfeb91ad, 0xeba999d5, 0xbfe8f5c2, 0x8f5c28f2},			/* -0.86153=f(-0.78000)*/
{62, 0,123,__LINE__, 0xbfeb25e6, 0xab0fe492, 0xbfe8a3d7, 0x0a3d70a0},			/* -0.84837=f(-0.77000)*/
{64, 0,123,__LINE__, 0xbfeabad1, 0x55b67515, 0xbfe851eb, 0x851eb84e},			/* -0.83530=f(-0.76000)*/
{64, 0,123,__LINE__, 0xbfea506b, 0x2dd3c68b, 0xbfe7ffff, 0xfffffffc},			/* -0.82231=f(-0.75000)*/
{64, 0,123,__LINE__, 0xbfe9e6b1, 0x7a1a61cb, 0xbfe7ae14, 0x7ae147aa},			/* -0.80941=f(-0.74000)*/
{64, 0,123,__LINE__, 0xbfe97da1, 0x85a7037c, 0xbfe75c28, 0xf5c28f58},			/* -0.79658=f(-0.73000)*/
{64, 0,123,__LINE__, 0xbfe91538, 0x9feedf1e, 0xbfe70a3d, 0x70a3d706},			/* -0.78384=f(-0.72000)*/
{64, 0,123,__LINE__, 0xbfe8ad74, 0x1cadfe96, 0xbfe6b851, 0xeb851eb4},			/* -0.77117=f(-0.71000)*/
{60, 0,123,__LINE__, 0xbfe84651, 0x53d5bdb8, 0xbfe66666, 0x66666662},			/* -0.75858=f(-0.70000)*/
{64, 0,123,__LINE__, 0xbfe7dfcd, 0xa17b6170, 0xbfe6147a, 0xe147ae10},			/* -0.74606=f(-0.69000)*/
{64, 0,123,__LINE__, 0xbfe779e6, 0x65c6ca07, 0xbfe5c28f, 0x5c28f5be},			/* -0.73363=f(-0.68000)*/
{64, 0,123,__LINE__, 0xbfe71499, 0x04e14019, 0xbfe570a3, 0xd70a3d6c},			/* -0.72126=f(-0.67000)*/
{64, 0,123,__LINE__, 0xbfe6afe2, 0xe6e45bcb, 0xbfe51eb8, 0x51eb851a},			/* -0.70897=f(-0.66000)*/
{64, 0,123,__LINE__, 0xbfe64bc1, 0x77c905d6, 0xbfe4cccc, 0xccccccc8},			/* -0.69674=f(-0.65000)*/
{64, 0,123,__LINE__, 0xbfe5e832, 0x275691ec, 0xbfe47ae1, 0x47ae1476},			/* -0.68459=f(-0.64000)*/
{64, 0,123,__LINE__, 0xbfe58532, 0x6911f213, 0xbfe428f5, 0xc28f5c24},			/* -0.67250=f(-0.63000)*/
{64, 0,123,__LINE__, 0xbfe522bf, 0xb42d0283, 0xbfe3d70a, 0x3d70a3d2},			/* -0.66049=f(-0.62000)*/
{64, 0,123,__LINE__, 0xbfe4c0d7, 0x8375ed99, 0xbfe3851e, 0xb851eb80},			/* -0.64854=f(-0.61000)*/
{64, 0,123,__LINE__, 0xbfe45f77, 0x5546a778, 0xbfe33333, 0x3333332e},			/* -0.63665=f(-0.60000)*/
{64, 0,123,__LINE__, 0xbfe3fe9c, 0xab7480e1, 0xbfe2e147, 0xae147adc},			/* -0.62483=f(-0.59000)*/
{64, 0,123,__LINE__, 0xbfe39e45, 0x0b3fd0e4, 0xbfe28f5c, 0x28f5c28a},			/* -0.61307=f(-0.58000)*/
{64, 0,123,__LINE__, 0xbfe33e6d, 0xfd43b4ed, 0xbfe23d70, 0xa3d70a38},			/* -0.60137=f(-0.57000)*/
{64, 0,123,__LINE__, 0xbfe2df15, 0x0d65e6dc, 0xbfe1eb85, 0x1eb851e6},			/* -0.58973=f(-0.56000)*/
{64, 0,123,__LINE__, 0xbfe28037, 0xcac6a8a0, 0xbfe19999, 0x99999994},			/* -0.57815=f(-0.55000)*/
{64, 0,123,__LINE__, 0xbfe221d3, 0xc7b0c504, 0xbfe147ae, 0x147ae142},			/* -0.56662=f(-0.54000)*/
{64, 0,123,__LINE__, 0xbfe1c3e6, 0x9989a53c, 0xbfe0f5c2, 0x8f5c28f0},			/* -0.55516=f(-0.53000)*/
{64, 0,123,__LINE__, 0xbfe1666d, 0xd8c17ac3, 0xbfe0a3d7, 0x0a3d709e},			/* -0.54375=f(-0.52000)*/
{64, 0,123,__LINE__, 0xbfe10967, 0x20c37d30, 0xbfe051eb, 0x851eb84c},			/* -0.53239=f(-0.51000)*/
{64, 0,123,__LINE__, 0xbfe0acd0, 0x0fe63b90, 0xbfdfffff, 0xfffffff4},			/* -0.52109=f(-0.50000)*/
{64, 0,123,__LINE__, 0xbfe050a6, 0x475c00e4, 0xbfdf5c28, 0xf5c28f50},			/* -0.50984=f(-0.49000)*/
{64, 0,123,__LINE__, 0xbfdfe9ce, 0xd64696aa, 0xbfdeb851, 0xeb851eac},			/* -0.49864=f(-0.48000)*/
{64, 0,123,__LINE__, 0xbfdf3322, 0x43eeab90, 0xbfde147a, 0xe147ae08},			/* -0.48749=f(-0.47000)*/
{64, 0,123,__LINE__, 0xbfde7d42, 0x2a8166ab, 0xbfdd70a3, 0xd70a3d64},			/* -0.47639=f(-0.46000)*/
{64, 0,123,__LINE__, 0xbfddc829, 0xe20bf8b2, 0xbfdccccc, 0xccccccc0},			/* -0.46534=f(-0.45000)*/
{64, 0,123,__LINE__, 0xbfdd13d4, 0xc7b9193c, 0xbfdc28f5, 0xc28f5c1c},			/* -0.45433=f(-0.44000)*/
{64, 0,123,__LINE__, 0xbfdc603e, 0x3db2a4ab, 0xbfdb851e, 0xb851eb78},			/* -0.44337=f(-0.43000)*/
{64, 0,123,__LINE__, 0xbfdbad61, 0xab035ad2, 0xbfdae147, 0xae147ad4},			/* -0.43245=f(-0.42000)*/
{64, 0,123,__LINE__, 0xbfdafb3a, 0x7b78bd98, 0xbfda3d70, 0xa3d70a30},			/* -0.42158=f(-0.41000)*/
{64, 0,123,__LINE__, 0xbfda49c4, 0x1f850ec3, 0xbfd99999, 0x9999998c},			/* -0.41075=f(-0.40000)*/
{64, 0,123,__LINE__, 0xbfd998fa, 0x0c216c44, 0xbfd8f5c2, 0x8f5c28e8},			/* -0.39996=f(-0.39000)*/
{62, 0,123,__LINE__, 0xbfd8e8d7, 0xbab00a19, 0xbfd851eb, 0x851eb844},			/* -0.38921=f(-0.38000)*/
{64, 0,123,__LINE__, 0xbfd83958, 0xa8de892b, 0xbfd7ae14, 0x7ae147a0},			/* -0.37850=f(-0.37000)*/
{64, 0,123,__LINE__, 0xbfd78a78, 0x58886a40, 0xbfd70a3d, 0x70a3d6fc},			/* -0.36782=f(-0.36000)*/
{64, 0,123,__LINE__, 0xbfd6dc32, 0x4f999c59, 0xbfd66666, 0x66666658},			/* -0.35718=f(-0.35000)*/
{64, 0,123,__LINE__, 0xbfd62e82, 0x17f125b5, 0xbfd5c28f, 0x5c28f5b4},			/* -0.34658=f(-0.34000)*/
{62, 0,123,__LINE__, 0xbfd58163, 0x3f43e6b2, 0xbfd51eb8, 0x51eb8510},			/* -0.33602=f(-0.33000)*/
{64, 0,123,__LINE__, 0xbfd4d4d1, 0x56ff75cc, 0xbfd47ae1, 0x47ae146c},			/* -0.32548=f(-0.32000)*/
{64, 0,123,__LINE__, 0xbfd428c7, 0xf42d140d, 0xbfd3d70a, 0x3d70a3c8},			/* -0.31498=f(-0.31000)*/
{64, 0,123,__LINE__, 0xbfd37d42, 0xaf54b916, 0xbfd33333, 0x33333324},			/* -0.30452=f(-0.30000)*/
{64, 0,123,__LINE__, 0xbfd2d23d, 0x24603618, 0xbfd28f5c, 0x28f5c280},			/* -0.29408=f(-0.29000)*/
{64, 0,123,__LINE__, 0xbfd227b2, 0xf27e6eed, 0xbfd1eb85, 0x1eb851dc},			/* -0.28367=f(-0.28000)*/
{64, 0,123,__LINE__, 0xbfd17d9f, 0xbc06a8af, 0xbfd147ae, 0x147ae138},			/* -0.27329=f(-0.27000)*/
{64, 0,123,__LINE__, 0xbfd0d3ff, 0x265becef, 0xbfd0a3d7, 0x0a3d7094},			/* -0.26293=f(-0.26000)*/
{64, 0,123,__LINE__, 0xbfd02acc, 0xd9d080f1, 0xbfcfffff, 0xffffffe0},			/* -0.25261=f(-0.25000)*/
{64, 0,123,__LINE__, 0xbfcf0409, 0x0312e035, 0xbfceb851, 0xeb851e98},			/* -0.24231=f(-0.24000)*/
{64, 0,123,__LINE__, 0xbfcdb343, 0x96c451c7, 0xbfcd70a3, 0xd70a3d50},			/* -0.23203=f(-0.23000)*/
{64, 0,123,__LINE__, 0xbfcc6340, 0xcfa05725, 0xbfcc28f5, 0xc28f5c08},			/* -0.22177=f(-0.22000)*/
{64, 0,123,__LINE__, 0xbfcb13f8, 0x138d93ff, 0xbfcae147, 0xae147ac0},			/* -0.21154=f(-0.21000)*/
{64, 0,123,__LINE__, 0xbfc9c560, 0xcd35ef5f, 0xbfc99999, 0x99999978},			/* -0.20133=f(-0.20000)*/
{64, 0,123,__LINE__, 0xbfc87772, 0x6bce5312, 0xbfc851eb, 0x851eb830},			/* -0.19114=f(-0.19000)*/
{64, 0,123,__LINE__, 0xbfc72a24, 0x62de88dd, 0xbfc70a3d, 0x70a3d6e8},			/* -0.18097=f(-0.18000)*/
{63, 0,123,__LINE__, 0xbfc5dd6e, 0x2a0933fd, 0xbfc5c28f, 0x5c28f5a0},			/* -0.17082=f(-0.17000)*/
{64, 0,123,__LINE__, 0xbfc49147, 0x3cd3e598, 0xbfc47ae1, 0x47ae1458},			/* -0.16068=f(-0.16000)*/
{64, 0,123,__LINE__, 0xbfc345a7, 0x1a6f4aa6, 0xbfc33333, 0x33333310},			/* -0.15056=f(-0.15000)*/
{64, 0,123,__LINE__, 0xbfc1fa85, 0x457f71db, 0xbfc1eb85, 0x1eb851c8},			/* -0.14045=f(-0.14000)*/
{64, 0,123,__LINE__, 0xbfc0afd9, 0x43e4283d, 0xbfc0a3d7, 0x0a3d7080},			/* -0.13036=f(-0.13000)*/
{64, 0,123,__LINE__, 0xbfbecb35, 0x3d02d5b5, 0xbfbeb851, 0xeb851e71},			/* -0.12028=f(-0.12000)*/
{64, 0,123,__LINE__, 0xbfbc3781, 0xc20fd8a8, 0xbfbc28f5, 0xc28f5be2},			/* -0.11022=f(-0.11000)*/
{64, 0,123,__LINE__, 0xbfb9a487, 0x337b596c, 0xbfb99999, 0x99999953},			/* -0.10016=f(-0.00100)*/
{64, 0,123,__LINE__, 0xbfb71234, 0xb28d4487, 0xbfb70a3d, 0x70a3d6c4},			/* -0.09012=f(-0.09000)*/
{64, 0,123,__LINE__, 0xbfb48079, 0x64dae38a, 0xbfb47ae1, 0x47ae1435},			/* -0.08008=f(-0.08000)*/
{64, 0,123,__LINE__, 0xbfb1ef44, 0x73d869da, 0xbfb1eb85, 0x1eb851a6},			/* -0.07005=f(-0.07000)*/
{64, 0,123,__LINE__, 0xbfaebd0a, 0x18d535bc, 0xbfaeb851, 0xeb851e2d},			/* -0.06003=f(-0.06000)*/
{64, 0,123,__LINE__, 0xbfa99c54, 0xbcf10d6f, 0xbfa99999, 0x9999990e},			/* -0.05002=f(-0.05000)*/
{64, 0,123,__LINE__, 0xbfa47c47, 0x38fab55b, 0xbfa47ae1, 0x47ae13ef},			/* -0.04001=f(-0.04000)*/
{64, 0,123,__LINE__, 0xbf9eb97f, 0xec690a08, 0xbf9eb851, 0xeb851da0},			/* -0.03000=f(-0.03000)*/
{64, 0,123,__LINE__, 0xbf947b3a, 0xc2a15f75, 0xbf947ae1, 0x47ae1362},			/* -0.02000=f(-0.02000)*/
{64, 0,123,__LINE__, 0xbf847af7, 0xa654e7bd, 0xbf847ae1, 0x47ae1249},			/* -0.01000=f(-0.00010)*/
{64, 0,123,__LINE__, 0x3cd19000, 0x00000000, 0x3cd19000, 0x00000000},			/* 9.74915e-16=f(9.74915e-16)*/
{64, 0,123,__LINE__, 0x3f847af7, 0xa654ec21, 0x3f847ae1, 0x47ae16ad},			/* 0.01000=f(0.01000)*/
{64, 0,123,__LINE__, 0x3f947b3a, 0xc2a161a7, 0x3f947ae1, 0x47ae1594},			/* 0.02000=f(0.02000)*/
{64, 0,123,__LINE__, 0x3f9eb97f, 0xec690c3b, 0x3f9eb851, 0xeb851fd2},			/* 0.03000=f(0.03000)*/
{64, 0,123,__LINE__, 0x3fa47c47, 0x38fab674, 0x3fa47ae1, 0x47ae1508},			/* 0.04001=f(0.04000)*/
{64, 0,123,__LINE__, 0x3fa99c54, 0xbcf10e89, 0x3fa99999, 0x99999a27},			/* 0.05002=f(0.05000)*/
{64, 0,123,__LINE__, 0x3faebd0a, 0x18d536d5, 0x3faeb851, 0xeb851f46},			/* 0.06003=f(0.06000)*/
{64, 0,123,__LINE__, 0x3fb1ef44, 0x73d86a66, 0x3fb1eb85, 0x1eb85232},			/* 0.07005=f(0.07000)*/
{64, 0,123,__LINE__, 0x3fb48079, 0x64dae416, 0x3fb47ae1, 0x47ae14c1},			/* 0.08008=f(0.08000)*/
{64, 0,123,__LINE__, 0x3fb71234, 0xb28d4514, 0x3fb70a3d, 0x70a3d750},			/* 0.09012=f(0.09000)*/
{64, 0,123,__LINE__, 0x3fb9a487, 0x337b59f9, 0x3fb99999, 0x999999df},			/* 0.10016=f(0.10000)*/
{64, 0,123,__LINE__, 0x3fbc3781, 0xc20fd935, 0x3fbc28f5, 0xc28f5c6e},			/* 0.11022=f(0.11000)*/
{64, 0,123,__LINE__, 0x3fbecb35, 0x3d02d642, 0x3fbeb851, 0xeb851efd},			/* 0.12028=f(0.12000)*/
{64, 0,123,__LINE__, 0x3fc0afd9, 0x43e42883, 0x3fc0a3d7, 0x0a3d70c6},			/* 0.13036=f(0.13000)*/
{64, 0,123,__LINE__, 0x3fc1fa85, 0x457f7222, 0x3fc1eb85, 0x1eb8520e},			/* 0.14045=f(0.14000)*/
{64, 0,123,__LINE__, 0x3fc345a7, 0x1a6f4aec, 0x3fc33333, 0x33333356},			/* 0.15056=f(0.15000)*/
{64, 0,123,__LINE__, 0x3fc49147, 0x3cd3e5df, 0x3fc47ae1, 0x47ae149e},			/* 0.16068=f(0.16000)*/
{64, 0,123,__LINE__, 0x3fc5dd6e, 0x2a093444, 0x3fc5c28f, 0x5c28f5e6},			/* 0.17082=f(0.17000)*/
{64, 0,123,__LINE__, 0x3fc72a24, 0x62de8924, 0x3fc70a3d, 0x70a3d72e},			/* 0.18097=f(0.18000)*/
{64, 0,123,__LINE__, 0x3fc87772, 0x6bce535a, 0x3fc851eb, 0x851eb876},			/* 0.19114=f(0.19000)*/
{64, 0,123,__LINE__, 0x3fc9c560, 0xcd35efa6, 0x3fc99999, 0x999999be},			/* 0.20133=f(0.20000)*/
{64, 0,123,__LINE__, 0x3fcb13f8, 0x138d9446, 0x3fcae147, 0xae147b06},			/* 0.21154=f(0.21000)*/
{64, 0,123,__LINE__, 0x3fcc6340, 0xcfa0576d, 0x3fcc28f5, 0xc28f5c4e},			/* 0.22177=f(0.22000)*/
{64, 0,123,__LINE__, 0x3fcdb343, 0x96c4520f, 0x3fcd70a3, 0xd70a3d96},			/* 0.23203=f(0.23000)*/
{64, 0,123,__LINE__, 0x3fcf0409, 0x0312e07d, 0x3fceb851, 0xeb851ede},			/* 0.24231=f(0.24000)*/
{64, 0,123,__LINE__, 0x3fd02acc, 0xd9d08115, 0x3fd00000, 0x00000013},			/* 0.25261=f(0.25000)*/
{64, 0,123,__LINE__, 0x3fd0d3ff, 0x265bed13, 0x3fd0a3d7, 0x0a3d70b7},			/* 0.26293=f(0.26000)*/
{64, 0,123,__LINE__, 0x3fd17d9f, 0xbc06a8d3, 0x3fd147ae, 0x147ae15b},			/* 0.27329=f(0.27000)*/
{64, 0,123,__LINE__, 0x3fd227b2, 0xf27e6f12, 0x3fd1eb85, 0x1eb851ff},			/* 0.28367=f(0.28000)*/
{64, 0,123,__LINE__, 0x3fd2d23d, 0x2460363c, 0x3fd28f5c, 0x28f5c2a3},			/* 0.29408=f(0.29000)*/
{64, 0,123,__LINE__, 0x3fd37d42, 0xaf54b93b, 0x3fd33333, 0x33333347},			/* 0.30452=f(0.30000)*/
{64, 0,123,__LINE__, 0x3fd428c7, 0xf42d1431, 0x3fd3d70a, 0x3d70a3eb},			/* 0.31498=f(0.31000)*/
{64, 0,123,__LINE__, 0x3fd4d4d1, 0x56ff75f0, 0x3fd47ae1, 0x47ae148f},			/* 0.32548=f(0.32000)*/
{64, 0,123,__LINE__, 0x3fd58163, 0x3f43e6d6, 0x3fd51eb8, 0x51eb8533},			/* 0.33602=f(0.33000)*/
{64, 0,123,__LINE__, 0x3fd62e82, 0x17f125da, 0x3fd5c28f, 0x5c28f5d7},			/* 0.34658=f(0.34000)*/
{64, 0,123,__LINE__, 0x3fd6dc32, 0x4f999c7e, 0x3fd66666, 0x6666667b},			/* 0.35718=f(0.35000)*/
{64, 0,123,__LINE__, 0x3fd78a78, 0x58886a65, 0x3fd70a3d, 0x70a3d71f},			/* 0.36782=f(0.36000)*/
{64, 0,123,__LINE__, 0x3fd83958, 0xa8de8951, 0x3fd7ae14, 0x7ae147c3},			/* 0.37850=f(0.37000)*/
{64, 0,123,__LINE__, 0x3fd8e8d7, 0xbab00a3f, 0x3fd851eb, 0x851eb867},			/* 0.38921=f(0.38000)*/
{64, 0,123,__LINE__, 0x3fd998fa, 0x0c216c69, 0x3fd8f5c2, 0x8f5c290b},			/* 0.39996=f(0.39000)*/
{64, 0,123,__LINE__, 0x3fda49c4, 0x1f850ee9, 0x3fd99999, 0x999999af},			/* 0.41075=f(0.40000)*/
{64, 0,123,__LINE__, 0x3fdafb3a, 0x7b78bdbe, 0x3fda3d70, 0xa3d70a53},			/* 0.42158=f(0.41000)*/
{63, 0,123,__LINE__, 0x3fdbad61, 0xab035af9, 0x3fdae147, 0xae147af7},			/* 0.43245=f(0.42000)*/
{64, 0,123,__LINE__, 0x3fdc603e, 0x3db2a4d1, 0x3fdb851e, 0xb851eb9b},			/* 0.44337=f(0.43000)*/
{64, 0,123,__LINE__, 0x3fdd13d4, 0xc7b91962, 0x3fdc28f5, 0xc28f5c3f},			/* 0.45433=f(0.44000)*/
{64, 0,123,__LINE__, 0x3fddc829, 0xe20bf8d9, 0x3fdccccc, 0xcccccce3},			/* 0.46534=f(0.45000)*/
{64, 0,123,__LINE__, 0x3fde7d42, 0x2a8166d2, 0x3fdd70a3, 0xd70a3d87},			/* 0.47639=f(0.46000)*/
{64, 0,123,__LINE__, 0x3fdf3322, 0x43eeabb7, 0x3fde147a, 0xe147ae2b},			/* 0.48749=f(0.47000)*/
{64, 0,123,__LINE__, 0x3fdfe9ce, 0xd64696d2, 0x3fdeb851, 0xeb851ecf},			/* 0.49864=f(0.48000)*/
{64, 0,123,__LINE__, 0x3fe050a6, 0x475c00f7, 0x3fdf5c28, 0xf5c28f73},			/* 0.50984=f(0.49000)*/
{64, 0,123,__LINE__, 0x3fe0acd0, 0x0fe63ba3, 0x3fe00000, 0x0000000b},			/* 0.52109=f(0.50000)*/
{64, 0,123,__LINE__, 0x3fe10967, 0x20c37d43, 0x3fe051eb, 0x851eb85d},			/* 0.53239=f(0.51000)*/
{64, 0,123,__LINE__, 0x3fe1666d, 0xd8c17ad6, 0x3fe0a3d7, 0x0a3d70af},			/* 0.54375=f(0.52000)*/
{64, 0,123,__LINE__, 0x3fe1c3e6, 0x9989a550, 0x3fe0f5c2, 0x8f5c2901},			/* 0.55516=f(0.53000)*/
{64, 0,123,__LINE__, 0x3fe221d3, 0xc7b0c518, 0x3fe147ae, 0x147ae153},			/* 0.56662=f(0.54000)*/
{64, 0,123,__LINE__, 0x3fe28037, 0xcac6a8b4, 0x3fe19999, 0x999999a5},			/* 0.57815=f(0.55000)*/
{64, 0,123,__LINE__, 0x3fe2df15, 0x0d65e6f0, 0x3fe1eb85, 0x1eb851f7},			/* 0.58973=f(0.56000)*/
{64, 0,123,__LINE__, 0x3fe33e6d, 0xfd43b501, 0x3fe23d70, 0xa3d70a49},			/* 0.60137=f(0.57000)*/
{60, 0,123,__LINE__, 0x3fe39e45, 0x0b3fd0f8, 0x3fe28f5c, 0x28f5c29b},			/* 0.61307=f(0.58000)*/
{64, 0,123,__LINE__, 0x3fe3fe9c, 0xab7480f5, 0x3fe2e147, 0xae147aed},			/* 0.62483=f(0.59000)*/
{64, 0,123,__LINE__, 0x3fe45f77, 0x5546a78c, 0x3fe33333, 0x3333333f},			/* 0.63665=f(0.60000)*/
{64, 0,123,__LINE__, 0x3fe4c0d7, 0x8375edad, 0x3fe3851e, 0xb851eb91},			/* 0.64854=f(0.61000)*/
{64, 0,123,__LINE__, 0x3fe522bf, 0xb42d0297, 0x3fe3d70a, 0x3d70a3e3},			/* 0.66049=f(0.62000)*/
{64, 0,123,__LINE__, 0x3fe58532, 0x6911f228, 0x3fe428f5, 0xc28f5c35},			/* 0.67250=f(0.63000)*/
{64, 0,123,__LINE__, 0x3fe5e832, 0x27569201, 0x3fe47ae1, 0x47ae1487},			/* 0.68459=f(0.64000)*/
{64, 0,123,__LINE__, 0x3fe64bc1, 0x77c905eb, 0x3fe4cccc, 0xccccccd9},			/* 0.69674=f(0.65000)*/
{64, 0,123,__LINE__, 0x3fe6afe2, 0xe6e45be0, 0x3fe51eb8, 0x51eb852b},			/* 0.70897=f(0.66000)*/
{64, 0,123,__LINE__, 0x3fe71499, 0x04e1402e, 0x3fe570a3, 0xd70a3d7d},			/* 0.72126=f(0.67000)*/
{64, 0,123,__LINE__, 0x3fe779e6, 0x65c6ca1c, 0x3fe5c28f, 0x5c28f5cf},			/* 0.73363=f(0.68000)*/
{64, 0,123,__LINE__, 0x3fe7dfcd, 0xa17b6185, 0x3fe6147a, 0xe147ae21},			/* 0.74606=f(0.69000)*/
{64, 0,123,__LINE__, 0x3fe84651, 0x53d5bdcd, 0x3fe66666, 0x66666673},			/* 0.75858=f(0.70000)*/
{64, 0,123,__LINE__, 0x3fe8ad74, 0x1cadfeab, 0x3fe6b851, 0xeb851ec5},			/* 0.77117=f(0.71000)*/
{64, 0,123,__LINE__, 0x3fe91538, 0x9feedf34, 0x3fe70a3d, 0x70a3d717},			/* 0.78384=f(0.72000)*/
{64, 0,123,__LINE__, 0x3fe97da1, 0x85a70392, 0x3fe75c28, 0xf5c28f69},			/* 0.79658=f(0.73000)*/
{64, 0,123,__LINE__, 0x3fe9e6b1, 0x7a1a61e1, 0x3fe7ae14, 0x7ae147bb},			/* 0.80941=f(0.74000)*/
{64, 0,123,__LINE__, 0x3fea506b, 0x2dd3c6a1, 0x3fe80000, 0x0000000d},			/* 0.82231=f(0.75000)*/
{64, 0,123,__LINE__, 0x3feabad1, 0x55b6752b, 0x3fe851eb, 0x851eb85f},			/* 0.83530=f(0.76000)*/
{64, 0,123,__LINE__, 0x3feb25e6, 0xab0fe4a8, 0x3fe8a3d7, 0x0a3d70b1},			/* 0.84837=f(0.77000)*/
{64, 0,123,__LINE__, 0x3feb91ad, 0xeba999ec, 0x3fe8f5c2, 0x8f5c2903},			/* 0.86153=f(0.78000)*/
{64, 0,123,__LINE__, 0x3febfe29, 0xd9db1ec0, 0x3fe947ae, 0x147ae155},			/* 0.87477=f(0.79000)*/
{64, 0,123,__LINE__, 0x3fec6b5d, 0x3c9c1700, 0x3fe99999, 0x999999a7},			/* 0.88810=f(0.80000)*/
{61, 0,123,__LINE__, 0x3fecd94a, 0xdf96740c, 0x3fe9eb85, 0x1eb851f9},			/* 0.90152=f(0.81000)*/
{60, 0,123,__LINE__, 0x3fed47f5, 0x9338c6f7, 0x3fea3d70, 0xa3d70a4b},			/* 0.91503=f(0.82000)*/
{62, 0,123,__LINE__, 0x3fedb760, 0x2cc8b20a, 0x3fea8f5c, 0x28f5c29d},			/* 0.92863=f(0.83000)*/
{64, 0,123,__LINE__, 0x3fee278d, 0x867579e5, 0x3feae147, 0xae147aef},			/* 0.94232=f(0.84000)*/
{64, 0,123,__LINE__, 0x3fee9880, 0x7f6ab6ea, 0x3feb3333, 0x33333341},			/* 0.95611=f(0.85000)*/
{64, 0,123,__LINE__, 0x3fef0a3b, 0xfbe32748, 0x3feb851e, 0xb851eb93},			/* 0.96999=f(0.86000)*/
{64, 0,123,__LINE__, 0x3fef7cc2, 0xe53ba22a, 0x3febd70a, 0x3d70a3e5},			/* 0.98397=f(0.87000)*/
{64, 0,123,__LINE__, 0x3feff018, 0x2a062c99, 0x3fec28f5, 0xc28f5c37},			/* 0.99805=f(0.88000)*/
{64, 0,123,__LINE__, 0x3ff0321f, 0x5f0e983a, 0x3fec7ae1, 0x47ae1489},			/* 1.01223=f(0.89000)*/
{64, 0,123,__LINE__, 0x3ff06c9c, 0xcd5b6b02, 0x3feccccc, 0xccccccdb},			/* 1.02651=f(0.90000)*/
{64, 0,123,__LINE__, 0x3ff0a785, 0xdf3c405f, 0x3fed1eb8, 0x51eb852d},			/* 1.04089=f(0.91000)*/
{64, 0,123,__LINE__, 0x3ff0e2dc, 0x16c537c8, 0x3fed70a3, 0xd70a3d7f},			/* 1.05538=f(0.92000)*/
{64, 0,123,__LINE__, 0x3ff11ea0, 0xf8d5c0ac, 0x3fedc28f, 0x5c28f5d1},			/* 1.06997=f(0.93000)*/
{64, 0,123,__LINE__, 0x3ff15ad6, 0x0d228efc, 0x3fee147a, 0xe147ae23},			/* 1.08467=f(0.94000)*/
{64, 0,123,__LINE__, 0x3ff1977c, 0xde3fa244, 0x3fee6666, 0x66666675},			/* 1.09948=f(0.95000)*/
{64, 0,123,__LINE__, 0x3ff1d496, 0xf9aa5f9a, 0x3feeb851, 0xeb851ec7},			/* 1.11440=f(0.96000)*/
{64, 0,123,__LINE__, 0x3ff21225, 0xefd3bea5, 0x3fef0a3d, 0x70a3d719},			/* 1.12943=f(0.97000)*/
{64, 0,123,__LINE__, 0x3ff2502b, 0x542a89ee, 0x3fef5c28, 0xf5c28f6b},			/* 1.14457=f(0.98000)*/
{62, 0,123,__LINE__, 0x3ff28ea8, 0xbd25b2de, 0x3fefae14, 0x7ae147bd},			/* 1.15982=f(0.99000)*/
{63, 0,123,__LINE__, 0x3ff2cd9f, 0xc44eb98c, 0x3ff00000, 0x00000007},			/* 1.17520=f(1.00000)*/
{57, 0,123,__LINE__, 0x3ff30d12, 0x064c28bf, 0x3ff028f5, 0xc28f5c30},			/* 1.19069=f(1.01000)*/
{57, 0,123,__LINE__, 0x3ff34d01, 0x22ec263e, 0x3ff051eb, 0x851eb859},			/* 1.20630=f(1.02000)*/
{58, 0,123,__LINE__, 0x3ff38d6e, 0xbd2f17df, 0x3ff07ae1, 0x47ae1482},			/* 1.22202=f(1.03000)*/
{61, 0,123,__LINE__, 0x3ff3ce5c, 0x7b525d94, 0x3ff0a3d7, 0x0a3d70ab},			/* 1.23788=f(1.04000)*/
{62, 0,123,__LINE__, 0x3ff40fcc, 0x06db2086, 0x3ff0cccc, 0xccccccd4},			/* 1.25385=f(1.05000)*/
{63, 0,123,__LINE__, 0x3ff451bf, 0x0ca137e7, 0x3ff0f5c2, 0x8f5c28fd},			/* 1.26995=f(1.06000)*/
{61, 0,123,__LINE__, 0x3ff49437, 0x3cda235d, 0x3ff11eb8, 0x51eb8526},			/* 1.28618=f(1.07000)*/
{62, 0,123,__LINE__, 0x3ff4d736, 0x4b241b96, 0x3ff147ae, 0x147ae14f},			/* 1.30254=f(1.08000)*/
{63, 0,123,__LINE__, 0x3ff51abd, 0xee913928, 0x3ff170a3, 0xd70a3d78},			/* 1.31902=f(1.09000)*/
{62, 0,123,__LINE__, 0x3ff55ecf, 0xe1b2b221, 0x3ff19999, 0x999999a1},			/* 1.33564=f(1.10000)*/
{58, 0,123,__LINE__, 0x3ff5a36d, 0xe2a42e5f, 0x3ff1c28f, 0x5c28f5ca},			/* 1.35240=f(1.11000)*/
{59, 0,123,__LINE__, 0x3ff5e899, 0xb317334f, 0x3ff1eb85, 0x1eb851f3},			/* 1.36928=f(1.12000)*/
{64, 0,123,__LINE__, 0x3ff62e55, 0x185ea6f5, 0x3ff2147a, 0xe147ae1c},			/* 1.38631=f(1.13000)*/
{63, 0,123,__LINE__, 0x3ff674a1, 0xdb7a6aee, 0x3ff23d70, 0xa3d70a45},			/* 1.40347=f(1.14000)*/
{64, 0,123,__LINE__, 0x3ff6bb81, 0xc9230f6b, 0x3ff26666, 0x6666666e},			/* 1.42077=f(1.15000)*/
{64, 0,123,__LINE__, 0x3ff702f6, 0xb1d59e9a, 0x3ff28f5c, 0x28f5c297},			/* 1.43822=f(1.16000)*/
{61, 0,123,__LINE__, 0x3ff74b02, 0x69df80c3, 0x3ff2b851, 0xeb851ec0},			/* 1.45581=f(1.17000)*/
{61, 0,123,__LINE__, 0x3ff793a6, 0xc96a7951, 0x3ff2e147, 0xae147ae9},			/* 1.47354=f(1.18000)*/
{62, 0,123,__LINE__, 0x3ff7dce5, 0xac88bd50, 0x3ff30a3d, 0x70a3d712},			/* 1.49143=f(1.19000)*/
{61, 0,123,__LINE__, 0xc070bbeb, 0x1603926c, 0xc01921fb, 0x54442d18},			/* -267.744=f(-6.28318)*/
{60, 0,123,__LINE__, 0xc04bd3c3, 0x4cf00a27, 0xc012d97c, 0x7f3321d2},			/* -55.6543=f(-4.71238)*/
{63, 0,123,__LINE__, 0xc02718f4, 0x5d72e671, 0xc00921fb, 0x54442d18},			/* -11.5487=f(-3.14159)*/
{62, 0,123,__LINE__, 0xc002690f, 0x661dd821, 0xbff921fb, 0x54442d18},			/* -2.30129=f(-1.57079)*/
{64, 0,123,__LINE__, 0x00000000, 0x00000000, 0x00000000, 0x00000000},			/* 0.00000=f(0.00000)*/
{62, 0,123,__LINE__, 0x4002690f, 0x661dd821, 0x3ff921fb, 0x54442d18},			/* 2.30129=f(1.57079)*/
{63, 0,123,__LINE__, 0x402718f4, 0x5d72e671, 0x400921fb, 0x54442d18},			/* 11.5487=f(3.14159)*/
{60, 0,123,__LINE__, 0x404bd3c3, 0x4cf00a27, 0x4012d97c, 0x7f3321d2},			/* 55.6543=f(4.71238)*/
{63, 0,123,__LINE__, 0xc2937047, 0x0aec28e4, 0xc03e0000, 0x00000000},			/* -5.34324e+12=f(-30.0000)*/
{63, 0,123,__LINE__, 0xc26c68ab, 0xda31cdb8, 0xc03c4ccc, 0xcccccccd},			/* -9.76121e+11=f(-28.3000)*/
{60, 0,123,__LINE__, 0xc244c263, 0x8e2b5848, 0xc03a9999, 0x9999999a},			/* -1.78321e+11=f(-26.6000)*/
{63, 0,123,__LINE__, 0xc21e56cf, 0x7144c252, 0xc038e666, 0x66666667},			/* -3.25764e+10=f(-24.9000)*/
{60, 0,123,__LINE__, 0xc1f62b79, 0x1e77d137, 0xc0373333, 0x33333334},			/* -5.95116e+09=f(-23.2000)*/
{64, 0,123,__LINE__, 0xc1d03343, 0x003272a8, 0xc0358000, 0x00000001},			/* -1.08718e+09=f(-21.5000)*/
{62, 0,123,__LINE__, 0xc1a7ad17, 0x51ce1a0d, 0xc033cccc, 0xccccccce},			/* -1.98610e+08=f(-19.8000)*/
{62, 0,123,__LINE__, 0xc1814d0b, 0xc17d4222, 0xc0321999, 0x9999999b},			/* -3.62827e+07=f(-18.1000)*/
{64, 0,123,__LINE__, 0xc15948e8, 0xe47ead6c, 0xc0306666, 0x66666668},			/* -6.62826e+06=f(-16.4000)*/
{63, 0,123,__LINE__, 0xc13279f9, 0xd10e66ed, 0xc02d6666, 0x6666666a},			/* -1.21087e+06=f(-14.7000)*/
{62, 0,123,__LINE__, 0xc10b00b5, 0x916a31d1, 0xc02a0000, 0x00000004},			/* -221206=f(-13.0000)*/
{63, 0,123,__LINE__, 0xc0e3bb5a, 0x33507fa0, 0xc0269999, 0x9999999e},			/* -40410=f(-11.3000)*/
{63, 0,123,__LINE__, 0xc0bcd664, 0x081f1af4, 0xc0233333, 0x33333338},			/* -7382.39=f(-9.60000)*/
{63, 0,123,__LINE__, 0xc0951290, 0x5cbc9963, 0xc01f9999, 0x999999a3},			/* -1348.64=f(-7.90000)*/
{62, 0,123,__LINE__, 0xc06ecbf3, 0xc2804b35, 0xc018cccc, 0xccccccd6},			/* -246.373=f(-6.20000)*/
{62, 0,123,__LINE__, 0xc0468062, 0xab5faa2d, 0xc0120000, 0x00000009},			/* -45.0030=f(-4.50000)*/
{64, 0,123,__LINE__, 0xc0206243, 0x1f5de430, 0xc0066666, 0x66666678},			/* -8.19191=f(-2.80000)*/
{63, 0,123,__LINE__, 0xbff55ecf, 0xe1b2b250, 0xbff19999, 0x999999bd},			/* -1.33564=f(-1.10000)*/
{64, 0,123,__LINE__, 0x3fe45f77, 0x5546a729, 0x3fe33333, 0x333332ec},			/* 0.63665=f(0.60000)*/
{63, 0,123,__LINE__, 0x4013bf72, 0xea61aeeb, 0x40026666, 0x66666654},			/* 4.93696=f(2.30000)*/
{61, 0,123,__LINE__, 0x403b4a38, 0x037035f3, 0x400fffff, 0xffffffee},			/* 27.2899=f(4.00000)*/
{62, 0,123,__LINE__, 0x4062add3, 0x2b565d1a, 0x4016cccc, 0xccccccc4},			/* 149.432=f(5.70000)*/
{64, 0,123,__LINE__, 0x40898fef, 0x6e2e3c20, 0x401d9999, 0x99999991},			/* 817.991=f(7.40000)*/
{64, 0,123,__LINE__, 0x40b17da5, 0x73a60dc4, 0x40223333, 0x3333332f},			/* 4477.64=f(9.10000)*/
{60, 0,123,__LINE__, 0x40d7ef99, 0xa2bdfbc7, 0x40259999, 0x99999995},			/* 24510=f(10.8000)*/
{64, 0,123,__LINE__, 0x410060c5, 0x2564c024, 0x4028ffff, 0xfffffffb},			/* 134168=f(12.5000)*/
{62, 0,123,__LINE__, 0x412669c0, 0x308d2005, 0x402c6666, 0x66666661},			/* 734432=f(14.2000)*/
{62, 0,123,__LINE__, 0x414eac09, 0x532f3d7e, 0x402fcccc, 0xccccccc7},			/* 4.02024e+06=f(15.9000)*/
{61, 0,123,__LINE__, 0x4174fcb4, 0x4c4756d4, 0x40319999, 0x99999997},			/* 2.20066e+07=f(17.6000)*/
{63, 0,123,__LINE__, 0x419cb879, 0xa3e73668, 0x40334ccc, 0xccccccca},			/* 1.20463e+08=f(19.3000)*/
{57, 0,123,__LINE__, 0x41c3a6e1, 0xfd9eecbf, 0x4034ffff, 0xfffffffd},			/* 6.59408e+08=f(21.0000)*/
{60, 0,123,__LINE__, 0x41eae4b2, 0x68df16f6, 0x4036b333, 0x33333330},			/* 3.60956e+09=f(22.7000)*/
{63, 0,123,__LINE__, 0x421266ce, 0xffa84595, 0x40386666, 0x66666663},			/* 1.97586e+10=f(24.4000)*/
{64, 0,123,__LINE__, 0x42392ead, 0xfa09870a, 0x403a1999, 0x99999996},			/* 1.08157e+11=f(26.1000)*/
{63, 0,123,__LINE__, 0x42613b19, 0x1e69fb25, 0x403bcccc, 0xccccccc9},			/* 5.92048e+11=f(27.8000)*/
{61, 0,123,__LINE__, 0x42879487, 0x9e85b8dc, 0x403d7fff, 0xfffffffc},			/* 3.24084e+12=f(29.5000)*/
0,};
test_sinh(m)   {run_vector_1(m,sinh_vec,(char *)(sinh),"sinh","dd");   }	
