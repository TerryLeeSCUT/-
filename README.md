# -
Process scheduling algorithm
 实验三 进程调度算法模拟实验
一、	实验目的
通过模拟单处理器进程调度算法，加深对进程调度的概念理解。
二、	实验内容 
设计一个按时间片轮转法实现进程调度的程序。
三、实验要求
1. 假设系统有3-5个进程，每个进程用一个进程控制块（PCB）来代表。进程应当有如下属性：
  进程名：即进程标识。
  链接指针：按照进程到达系统的时间将处于就绪状态的进程连接成一个就绪队列。指针指出下一个到达的进程控制块地址。最后一个进程的链接指针为NULL。
  到达时间：进程创建时的系统时间或由用户指定，调度时，总是选择到达时间最早的进程。
  估计运行时间：可由设计者任意指定一个时间值。
  进程状态：为简单起见，这里假定进程有两种状态：就绪态和完成态。就绪状态用“R”表示，完成状态用“C”表示。假定进程一创建就处于就绪状态，运行结束时，就被置成完成状态。
2. 按照进程到达的先后顺序排成一个循环队列，设一个队首指针指向第一个到达进程的首址。另外再设一个当前运行的进程指针，指向当前正运行的进程。
3. 执行进程调度时，首先选择队首的第一个进程运行。
4. 由于本实验是模拟实验，所以对被选中的进程并不实际启动运行，而只是执行：估计运行时间减1，输出当前运行进程的名字。用这个操作来模拟进程的一次运行。
5. 进程运行一次后，以后的调度则将当前指针依次下移一个位置，指向下一个进程，即调整当前运行指针指向该进程的链接指针所指进程，以指示应运行进程，同时还应判断该进程的剩余运行时间是否为0。若不    为0，则等待下一轮的运行；若该进程的剩余运行时间为0，则将该进程的状态置为完成状态“C”，并退出循环队列。
6. 若就绪队列不空，则重复上述步骤4和5直到所有进程都运行完为止。
7. 在所设计的调度程序中，应包含显示或打印语句，以便显示或打印每次选中进程的名称及运行一次后队列的变化情况。
