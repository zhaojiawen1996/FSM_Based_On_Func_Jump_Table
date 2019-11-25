/*
*************************************************************
* 文件名：Finite_State_Machine.c
* 作  者：wenzi
* 日  期：2019/11/24
* 版  本：V1.0
*************************************************************
*/


#include "Finite_State_Machine.h"
#include "stdio.h"

/*小孩醒的时候的跳转表*/
action_st action_weak[] = 
{
	{EAT,eat},
	{SMILE,sleep},
	{PEE,pee},
};

/*小孩睡觉时候的跳转表*/
action_st action_sleep[] =
{
	{SMILE,sleep},
	{PEE,pee},
};

/*小孩处于不同状态的跳转表*/
stat_st status_hal[] = 
{
	{WEAK, sizeof(action_weak)/sizeof(action_st), action_weak},
	{SLEEP,sizeof(action_sleep)/sizeof(action_st),action_sleep},
};


/*小孩吃饭的行为*/
int eat(int status)
{
    printf("kids eat\n");
	return SLEEP;
}

/*小孩微笑的行为*/
int sleep(int status)
{
	printf("kids sleep\n");
	return status;
}

/*小孩撒尿的行为*/
int pee(int status)
{
    printf("kid pee\n");
	return WEAK;
}

#if 0
int excute(int action)
{
     int next_state;
	 int act_id;
	 //status_hal[action].
	 next_state = status_hal[now_state].action_hal[action].act_handle(action);
     now_state = next_state;
	 printf("The kids now status is %d\n",now_state);
}

#else

/*
************************************************************
* 函数名：excute
* 功  能：转换表计算，根据参数选择对应的函数进行执行
* 形  参：int action：小孩的目前的行为
* 返回值：now_state:目前的状态
************************************************************
*/
int excute(int action)
{
    int next_state;
	int act_id;
	int act_num;
	action_st *action_handle;

	action_handle = status_hal[now_state].action_hal;
	act_num = status_hal[now_state].act_num;
	next_state = 0;

	if(now_state >= status_num)
	{
	    printf("unknown status!\n");
		return;
	}

	/*遍历整个转换表，当遍历到与当前设定值相等时，退出循环*/
	for(act_id = 0;act_id < act_num;act_id++)
	{
		if(action_handle[act_id].act == action)
		{
			next_state = action_handle[act_id].act_handle(action);
			break;
		}
	}

	if(act_id == act_num)
	{
		printf("Do Not Find action %d",action_handle[act_id]);
		printf(" in status %d\n",now_state);
	}
	now_state = next_state;
	printf("Next Status is:%d\n",now_state);
	return now_state;
}


#endif