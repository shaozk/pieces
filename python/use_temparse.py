from temparse import parse

city, year = parse[str, int](
    t"I live in {str}, since {int}", "I live in shenzhen, since 2025"
)

assert city == "shenzhen"
assert year == 2025

print("city = ", city)
print("year = ", year)
