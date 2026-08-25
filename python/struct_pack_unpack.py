import struct

# 字节序定义
# < 小端
# > 大端
# ! 网络字节序（同 > ）
# @ 本机字节序
#
# 格式符定义
# b signed char
# B unsigned char
# h short
# H unsigned short
# i int
# I unsigned int
# q signed long long
# Q unsigned long long
# f float


if __name__ == "__main__":
    value = struct.pack("<B", 128)
    [byte1_val] = struct.unpack("<B", value)
    print(byte1_val)

    value = struct.pack("<H", 76)
    [byte2_val] = struct.unpack("<H", value)
    print(byte2_val)
