#include<iostream>
using namespace std;

struct process
{
    int PS; //进程序号
    int RunTime; //估计运行时间
    char State='R'; //运行状态
    int ArrTime;
    process* next;
    process(int PS, int RunTime, int ArrTime, process* next = NULL)
    {
        this->PS = PS;
        this->RunTime = RunTime;
        this->State = 'R';
        this->ArrTime = ArrTime;
        this->next = next;
    }
};
//打印出当前各个进程的运行情况
void PrintProcess(process* p)
{
    for (int i = 0; i < 5; i++)
    {
        cout << "进程编号" << " " << "剩余运行时间" << " " << "目前状态" << endl;
        cout << "    " << i << "      " << p->RunTime << "                " << p->State << endl;
        p = p->next;
    }
}
void CheckOnce(process* p, int &Timer)
{
    for (int i = 0; i < 5; i++)
    {
        if (p->ArrTime > Timer)
        {
            //这个程序还没到达，先跳过，直接到下一个进程,假设这个判断不消耗时间片
            p = p->next;
            continue;
        }
        
        else
        {
            if (p->RunTime == 0)
            {
                p->State = 'C';
 
            }
            else if (p->RunTime != 0)
            {
                //运行一个时间片
                p->RunTime -= 1;
                if (p->RunTime == 0)
                {
                    p->State = 'C';

                }
                cout << "Process[" << p->PS << "] is Running now." << endl;
                Timer++;

            }
        }

        p = p->next;

    }
    cout << endl;
    PrintProcess(p);//打印目前各个进程的状态
    cout << endl << endl << endl;
}
//判断是否完成了全部进程的执行
bool IsFinished(process* p)
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (p->RunTime != 0)
        {
            count++;
        }
        p = p->next;
    }

    if (count == 0)
    {
        return true;
    }
    return false;
}

void RoundTime(process* p)
{
    int Timer = 0;
    while (!IsFinished(p))
    {
        CheckOnce(p, Timer);
    }
    cout << "All processes have finished !" << endl;
}



int main()
{
    process p4 = { 4,1,9,NULL };
    process p3 = { 3,2,3,NULL };
    process p2 = { 2,4,2,NULL };
    process p1 = { 1,3,1,NULL };
    process p0 = { 0,9,0,NULL };

    p0.next = &p1;
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = &p0;

    
    //cout << "Enter the Process Running time in order of their arrive time" << endl;
    //cin >> p0.RunTime >> p1.RunTime >> p2.RunTime >> p3.RunTime >> p4.RunTime;
    //cout << p0.next->RunTime << endl;
   // cout << p0.RunTime << endl;
    RoundTime(&p0);
    return 0;
}
