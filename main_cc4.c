#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int age;
} Student;

/**
 * 结构体赋值操作
 *
 * @return
 */
/*int main() {
    Student stu1 = {"Darren", 24};
    Student stu2;

    stu2 = stu1; //赋值操作 =相当于内容赋值操作

    printf("%p, %p\n", &stu1, &stu2);
    printf("%p, %p\n", &(stu1.name), &(stu2.name));
    printf("name: %s,age: %d\n", stu2.name, stu2.age);

    return 0;
}*/

/**
 * 结构体套指针
 *
 * @return
 */
/*int main() {
    Student stu = {"Jack",//指向常量区的"Jack"
                   23};
    //结构体套指针，我们必须要对结构体指针进行初始化（赋值）
    //指针可以指向任何地址，指针的大小永远是8字节（Mac）
    stu.name = malloc(100);
    strcpy(stu.name, "Mark");
    //size 16  mac上指针8字节，win4字节
    printf("name: %s,age: %d,size: %d\n", stu.name, stu.age, sizeof(Student));

    free(stu.name);
    return 0;
}*/

// 3 深拷贝和浅拷贝
void CopyTo(Student *from, Student *to) {
    *to = *from;

    to->name = malloc(100);
    strcpy(to->name, from->name);//值拷贝，目标在前面
}

/*int main() {
    Student stu = {"Jack",//指向常量区的"Jack"
                   23};
    stu.name = malloc(100);
    strcpy(stu.name, "Mark");

    Student stu1;
    CopyTo(&stu, &stu1);

    printf("name: %s,age: %d\n", stu1.name, stu1.age);

    if (stu.name) {
        free(stu.name);
        stu.name = NULL;
    }

    if (stu1.name) {
        free(stu1.name);
        stu1.name = NULL;
    }
    return 0;
}*/

struct date {//12
    int year;//4
    int month;//4
    int day;//4
    char min;//两个连续小于4就会合并为算为4，否者单独算为4
    char max;
};

struct student {//31
    int number;//4
    char sex;//1 字节对齐占4字节
    int age;//4
    char name[10];//10
    struct date birthday;//12
};

/**
 * 结构体偏移量
 *
 * 0.指针置为NULL
 * 1.获取内存元素偏移量 &(stu->name)
 * 2.获取结构体的大小sizeof(student)
 * 3.根据美俄偏移量计算出来的，结构体的大小和数据变量位置摆放有关
 * 4.把最小字节尽量往后靠，结构体一旦定义了不要轻易区移动，因为我们只要知道内部任一地址，那么就能知道整个结构体
 *
 * @return
 */
int main() {
    int size = sizeof(struct student); //36
    printf("size = %d\n", size);

    struct student *stu = NULL;

    // 内部偏移量问题 NULL将地址置为0  &(stu->age)
    printf("%d\n", &(stu->age));

    return 0;
}

