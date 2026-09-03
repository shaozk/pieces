import asyncio


async def async_generator():
    for i in range(3):
        yield i


async def main():
    # Create async iterator - O(1)
    async_iter = aiter(async_generator())

    # Iterate
    value = await async_iter.__anext__()
    print(value)  # 0


asyncio.run(main())
