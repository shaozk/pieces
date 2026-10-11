// 704
//
// 题目描述
// 系统从传感器的某个寄存器
// 读取一个32位的 int 型整数 packet。请按如下要求解析输入数据,然后按十进制格式输出结果。
// 
// 该数据的二进制结构定义如下:
// * bit0(最低位):状态。1表示传感器正常,0表示传感器故障重。
// * bit1~bit2:寄存器ID。0~3。
// * bit3:数据类型。1表示变长数据类型,0表示固定长度数据关类型。
// * bit4~bit11:数据修正因子。
// * bit12~bit15:数据有效长度。0~15,数据类型为1时才生效。
// * bit16~bit30:数据。数据类型为1时,从低到高依据数据有效改长度确定实际有效数据位;数据类型为0时,全部为有效数据位。
// * bit31:数据奇偶校验位:数据中的所有有效数据位与奇偶校驱俭中1的个数为偶数,表示数据校验通过;否则为不通过。
// 
// 解析流程:
// 1.检查状态,如果传感器故障(状态为0),返回-1。
// 2.检查数据奇偶校验是否通过,不通过则返回-2。
// 3.数据类型为1时,数据有效长度如果为0,则返回-3。
// 4.寄存器ID为0时:返回有效数据与数据修正因子按位与的结果。
// 5.寄存器ID为1时:返回有效数据与数据修正因子按位或的约结果。
// 6.寄存器ID为2时:返回有效数据与数据修正因子按位异或的结果。
// 7.寄存器ID为3时:返回有效数据与数据修正因子按位同或的的结果。
// 注:解析流程中4、5、6、7步骤的结果返回前需要和0xOFFFFFFFFF取与。
// 
// 输入描述
// 输入为一个32位整型数值 packet。
// 
// 输出描述
// 按十进制格式输出解析结果。

#include <iostream>

using namespace std;

int popcount(int x) {
  int cnt = 0;
  while (x) {
    cnt += x & 1;
    x >>= 1;
  }
  return cnt;
}

int parse(int packet) {
  if ((packet & 0x01) == 0) {
    return -1;
  }
  int id = (packet >> 1) & 0x03;
  int type = (packet >> 3) & 0x01;
  int factor = (packet >> 4) & 0xFF;
  int len = (packet >> 12) & 0x0F;
  int check = (packet >> 31) & 0x01;

  int data = 0;
  if (type == 1) {
    if (len == 0) return -3;
    data = (packet >> 16) & ((1u << len) - 1);
  } else {
    data = (packet >> 16) & 0x7FFF;
  }

  int ones = popcount(data) + check;
  if (ones % 2 == 1) {
    return -3;
  }  

  int result = 0;
  switch (id) {
    case 0:
      result = data & factor;
      break;
    case 1:
      result = data | factor;
      break;
    case 2:
      result = data ^ factor;
      break;
    case 3:
      result = (data ^ factor); // 同或
      break;
    default:
      break;
  }
  result &= 0xFFFFFFFF;
  return result;
}

int main() {
  int packet;
  cin >> packet;
  return 0;
}
