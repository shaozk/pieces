def func(name: str, items: list = []):
    items.append(name)
    print(items)


func("hello")
func("world")
