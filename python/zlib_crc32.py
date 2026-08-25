import zlib

if __name__ == "__main__":
    crc = zlib.crc32(b"hello world")
    print(crc)
