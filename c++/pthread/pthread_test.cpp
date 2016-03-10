#include <iostream>
#include <pthread.h>
#include <unistd.h>

using std::cout;
using std::cin;
using std::endl;

int i=100;

pthread_cond_t cond_show = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex_cond = PTHREAD_MUTEX_INITIALIZER;

void *inc(void *)
{
	bool s=false;
	while(i){
		pthread_mutex_lock(&mutex_cond);
		if(i>50){
			i--;
			cout<<"inc"<<i<<endl;
		}else if(!s){
			pthread_cond_signal(&cond_show);
			s=true;
		}
		pthread_mutex_unlock(&mutex_cond);
	}
	return (void *)0;
}

void *show(void *)
{
	while(i)
	{
		pthread_mutex_lock(&mutex_cond);
		if(i>50){
			pthread_cond_wait(&cond_show,&mutex_cond);
		}else{
			i--;
			cout<<"show"<<i<<endl;
		}
		pthread_mutex_unlock(&mutex_cond);
	}
	return (void *)0;
}
int main()
{
	pthread_t thread_show;
	pthread_t thread_inc;
	pthread_create(&thread_inc,NULL,show,NULL);
	pthread_create(&thread_show,NULL,inc,NULL);
	pthread_join(thread_show,NULL);
	pthread_join(thread_inc,NULL);
    return 0;
}

		


