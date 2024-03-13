#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int getByte(int x, int n) {
    // 左移n * 8位，将目标字节移到最低字节位置，然后使用&运算提取
    return (x >> (n << 3)) & 0xFF;
}

int logicalShift(int x, int n) {
    int mask = ~(1 << 31);
    mask = ((mask >> n) << 1) + 1;
    return (x >> n) & mask;
}

int bitCount(int x) {
    // int mask1 = 0x55555555; // 01010101...
    // int mask2 = 0x33333333; // 00110011...
    // int mask4 = 0x0F0F0F0F; // 00001111...
    // int mask8 = 0x00FF00FF; // 0000000011111111...
    // int mask16 = 0x0000FFFF; // 00000000000000001111111111111111
    int mask1 = 0x55 | (0x55 << 8);
    int mask2 = 0x33 | (0x33 << 8);
    int mask4 = 0x0f | (0x0f << 8);
    int mask8 = 0xff | (0xff << 16);
    int mask16 = 0xff | (0xff << 8);
    mask1 = mask1 | (mask1 << 16);
    mask2 = mask2 | (mask2 << 16);
    mask4 = mask4 | (mask4 << 16);

    cout << (bitset<sizeof(x)*8>)x << endl;
    x = (x & mask1) + ((x >> 1) & mask1);
    cout << (bitset<sizeof(x)*8>)x << endl;
    x = (x & mask2) + ((x >> 2) & mask2);
    cout << (bitset<sizeof(x)*8>)x << endl;
    x = (x & mask4) + ((x >> 4) & mask4);
    cout << (bitset<sizeof(x)*8>)x << endl;
    x = (x & mask8) + ((x >> 8) & mask8);
    cout << (bitset<sizeof(x)*8>)x << endl;
    x = (x & mask16) + ((x >> 16) & mask16);
    cout << (bitset<sizeof(x)*8>)x << endl;

    return x;
}

int conditional(int x, int y, int z) {
    int mask = !!x; // 如果 x 不为 0，mask 就是 1，否则为 0
    int result = (mask << 31) >> 31; // 将 mask 扩展到 32 位

    return (result & y) | (~result & z); // 根据 mask 选择 y 或 z
}

// int fitsBits(int x, int n) {
//     int shift = 32 + (~n + 1); // 计算右移的位数
//      cout << (bitset<sizeof(x)*8>)x << endl;
//     int shifted = x >> shift; // 将 x 右移 n-1 位
//     cout << (bitset<sizeof(shifted)*8>)shifted << endl;
//     return !(shifted ^ 0) | !(shifted ^ -1); // 如果 shifted 等于 0 或 -1，返回1，否则返回0
// }

int fitsBits(int x, int n) {
    int shift = 32 + ~n + 1;
    return !(x ^ ((x<<shift)>>shift));
}

int dividePower2(int x, int n) {
    return (x + ((x>>31) & ((1<<n) + ~0))) >> n;
}

// int howManyBits(int x) {
//   int m=0;
//   x=x^(x<<1);
//   m=m+((!!(x&((~0)<<(m+16))))<<4);
//   m=m+((!!(x&((~0)<<(m+8))))<<3);
//   m=m+((!!(x&((~0)<<(m+4))))<<2);
//   m=m+((!!(x&((~0)<<(m+2))))<<1);
//   m=m+(!!(x&((~0)<<(m+1))));
//   return m+1;
// }

int howManyBits(int x) {
  // 原理：对于正数，从高位到低位，找第一个位是1的（比如是n），再加上符号位，则最少需要n+1个位；
  // 对于负数，从高位到低位，找第一个位是0的（比如是n），则最少需要n位
  int b16, b8, b4, b2, b1, b0; // 表示0~15、16~23、24~27、28~29、30、31的位置处是否含有1，如有，则对其赋值需要的位数
  int sign = x >> 31; // 取符号位
  x = (sign&~x)|(~sign&x); // 如果x为正则不变，x为负则取反，这里是为了统一正负数，我们之后只用找到含有1的位置即可

  b16 = !!(x >> 16) << 4;// 先看高16位是否含有1，若有则表示至少需要16位，所以给b16赋值为16(1 << 4 = 16)
  x =  x >> b16; // 若有1，则原数右移16位，因为上面已经确定是否至少需要16位(针对0~15)；若没有1，则b16为0，x不用移位，继续往下面判断

  b8 = !!(x >> 8) << 3; // 看剩余位的高8位是否含有1，若有则表示至少还需要8位，给b8赋值为8
  x = x >> b8; // 同理...

  b4 = !!(x >> 4) << 2;
  x = x >> b4;

  b2 = !!(x >> 2) << 1;
  x = x >> b2;

  b1 = !!(x >> 1);
  x = x >> b1;
  b0 = x;
  return b16+b8+b4+b2+b1+b0+1; // 最后加上符号位
}

