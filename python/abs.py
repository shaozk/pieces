class MyStr:
    def __init__(self, s):
        self._str = s

    def __abs__(self):
        if self._str.startswith("-"):
            self._str = self._str[1:]
        return self._str

    def __str__(self):
        return f"{self._str}"


if __name__ == "__main__":
    print(abs(-1))
    print(abs(-1.0))
    print(MyStr("-10"))
    print(abs(MyStr("-10")))
