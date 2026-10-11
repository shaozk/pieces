def foo():
    pass


if __name__ == "__main__":
    print(callable(foo))
    print(callable(len))
    print(callable(12))
    print(callable("str"))
