import time
import asyncio


def sync_blocking():
    print("sync blocking start")
    time.sleep(3)
    print("sync blocking stop")


def sync_stream():
    print("sync loop start")
    for i in range(5):
        time.sleep(0.5)
        yield i
    print("sync loop stop")


async def async_blocking():
    print("async blocking start")
    await asyncio.sleep(3)
    print("async blocking stop")


async def async_stream():
    print("async loop start")
    for i in range(5):
        await asyncio.sleep(0.5)
        yield i
    print("async loop stop")


if __name__ == "__main__":
    # sync
    sync_blocking()
    for item in sync_stream():
        print(item)

    print("---")

    # async
    async def main():
        task = asyncio.create_task(async_blocking())

        async for item in async_stream():
            print(item)

        await task

    asyncio.run(main())