// int howManyBits(int x) {
//   int neg = x >> 31;
//   int sign = (x >> 31) & 1;
//   int bit0, bit1, bit2, bit4, bit8;
//   int bit16, bit32;
//   x = (x & ~neg) | ((~x + 1) & neg);
//   bit16 = !!(x >> 16) << 4;
//   x >>= bit16;
//   bit8 = !!(x >> 8) << 3;
//   x >>= bit8;
//   bit4 = !!(x >> 4) << 2;
//   x >>= bit4;
//   bit2 = !!(x >> 2) << 1;
//   x >>= bit2;
//   bit1 = !!(x >> 1);
//   x >>= bit1;
//   bit0 = x;
//   bit32 = bit16 + bit8 + bit4 + bit2 + bit1 + bit0 + 1;
//   return sign + bit32;
// }

// int isLessOrEqual(int x, int y) {
//   int z = x + ~y + 1;
//   return !((z >> 31) ^ -1) | !(z ^ 0);
// }

int isLessOrEqual(int x, int y) {
  int sign_x = (x >> 31) & 1;
  int sign_y = (y >> 31) & 1;
  int sign_z = ((y + (~x + 1)) >> 31) & 1;
  return ((!sign_y) & (sign_x) & (sign_z)) | ((!((sign_y) & (!sign_x))) & (!sign_z));
}


int intLog2(int x) {
  int z = 0;
  z = z + ((!!(x & ((~0) << (z + 16)))) << 4);
  z = z + ((!!(x & ((~0) << (z + 8)))) << 3);
  z = z + ((!!(x & ((~0) << (z + 4)))) << 2);
  z = z + ((!!(x & ((~0) << (z + 2)))) << 1);
  z = z + (!!(x & ((~0) << (z + 1))));
  return z;
}

unsigned floatScale1d2(unsigned uf) {
    unsigned int sign = uf & 0x80000000;
    unsigned int exp = uf & 0x7F800000;

    if (exp == 0x7F800000) {
        return uf;
    } else if (exp > 0x00800000) {
        exp -= 0x00800000;
        return (uf & 0x807fffff) | exp;
    } else {
        if ((uf & 0x3) == 0x3) uf += 0x2;
        return sign | ((uf >> 1) & 0x007fffff);
    }
}

// unsigned floatScale1d2(unsigned uf) {
//   int sign = uf & 0x80000000;
//   int exp = (uf & 0x7f800000) >> 23;
//   if (exp == 255) return uf;
//   if (exp > 1) return (uf&0x807fffff)+((exp-1)<<23);
//   if((uf&0x3)==0x3) uf=uf+2;
//   return sign | ((uf>>1)&0x007fffff);
// }


// unsigned floatAbsVal(unsigned uf) {
//     unsigned int abs_uf = uf & 0x7FFFFFFF;  // 将符号位清零
//     unsigned int is_nan = uf & 0x7F800000;  // 检查指数字段，判断是否为 NaN
    
//     if (is_nan == 0x7F800000) {
//         return uf;  // 如果指数字段为全1，说明是 NaN，返回原始值
//     } else {
//         return abs_uf;  // 否则返回绝对值
//     }
// }

unsigned floatAbsVal(unsigned uf) {
  if (((uf & 0x7f800000) >> 23 == 255) && (uf & 0x7fffff)) return uf;
  return uf & 0x7fffffff;
}


int floatFloat2Int(unsigned uf) {
  int exp = ((uf & 0x7F800000) >> 23) - 127; // 计算出指数
  int sign = uf >> 31; // 取符号位
  int frac = ((uf & 0x007FFFFF) | 0x00800000); 
  if (!(uf & 0x7FFFFFFF)) return 0; // 若原浮点数为0，则返回0

  if (exp > 31) return 0x80000000; // 若原浮点数指数大于31，返回溢出值
  if (exp < 0) return 0; // 若浮点数小于0，则返回0；

  if (exp > 23) frac = frac << (exp - 23); // 将小数转化为整数
  else frac = frac >> (23 - exp);

  if (!((frac >> 31) ^ sign)) return frac; // 判断是否溢出，若符号位没有变化，则没有溢出，返回正确的值
  else if (frac >> 31) return 0x80000000; // 原数为正值，现在为负值，返回溢出值
  else return ~frac + 1; // 原数为负值，现在为正值，返回相反数
}

int main()
{
    int z = floatScale1d2(0x0);
    cout << z;
}
