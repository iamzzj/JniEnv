#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 定义一个结构体
 * 相当于java的class
 */
struct Worker {
    char name[8];
    int age;
    double salary;
};
typedef struct Worker Worker;
typedef struct Worker *WorkerP;

//第二种方式，这种方式会有一个默认初始值
struct Worker1 {
    char name[18];
    int age;
    double salary;
} darren = {"darren", 43}, jack;

//第三种方式
struct Work {
    char name[10];
    char grade[10];
};
struct Worker3 {
    char name[10];
    int age;
    double salary;
    struct Work work;
};

/*int main() {

    struct Worker worker = {"Darren", 23, 2400.1};

    //赋值
    worker.age = 24;
    strcpy(worker.name, "Jack");

    printf("name = %s, age = %d, salary = %lf\n",
           darren.name,
           darren.age,
           darren.salary);

    struct Worker3 worker3 = {"Darren", 23, 1000, {
            "Android", "中级"
    }};

    printf("name is %s, work.name is %s\n", worker3.name, worker3.work.name);

    return 0;
}*/

/**
 * 结构体的指针和内存开辟
 *
 * @return
 */
/*int main() {
    struct Worker worker = {"Darren", 23};

    struct Worker *worker_p = &worker;
    //通过结构体指针去操作数据
    worker.age = 33;
    printf("age is %d\n", worker.age);

    worker_p->age = 43;
    strcpy(worker_p->name, "Jack");
    printf("name is %s\n", worker_p->name);
    printf("age is %d\n", worker_p->age);

    return 0;
}*/

/*int main() {
    //指针取别名 Worker* = WorkerP
    //结构体 struct Workder = Workder
    WorkerP worker = (Worker *) malloc(sizeof(Worker));
    strcpy(worker->name, "Jack");
    worker->age = 24;

    printf("name is %s\n", worker->name);
    printf("age is %d\n", worker->age);

    //结构体数组
    //第一种
    Worker workers[10] = {
            {"Jack", 23, 3004},
            {"Mark", 23, 3400}
    };//创建10个，静态开辟
    printf("workers[0].name is %s\n", workers[0].name);
    //第二种
    Worker *workers1 = (Worker *) malloc(sizeof(Worker) * 10);
    strcpy(workers1[0].name, "Jack");
    workers1->age = 10;
    printf("workers1[0].name is %s\n", workers1[0].name);
    printf("workers1[0].age is %d\n", workers1[0].age);

    // 24字节
    printf("size of worker: %d", sizeof(Worker));
    // 计算规则 18+4+8=30
    // 1.按照最大的字节计算
    // 2.算的时候只会计算基本数据类型
    // 3.会把所有字节数加起来，是否能整除最大基本类型字节数

    return 0;
}*/

/**
 * 联合体只能存在一个
 */
union Person {
    char name[10];
    int age;
};
typedef union Person Person;

/*int main() {
    //Person person = {"Darren"};
    Person person;
    //person.age = 23;
    //strcpy(person.name, "Darren");

    // 只能出现一个，找最大值 10，除以最大基本类型，然后要被最大基本类型整除
    printf("sizeof union %d\n", sizeof(Person));
    printf("name is %s\n", person.name);
    printf("age is %d\n", person.age);

    return 0;
}*/

/**
 * 枚举的定义和使用，枚举有点类似于int
 */
enum CommentType {
    TEXT,
    TEXT_IMAGE,
    IMAGE
};
typedef enum CommentType CommentType;

int main() {
    CommentType commentType = TEXT;
    CommentType commentType1 = TEXT_IMAGE;

    printf("%d, %d", commentType, commentType1);

    return 0;
}