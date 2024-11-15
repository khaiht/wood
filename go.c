#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Kích thước tối đa của ngăn xếp
#define MAX_STACK_SIZE 100

// Cấu trúc để lưu thông tin của một tấm gỗ
typedef struct {
    int age;
    char type[20];
    int size;
} WoodPlank;

// Cấu trúc ngăn xếp để lưu trữ các tấm gỗ
typedef struct {
    WoodPlank data[MAX_STACK_SIZE];
    int top;
} WoodStack;

// Khởi tạo ngăn xếp rỗng
void initStack(WoodStack* stack) {
    stack->top = -1;
}

// Kiểm tra ngăn xếp có rỗng không
int isEmpty(WoodStack* stack) {
    return stack->top == -1;
}

// Kiểm tra ngăn xếp có đầy không
int isFull(WoodStack* stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

// Thêm một tấm gỗ vào ngăn xếp
void push(WoodStack* stack, int age, const char* type, int size) {
    if (isFull(stack)) {
        printf("Loi: Ngan xep da day.\n");
        return;
    }
    stack->data[++stack->top].age = age;
    strcpy(stack->data[stack->top].type, type);
    stack->data[stack->top].size = size;
}

// Lấy một tấm gỗ ra khỏi ngăn xếp
WoodPlank pop(WoodStack* stack) {
    if (isEmpty(stack)) {
        printf("Loi: Ngan xep rong.\n");
        return (WoodPlank){0, "", 0};
    }
    return stack->data[stack->top--];
}

// Hiển thị tất cả các tấm gỗ có cùng tuổi
void displaySameAge(WoodStack* stack, int age) {
    int count = 0;
    for (int i = stack->top; i >= 0; i--) {
        if (stack->data[i].age == age) {
            printf("Go - Tuoi: %d, Loai: %s, Kich thuoc: %d\n", 
                   stack->data[i].age, stack->data[i].type, stack->data[i].size);
            count++;
        }
    }
    if (count == 0) {
        printf("Khong co go %d tuoi.\n", age);
    }
}

int main() {
    // Khởi tạo kho lưu trữ gỗ
    WoodStack inventory;
    initStack(&inventory);

    // Thêm các tấm gỗ vào kho
    push(&inventory, 10, "Go Soi", 8);
    push(&inventory, 15, "Go Hoang Dan", 10);
    push(&inventory, 8, "Go Thong", 6);
    push(&inventory, 10, "Go Tuyet", 7);

    // Hiển thị tất cả các tấm gỗ 10 tuổi
    displaySameAge(&inventory, 10);

    return 0;
}