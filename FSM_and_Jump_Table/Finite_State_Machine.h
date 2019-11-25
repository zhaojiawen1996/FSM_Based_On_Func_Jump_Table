/*
*************************************************************
* 文件名：Finite_State_Machine.c
* 作  者：wenzi
* 日  期：2019/11/24
* 版  本：V1.0
*************************************************************
*/

#ifndef __FINITE_STATE_MACHINE_H__
#define __FINITE_STATE_MACHINE_H__

/*小孩目前处于的状态*/
typedef enum
{
    WEAK = 0,
	SLEEP,
}KID_STAT;


/*小孩当前的行为*/
typedef enum
{
    EAT = 0,
	SMILE,
	PEE,
}KID_ACT;

/*定义小孩行为处理函数的函数指针*/
typedef int (*Act_Handle)(int);

typedef struct
{
    KID_ACT act;   
	Act_Handle act_handle;
}action_st;

typedef struct
{
	KID_STAT stat;
	int act_num;
	action_st *action_hal;/*定义为指针的原因是为了方便后续的跳转表中参数的传递*/
}stat_st;

/*小孩的各种行为*/
int eat(int status);
int sleep(int status);
int pee(int status);

int excute(int action);

extern int now_state;

#define status_num sizeof(status_hal)/sizeof(stat_st)

#endif