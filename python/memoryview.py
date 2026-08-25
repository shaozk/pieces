import functools


def log_func_name(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        print(f"---{func.__name__}()---")
        return func(*args, **kwargs)

    return wrapper


@log_func_name
def from_bytes():
    b = b"hello"
    mv = memoryview(b)

    print(mv)
    print(mv[0])
    print(mv[1:3])


@log_func_name
def from_bytearray():
    ba = bytearray(b"hello")
    mv = memoryview(ba)

    mv[0] = 72
    print(mv[0])
    print(mv[1:3])


@log_func_name
def from_array():
    import array

    arr = array.array("i", [1, 2, 3, 4, 5])
    mv = memoryview(arr)

    mv[0] = 2
    print(mv[0])
    print(mv)


if __name__ == "__main__":
    from_bytes()
    from_bytearray()
    from_array()
