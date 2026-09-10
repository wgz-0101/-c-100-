#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//什么是交叉编译
//交叉编译是指在一种平台上编译生成另一种平台可执行文件的过程。通常用于在开发环境和目标环境不同的情况下进行软件开发。例如，在Windows上编译生成Linux可执行文件，或者在x86架构上编译生成ARM架构的可执行文件。
//什么是环形缓冲区
//环形缓冲区（Circular Buffer）是一种数据结构，它使用固定大小的缓冲区作为一个循环队列。当缓冲区满时，新写入的数据会覆盖最旧的数据。环形缓冲区常用于数据流处理、音频处理和网络通信等场景，因为它可以高效地管理数据的读写操作，避免频繁的内存分配和释放。
//定义缓冲区
#define BUFFER_SIZE 1024

//定义缓冲区结构体
struct CircularBuffer{
    char buffer[BUFFER_SIZE];
    int head;//写指针
    int tail;//读指针
    int count;//是否满
};

//写入缓冲区函数
/*
    函数名: WriteBuffer
    功能: 将数据写入环形缓冲区
    参数:
        cb: 指向环形缓冲区结构体的指针
        data: 要写入的数据
        len: 数据长度
*/
void WriteBuffer(struct CircularBuffer *cb, const char *data, int len)
{
    // 实现写入逻辑
    for (int i = 0;i<len;i++)
    {
        cb->buffer[cb->head] = data[i];
        cb->head = (cb->head + 1) % BUFFER_SIZE;
    }
    //更新计数器
    cb->count += len;
    if (cb->count > BUFFER_SIZE)
    {
        cb->count = BUFFER_SIZE;
    }

}

/*
    读取缓冲区函数
    函数名: ReadBuffer
    功能: 从环形缓冲区读取数据
    参数:
        cb: 指向环形缓冲区结构体的指针
        data: 用于存储读取数据的缓冲区
        len: 要读取的数据长度
    返回值: 实际读取的数据长度  
*/
int ReadBuffer(struct CircularBuffer *cb, char *data, int len)
{
    //实现读取逻辑
    int readLen = (len < cb->count) ? len : cb->count;  //取要读取的长度和缓冲区中数据量的最小值
    for (int i = 0; i < readLen; i++)   //循环读取数据
    {
        data[i] = cb->buffer[cb->tail];    //将缓冲区中的数据读取到data中
        cb->tail = (cb->tail + 1) % BUFFER_SIZE;   //更新读指针
    }
    //更新计数器
    cb->count -= readLen; 
    return readLen;
}

//判断缓冲区是否满
/*
    函数名: IsBufferFull
    功能: 判断环形缓冲区是否已满
    参数:
        cb: 指向环形缓冲区结构体的指针
    返回值: 1表示缓冲区已满，0表示缓冲区未满
*/
int IsBufferFull(struct CircularBuffer *cb)
{
    return cb->count == BUFFER_SIZE;
}

//判断缓冲区是否空
/*
    函数名: IsBufferEmpty
    功能: 判断环形缓冲区是否为空
    参数:
        cb: 指向环形缓冲区结构体的指针
    返回值: 1表示缓冲区为空，0表示缓冲区不为空
*/
int IsBufferEmpty(struct CircularBuffer *cb)
{
    return cb->count == 0;
}

//清空缓冲区
/*
    函数名: ClearBuffer
    功能: 清空环形缓冲区
    参数:
        cb: 指向环形缓冲区结构体的指针
*/
void ClearBuffer(struct CircularBuffer *cb)
{
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

/*

    函数名: main
    功能: 测试环形缓冲区的写入和读取功能
    参数:
        argc: 命令行参数个数
        argv: 命令行参数数组
    返回值: 0表示程序正常结束
*/

int main(int argc, char const *argv[])
{
    /* code */
    struct CircularBuffer cb;  //定义环形缓冲区结构体变量
    ClearBuffer(&cb);  //初始化缓冲区
    WriteBuffer(&cb, "Hello, Circular Buffer!", 23);
    char readData[BUFFER_SIZE];  //定义读取数据的缓冲区
    int bytesRead = ReadBuffer(&cb, readData, 23);  //从环形缓冲区读取数据
    readData[bytesRead] = '\0';  //在读取的数据末尾添加字符串结束符
    printf("读取的数据: %s\n", readData);  //打印读取的数据
    printf("缓冲区是否已满: %s\n", IsBufferFull(&cb) ? "是" : "否");
    printf("缓冲区是否为空: %s\n", IsBufferEmpty(&cb) ? "是" : "否");
    

    return 0;
}
