#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

void tmp() {
  printf("tmp()\n");
}

void foo() {
  printf("foo()\n");
  longjmp(env, 1);
  tmp();
}

int main() {
  if (setjmp(env) == 0) {
    // 首次执行，正常流程
    foo();
  } else {
    // 从 longjmp(env, 1) 跳回
    printf("jumped back\n");
  }
  return 0;
}
