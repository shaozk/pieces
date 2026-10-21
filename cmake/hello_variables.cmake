# 变量与列表基础：set/list 操作与 message 输出，运行 cmake -P hello_variables.cmake
set(name "CMake")
set(nums 1 2 3)

# 单个值 vs 列表：QUOTED 是一个整串，UNQUOTED 是 3 元素列表
set(quoted "1 2 3")
set(unquoted 1 2 3)
list(LENGTH unquoted len)
message(STATUS "quoted   = ${quoted}")    # 1 2 3
message(STATUS "unquoted = ${unquoted}")  # 1;2;3
message(STATUS "len      = ${len}")       # 3

# 列表追加 / 删除 / 反转
list(APPEND nums 4 5)
list(REMOVE_ITEM nums 2)
list(REVERSE nums)
message(STATUS "nums     = ${nums}")      # 5;4;3;1

# 未定义变量展开为空串，不报错
message(STATUS "undef    = '${no_such_var}'")

# 环境变量与普通变量是两个命名空间
set(ENV{MY_ENV} "hello")
message(STATUS "env      = $ENV{MY_ENV}")

message(STATUS "hello, ${name}!")
