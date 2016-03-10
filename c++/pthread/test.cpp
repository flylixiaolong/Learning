#include <iostream>
#include <pthread.h>
#include <unistd.h>

using std::cout;
using std::cin;
using std::endl;

long int i=100000;

pthread_cond_t cond_show1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_show2 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex_cond = PTHREAD_MUTEX_INITIALIZER;

void *inc(void *)
{
	bool s=false;
	while(i){
		pthread_mutex_lock(&mutex_cond);
		if(i%2!=0)
			pthread_cond_wait(&cond_show1,&mutex_cond);
		else{
			pthread_cond_signal(&cond_show2);
			cout<<"inc:"<<i<<endl;
			i--;
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
		if(i%2==0)
			pthread_cond_wait(&cond_show2,&mutex_cond);
		else{
			pthread_cond_signal(&cond_show1);
			cout<<"show:"<<i<<endl;
			i--;
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

		


