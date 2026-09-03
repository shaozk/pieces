class BadPlayer:
    def __init__(self, name: str, items: list = []):
        self.name = name
        self.items = items


class GoodPlayer:
    def __init__(self, name: str, items: list = None):
        self.name = name
        if items is None:
            self.items = []
        else:
            self.items = items


a = GoodPlayer("A")
b = GoodPlayer("B")

a.items.append("hello")
b.items.append("world")

print(a.items)
print(b.items)
