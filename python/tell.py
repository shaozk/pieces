from io import BytesIO


if __name__ == "__main__":
    io: BytesIO = BytesIO(b"hello world")
    print(f"tell: {io.tell()}")

    io.read(1)
    print(f"tell: {io.tell()}")

    io.read(2)
    print(f"tell: {io.tell()}")

    io.read(15)
    print(f"tell: {io.tell()}")
